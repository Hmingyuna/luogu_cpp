#include <bits/stdc++.h>
//#define scanf scanf_s
using namespace std;
int q[10005];//�������飨a)
int w[10005];//�⣨b)
int used[10005];
int main()
{
	int m, n, i, j;
	char a, b, c;//����
	while (~scanf("%d", &m))//����
	{
		memset(w, 0, sizeof(w));
		memset(used, 0, sizeof(used));
		scanf("%c%*%*", &a);
		if (a == 'A')
		{
			scanf("%d", &q[1]);
			for (i = 2; i <= m; i++)
				scanf(",%d", &q[i]);//����
			cin >> b;
			for (i = 1; i <= m; i++)
				for (j = 1; j < i; j++)
				{
					if (q[i] > q[j])
						w[i]++;//ͳ�Ƹ���
				}
			printf("B=(");
			cout << w[1];
			for (i = 2; i <= m; i++)
				printf(",%d", w[i]);
			printf(")\n");//���
		}
		else if (a == 'B')//��һ�����
		{
			scanf("%d", &w[1]);
			for (i = 2; i <= m; i++)
				scanf(",%d", &w[i]);
			cin >> b;//����
			int s;
			memset(used, 0, sizeof(used));
			for (i = m; i >= 1; i--)
			{
				s = 0;//��ǰ����
				for (j = 0; j < m; j++)
				{
					if (s == w[i] && !used[j])//sΪ������j��δ�ù�
					{
						q[i] = j;//��Ϊj
						used[j] = 1;//���
						break;
					}
					if (!used[j])
						s++;
				}
			}
			printf("A=(");
			cout << q[1];
			for (i = 2; i <= m; i++)
				printf(",%d", q[i]);
			printf(")\n");//���
		}
	}
	return 0;
}
