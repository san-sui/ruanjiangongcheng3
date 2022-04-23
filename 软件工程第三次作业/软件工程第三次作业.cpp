#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <malloc.h> 
#define MAX 20 // ��������
typedef struct{
 int path;
 int distance;
} Vert;
typedef struct{
 int n;// ��Ŷ�����
 char name[MAX][60];// �������Ƽ����
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
   printf("%s �� %s ;�� :",g.name[m],g.name[n]);
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
 printf(" ������Ҫ��ѯ�������б�� \n");
 printf(" �����ǳ������Ӧ�ı�� :\n");
 for(i=0;i<g.n;i++)
 {
   w++;
   printf("%s: %d ",g.name[i],i);
 if(w%g.n==0)
     printf("\n");
 }
 scanf("%d%d",&m,&n);
 printf("%s �� %s ����̾����� %d\n",g.name[m],g.name[n],g.v[m][n].distance);
 s=g.v[m][n].path;
 if(s==-1)
   printf("%s �� %s ���·����;���������� \n",g.name[m],g.name[n]);
 if(s>=0)
   path(g,m,n,f);
}
Mgraph Modify(Mgraph g) //  �޸������е�����
{ 
 int p,q,s;
 printf(" ����Ҫ�޸ĵ������б�� \n",g.v[p][q].distance);
 scanf("%d%d",&p,&q);
 printf(" ԭ�������о���Ϊ %d\n");
 printf(" �޸������м�ľ��� \n");
 scanf("%d",&s);
 g.v[p][q].distance=s;
 return g;
}
Mgraph ADD(Mgraph g) //  ����µĳ���
{
 int p=0,q=0,dis;
 char s;
 printf(" ��������ӳ��е����� \n");
 scanf("%s",&g.name[g.n]);
 for(q=0;q<g.n;q++)
 {
 printf("%s �� %s �Ƿ��ڽ�   �ǵģ� 1  ���ǣ� 0\n",g.name[q],g.name[g.n]);
   scanf("%d",&p);
   if(p==1)// �ڽ���Ϣ
   {
     g.v[q][g.n].path=-1;
     printf(" ������ %s �� %s ��ľ��� \n",g.name[q],g.name[g.n]);
     scanf("%d",&dis);
     g.v[q][g.n].distance=dis;
     g.v[g.n][q].distance=dis;
   }
   else
   {
     g.v[q][g.n].distance=99999;//99999 ��ʾ��������޴�ֵ
     g.v[g.n][q].distance=99999;//99999 ��ʾ��������޴�ֵ
   }
 }
   g.n++;
 return g;
}// ��ӽ���
Mgraph Init(Mgraph g)// ��ʼ��һ���ڽӾ�������ͼ
{
 int q=0,p=0;
 g.n=1;
 printf(" �������һ�����е����� \n");
 scanf("%s",g.name[0]);
 for(q=0;q<MAX;q++)
 for(p=0;p<MAX;p++)
 {
   g.v[p][q].path=-2;
   g.v[q][q].distance=0 ;
 }
 return g;
}// ��ʼ������
void main()
{
 
 int i,m=0;
 Mgraph p;
 do{  
   printf("|__________________________________|\n");
 printf("|  ѡ�����  |\n");
 printf("| 1.  ����һ��ͼ  |\n");
 printf("| 2.  ���һ���µĳ���  |\n");
 printf("| 3.  �޸����г��е�����  |\n");
 printf("| 4.  �����·��  |\n");
 printf("| 5. �˳�����  |\n");
 printf("|__________________________________|\n");
 scanf("%d",&i);
   switch(i)
   {
     case 1:p=Init(p);break;// ��ʼ��
     case 2:p=ADD(p);break;// ��ӳ���
     case 3:p=Modify(p);break;// �޸ĳ�������
     case 4:Floyd(p);break;// ���������㷨
     case 5:exit(0);break;// �˳�����
   }
 printf(" �Ƿ����  1 ������  0 ���˳� \n");
   scanf("%d",&m);
   system("cls");
 }while(m==1);
 
}