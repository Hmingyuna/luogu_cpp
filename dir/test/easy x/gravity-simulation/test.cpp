/////////////////////////////////////////////////////////
// �������ƣ�����ģ��
// ���뻷����Visual C++ 6.0��EasyX 2013������
// ��    �ߣ���ʱ����� <http://www.baidu.com/p/��ʱ�����>
// ����޸ģ�2013-9-19
//
#include"object.h"
#include"easyx.h"
#include<cstdio>
#include<conio.h>
#include<vector>
#include<time.h>
#include<deque>

double sx=1;							//����ϵ��
const int st=5000;						//ÿ֡����ѭ���������ӿ��ٶ�
const int maxx=1366;
const int maxy=768;
double cmass=1.0;						//��ʼ����
double cradius=1.0;						//��ʼ�뾶
const double maxmass=5000;				//��������


void NewSleep(int t)
{
	static clock_t oldclock = clock();	// ��̬��������¼��һ�� tick

	t *= CLOCKS_PER_SEC / 1000;			// ������ת��Ϊ tick
	oldclock += t;						// ���� tick

	while(clock() < oldclock)			// ��ʱ
		Sleep(1);						// �ͷ� CPU ����Ȩ������ CPU ռ����
}

void draw(const gravitation::object& obj,COLORREF color=LIGHTGRAY)
{
	if(obj.radius()*sx>=2||obj.radius()*sx<=-2)		//��ֹ����ʧ��
	{
		setfillcolor(color);
		solidcircle(static_cast<int>(obj.position().x()*sx),static_cast<int>(obj.position().y()*sx),static_cast<int>(obj.radius()*sx));
	}
	else
		putpixel(static_cast<int>(obj.position().x()*sx),static_cast<int>(obj.position().y()*sx),color);
}

void draw(const gravitation::vector& vec,COLORREF color=BLUE)
{
	putpixel(static_cast<int>(vec.x()*sx),static_cast<int>(vec.y()*sx),color);
}


int main()
{
	using namespace gravitation;


	initgraph(maxx,maxy);
	HWND hwnd=GetHWnd();
	SetWindowLong(hwnd , GWL_STYLE ,GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
	SetWindowPos(hwnd , HWND_TOP , 0 , 0 ,GetSystemMetrics(SM_CXSCREEN) , GetSystemMetrics(SM_CYSCREEN) ,SWP_SHOWWINDOW);

	setorigin(maxx/2, maxy/2);
	settextcolor(RED);
	setlinecolor(RED);

	std::deque<object*> objque;						//�洢����
	std::deque<std::vector<vector> > veque;			//�洢β��

	int mx,my,vx,vy;								//��¼������λ�ü��ٶ�
	char s[50];										//���
	MOUSEMSG msg;
	
	objque.push_back(new object(10000,30,vector(-100),vector(0,2.357023)));
	objque.push_back(new object(5000,15,vector(200),vector(0,-4.714045)));
	objque.push_back(new object(1,2,vector(220),vector(0,-20)));

	BeginBatchDraw();
	while(!_kbhit())
	{
		while(MouseHit())
		{
			msg=GetMouseMsg();
			switch(msg.uMsg)
			{
				case WM_LBUTTONDOWN:		//��¼����λ��
					mx=msg.x-maxx/2;
					my=msg.y-maxy/2;
					break;
				case WM_LBUTTONUP:			//����
				{
					//ȷ���ٶ�
					vx=(msg.x-maxx/2-mx)/10;	
					vy=(msg.y-maxy/2-my)/10;
					//����������
					if(static_cast<int>(sx*1000)!=0)
					{
						if(objque.size()==10)			//���ʮ��
						{
							delete objque.front();
							objque.pop_front();
						}
						objque.push_back(new object(cmass,cradius,vector(mx/sx,my/sx),vector(vx,vy)));
					}
					cmass=1.0;
					cradius=1.0;
					break;
				}
				case WM_RBUTTONDOWN:			//ɾ�����һ��
					if(objque.size())
					{
						delete objque.back();
						objque.pop_back();
					}
					break;
				case WM_MOUSEWHEEL:			//����
					sx+=(static_cast<double>(msg.wheel)/1200)*sx;
					break;
			}
		}
		//����ʱһֱ����,���һֱ���»����Ӵ�С������
		if(msg.mkLButton)
		{
		
			line(mx,my,msg.x-maxx/2,msg.y-maxy/2);
			if(cmass<maxmass)
			{
				cmass=cmass+10.0;
				cradius=cradius+0.04;
			}
			sprintf(s,"������ %0.3lf\0",cmass);
			outtextxy(-1*maxx/2,-1*maxy/2+40,s);
			sprintf(s,"�뾶�� %0.3lf\0",cradius);
			outtextxy(-1*maxx/2,-1*maxy/2+60,s);
		}

		//��¼�����β��
		static int wi(0);	
		std::vector<vector> ve;																			//ÿ��objectһ��洢
		for(std::deque<object* >::iterator itr=objque.begin();itr!=objque.end();++itr)					//��¼β��
		{
			ve.push_back((*itr)->position());
		}
		veque.push_back(ve);
		if(++wi==200){veque.pop_front();--wi;}															//β������
		for(std::deque<std::vector<vector> >::iterator it1=veque.begin();it1!=veque.end();++it1)		//��β��
		{
			for(std::vector<vector>::iterator it2=it1->begin();it2!=it1->end();++it2)
				draw(*it2);
		}


		for(int i=0;i!=st;++i){stepforward();}															//�н�
		for(std::deque<object* >::iterator itr=objque.begin();itr!=objque.end();++itr)	{draw(**itr);}	//��ͼ

		sprintf(s,"����:%d\0",objque.size());
		outtextxy(-1*maxx/2,-1*maxy/2,s);
		sprintf(s,"�Ŵ����� %0.3lf\0",sx);
		outtextxy(-1*maxx/2,-1*maxy/2+20,s);

		FlushBatchDraw();
		NewSleep(20);
		cleardevice();
	}
	closegraph();
	while(objque.size()!=0)
	{
		delete objque.back();
		objque.pop_back();
	}
	return 0;
}