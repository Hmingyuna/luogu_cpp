#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct color{    //û��Ҫ�ýṹ��  ��ʼ�븴���� �����OK
   char aa;
   int bb;
}q[10];
int num=0,s;
int sss=0;      //ͬ����ɫ˳����������
void dfs(int a,int b,int c)          //a��ʾ������ɫ  b��ʾ�ѷŸ�����  c��ʾ�Ƿ�Ҫ�ſո�
{
    if(a==num&&b==s)//��������
        {
            sss++;
            return;
        }
    if(b>s)//�ŵĴ��ڸ�����
        return;
    if(c!=1)
	    dfs(a+1,b+q[a].bb,1); //�ſո�
	dfs(a,b+1,0);//����
}
int main()
{
    int i,j;
    int sum;
    int ss=0;
    char a;
    int b;
    scanf("%d",&s);
    while(cin>>a&&a!='Q')
    {
        scanf("%d",&b);
        ss=ss+b;
        int t=0;
        for(i=0;i<num;i++)
          {
              if(q[i].aa==a)
                {
                    q[i].bb+=b;
                    t=1;
                }
          }
          if(t==0)
          {
              q[num].aa=a;
              q[num++].bb=b;
          }
    }//���� + Ԥ����
    int per=1;
    for(i=1;i<=num;i++)
        per=per*i;
    if(s-ss-num+1<=0)         //���Ӳ���
        cout<<0<<endl;
    else
    {
        dfs(0,0,0);//����
        cout<<sss*per<<endl;
		/*ע��ͬ����ɫ�鵽һ��
		����������һ����ɫ˳���µ�����˳��
		�ٽ�������N����ɫ��������N��
		���ɵõ���������
		*/
    }
    return 0;
}
