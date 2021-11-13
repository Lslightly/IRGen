[TOC]

---

### 任务描述
本关任务：熟悉LLVM IR，并根据给出的4个sy程序手写ll文件以实现相同功能。

### 相关知识
#### LLVM IR介绍
根据[维基百科](https://zh.wikipedia.org/zh-cn/LLVM)的介绍，LLVM是一个自由软件项目，它是一种编译器基础设施，以C++写成，包含一系列模块化的编译器组件和工具链，用来开发编译器前端和后端。IR的全称是Intermediate Representation，即中间表示。LLVM IR是一种类似于汇编的底层语言。  
LLVM IR的具体指令可以参考[Reference Manual](http://llvm.org/docs/LangRef.html)。但是你会发现其内容庞杂。虽然助教认为，高效地查阅官方文档及手册是非常必要的一项技能，但是由于其手册过于复杂，因此助教筛选了后续实验中将要用到的子集，总结为了**精简的IR Reference手册**`doc/SysYFIR.md`。  
作为一开始的参考，你可以先阅读其中`IR Features`和`IR Format`两节，后续有需要再反复参考。  

#### 样例学习
<details>
  <summary> go_upstairs.c（点击展开） </summary>

```c
int num[2] = {4, 8};
int x[1];
int n;
int tmp = 1;

int climbStairs(int n) {
    if(n < 4)
        return n;
    int dp[10];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int i;
    i = 3;
    while(i<n+1){
        dp[i] = dp[i-1] + dp[i-2];
        i = i + 1;
    }
    return dp[n];
}

int main(){
    int res;
    n=num[0];
    x[0] = num[tmp];
    res = climbStairs(n + tmp);
    return res - x[0];
}
```
</details>

阅读`SysYF_Student/SysYF_Task1/ta_demo/go_upstairs.c`。  
在`SysYF_Student/SysYF_Task1/ta_demo`文件夹内输入`clang -S -emit-llvm go_upstairs.c`指令，你可以得到对应的`go_upstairs.ll`。  
你需要结合`go_upstairs.c`阅读`go_upstairs.ll`，理解其中每条LLVM IR指令与C代码的对应情况。  
通过`lli go_upstairs.ll; echo $?`指令，你可以测试`go_upstairs.ll`执行结果的正确性。  

### 本关具体任务
1. 助教在`SysYF_Student/SysYF_Task1/student_sy/`内提供了四个简单的sy程序：`assign_test.sy`，`func_test.sy`，`if_test.sy`，`while_test.sy`。  
你需要在`SysYF_Student/SysYF_Task1/student_ll/`内手工完成自己的`assign_test.ll`，`func_test.ll`，`if_test.ll`，`while_test.ll`文件，以实现与上述C程序相同的逻辑功能。  
你需要在`ll`文件内添加必要的注释，`ll`文件的注释是以`;`开头的。  
必要的情况下，你可以参考`clang -S -emit-llvm`的输出，但是你提交的结果必须避免同此输出一字不差。  
2. 在`report.md`内回答[思考题](#思考题)

### 运行说明
- `lli`会运行`*.ll`文件
- `$?`的内容是上一条命令所返回的结果，而`echo $?`可以将其输出到终端中
- 使用`clang`时，注意`sy`文件是我们定义的语言文件，`clang`是无法直接识别的  

### 思考题
请在`report/report.md`中详细回答下述思考题。  