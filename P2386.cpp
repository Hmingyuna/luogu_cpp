#include <bits/stdc++.h>
using namespace std;
int t, m, n;
int solve(int m, int n){//m : ƻ���� n �� ����
	if(m == 0 || m == 1 || n == 1) return 1;//����ֻ��һ����ƻ��û�˻�ֻ��һ��
	//ֻ��һ�ַ���
	if(m < n) return solve(m, m);//����̫���ˣ� �����ֻ��m�����ӷŶ����� solve(m, m);
	else return solve(m - n, n) + solve(m, n - 1);//��һ�����ӿճ�����ÿһ�����ӷ�һ�����ܺ�
}
int main(){
	cin >> t;
	for(int _ = 1; _ <= t; _++){
		scanf("%d %d", &m, &n);
		cout << solve(m, n) << endl;//���룬 ���
	}
	return 0;
}
