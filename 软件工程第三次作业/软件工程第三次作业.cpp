#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <malloc.h> 
#define MAX 20 // 城市数量
typedef struct{
 int path;
 int distance;
} Vert;
typedef struct{
 int n;// 存放顶点数
 char name[MAX][60];// 城市名称及编号
 Vert v[MAX][MAX];
} Mgraph;
void path(Mgraph g,int m,int n,int f)
{
 int k,i,a[21];
 for(i=0;i<21;i++)
   a[i]=-3;
 k=g.v[m][n].path;
 if(k>=0)
 {
   f++;
 a[f]=k;
 k=g.v[m][k].path;
 path(g,m,k,f);
 k=g.v[k][n].path;
 path(g,k,n,f);
 }
 
 for(i=1;a[i]>=0;i++)
 {
   printf("%s 到 %s 途经 :",g.name[m],g.name[n]);
 printf("%s ",g.name[a[i]] );
 }
   
 
}
void Floyd(Mgraph g)
{
 int i,j,k,m,n,h=0,w=0,f=0,s;
 for(k=0;k<g.n-1;k++)
 {
   for(i=0;i<g.n-1;i++)
     for(j=0;j<g.n;j++)
     {
       if(g.v[i][j].distance>g.v[i][k].distance+g.v[k][j].distance)
       {
         g.v[i][j].distance=g.v[i][k].distance+g.v[k][j].distance;
 g.v[j][i].distance=g.v[i][j].distance;
       g.v[i][j].path=k;
 g.v[j][i].path=g.v[i][j].path;
       }
     }
 }
 printf(" 输入你要查询的两城市编号 \n");
 printf(" 以下是城市相对应的编号 :\n");
 for(i=0;i<g.n;i++)
 {
   w++;
   printf("%s: %d ",g.name[i],i);
 if(w%g.n==0)
     printf("\n");
 }
 scanf("%d%d",&m,&n);
 printf("%s 和 %s 的最短距离是 %d\n",g.name[m],g.name[n],g.v[m][n].distance);
 s=g.v[m][n].path;
 if(s==-1)
   printf("%s 到 %s 最短路径不途经其他城市 \n",g.name[m],g.name[n]);
 if(s>=0)
   path(g,m,n,f);
}
Mgraph Modify(Mgraph g) //  修改俩城市的数据
{ 
 int p,q,s;
 printf(" 输入要修改的两城市编号 \n",g.v[p][q].distance);
 scanf("%d%d",&p,&q);
 printf(" 原来两城市距离为 %d\n");
 printf(" 修改两城市间的距离 \n");
 scanf("%d",&s);
 g.v[p][q].distance=s;
 return g;
}
Mgraph ADD(Mgraph g) //  添加新的城市
{
 int p=0,q=0,dis;
 char s;
 printf(" 请输入添加城市的名字 \n");
 scanf("%s",&g.name[g.n]);
 for(q=0;q<g.n;q++)
 {
 printf("%s 和 %s 是否邻接   是的： 1  不是： 0\n",g.name[q],g.name[g.n]);
   scanf("%d",&p);
   if(p==1)// 邻接信息
   {
     g.v[q][g.n].path=-1;
     printf(" 请输入 %s 和 %s 间的距离 \n",g.name[q],g.name[g.n]);
     scanf("%d",&dis);
     g.v[q][g.n].distance=dis;
     g.v[g.n][q].distance=dis;
   }
   else
   {
     g.v[q][g.n].distance=99999;//99999 表示距离的无限大值
     g.v[g.n][q].distance=99999;//99999 表示距离的无限大值
   }
 }
   g.n++;
 return g;
}// 添加结束
Mgraph Init(Mgraph g)// 初始化一个邻接矩阵无向图
{
 int q=0,p=0;
 g.n=1;
 printf(" 请输入第一个城市的名称 \n");
 scanf("%s",g.name[0]);
 for(q=0;q<MAX;q++)
 for(p=0;p<MAX;p++)
 {
   g.v[p][q].path=-2;
   g.v[q][q].distance=0 ;
 }
 return g;
}// 初始化结束
void main()
{
 
 int i,m=0;
 Mgraph p;
 do{  
   printf("|__________________________________|\n");
 printf("|  选择操作  |\n");
 printf("| 1.  创建一个图  |\n");
 printf("| 2.  添加一个新的城市  |\n");
 printf("| 3.  修改现有城市的数据  |\n");
 printf("| 4.  求最短路径  |\n");
 printf("| 5. 退出程序  |\n");
 printf("|__________________________________|\n");
 scanf("%d",&i);
   switch(i)
   {
     case 1:p=Init(p);break;// 初始化
     case 2:p=ADD(p);break;// 添加城市
     case 3:p=Modify(p);break;// 修改城市数据
     case 4:Floyd(p);break;// 弗洛伊的算法
     case 5:exit(0);break;// 退出程序
   }
 printf(" 是否继续  1 ：继续  0 ：退出 \n");
   scanf("%d",&m);
   system("cls");
 }while(m==1);
 
}