# Programe

### ✅ setup()

每次上电和复位时只运行一次 初始化变量/引脚模式 引用库 

### ✅ loop()

连续循环执行 响应改变状态 和 作出改变

### ✅ 控制语句

```java
if(value>50){
  // 执行的代码
}

if(value>50) //大括号可以省略;

if(value>50){
  //执行代码
}else if(value<0){
  //执行代码;
}

for(int i=0;i<=128;i++){
  //执行代码
}

switch(val){
  case 1:
    // 代码
    break;
  case 2:
    //代码
    break;
  default:
    break;
}

while(i>10){
  i--;
}

do{
  i++
}while(i<10);

//break; 用来中止 do for while switch 语句
//continue ；继续下一次循环 do while for
//return 返回值

labelName:
//我的代码 支持跳转语句
goto labelName;
```

### ✅ 函数

```java
void myfunction(datatype arg){
//代码
}
```

### ✅ 宏定义 

```c++
#define MaxSize  1024   // 不可以添加 =  ；
#define     HIGH   0x1 //高电平
#define     LOW   0x0	//低电平
#define     INPUT   0x0	//输入
#define     OUTPUT   0x1 //输出
#define     true   0x1   //真
#define     false   0x0				 //假
#define     PI   3.14159265 	//PI.
#define     HALF_PI   1.57079 	//二分之一PI
#define     TWO_PI   6.283185 // 二倍PI
#define     DEG_TO_RAD   0.01745329 //弧度转角度
#define     RAD_TO_DEG   57.2957786 //角度转弧度
```

### ✅ 包含

```c++
#include <avr/pgmspace.h> //引用sketch中包含的库
```

### ✅ 运算

```
算数运算符 + - * / % 
布尔运算符 && || ! 
指针运算符 &引用 *间接引用
位运算 & | ^ ~ << >> 
复合运算符 ++ -- -= += *= /= &= |=
```

### ✅ 变量

```java
Boolean true false 0 1
引脚电压 HIGH LOW
引脚定义 pinMode() INPUT OUTPUT 先简单理解 一种读取电压变化 一种设置电压变化
void
char unsigned_char 'A' '1'
byte b = B10010; 0-255
int -32768~32767
unsigned_int 0-65535
word 0-65535 
long 4byte
unsigned_long 4Byte
float 4Byte
double 4Byte？？？
string  //char name[] = "arduino";??? 好像可以使用C++里面的方法
Array 
static 静态变量支持
volatile //被c遗弃的变量类型
const 常量
sizeof() 
```

### ✅ 基本函数

```c++
pinMode(引脚编号,INPUT/OUTPUT)
//设置引脚模式

digitalWrite(引脚编号,HIGH/LOW)
// 将OUTPUT模式的引脚设置高或低电平

digitalRead(引脚编号)
// 读取INPUT模式引脚的电平 返回值 HIGH/LOW  若引脚悬空 随机返回HIGH/LOW

analogReference(DEFAULT/INTERNAL/EXTERNAL)
// 配置模式引脚参考电压 搞不懂干啥用的

analogRead(引脚编号)
// 读模拟引脚 返回 0-1023 每次1微s

analogWrite(引脚编号,0-255)
// 写模拟引脚 应该是用来控制电压的 验证了 是这样的控制电压

shiftOut(dataPin,clockPin,bitOrder,value)
// 位移输出函数 自动把数据移动分配到8个并行输出端 搞不懂干啥用的	😔

pulseIn(引脚编号，脉冲状态，TimeOut)
// 读取引脚脉冲状态 发生的时间 若TimeOut时间还没有读到脉冲状态 返回超时

millis()
// 机器运行时长 毫秒 最长50天

delay(毫秒)
// 延时函数 最大值 32767 再多 60000UL 还是用循环做吧

delayMicroseconds(微秒)
// 最大 16383

max/min(val1,val2) 
// 返回最小值

abs(value)
// 绝对值

constrain(val,min,max)
// val小于min返回min val大于max返回max 中间则返回val 归一化操作

map(val,0,1023,0,256)
// 将0 1023 的等比映射到 0 256 应该是这个意思

pow(base,exponent)
sqrt(val)
sin/cos/tan(val)


randomSeed(seed)
// 设置随机种子

random(max)
// 返回 0-max-1 之间的随机数

位操作
#define  lowByte(w)   ((w) & 0xff)
  //取低字节
#define  highByte(w)   ((w) >> 8)
  //取高字节
#define  bitRead(value, bit)   (((value) >> (bit)) & 0x01)
  //读一个bit
#define  bitWrite(value, bit, bitvalue)   (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
  //写一个bit
#define  bitSet(value, bit)   ((value) |= (1UL << (bit)))
  //设置一个bit
#define  bitClear(value, bit)   ((value) &= ~(1UL << (bit)))
  //清空一个bit
#define  bit(b)   (1 << (b))
  //生成相应bit

attachInterrupt(中断类型0/1，中断函数，触发方式)
// LOW CHANGE RISING FALLING 中断函数中使用的变量要 volatile 类型 不能调用delay

detachInterrupt(interruptNum)
// 取消中断 搞不懂这是通过什么来指定中断器的

interrupts()
// 开中断

noInterrupts()
// 关中断

Serial.begin(指定波特率)
//打开串口

Serial.available()
// 是否有缓存的字节

Serial.read()
// 读取缓存的字节输入的第一个 返回int型 比如说'0'=48

flush()
// 刷新串口数据

Serial.print(数据，可选用于指定数据的格式)
// 往串口发送数据 第二个参数有点复杂 使用的时候 再查吧 
Serial.print(F("Hello World!"));
Serial.println()
// 带换行

Serial.write(val)
// 发送一个字节 或者一个字符串 buf 都可以哦

Serial.peal()
// 偷看缓冲区的数据 但不取出

Serial.serialEvent()
// 当串口有数据到达时 调用该函数 设备不一定都支持

👍 我竟然看完了 整个语法 还是因为和 java/c 太像了
```

