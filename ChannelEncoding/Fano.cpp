#include<stdio.h>                                             //头文件 
#include<math.h> 
#include<string.h> 
#define Bmax 10                                               //最长码长度 
#define Smax 20                                               //数组最大长度 
 
/************定义"位"的结构**********/ 
struct Bit 
{ 
 char b[Bmax];                    //定义码长度数组的数据类型 字符型   组成成员 
 int last; 
}; 
/***********定义符号的结构**********/ 
typedef struct symbol                                         //共用体结构 
{ 
 char c;                                               //定义信源符号c为字符型 
 float probability;                                //定义符号概率probality为浮点型 
 struct Bit bit;                                           //嵌套的结构体 
}sbl; 
sbl s[Smax];                                                  //S数组最大容量符号 
/********输入符号的符号概率********/ 
void input(int n) 
{ 
 int i;                                                    //定义变量i类型 整型 
 int c;                           //定义变量c类型 还是整型的好字符型的也可以 
 printf("请输入符号及符号概率\n");          //打印出提示语"请输入符号及符号概率" 
    c=getchar(); 
 for(i=0;i<n;i++)                                //用for循环为符号及符号概率赋值 
 { 
  scanf("%c",&s[i].c);                               //用scanf函数输入符号 
  scanf("%f",&s[i].probability);                      //用scanf函数输入符号概率 
  c=getchar(); 
 } 
} 
/***********用冒泡法排序**********/ 
void sort(int n) 
{ 
 float t;                                                   //定义变量t为浮点型 
 char a;                                                   //定义变量a为字符型 
 int i,j;                                                 //定义循环变量i,j为整型 
 for(i=1;i<n;i++)                          //嵌套for循环 i从1到n-1 大循环n-1次 
  for(j=0;j<n-i;j++)                                      //从下标为0的第一个符号概率开始与其之后的概率依次比较 
   if(s[j].probability<s[j+1].probability)             //如果后者大于前者则通过www.docin.com 
 //引进的变量a和t分别交换其符号和概率 
   {t=s[j].probability; 
   a=s[j].c; 
   s[j].probability=s[j+1].probability; 
   s[j].c=s[j+1].c; 
   s[j+1].probability=t; 
            s[j+1].c=a; 
   }                       //因此此函数实现了各符号和其所对应的概率按照概率的大小从大到小排序 
} 
/************分组函数************/ 
void group(int n)                                         //定义函数无返回值 
{ 
void group1(int low,int mid,int high);
 int i,pmid,plow,phigh;                                       //定义变量为整型 
 pmid=phigh=n;                                            //给两个变量赋值为n 
 plow=0;                                                      //给变量赋值为0 
 for(i=0;i<n;i++)                                             //for循环n次 
  s[i].bit.last=0;                                         //给符号的位赋值为0 
    group1(plow,pmid,phigh);                                    //调用依次分组函数 
} 
/**依次将按排好序的符号概率进行近似1:1分成两大组**/ 
void group1(int low,int mid,int high)                    //定义函数低位中位高位 
{ 
 float d,dmin;                                         //定义变量d,dmin为浮点数 
 d=0;                                                         //给d赋初值为0 
 int i;                                                 //定义循环变量i为整型 
 if(high==low+1)                                   //如果低位和高位只相差1也就是它们两相邻 
  return;                                                  //则返回 
 for(i=low;i<mid;i++)                     //否则就进入循环i=低位开始到<中间数位 
  d+=s[i].probability;                                     //每次循环d的概率就是前几个符号概率的累加和 
        dmin=d-2*s[low].probability;                             //dmin= 
 for(i=low+1;i<high;i++)                   //进入后半循环i从低位加一开始到<高位 
 { 
  d=fabs(dmin-2*s[i].probability);                         //给d赋值绝对值 
  if(d<dmin)                            //如果d<dmin,则把d的值赋值给dmin 
   dmin=d; 
  else                                                     //如果d>=dmin,则跳出整个for循环要尽量使两组的差为0才最接近1:1 
   break; 
 } 
 mid=i; 
 void code(int low,int mid,int high);                                                    //给中间数位赋值i 
    code(low,mid,high);
  group1(low,mid,mid);                         //将一组分为了两组中间为零界mid 
    group1(mid,high,high); 
} 
 
/****对各组赋予一个二进制码元“0”和“1”***/ 
void code(int low,int mid,int high)                              //编码 
{ 
 int i;                                               //定义循环变量i为整型 
 for(i=low;i<high;i++)                                        //循环 
 { 
  if(i<mid)                                          //如果i小于中间的数 
  { 
   s[i].bit.b[s[i].bit.last]='0';                       //则给这组数赋值为"0" 
            s[i].bit.last++; 
  } 
  else 
  { 
   s[i].bit.b[s[i].bit.last]='1';                       //否则就给这组数赋值为"1" 
   s[i].bit.last++; 
  } 
 } 
} 
/*****输出符号,符号概率及编码****/ 
void output(int n)                                           //输出编码函数n为整型 
{ 
 int i,j;                                                     //定义循环变量i,j 
 printf("请输出符号,符号概率及编码\n");                       //打印提示语"请输出符号,符号概率及编码" 
 for(i=0;i<n;i++)                                   //i从0到n大循环执行n-1次 
 { 
  printf("%c\t%f\t",s[i].c,s[i].probability);              //每次的大循环都输出一个符号和其相对应的概率 
  for(j=0;j<s[i].bit.last;j++) 
   printf("%c",s[i].bit.b[j]);                          //输出编码 
  printf("\n"); 
 } 
} 
/***********译码函数**************/ 
void decode(int n,char a[100])                                   //译码 
{ 
 int i=0,j;                                        //定义变量整型。并给i赋初值=0 
 char s2[100];                                                //数组s2字符型 
 s2[0]='\0';                                          //数组s2的第一个元素为\n 
 while(i<strlen(a))                            //当i<数组a的长度时执行以下程序 www.docin.com 
  { 
  char temp[2];                                      //定义数组temp,字符型 
  temp[0]=a[i]; 
  temp[1]='\0'; 
  strcat(s2,temp); 
  for(j=0;j<n;j++) 
  { 
   if(strcmp(s2,s[j].bit.b)==0) 
   { 
    printf("%c",s[j].c); 
    s2[0]='\0'; 
    break; 
   } 
  } 
  i++; 
 } 
 printf("\n"); 
} 
 
int main()                                                      //主函数 
{ 
 int n;                                                       //定义变量 
 char a[100];                                            //数组最大人容量为100 
 printf("请注意当显示器再次输出“请输入符号个数时”说明输入的n值有误!\n"); 
 do{ 
 printf("请输入符号个数0<n<=20\n");                           // do...while...循环当n>Smax或者n<=0时输入有误 
 scanf("%d",&n);                                            //键盘输入符号个数 
 }while(n>Smax||n<=0); 
 input(n);                                                    //分别调用输入、排序、分组、输出函数并执行 
 sort(n); 
 group(n); 
 output(n); 
 printf("请输入要译的二进制代码\n");                          //打印提示语"请输入要译的二进制代码" 
 scanf("%s",a);                                      //键盘输入要译的二进制代码 
 printf("输出译码结果\n");                            //打印提示语"输出译码结果" 
 decode(n,a);                                    //调用译码函数输出结果 
 
} 
