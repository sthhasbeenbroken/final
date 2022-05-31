# [2020-2021学年第2学期](https://plc-sigcc.vercel.app/#/lab/proj.final?id=_2020-2021%e5%ad%a6%e5%b9%b4%e7%ac%ac2%e5%ad%a6%e6%9c%9f)

# [**实 验 报 告**](https://plc-sigcc.vercel.app/#/lab/proj.final?id=%e5%ae%9e-%e9%aa%8c-%e6%8a%a5-%e5%91%8a)

![zucc](https://plc-sigcc.vercel.app/lab/zucc.png "ZUCC")

* 课程名称:编程语言原理与编译
* 实验项目:期末大作业
* 专业班级__计算1903_
* 学生学号__31901072_
* 学生姓名__高扬_
* 实验指导教师:张芸

| 姓名 | 学号     | 班级     | 任务 | 权重 |
| ---- | -------- | -------- | ---- | ---- |
| 高扬 | 31901072 | 计算1903 | 全部 | 1.0  |

###### 成员代码提交日志：![img](image/final/1653975809312.png)![img](image/final/1653975857471.png)

###### 项目自评等级:(1-5)

| 解释器   | 完善程度 | 难度 | 备注                                       |
| -------- | -------- | ---- | ------------------------------------------ |
| array    | 5        | 1    |                                            |
| bool     | 5        | 2    |                                            |
| break    | 5        | 1    |                                            |
| char     | 5        | 1    |                                            |
| dountil  | 5        | 1    |                                            |
| dowhile  | 5        | 1    |                                            |
| float    | 5        | 3    |                                            |
| for      | 5        | 1    |                                            |
| forin    | 5        | 2    |                                            |
| hex      | 3        | 3    | 存在读入['a'-'f']['A'-'F']字符报错         |
| if       | 5        | 1    |                                            |
| int      | 5        | 1    |                                            |
| 三元运算 | 5        | 2    |                                            |
| print    | 5        | 1    |                                            |
| 自增     | 5        | 1    | 解释器中的自增在.c文件可写入循环等多种语境 |
| 自减     | 5        | 1    | 解释器中的自减在.c文件可写入循环等多种语境 |
| string   | 3        | 3    | 无法识别非['0'-'9']的字符串                |
| switch   | 5        | 1    |                                            |


| 编译器   | 完善程度 | 难度 | 备注                                               |
| -------- | -------- | ---- | -------------------------------------------------- |
| array    | 5        | 1    |                                                    |
| bool     | 5        | 2    |                                                    |
| break    | 5        | 1    |                                                    |
| char     | 5        | 1    |                                                    |
| dountil  | 5        | 1    |                                                    |
| dowhile  | 5        | 1    |                                                    |
| float    | 5        | 3    |                                                    |
| for      | 5        | 1    |                                                    |
| forin    | 5        | 2    |                                                    |
| hex      | 3        | 3    | 存在读入['a'-'f']['A'-'F']字符报错                 |
| if       | 5        | 1    |                                                    |
| int      | 5        | 1    |                                                    |
| 三元运算 | 5        | 2    |                                                    |
| print    | 4        | 1    | 打印16进制数时不会输出16进制数而是输出10进制的结果 |
| 自增     | 2        | 1    | 存在错误，在栈中无限+1造成栈溢出                   |
| 自减     | 2        | 1    | 存在错误，在栈中无限-1造成栈溢出                   |
| string   | 3        | 3    | 无法识别非['0'-'9']的字符串                        |
| switch   | 5        | 1    |                                                    |


###### 项目说明

- 整体文件架构

  src文件夹               Java虚拟机

  exampleinterp文件夹  解释器测试集

  example文件夹   编译器测试集

  Absyn.fs                 抽象语法

  CLex.fsl          		fslex词法定义

  CPar.fsy             	fsyacc语法定义

  Parse.fs                 语法解析器

  Interp.fs                 解释器

  interpc.fsproj        项目文件

  Contcomp.fs         编译器

  StackMachine.fs            指令定义

  microcc.fsproj      编译器项目文件
- ###### 解释器、优化编译器、虚拟机

  ###### 解释器interpreter


  ```
  //编译解释器 interpc.exe 命令行程序 
  dotnet restore  interpc.fsproj  //可选
  dotnet clean  interpc.fsproj    //可选
  dotnet build -v n interpc.fsproj //构建，-v n查看详细生成过程

  //执行解释器
  ./bin/Debug/net5.0/interpc.exe ex1.c 8
  dotnet run -p interpc.fsproj ex1.c 8
  dotnet run -p interpc.fsproj -g ex1.c 8  //显示token AST 等调试信息
  ```
  ###### 优化编译器complier
