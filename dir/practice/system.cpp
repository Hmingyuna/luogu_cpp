//system.cpp
#include <stdio.h>
#include "string.h"
#include <stdlib.h>
using namespace std;
int main(){
	printf("Microsoft Windows [�汾 6.1.7601]\n��Ȩ���� (c) 2009 Microsoft Corporation����������Ȩ����\n\n");
	string scmd;
	while(1){
		printf("C:\\");
		scmd = scanstring();
		system(scmd.v);
	}
	return 0;
}
