#include <bits/stdc++.h>
using namespace std;
char x[10010];
int a[10010], la;
int b;
int c[10010], lc = 0;
int t = 0; 
int main (){
	scanf("%s", x);
	scanf("%d", &b);
	if(b == 0){
		printf("��������Ϊ��");
		return 0;
	}
	la = strlen(x);
	for(int i = 0; i < la; i++){
		a[i + 1] = x[i] - '0';
	}//��������
	
	 
	for(int i = 1; i <= la; i++){
		t = 10 * t + a[i];
		lc++;
		c[lc] = t / b;
		t %= b;
	}//tΪС���� ģ������
	
	 
	int flag = 1;
	for(int i = 1; i <= lc; i++){
		if(flag){
			if(c[i] != 0){//ȥǰ���� 
				flag = 0;
				printf("%d", c[i]);
			}
		}else{
			printf("%d", c[i]);
		}
	}
	if(t) 
	printf("��%d", t);
	return 0;
} 

