#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[11], b[1000001];
	gets(a);
	gets(b);
	strcat(a, " ");
	strcat(b, " ");
	int i, s, n = 0, l, j, ss = 0, k, rec;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] >= 'a')
			a[i] -= 'a' - 'A';
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] >= 'a')
			b[i] -= 'a' - 'A';
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == ' ')
		{
			s = 1;
			for (j = n, k = 0; j <= i, a[k] != '\0'; j++, k++)
			{
				if (b[j] == a[k])
				{
					s *= 1;
				}
				else
				{
					s *= 0;
				}
			}
			if (s == 1)
			{
				ss++;
			}
			if (ss == 1 && s == 1)
			{
				rec = n;
			}
			n = i;
			n++;
		}
	}
	if (ss == 0)
	{
		ss = -1;
		printf("%d", ss);
	}
	else if (ss >= 1)
	{
		printf("%d %d", ss, rec);
	}
	return 0;
}