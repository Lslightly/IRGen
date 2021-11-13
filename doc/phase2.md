# IR实验阶段二
本实验由黄庄湫、吴毓辰助教设计

## 前言
本次实验的目的是让大家熟悉阶段三所需相关知识:   
SysY IR（由助教编写的LLVM IR的轻量级C++接口）。  

## 任务描述
[了解SysY IR](#sysy-ir---llvm-ir的c接口)  
[通过助教提供的C++例子，了解SysY IR的C++接口及实现](#例子-利用sysy-ir--cpp-生成ll)  
[根据c程序手写C++文件调用SysY IR的API生成相同功能的.ll文件](#你需要做-利用sysy-ir--c编写生成ll的程序)

## 实验内容
### SysY IR - LLVM IR的C++接口
由于LLVM IR官方的C++接口的文档同样过于冗长，助教提供了SysY IR这一C++接口库。你需要阅读[SysY IR核心类的介绍](./SysYIR.md)。  
本关会要求大家通过SysY IR根据AST构建生成LLVM IR。所以你需要仔细阅读文档了解其接口的设计。

### 例子: 利用SysY IR + C++ 生成.ll
为了让大家更直观地感受并学会LightIR接口的使用，助教提供了`SysYF_Student/SysYF_Task2/ta_demo/go_upstairs_gen.cpp`。  
该C++程序会生成与go_upstairs.c逻辑相同的LLVM IR文件。助教提供了详尽的注释，一定要好好利用！  

### 你需要做: 利用SysY IR + C++编写生成.ll的程序
你需要在`SysYF_Student/SysYF_Task2/student_cpp/`文件夹中，调用SysY IR接口，编写自己的assign_gen.cpp，func_gen.cpp，if_gen.cpp，while_gen.cpp程序，以生成与phase1的四个sy程序相同逻辑功能的`.ll`文件。

### 编译、运行和验证
在 `SysYF_Student/SysYF_Task2/build/` 下执行:
``` shell
# 如果存在 CMakeCache.txt 要先删除
# rm CMakeCache.txt
cmake ..
make
```
你可以得到对应`assign_gen.cpp`，`func_gen.cpp`，`if_gen.cpp`，`while_gen.cpp`，`go_upstairs_gen.cpp`的可执行文件`assign_generator`，`func_generator`，`if_generator`，`while_generator`，`go_upstairs_generator`  
之后直接执行可执行文件即可得到对应`.ll`文件：  
``` shell
# 在build文件夹内
./go_upstairs_generator
```
