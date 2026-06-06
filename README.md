# 挖矿模拟器 (Bitcoin Mining Simulator)

一款 Windows 平台的比特币挖矿模拟游戏，体验虚拟矿场的经营与升级。

## 游戏特性

- 虚拟货币系统（人民币 & 比特币）
- GPU 设备选购与升级（GTX1060 等）
- 商店系统
- 邮件通知
- 存档 / 读档
- 中英文界面

## 运行方式

编译并运行 `launch.cpp`，或直接执行 `bcms_files/bcms.exe`。

```bash
g++ launch.cpp -o launch.exe
./launch.exe
```

## 项目结构

```
BitCoinMiningSimulator/
├── launch.cpp              # 启动入口（免责声明 + 启动主程序）
├── archive.txt             # 存档文件
└── bcms_files/
    ├── bcms.cpp            # 主游戏逻辑
    ├── save.h              # 存档系统
    └── versions/1.7.0/     # 版本模块
```

## 版本

v1.8.0

## 免责声明

本项目为纯模拟游戏，不涉及真实货币交易或真实挖矿行为。
