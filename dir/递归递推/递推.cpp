#include <stdio.h>
#include <windows.h>
int main()
{ 
   
   int n;
   int i;
   int fn_1,fn_2;
   printf("please input n=");
   scanf("%d",&n); //��������nֵ
   int fn=0;
   if(n==1)
     fn=3; //��ʼ����n=1��n=2ʱ���ٽ����� 
   else if(n==2)
     fn=7;
   else{ 
     fn_1=7;
     fn_2=3;
     for(i=3;i<=n;i++)
     {
        fn=2*fn_1+fn_2; //��n>=3ʱfn��ͨʽ 
        fn_2=fn_1;//����fn_1��fn_2��ֵ 
        fn_1=fn;
     }
   }
   printf("һ����%d���߷���\n",fn);  //������
   return 0;
}
