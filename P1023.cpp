#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int now;//����
struct goods{
    int p;
    int n;
}g[10000];//��¼���������
int x, n, cost;
void add(int a, int b)
 {
    g[now].p = (a);
    g[now].n = (b);
    now++;
}
void init()
{
    int i;//ѭ������
    int a, b;//�ɱ� ������
    int c, d;//�ֶ����Ա���
    int k, f;//k:��������y=kx,f=����
    scanf("%d", &x);//����
    scanf("%d%d", &a, &b);//����
    cost = a;//�ɱ�
    x -= cost;//ÿ�������ٳɱ���
    while(scanf("%d%d", &c, &d)==2&&(c != -1 || d != -1))//ѭ������ֱ��-1
	{
        k = (d - b) / (c - a);//��������
        f = d - c * k;//����
        for(i = a; i <= c - 1; i++)
	{
            add(i - cost, k * i + f);//�����м�۸�
        }
        a = c, b = d;
    }
    scanf("%d", &k);//����
    for(i = a; (b - (i - a) * k) > 0; i++)
	{
        add(i - cost, (b - (i - a) * k));//��߼ۺ�ļ۸�
    }
}

int main()
{
    int i, j;
    int a, b, k;
    double up = -100000, down = 1000000;
    init();
    for(i = 0; i < now; i++)
	{
        if(g[i].p == x)//����ΪԤ�ڼ۸�
	{
            n = g[i].n;//����
            break;
        }
    }
    for(i = 0; i < now; i++)
	{
        k = 1;//����
        a = g[i].p * g[i].n - n * x;//�������
        b = n - g[i].n;//��������
        if(b < 0)
	{
            k = -1;
        }//����
        if(b != 0)//����
	{
            if(k == 1)
			{
                up = max(up, (double)a / b);//���ֵ
            }
            else
            {
                down = min(down, (double)a / b);//��Сֵ
            }
        }
    }
    if(up <= down)
    {
        if(up > 0)
        {
            printf("%d\n", (int)ceil(up));//����ֵС
        }
        else
        {
            down = fabs(down);
            printf("%d\n", - (int)ceil(down));//����ֵ��
        }
    }
    else//������
    {
        printf("NO SOLUTION\n");
    }
    return 0;
}
init