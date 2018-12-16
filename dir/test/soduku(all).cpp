#include<bits/stdc++.h>

using namespace std;

int a[3][9][9]= {0},map_start[9][9],flag[9][9];

long long count_way=0;

int get_index_in_small(int y,int x)
{
    return 3*(y/3)+(x/3);
}

int get_next(int y,int x,int start)

{
    //�Ե�ǰ����ĵ�ǰֵΪ��׼��Ѱ�ҽ����е���һ����

    for(int i=start; i<9; i++)

        if(a[0][y][i]==0&&a[1][x][i]==0&&a[2][get_index_in_small(y,x)][i]==0)return i;

    return -1;
}

void show()
{
	cout << endl;
    //��ӡ�Ź��Ŀ��н�
    for(int i=1; i<=81; i++)
    {
        printf("%d",map_start[i/9][i%9-1]+1);
        if(!(i%9))printf("\n");
    }
    cout << endl;
}

void change_rule(int style,int x,int y)
{
    //��styleΪ0,��д����Ϊδռ�á���styleΪ1,��д����Ϊ��ռ��
    a[0][y][map_start[y][x]]=style;
    a[1][x][map_start[y][x]]=style;
    a[2][get_index_in_small(y,x)][map_start[y][x]]=style;
}

void solve(int y,int x)
{
    if(x==9)
    {
        y++;
        x=0;
    }
    while(!flag[y][x]&&y<=8)
    {
        x++;    //��ȡ��һ��������������
        if(x==9)
        {
            y++;
            x=0;
        }
    }
    if(y>8)
    {
        show();    //��ǰ�������Ѿ�����������Χ��Ĭ���ѵó�һ�����н�
        count_way++;
        return;
    }
    while((map_start[y][x]=get_next(y,x,map_start[y][x]+1))!=-1)//�Ե�ǰ����ĵ�ǰֵΪ��׼��Ѱ����һ��������
    {
        change_rule(1,x,y);//��д����Ϊ��ռ��
        solve(y,x+1);      //��ֻ�����һ�����н���˳����ɼ�������룺if(count_way)break;
        change_rule(0,x,y);//��д����Ϊδռ��
    }
}

int main()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            map_start[i][j]=getchar()-'0';
            if(!map_start[i][j])
            {
                flag[i][j]=1;
                map_start[i][j]=-1;
            }
            else
            {
                flag[i][j]=0;
                map_start[i][j]--;//Ϊ������㣬���ǳ�ʼ�����ַ�ΧΪ0-8�������������ʱ�ټ���1����
                change_rule(1,j,i);//��д����Ϊ��ռ��
            }
        }
        getchar();//�ѻس����Ե�
    }
    solve(0,0);//��(0,0)λ�ÿ�ʼ����
    cout << count_way << endl;
    return 0;
}