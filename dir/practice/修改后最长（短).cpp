#include <bits/stdc++.h>
using namespace std;
string a;
int l, Max = -1, Min = 1000001, t, cnt;
char MIN[100001], MAX[100001], t1[101];
int main(){
	getline(cin, a);
	a = a+"," ;                //���ӿո���߶��ŵĻ������һ������û���������� 
	for(int i = 0; i <= a.length() - 1;){
		t = i;
		cnt = 0;
		memset(t1, 0, sizeof(t1));
		while (1) {
			if (a[t] == ' ' || a[t] == ',') 
			{
				break;
			}
			t1[cnt] = a[t];
			t++;
			cnt++ ;
		}
		if(cnt < Min){
			memcpy(MIN, t1, sizeof(t1));
			Min = cnt;
		}
		if(cnt > Max){
			memcpy(MAX, t1, sizeof(t1));
			Max = cnt;
		}
		i = t + 1;  //���о������������� ��ԭ����i=i+t+1;����ڵ�10�е�ʱ���Ѿ���i��ֵ��t���ˣ�
		            //t���Լ����¼���  
	}
	printf("%s\n%s\n", MAX, MIN);
	return 0;
}
