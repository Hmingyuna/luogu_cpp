#include <bits/stdc++.h>
using namespace std;
long long l = 1, r, mid, n;//l:���ָ�룬 r:�ұߣ� mid���м䣬 n����
int main(){
    cin >> n;//��������
    r = n;//��ֵ��ָ�루l~r��1~n��
    while(l < r){//���ֻ���
        mid = (l + r) / 2;//ȡ�м�
        if(mid * (mid + 1) / 2 < n/*���ұ�Ϊi * (i + 1) / 2*/) l = mid + 1;//̫С��
        else r = mid;//̫����
    }
	int tmp = n - l * (l - 1) / 2;//�������
    if(l % 2 == 0) cout << tmp << '/' << l + 1 - tmp << endl;//Ϊż
    else cout << l + 1 - tmp << '/'<< tmp << endl;//������
    return 0;
}
