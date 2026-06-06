#ifndef I18N_H
#define I18N_H

#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define VERSION "1.8.2"

typedef struct {
    const char* disclaimer;
    const char* loading;
    const char* ready;
    const char* saving;
    const char* menu;
    const char* menu_prompt;
    const char* draw_menu;
    const char* not_enough;
    const char* draw_got;
    const char* draw_nothing;
    const char* draw_bonus;
    const char* mail_new;
    const char* mail_claimed;
    const char* mail_none;
    const char* overdraft_free;
    const char* overdraft_over;
    const char* settings_menu;
    const char* changelog;
    const char* about;
    const char* loan_prompt;
    const char* mining_ok;
    const char* mining_fail;
    const char* round_end;
    const char* round_menu;
    const char* debt_repaid;
    const char* debt_insuf;
    const char* version_str;
} Lang;

static const Lang LANG_ZH = {
    "=免责声明=\n挖矿模拟器 " VERSION " by XINGJI Interactive Software\nhttps://www.xingjisoft.top/",
    "| 加载中... |",
    "| 加载完成! |",
    "保存中...",
    "\n* 挖矿模拟器 " VERSION " *",
    " A.开始  B.退出  C.设置  D.商店  E.邮件",
    "A.抽卡 (10000元/次)  B.返回",
    "钱不够！",
    "获得: ",
    "什么都没有，再接再厉！",
    "获得: 钱*6666 比特币*6",
    "[新邮件] 欢迎！奖励: 1,000,000元。输入A领取。",
    "领取成功！",
    "暂无新邮件。",
    "[MXUSB] 免费透支已激活（上限: -10000元）",
    "[MXUSB] 超出透支额度，将按每天1%计息。",
    "A.自动暂停  B.更新日志  C.关于  D.贷款  E.版本",
    "1.8.2 - 代码重构，跨平台，纯C\n1.8.0 - 开源\n1.7.0 - 多语言、存档",
    "挖矿模拟器 by XINGJI Interactive Software",
    "贷款金额（每天1%%利息）: ",
    " #### %d/%d/%d | 成功 | 成:%lld 败:%lld ####",
    " **** %d/%d/%d | 失败 | 成:%lld 败:%lld ****",
    "\n合计: %lld BTC = %lld 元 | 债务: %lld 元",
    " A.继续  B.菜单  C.还债",
    "还款成功。余额: %lld 元",
    "余额不足。",
    "版本: " VERSION,
};

static const Lang LANG_EN = {
    "=Disclaimer=\nMining Simulator " VERSION " by XINGJI Interactive Software\nhttps://www.xingjisoft.top/",
    "| Loading... |",
    "| Ready!     |",
    "Saving...",
    "\n* Mining Simulator " VERSION " *",
    " A.Start  B.Exit  C.Settings  D.Shop  E.Mail",
    "A.Draw (10000 RMB/time)  B.Back",
    "Not enough money!",
    "Got: ",
    "Nothing this time.",
    "Got: Money*6666 Bitcoin*6",
    "[New Mail] Welcome! Reward: 1,000,000 RMB. A to claim.",
    "Claimed!",
    "No new mail.",
    "[MXUSB] Free overdraft active (limit: -10000 RMB)",
    "[MXUSB] Overdraft exceeded. Daily interest charged.",
    "A.Auto-pause  B.Changelog  C.About  D.Loan  E.Version",
    "1.8.2 - Rewrite in C, cross-platform\n1.8.0 - Open source\n1.7.0 - Multi-language, save system",
    "Mining Simulator by XINGJI Interactive Software",
    "Loan amount (1%%/day interest): ",
    " #### %d/%d/%d | OK   | S:%lld F:%lld ####",
    " **** %d/%d/%d | FAIL | S:%lld F:%lld ****",
    "\nTotal: %lld BTC = %lld RMB | Debt: %lld RMB",
    " A.Continue  B.Menu  C.Repay debt",
    "Debt repaid. Balance: %lld RMB",
    "Insufficient balance.",
    "Version: " VERSION,
};

static const Lang* get_lang(void) {
    const char* loc = setlocale(LC_ALL, "");
    if (loc && (strstr(loc, "zh") || strstr(loc, "Chinese") || strstr(loc, "CHS") || strstr(loc, "CHT")))
        return &LANG_ZH;
    const char* env = getenv("LANG");
    if (env && strncmp(env, "zh", 2) == 0)
        return &LANG_ZH;
    return &LANG_EN;
}

#endif
