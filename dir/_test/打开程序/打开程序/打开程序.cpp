// 打开程序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
int* test(int t) {
	int *a = (int *)malloc(4);
	*a = t;
	return a;
}
using namespace std;
int main()
{
	int *tes = test(5);
	cout << *tes;
	system("pause");
    return 0;
}

