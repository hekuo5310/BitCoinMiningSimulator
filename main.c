#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "save.h"
#include "i18n.h"

#ifdef _WIN32
#include <windows.h>
static void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
static void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

static void next_day(int* y, int* m, int* d) {
    int dim[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (*y % 4 == 0) dim[2] = 29;
    if (++(*d) > dim[*m]) { *d = 1; if (++(*m) > 12) { *m = 1; (*y)++; } }
}

typedef struct { int lo, hi; const char* name; const char* grade; int t_bonus; } Card;
static const Card CARDS[] = {
    {1,   1,    "H100",       "SSSSS", 10000},
    {10,  15,   "Tesla H800", "SSSS",   9500},
    {16,  20,   "RTX5090",    "SSS",    9000},
    {21,  25,   "RTX5080",    "SSS",    8000},
    {26,  30,   "RTX4090",    "SSS",    8000},
    {31,  40,   "RTX4080",    "SS",     7300},
    {41,  70,   "RTX3090",    "SS",     7000},
    {71,  140,  "RTX3070",    "S",      6000},
    {141, 240,  "RTX2090",    "S",      6000},
    {241, 1240, "RTX2070",    "A",      4500},
    {1241,2240, "RTX1090",    "A",      4500},
    {2241,4238, "RTX1070",    "B",      3000},
    {4239,4239, "RX6000XT",   "SSS+",   9900},
    {4240,4240, "RX6000",     "SSS",    9000},
    {4241,4340, "RX5000",     "SS",     7500},
    {4341,4440, "RX4000",     "S",      6000},
};
#define CARDS_LEN (int)(sizeof(CARDS)/sizeof(CARDS[0]))

static void do_draw(char* xk, int* t, const Lang* L) {
    int r = rand() % 10000;
    for (int i = 0; i < CARDS_LEN; i++) {
        if (r >= CARDS[i].lo && r <= CARDS[i].hi) {
            printf("%s%s [%s]\n", L->draw_got, CARDS[i].name, CARDS[i].grade);
            strcpy(xk, CARDS[i].name);
            *t = *t - CARDS[i].t_bonus;
            if (*t < 0) *t = 0;
            return;
        }
    }
    if (r >= 4441 && r <= 9990) printf("%s\n", L->draw_bonus);
    else printf("%s\n", L->draw_nothing);
}

int main(void) {
    const Lang* L = get_lang();
    srand((unsigned)time(NULL));

    int y = 2022, m = 1, d = 1;
    int t = 10000, c = 0, b_yuan = 36000;
    char in[4];
    long long success = 0, fail = 0;
    long long w = 0, wh = 100, rmb = 0, um = 0, xkm = 1;
    int mail[3] = {1, 0, 0};
    char xk[32] = "GTX1060";

    printf("%s\n", L->disclaimer);
    sleep_ms(3000);

    printf("%s", L->loading); fflush(stdout);
    load_game(&rmb, &success, &xkm, xk);
    sleep_ms(1000);
    printf("\r%s\n", L->ready);
    printf("|=== Mining Simulator " VERSION " - XINGJI ===|\n");
    sleep_ms(1500);
    for (int i = 0; i < 40; i++) printf("\n");

    while (1) {
        if (rmb < 0 && rmb >= -10000)
            printf("%s\n", L->overdraft_free);
        else if (rmb < -10000) {
            printf("%s\n", L->overdraft_over);
            um += (-rmb) / 100;
        }

        printf("%s\n%s\n", L->menu, L->menu_prompt);
        scanf(" %c", &in[0]); in[0] = (char)toupper((unsigned char)in[0]);

        if (in[0] == 'A') {
            c = 1;
        } else if (in[0] == 'B') {
            printf("%s\n", L->saving);
            save_game(rmb, success, xkm, xk);
            sleep_ms(1000);
            return 0;
        } else if (in[0] == 'C') {
            c = 2;
        } else if (in[0] == 'D') {
            printf("%s\n", L->draw_menu);
            scanf(" %c", &in[0]); in[0] = (char)toupper((unsigned char)in[0]);
            if (in[0] == 'A') {
                if (rmb < 10000) printf("%s\n", L->not_enough);
                else { rmb -= 10000; do_draw(xk, &t, L); }
            }
        } else if (in[0] == 'E') {
            if (mail[0]) {
                printf("%s\n", L->mail_new);
                scanf(" %c", &in[0]);
                rmb += 1000000;
                mail[0] = 0;
                printf("%s\n", L->mail_claimed);
            } else {
                printf("%s\n", L->mail_none);
            }
        }

        if (c == 2) {
            printf("%s\n", L->settings_menu);
            scanf(" %c", &in[0]); in[0] = (char)toupper((unsigned char)in[0]);
            if      (in[0] == 'A') { scanf("%lld", &wh); }
            else if (in[0] == 'B') { printf("%s\n", L->changelog); }
            else if (in[0] == 'C') { printf("%s\n", L->about); }
            else if (in[0] == 'D') {
                long long amount;
                printf("%s", L->loan_prompt);
                scanf("%lld", &amount);
                um += amount; rmb += amount;
            }
            else if (in[0] == 'E') { printf("%s\n", L->version_str); }
            c = 0;
        }

        while (c == 1) {
            int l = rand() % 500 + 1;
            w++;
            next_day(&y, &m, &d);
            if (um > 0) um += um / 100;

            if (w % l == 0) {
                success++;
                printf(L->mining_ok, y, m, d, success, fail); printf("\n");
            } else {
                fail++;
                printf(L->mining_fail, y, m, d, success, fail); printf("\n");
            }
            sleep_ms(t);

            if (w == wh) {
                rmb = success * b_yuan;
                printf(L->round_end, success, rmb, um); printf("\n");
                printf("%s\n", L->round_menu);
                scanf(" %c", &in[0]); in[0] = (char)toupper((unsigned char)in[0]);
                if (in[0] == 'B') { c = 0; }
                else if (in[0] == 'C') {
                    if (rmb >= um) {
                        rmb -= um; um = 0;
                        printf(L->debt_repaid, rmb); printf("\n");
                    } else {
                        printf("%s\n", L->debt_insuf);
                    }
                    sleep_ms(1000);
                    c = 0;
                }
                w = 0;
            }
        }
    }
}
