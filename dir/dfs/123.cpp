#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
int data[6][6]={{0,0,0,0,0,0},{0,13,11,10,4,7},{0,13,10,10,8,5},{0,5,9,7,7,4},{0,15,12,10,11,5},{0,10,11,8,8,4}};
int max1=0,g[10],f[10];
bool p[6]={0};
int go(int step,int t)                   // step�ǵڼ����ˣ�t��֮ǰ�ѵõ�Ч��
{  
   for (int i=1;i<=5;i++)
    if (!p[i])                                    //�жϵ�i���û��ѡ��
     { 
        f[step]=i;                             //��step���ˣ���ѡ��i���
        p[i]=1;                                  //��ǵ�i������˰�����
        t+=data[step][i];                 //����Ч��ֵ
        if (step<5) go(step+1,t);
            else if (t>max1)              //�������Ч��ֵ
             {
               max1=t;
               for (int j=1;j<=5;j++)
                 g[j]=f[j];                     //��������Ч���µĹ���ѡ�񷽰�
             }
        t-=data[step][i];                 //����
        p[i]=0;
     }
}
int main()
{
  go(1,0);                                                  //�ӵ�1���ˣ���Ч��Ϊ0��ʼ
  for (int i=1;i<=5;i++)
    cout<<char(64+i)<<":J"<<g[i]<<setw(3);  //���������������
  cout<<endl;
  cout<<"supply:"<<max1<<endl;                 //������Ч��ֵ
}



