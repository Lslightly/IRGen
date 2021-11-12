# PW6 实验文档
本实验由黄庄湫、吴毓辰助教设计
- [PW6 实验文档](#pw6-实验文档)
  - [0. 前言](#0-前言)
    - [主要工作](#主要工作)
  - [1. 实验要求](#1-实验要求)
    - [1.1 目录结构](#11-目录结构)
    - [1.2 提交要求和评分标准](#12-提交要求和评分标准)
## 0. 前言

本次实验分为3关，前2关是个人实验，第3关为组队实验。**本次实验请务必使用git提交**。    
本次实验的目的是让大家熟悉生成中间代码所需要的相关知识: LLVM IR、 SysY IR（LLVM IR的轻量级C++接口），并实际实现一个IR Builder。
在开始实验之前，请确保LLVM的版本不低于10.0.1，且PATH环境变量配置正确。可以通过`lli --version`命令是否可以输出10.0.1的版本信息来验证。

### 主要工作

1. 第一部分: 了解LLVM IR。通过clang生成的.ll，了解LLVM IR与c代码的对应关系。相应文档见[phase1.md](./doc/phase1.md)
2. 第二部分: 了解SysY IR。通过助教提供的c++例子，了解SysY IR的c++接口及实现。相应文档见[phase2.md](./doc/phase2.md)
3. 第三部分: 使用SysY IR，实现一个IR Builder，使其可以通过抽象语法树生成LLVM兼容的IR代码。相应文档见[phase3.md](./doc/phase3.md)
4. 实验报告：在[report.md](./report.md)中撰写报告。

## 1. 实验要求

### 1.1 目录结构
除了下面指明你所要修改或提交的文件，其他文件请勿修改。
``` log
.
├── CMakeLists.txt
├── README.md                           <- PW6实验文档说明（你在这里）
├── contribution.md                     <- PW6所需提交的组员贡献（队长提交即可）
├── report.md                           <- PW6所需提交的实验报告
├── doc
│   ├── AST.md
│   ├── phase1.md
│   ├── phase2.md
│   ├── phase3.md
|   └── SysYIR.md                       <- SysY IR 相关文档
├── include                             <- 实验所需的头文件
│   ├── ...
│   └── SysYIR
├── src
│   ├── ...
│   ├── SysYIR
│   └── SysYBuilder
|       ├── CMakeLists.txt
|       └── SysYBuilder.cpp             <- 第三部分你需要修改的文件
└── SysYF_Student
    ├── CMakeLists.txt
    ├── SysYF_Task1
    |   ├── student_ll                  <- PW6所需提交的.ll目录（第一部分）
    |   |   ├── assign_hand.ll
    |   │   ├── fun_hand.ll
    |   │   ├── if_hand.ll
    |   │   └── while_hand.ll
    |   ├── student_sy
    |   |   ├── assign.sy
    |   │   ├── fun.sy
    |   │   ├── if.sy
    |   │   └── while.sy
    |   └── ta_demo
    |       └── go_upstairs.c
    ├── SysYF_Task2
    |   ├── student_cpp                 <- PW6所需提交的.cpp目录（第二部分）
    |   |   ├── CMakeLists.txt
    |   |   ├── assign_gen.cpp
    |   │   ├── fun_gen.cpp
    |   │   ├── if_gen.cpp
    |   │   └── while_gen.cpp
    |   ├── student_sy
    |   |   ├── assign.sy
    |   │   ├── fun.sy
    |   │   ├── if.sy
    |   │   └── while.sy
    |   └── ta_demo
    |       |── CMakeLists.txt
    |       |── go_upstairs.sy
    |       └── go_upstairs_gen.cpp     <- 助教提供的打印go_upstairs.ll的cpp
    └── SysYF_Task3
        └── Test_H
            ├── test_H.py               <- PW6第三部分评测脚本
            └── Easy_H                  <- 测试样例文件夹
```

### 1.2 提交要求和评分标准
* 提交要求  
  本实验的提交要求分为两部分: 实验部分的文件和报告。
  * 实验部分:
    * 需要完成 `./SysYF_Student/SysYF_Task1/student_ll`目录下的4个文件
    * 需要完成 `./SysYF_Student/SysYF_Task2/student_cpp`目录下的4个文件
    * 需要完成 `./src/SysYBuilder/SysYBuilder.cpp`
    * 需要在 `./report.md` 中撰写实验报告
      * 实验报告内容包括:
        * 实验要求、问题回答、实验设计、实验难点及解决方案、实验总结、实验反馈、组间交流(具体参考[report.md](./report.md))
        * 本次实验报告**参与**评分标准.
  * 提交规范: 
    * 不破坏目录结构(`report.md`如果需要放图片，请放在`./report_figs/`下)
    * 不上传临时文件(凡是自动生成的文件和临时文件请不要上传)
* **组队实验要求**
  * 由队长在 `contribution.md` 中解释每位队员的贡献，并说明贡献比例
  * 组队实验意味着合作，但是小组间的交流是受限的，且**严格禁止**代码的共享。除此之外，如果小组和其它组进行了交流，必须在 `report.md` 中记录交流的小组和你们之间交流内容
* 评分标准: 本次实验分为3部分, 请注意前两部分为个人实验, 第三部分为组队实验, 个人实验需要各自完成, 组队实验的代码和报告我们只检查组长的仓库
  * **禁止执行恶意代码，违者本次实验0分处理**
  * 第一部分10分: `.ll`运行结果正确(1个2分, 注释共2分)
  * 第二部分20分: `.cpp`运行结果正确(1个5分)
  * 第三部分70分: 该部分成绩由5部分组成(团队代码得分, 实验报告得分, 迟交天数, 组员贡献比, 组长奖励加分)
* 实验检查
  * 线上: 助教会在educoder上检查前两部分, 该部分是每个人需要独自完成的
  * 线下: 线下检查只检查第三部分, 组长带组员到负责组长的助教处检查
* 迟交规定
  * 迟交需要邮件通知助教: 
    * 邮箱: huangzq@mail.ustc.edu.cn
    * 邮件主题: PW6迟交-学号
    * 内容: 包括迟交原因、最后版本commitID、迟交时间等
* 关于抄袭和雷同
  经过助教和老师判定属于作业抄袭或雷同情况，所有参与方一律零分，不接受任何解释和反驳。
如有任何问题，欢迎提issue进行批判指正。
