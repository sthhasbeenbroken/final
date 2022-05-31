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

##### 成员代码提交日志：![img](image/final/1653975809312.png)![img](image/final/1653975857471.png)

##### 项目自评等级:(1-5)

| 解释器   | 完善程度 | 难度 | 备注                                       |
| -------- | -------- | ---- | ------------------------------------------ |
| array    | 5        | 1    |                                            |
| bool     | 5        | 2    |                                            |
| break    | 5        | 1    | 通过failwith直接跳出                       |
| continue | 3        | 1    | 通过failwith直接跳出存在错误               |
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

##### 项目说明

* 整体文件架构

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

##### 解释器、优化编译器、虚拟机

###### 解释器interpreter

```
//编译解释器 interpc.exe 命令行程序 
dotnet restore  interpc.fsproj  //可选
dotnet clean  interpc.fsproj    //可选
dotnet build -v n interpc.fsproj //构建，-v n查看详细生成过程

//执行解释器
./bin/Debug/net5.0/interpc.exe example/int.c
dotnet run -p interpc.fsproj example/int.c
dotnet run -p interpc.fsproj -g example/int.c  //显示token AST 等调试信息
```

###### 优化编译器complier

```
dotnet restore  microcc.fsproj
dotnet clean  microcc.fsproj
dotnet build  microcc.fsproj  //构建编译器

dotnet run -p microcc.fsproj example/int.c//执行编译器
./bin/Debug/net5.0/microcc.exe example/int.c  //直接执行

```

###### 虚拟机JAVA

```
javac Machine.java
java Machine ex9.out 3

javac Machinetrace.java
java Machinetrace ../example/int.out
java Machinetrace ../example/int.out
```

##### 项目说明

1.项目说明

###### 解释器部分是基于现有代码 MICROC 的改进主要添加了上述表格中的功能。以下是具体的内容：

1. int类型：
   定义了HEX可以进行16进制的转化，输出函数为print 16 i，具体可见hex.c

   ![img](image/final/1653979858209.png)
2. bool类型：（bool类型是我第一个做的类型，万事开头难，在byte转化的时候各种报错，查遍了.NET类型转化的文档尝试了各种方法还是报错，最后发现它true，false本身就可以是一个int类型）

   ![img](image/final/1653980653095.png)![img](image/final/1653980747559.png)
3. float类型：float的关键在于对原本的整形进行浮点数的转化，当初怎么样都输出不了浮点数，输出的是一长串的整形，最后经过转化得到成功。解释器中关键的代码![img](image/final/1653982225070.png)先转化为整形存入store![img](image/final/1653982190889.png)再读取整形转化为浮点数

   ![img](image/final/1653982385886.png)
