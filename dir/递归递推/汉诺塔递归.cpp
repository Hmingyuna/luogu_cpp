#include <stdio.h>  
 
int i=1;
void move(int n,char from,char to) 
{printf("��%d��:��%d������%c---->%c\n",i++,n,from,to);  
}  
void hanoi(int n,char from,char denpend_on,char to)
{  
    if (n==1)  
    move(1,from,to);
    else  
    {  
      hanoi(n-1,from,to,denpend_on);
      move(n,from,to);              
      hanoi(n-1,denpend_on,from,to);
    }  
}  
int main()  
{  
     printf("���������ӵĸ���:\n");  
     int n;  
     scanf("%d",&n);  
     char x='A',y='B',z='C';  
     printf("�����ƶ��������:\n");  
     hanoi(n,x,y,z);
	 return 0 ;  
}
