// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int a = 5;
	FILE* fout = fopen("test.txt", "w");
	while (a--) {
		fprintf(fout, "Hi!");
	}
	cin.get();
    return 0;
}

