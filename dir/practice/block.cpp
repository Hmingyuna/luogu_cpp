#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
 
int DIFFICULT=44;
int count=0 ;
int TYPE_SHAPE=2 ;
int flag=7 ;
int LINE=12;
 
struct MyStruct
{
  int shape ;
  int color ;
  int infect ;
};
 
void SetColor(unsigned short ForeColor,unsigned short BackGroundColor)
{
  HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor);
}
 
void WelcomeScr()
{
  int i;
  printf("\n\n\n\t\t");
  printf("������ʼ���С�");
  for(i=0; i<=100; i++)
  {
    SetColor(i%6+8,0);
    printf("%3d",i);
    SetColor(15,0);
    printf(" %%");
    SetColor(i%6+8,0);
    printf(" Written by Oliver!");
    Sleep(20);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
  }
  printf("\a");
  Sleep(1000);
  system("cls");
  printf("\n\n\n\t\t");
  SetColor(15,0);
  printf("�������뷽������ �� ����ò�����21�У�");
  printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
  scanf("%d",&LINE);
  printf("\n\n\n\t\t");
  printf("�������������� ��");
  scanf("%d",&DIFFICULT);
  system("cls");
}
 
void Show()
{
  int i ;
  SetColor(15,0);
  printf("\n �� ���������� %-2d / %d  ����%3d��ɫ�飩\n",count,DIFFICULT,LINE*LINE);
  printf("\n �� ���������� ");
  for(i=1; i<7; i++)
  {
    SetColor(15,0);
    printf("%d.",i);
    SetColor(i+8,0);
    printf("%c ",TYPE_SHAPE);
  }
  SetColor(15,0);
  printf("7.");
  SetColor(9,0);
  printf("��");
  SetColor(10,0);
  printf("��");
  SetColor(11,0);
  printf("��");
  SetColor(12,0);
  printf("�� ");
  SetColor(15,0);
  printf("0.");
  SetColor(14,0);
  printf("��");
  SetColor(13,0);
  printf("��");
  SetColor(12,0);
  printf("ͼ");
  SetColor(11,0);
  printf("�� ");
  SetColor(15,0);
  printf("\n\n �� �밴�� 0 ~ 7 ��λ> ");
}
 
int Choose()
{
  int choose ;
  fflush(stdin);
  scanf("%d",&choose);
  switch(choose)
  {
  case 0 :
    TYPE_SHAPE++;
    if(TYPE_SHAPE==7)
    {
      TYPE_SHAPE=1 ;
    }
    return 0 ;
  case 1 :
    return 1 ;
  case 2 :
    return 2 ;
  case 3 :
    return 3 ;
  case 4 :
    return 4 ;
  case 5 :
    return 5 ;
  case 6 :
    return 6 ;
  case 7 :
    return 7 ;
  default :
    printf("\n\t\t\a�� ������Ч�����������룡");
    Sleep(1000);
    return 0 ;
  }
}
 
int main()
{
  int i,j ;
  int num=0 ;
  char ch ;
  int cc ;
  int jj;
  struct MyStruct array[41][41];
  system("title ��Ⱦ���� Oliver's QQ 564404096");
  srand((time(NULL)%100)*rand());
  WelcomeScr();
loop :
  for(i=0; i<LINE; i++)
  {
    for(j=0; j<LINE; j++)
    {
      array[i][j].shape=TYPE_SHAPE ;
      if(flag==7)
      {
        array[i][j].color=rand()%6+1 ;
        array[i][j].infect=0 ;
        count=0 ;
        cc=1 ;
      }
    }
  }
  printf("\n");
  array[0][0].infect=1 ;
  for(jj=0; jj<LINE; jj++)
  {
    for(i=0; i<LINE; i++)
    {
      for(j=0; j<LINE; j++)
      {
        if(array[i][j].color==array[i][j+1].color&&array[i][j].infect==1&&array[i][j+1].infect!=1)
        {
          array[i][j+1].infect=1 ;
        }
        if(array[i][j].color==array[i+1][j].color&&array[i][j].infect==1&&array[i+1][j].infect!=1)
        {
          array[i+1][j].infect=1 ;
        }
      }
    }
 
    for(i=LINE-1; i>0; i--)
    {
      for(j=LINE-1; j>0; j--)
      {
        if(array[i][j].color==array[i-1][j].color&&array[i][j].infect==1&&array[i-1][j].color!=1)
        {
          array[i-1][j].infect=1 ;
        }
        if(array[i][j].color==array[i][j-1].color&&array[i][j].infect==1&&array[i][j-1].color!=1)
        {
          array[i][j-1].infect=1 ;
        }
      }
    }
    cc=1 ;
    for(i=0; i<LINE; i++)
      for(j=0; j<LINE; j++)
      {
        if(array[i][j].infect==0)
        {
          cc=0 ;
          break ;
        }
      }
  }
  for(i=0; i<LINE; i++)
  {
    printf(" ");
    for(j=0; j<LINE; j++)
    {
      SetColor(array[i][j].color+8,0);
      printf("%c ",array[i][j]);
    }
    printf("\n");
  }
  Show();
  if(count<=DIFFICULT&&cc==1&&flag!=7&&flag!=0)
  {
    system("cls");
    printf("\n\n\n\n\t\t\t��%5d��ɫ��������%d�����  ��",LINE*LINE,count);
    printf("\n\n\t\t\t�� ��ϲ�㣬�������ʤ����\n");
loop2 :
    printf("\n\t\t\t\a�� �Ƿ��������Y/N��>");
    fflush(stdin);
    if((ch=getch())=='Y'||ch=='y')
    {
      system("cls");
      flag=7 ;
      goto loop ;
    }
    else if(ch=='n'||ch=='N')
    {
      system("cls");
      printf("\n\t\t\t�� л л �� �� ʹ �� ��\n\n\t\t\t�� �� ��: Oliver\n\n\t\t\t�� Q Q: 564404096\n\n\t\t\t�� �� �� ԭ ������ Ȩ �� �� ��");
      Sleep(5000);
      exit(1);
    }
    else
    {
      printf("\n\n\t\t\t\a�� ��������������� >");
      Sleep(1000);
      system("cls");
      goto loop2 ;
    }
  }
  else if(count>DIFFICULT)
  {
    system("cls");
    printf("\n\n\n\n\t\t\t\a�� ���ź���������ʧ�ܣ�\n");
    goto loop2 ;
  }
  else
    ;
  flag=Choose();
  if(flag!=0)
  {
    array[0][0].color=flag ;
    if(flag!=7)
    {
      count++;
    }
    for(i=0; i<LINE; i++)
    {
      for(j=0; j<LINE; j++)
      {
        if(array[i][j].infect==1)
        {
          array[i][j].color=flag ;
        }
      }
    }
  }
  system("cls");
  goto loop ;
  return 0;
}