4. string类型：（不完整，只可以输出数字字符串）![img](https://file+.vscode-resource.vscode-cdn.net/d%3A/homework/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86/final/image/final/1653983532866.png)
5. char类型:一开始也是因为转换问题无法输出字符，char类型只占16个字节，最后转换后得到解决

   ![img](image/final/1653983748796.png)
6. array数组

   ![img](image/final/1653983899262.png)
7. 自增，自减（前置后置都支持）i++先运算再加，++i先加再运算，--同理

   ```c
   int main(){
       int b; 
       b=0;
      print "%d" b++;
      print "%d" ++b;

   }//自增
   ```

   ![img](image/final/1653984404531.png)

   ```c
   int main(){
       int b;
       b=2;
       print "%d" b--;
       print "%d" --b;

   }//自减
   ```

   ![img](image/final/1653984431337.png)
8. for循环(循环体内可以使用自增，自减)

```c
int main(){
    int i;
    for (i = 0; i < 2; i++)//(在编译器中i++报错。进入无限循环。)
    {
        print "%d" i;
    }
}
```

![](image/final/1653984846459.png)

   9.dowhile循环(可用自增自减)

```c
int main() {
    int i;
    i=0;
   do {
        print "%d" i;
        //i++;//编译时栈溢出
        i=i+1;
   }  
   while(i<4);

}
```

![](image/final/1653985045988.png)

  10.dountil循环(自增自减支持)

```c
int main() {
    int i;
    i=0;
   do{
        print "%d" i ;
        i = i+1;//i++
   }  
   until(i>4);

}
```

![](image/final/1653985165277.png)

  11.break（break我是直接通过failwith直接跳出，可能不是很体面）

```c
int main(){
    int i;
    i=0;
   for( i = 0 ; i < 4;  i++){
        print "%d" i;
        if(i==2)
        break;
    }
}
```

![](image/final/1653985643364.png)

12.forin循环(自增自减支持)

```c
int main() {
  
    int i;
    for i in (3,7)
    {
        print "%d" i;
    }

}
```

![](image/final/1653985905161.png)

13.hex 16进制输出(不支持'a'-'f','A'-'F'含字符的16进制转换，只支持数字)

```c
int main() {
    int a;
    a = hex("121",16);
    print 16 a;
    print "%d" a;
}
```

![](image/final/1653986066974.png)

14.prim3三目运算符(如红圈，别忘传入n)

```c
int main(int n) {
    int i;
    i =  n>2?12:21;
    print "%d" i ;
  
}
```

![](image/final/1653986236012.png)

15. print，改进了它原来的print，使得其能输出浮点数、字符、整形、布尔、字符串（只有数字字符串），一开始因为字符转化之类的一直报错，后面看了.NETBitConverter的文档，发现string的转化不能通过读取byte，就直接进行了强制的转化。可能也是因为我string强制转化导致只能输出数字字符串。

    ![img](image/final/1653990700517.png)
    (其中还增加了printhex输出16进制数 格式为print 16 i)

    ```c
    int main() {
               int a ;
               a=1;
               char b ;
               b='c';
               float f ;
               f=1.1;
               bool c ;
               c= false;
               print "%d" a ;
               print "%d" c ;
               print "%c" b ;
               print "%f" f;
               print "%f" a;
    }
    ```

    16.switch

    ```c
    int main(int n) {
        switch( n ){
            case 1 :  print "%d" n;
            case 2 :  print "%d" n+1;
            default : print "%d" 2;
        }
        print "%d" n;

    }
    ```

    ###### 编译器在MICORC的源代码的基础上进行改进

    编译器在原有的MICORC的源代码的基础上进行了更改，增添了float，char，bool，string（只有整数型）的类型，其中编译器的自增自减存在越栈的错误。所以在for、while、dowhile等循环中不使用自增或自减，而是i=i+1.使用了CUBY的java虚拟机。

    1.bool类型:

![](image/final/1654004238117.png)

2.char类型：

![](image/final/1654004264141.png)

3.array:

![img](image/final/1654004377776.png)

4.dountil:(太长了一张图截不下)

```
D:\homework\编译原理\final\src>java Machinetrace ../example/dountil.out
[ ]{0: LDARGS}
[ ]{1: CALL 0 5}
[ 4 -999 ]{5: INCSP 1}
[ 4 -999 null ]{7: GETBP}
[ 4 -999 null 2 ]{8: CSTI 0}
[ 4 -999 null 2 0 ]{10: STI}
[ 4 -999 0 0 ]{11: INCSP -1}
[ 4 -999 0 ]{13: GETBP}
[ 4 -999 0 2 ]{14: LDI}
[ 4 -999 0 0 ]{15: PRINTI}
0 [ 4 -999 0 0 ]{16: INCSP -1}
[ 4 -999 0 ]{18: GETBP}
[ 4 -999 0 2 ]{19: GETBP}
[ 4 -999 0 2 2 ]{20: LDI}
[ 4 -999 0 2 0 ]{21: CSTI 1}
[ 4 -999 0 2 0 1 ]{23: ADD}
[ 4 -999 0 2 1 ]{24: STI}
[ 4 -999 1 1 ]{25: INCSP -1}
[ 4 -999 1 ]{27: GETBP}
[ 4 -999 1 2 ]{28: LDI}
[ 4 -999 1 1 ]{29: CSTI 4}
[ 4 -999 1 1 4 ]{31: SWAP}
[ 4 -999 1 4 1 ]{32: LT}
[ 4 -999 1 0 ]{33: IFZERO 13}
[ 4 -999 1 ]{13: GETBP}
[ 4 -999 1 2 ]{14: LDI}
[ 4 -999 1 1 ]{15: PRINTI}
1 [ 4 -999 1 1 ]{16: INCSP -1}
[ 4 -999 1 ]{18: GETBP}
[ 4 -999 1 2 ]{19: GETBP}
[ 4 -999 1 2 2 ]{20: LDI}
[ 4 -999 1 2 1 ]{21: CSTI 1}
[ 4 -999 1 2 1 1 ]{23: ADD}
[ 4 -999 1 2 2 ]{24: STI}
[ 4 -999 2 2 ]{25: INCSP -1}
[ 4 -999 2 ]{27: GETBP}
[ 4 -999 2 2 ]{28: LDI}
[ 4 -999 2 2 ]{29: CSTI 4}
[ 4 -999 2 2 4 ]{31: SWAP}
[ 4 -999 2 4 2 ]{32: LT}
[ 4 -999 2 0 ]{33: IFZERO 13}
[ 4 -999 2 ]{13: GETBP}
[ 4 -999 2 2 ]{14: LDI}
[ 4 -999 2 2 ]{15: PRINTI}
2 [ 4 -999 2 2 ]{16: INCSP -1}
[ 4 -999 2 ]{18: GETBP}
[ 4 -999 2 2 ]{19: GETBP}
[ 4 -999 2 2 2 ]{20: LDI}
[ 4 -999 2 2 2 ]{21: CSTI 1}
[ 4 -999 2 2 2 1 ]{23: ADD}
[ 4 -999 2 2 3 ]{24: STI}
[ 4 -999 3 3 ]{25: INCSP -1}
[ 4 -999 3 ]{27: GETBP}
[ 4 -999 3 2 ]{28: LDI}
[ 4 -999 3 3 ]{29: CSTI 4}
[ 4 -999 3 3 4 ]{31: SWAP}
[ 4 -999 3 4 3 ]{32: LT}
[ 4 -999 3 0 ]{33: IFZERO 13}
[ 4 -999 3 ]{13: GETBP}
[ 4 -999 4 2 ]{19: GETBP}
[ 4 -999 4 2 2 ]{20: LDI}
[ 4 -999 4 2 4 ]{21: CSTI 1}
[ 4 -999 4 2 4 1 ]{23: ADD}
[ 4 -999 4 2 5 ]{24: STI}
[ 4 -999 5 5 ]{25: INCSP -1}
[ 4 -999 5 ]{27: GETBP}
[ 4 -999 5 2 ]{28: LDI}
[ 4 -999 5 5 ]{29: CSTI 4}
[ 4 -999 5 5 4 ]{31: SWAP}
[ 4 -999 5 4 5 ]{32: LT}
[ 4 -999 5 1 ]{33: IFZERO 13}
[ 4 -999 5 ]{35: RET 0}
[ 5 ]{4: STOP}

Ran 0.047 seconds
```

5.float ,float输出的时候一开始我一直都在报错说我越栈，最后发现

![img](image/final/1654004490603.png)PRINTI写成了PRINTF，然而虚拟机中根本没有定义PRINTF。

![](image/final/1654004543602.png)

6.dowhile:

```
D:\homework\编译原理\final\src>java Machinetrace ../example/dowhile.out
[ ]{0: LDARGS}
[ ]{1: CALL 0 5}
[ 4 -999 ]{5: INCSP 1}
[ 4 -999 null ]{7: GETBP}
[ 4 -999 null 2 ]{8: CSTI 0}
[ 4 -999 null 2 0 ]{10: STI}
[ 4 -999 0 0 ]{11: INCSP -1}
[ 4 -999 0 ]{13: GETBP}
[ 4 -999 0 2 ]{14: LDI}
[ 4 -999 0 0 ]{15: PRINTI}
0 [ 4 -999 0 0 ]{16: INCSP -1}
[ 4 -999 0 ]{18: GETBP}
[ 4 -999 0 2 ]{19: GETBP}
[ 4 -999 0 2 2 ]{20: LDI}
[ 4 -999 0 2 0 ]{21: CSTI 1}
[ 4 -999 0 2 0 1 ]{23: ADD}
[ 4 -999 0 2 1 ]{24: STI}
[ 4 -999 1 1 ]{25: INCSP -1}
[ 4 -999 1 ]{27: GETBP}
[ 4 -999 1 2 ]{28: LDI}
[ 4 -999 1 1 ]{29: CSTI 4}
[ 4 -999 1 1 4 ]{31: LT}
[ 4 -999 1 1 ]{32: IFNZRO 13}
[ 4 -999 1 ]{13: GETBP}
[ 4 -999 1 2 ]{14: LDI}
[ 4 -999 1 1 ]{15: PRINTI}
1 [ 4 -999 1 1 ]{16: INCSP -1}
[ 4 -999 1 ]{18: GETBP}
[ 4 -999 1 2 ]{19: GETBP}
[ 4 -999 1 2 2 ]{20: LDI}
[ 4 -999 1 2 1 ]{21: CSTI 1}
[ 4 -999 1 2 1 1 ]{23: ADD}
[ 4 -999 1 2 2 ]{24: STI}
[ 4 -999 2 2 ]{25: INCSP -1}
[ 4 -999 2 ]{27: GETBP}
[ 4 -999 2 2 ]{28: LDI}
[ 4 -999 2 2 ]{29: CSTI 4}
[ 4 -999 2 2 4 ]{31: LT}
[ 4 -999 2 1 ]{32: IFNZRO 13}
[ 4 -999 2 ]{13: GETBP}
[ 4 -999 2 2 ]{14: LDI}
[ 4 -999 2 2 ]{15: PRINTI}
2 [ 4 -999 2 2 ]{16: INCSP -1}
[ 4 -999 2 ]{18: GETBP}
[ 4 -999 2 2 ]{19: GETBP}
[ 4 -999 2 2 2 ]{20: LDI}
[ 4 -999 2 2 2 ]{21: CSTI 1}
[ 4 -999 2 2 2 1 ]{23: ADD}
[ 4 -999 2 2 3 ]{24: STI}
[ 4 -999 3 3 ]{25: INCSP -1}
[ 4 -999 3 ]{27: GETBP}
[ 4 -999 3 2 ]{28: LDI}
[ 4 -999 3 3 ]{29: CSTI 4}
[ 4 -999 3 3 4 ]{31: LT}
[ 4 -999 3 1 ]{32: IFNZRO 13}
[ 4 -999 3 ]{13: GETBP}
[ 4 -999 3 2 ]{14: LDI}
[ 4 -999 3 3 ]{15: PRINTI}
3 [ 4 -999 3 3 ]{16: INCSP -1}
[ 4 -999 3 ]{18: GETBP}
[ 4 -999 3 2 ]{19: GETBP}
[ 4 -999 3 2 2 ]{20: LDI}
[ 4 -999 3 2 3 ]{21: CSTI 1}
[ 4 -999 3 2 3 1 ]{23: ADD}
[ 4 -999 3 2 4 ]{24: STI}
[ 4 -999 4 4 ]{25: INCSP -1}
[ 4 -999 4 ]{27: GETBP}
[ 4 -999 4 2 ]{28: LDI}
[ 4 -999 4 4 ]{29: CSTI 4}
[ 4 -999 4 4 4 ]{31: LT}
[ 4 -999 4 0 ]{32: IFNZRO 13}
[ 4 -999 4 ]{34: RET 0}
[ 4 ]{4: STOP}

Ran 0.041 seconds
```

7.for(因为我自增自减在编译器中报错，以至于一开始的时候在循环中写着i++以至于报错后面改成了i=i+1成功运行)

```
D:\homework\编译原理\final\src>java Machinetrace ../example/for.out  
[ ]{0: LDARGS}
[ ]{1: CALL 0 5}
[ 4 -999 ]{5: INCSP 1}
[ 4 -999 null ]{7: GETBP}
[ 4 -999 null 2 ]{8: CSTI 0}
[ 4 -999 null 2 0 ]{10: STI}
[ 4 -999 0 0 ]{11: INCSP -1}
[ 4 -999 0 ]{13: GOTO 29}
[ 4 -999 0 ]{29: GETBP}
[ 4 -999 0 2 ]{30: LDI}
[ 4 -999 0 0 ]{31: CSTI 2}
[ 4 -999 0 0 2 ]{33: LT}
[ 4 -999 0 1 ]{34: IFNZRO 15}
[ 4 -999 0 ]{15: GETBP}
[ 4 -999 0 2 ]{16: LDI}
[ 4 -999 0 0 ]{17: PRINTI}
0 [ 4 -999 0 0 ]{18: INCSP -1}
[ 4 -999 0 ]{20: GETBP}
[ 4 -999 0 2 ]{21: GETBP}
[ 4 -999 0 2 2 ]{22: LDI}
[ 4 -999 0 2 0 ]{23: CSTI 1}
[ 4 -999 0 2 0 1 ]{25: ADD}
[ 4 -999 0 2 1 ]{26: STI}
[ 4 -999 1 1 ]{27: INCSP -1}
[ 4 -999 1 ]{29: GETBP}
[ 4 -999 1 2 ]{30: LDI}
[ 4 -999 1 1 ]{31: CSTI 2}
[ 4 -999 1 1 2 ]{33: LT}
[ 4 -999 1 1 ]{34: IFNZRO 15}
[ 4 -999 1 ]{15: GETBP}
[ 4 -999 1 2 ]{16: LDI}
[ 4 -999 1 1 ]{17: PRINTI}
1 [ 4 -999 1 1 ]{18: INCSP -1}
[ 4 -999 1 ]{20: GETBP}
[ 4 -999 1 2 ]{21: GETBP}
[ 4 -999 1 2 2 ]{22: LDI}
[ 4 -999 1 2 1 ]{23: CSTI 1}
[ 4 -999 1 2 1 1 ]{25: ADD}
[ 4 -999 1 2 2 ]{26: STI}
[ 4 -999 2 2 ]{27: INCSP -1}
[ 4 -999 2 ]{29: GETBP}
[ 4 -999 2 2 ]{30: LDI}
[ 4 -999 2 2 ]{31: CSTI 2}
[ 4 -999 2 2 2 ]{33: LT}
[ 4 -999 2 0 ]{34: IFNZRO 15}
[ 4 -999 2 ]{36: RET 0}
[ 2 ]{4: STOP}

Ran 0.023 seconds
```
