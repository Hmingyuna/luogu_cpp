#include<iostream>

using namespace std;

int main()

{

	float x, k, b, h;

	cout << "һԪһ�η������� 'kx+b=h'" << endl << "������k,b,h" << endl;

	cin >> k >> b >> h;
	
	if (k == 0)
	{
		cout << 0 << endl;
	}
	x = (h - b) / k;

	cout << "���Ϊ" << x << endl;

	system("pause");

	return 0;

}