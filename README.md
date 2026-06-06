# 挖矿模拟器 (Bitcoin Mining Simulator)

一款跨平台的比特币挖矿模拟游戏，支持 Windows / Linux / macOS。

## 游戏特性

- 虚拟货币系统（人民币 & 比特币）
- GPU 抽卡系统（GTX1060 ~ H100）
- 贷款 / 还债
- 邮件通知
- 存档 / 读档
- 自动检测系统语言（中文 / English）

## 下载

前往 [Releases](https://github.com/hekuo5310/BitCoinMiningSimulator/releases) 页面下载对应平台的可执行文件，无需安装，直接运行。

## 从源码编译

需要 GCC（C11）。

```bash
gcc -std=c11 main.c -o mining-simulator
./mining-simulator
```

## 项目结构

```
BitCoinMiningSimulator/
├── main.c      # 主游戏逻辑
├── save.h      # 存档系统
├── i18n.h      # 国际化（中/英）
└── .github/
    └── workflows/
        └── release.yml   # 自动构建发布
```

## 版本

v1.8.3

## 免责声明

本项目为纯模拟游戏，不涉及真实货币交易或真实挖矿行为。
