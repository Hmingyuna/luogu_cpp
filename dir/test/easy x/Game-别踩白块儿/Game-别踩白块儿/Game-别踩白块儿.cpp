#include "stdafx.h"  
#include<graphics.h>  
#include<conio.h>  

int main(int argc, _TCHAR* argv[])
{
	initgraph(640, 480);
	IMAGE img;
	loadimage(&img, L"D:\\Desktop\\block.png", 100, 100);//先把图片放在工程项目下，使用L+"绝对路径"  
	putimage(100, 100, &img);//显示图片  
	_getch();
	closegraph();
	return 0;
}