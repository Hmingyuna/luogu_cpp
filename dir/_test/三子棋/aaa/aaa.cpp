// aaa.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
char qi[3][3];
char zi[3] = { ' ', 'a', 'b' };
char players[3][50];
int player = 1;
int x, y;
int playern(int p) {
	int p1;
	if (p == 1) {
		p1 = 2;
	}
	else
	{
		p1 = 1;
	}
	return p1;

}
bool comp(char a, char b, char c, char d) {
	if (a == b && b == c && c == d) return 1;
	return 0;
}
int pan() {
	for (int i = 0; i < 3; i++)
	{
		if (comp(qi[1][i], qi[2][i], qi[0][i], 'a'))
		{
			return 1;
		}
		if (comp(qi[1][i], qi[2][i], qi[0][i], 'b'))
		{
			return 2;
		}
		if (comp(qi[i][0], qi[i][1], qi[i][2], 'a'))
		{
			return 2;
		}
		if (comp(qi[i][0], qi[i][1], qi[i][2], 'b'))
		{
			return 2;
		}
	}
	if (comp(qi[0][0], qi[1][1], qi[2][2], 'a')) return 1;
	if (comp(qi[0][0], qi[1][1], qi[2][2], 'b')) return 2;
	if (comp(qi[2][0], qi[1][1], qi[0][2], 'a'))return 1;
	if (comp(qi[2][0], qi[1][1], qi[0][2], 'b'))return 2;
	int flag = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (qi[i][j] == '_')
			{
				flag = 0;
			}
		}
	}
	if (flag)
	{
		return 0;
	}
	return -1;
}
void print() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << qi[i][j];
		}
		cout << endl;
	}
}
int main() {
	cout << "player1 name : ";
	cin >> players[1];
	cout << "player2 name : ";
	cin >> players[2];
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			qi[i][j] = '_';
		}
	}
	while (1)
	{
		cout << "player : " << players[player] << endl;
		print();
		cin >> x >> y;
		while (1) { 
			if (0 < x < 3 && 0 < y < 3 && qi[x - 1][y - 1] == '_') { 
				qi[x - 1][y - 1] = zi[player];
				break;
			}
			else cin >> x >> y;
		}
		if (pan() == 2)
		{
			cout << players[1] << "胜利";
			break;
		}
		else if (pan() == 1)
		{
			cout << players[2] << "胜利";
			break;
		}
		else if(pan() == 0)
		{
			cout << "平局";
			break;
		}
		player = playern(player);
		system("cls");
	}
	cout << "\nGame Over";
	system("pause > nul");
}

