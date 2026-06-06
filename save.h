#ifndef SAVE_H
#define SAVE_H

#include <stdio.h>
#include <string.h>

static void save_game(long long rmb, long long bitcoin, long long xkm, const char* xk) {
    FILE* f = fopen("archive.txt", "w");
    if (f) { fprintf(f, "%lld\n%lld\n%s\n%lld\n", rmb, bitcoin, xk, xkm); fclose(f); }
}

static void load_game(long long* rmb, long long* bitcoin, long long* xkm, char* xk) {
    FILE* f = fopen("archive.txt", "r");
    if (f) { fscanf(f, "%lld %lld %s %lld", rmb, bitcoin, xk, xkm); fclose(f); }
}

#endif
