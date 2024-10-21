#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include <conio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN, NEN };
eDirection dir;
using namespace std;
int q;
int w;
int e;
int n = 10;
int xxx = 120;
int yyy = 30;
string fileName = "save.txt";
ifstream saveup;
ofstream savelo;
bool zxc, vvv;
class vishna
{
public:
	int vx, vy;
	vishna() :vx(0), vy(0) {}
};
class ataka
{
public:
	int ax;
	ataka() :ax(0) {}
};
class payer
{
public:
	int LV, Y, X, HP, XP, ATK, MAXHP, MAXXP;
	payer() :Y(0), X(0), LV(0), HP(0), XP(0), ATK(0), MAXHP(0), MAXXP(0) {}
};
bool game = true;
payer a;
ataka* j = new ataka[n];
vishna* vv = new vishna[n];
void start()
{
	saveup.open(fileName);
	if (saveup.is_open())
	{
		cout << "загрузка сохранения..." << endl;
		while (!saveup.eof())
		{
			q++;
			if (q == 1)
			{
				saveup >> a.LV;
			}
			else if (q == 2)
			{
				saveup >> a.HP;
			}
			else if (q == 3)
			{
				saveup >> a.XP;
			}
			else if (q == 4)
			{
				saveup >> a.X;
			}
			else if (q == 5)
			{
				saveup >> a.Y;
			}
			else
			{
				break;
			}
		}
		saveup.close();
	}
	else
	{
		cout << "создание сохранения..." << endl;
		savelo.open(fileName);
		if (savelo.is_open())
		{
			savelo << a.LV << endl;
			savelo << a.HP << endl;
			savelo << a.XP << endl;
			savelo << a.X << endl;
			savelo << a.Y << endl;
			savelo.close();
		}
		else
		{
			game = false;
		}
	}
	for (int m = 0; m < n; m++)
	{
		vv[m].vx = rand() % 120;
		vv[m].vy = rand() % 30;
	}
}
void save()
{
	savelo.open(fileName);
	savelo << a.LV << endl;
	savelo << a.HP << endl;
	savelo << a.XP << endl;
	savelo << a.X << endl;
	savelo << a.Y << endl;
	savelo.close();
}
void games()
{
	//опыт
	a.MAXXP = a.LV * 20;
	//хп
	a.MAXHP = a.LV * 12 + 100;
	while (a.XP >= a.MAXXP)
	{
		a.LV++;
		cout << "LV++ LV=" << a.LV << endl;
		a.XP = a.XP - a.MAXXP;
		a.HP = a.MAXHP;
		a.MAXXP = a.LV * 4;
	}
	if (a.HP <= 0)
	{
		game = false;
	}
	for (int p = 0; p < n; p++)
	{
		if (vv[p].vx == a.X && vv[p].vy == a.Y)
		{
			a.XP = a.XP + rand() % a.MAXXP;
			vv[p].vx = rand() % 120;
			vv[p].vy = rand() % 30;
		}
	}
	if (a.X <= 1)
	{
		a.X = 2;
	}
	if (a.Y <= 1)
	{
		a.Y = 2;
	}
	if (a.Y >= 30)
	{
		a.Y = 29;
	}
	if (a.X >= 120)
	{
		a.X = 119;
	}
}
void gamepley()
{
	dir = NEN;
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'z':
			game = false;
			break;
		}
	}
	switch (dir)
	{
	case LEFT:
		a.X--;
		break;
	case RIGHT:
		a.X++;
		break;
	case UP:
		a.Y--;
		break;
	case DOWN:
		a.Y++;
		break;
	}
	/*
	e = rand() % a.LV+1;
cout << e << endl;
		a.XP = a.XP + e;
	*/
	for (int p = 0; p < n; p++)
	{
		if (a.X == j[p].ax)
		{
			a.HP = a.HP - 10;
		}
	}
}
int ty;
void at()
{
	if (ty == 1)
	{
		for (int m = 0; m < n; m++)
		{
			j[m].ax = rand() % 120;
		}
		ty = 0;
	}
	else if (ty == 0)
	{
		ty = 1;
	}
}
void grafon()
{
	for (int yy = 1; yy <= yyy; yy++)
	{
		for (int xx = 1; xx <= xxx; xx++)
		{
			if (xx == 1 || xx == 120)
			{
				cout << "#";
			}
			else if (yy == 1 || yy == 30)
			{
				cout << "#";
			}
			else if (xx == a.X && yy == a.Y)
			{
				cout << "@";
			}
			else
			{
				for (int p = 0; p < n; p++)
				{
					if (xx == j[p].ax)
					{
						zxc = true;
					}
					else if (vv[p].vx == xx && vv[p].vy == yy)
					{
						vvv = true;
					}
				}
				if (zxc)
				{
					if (ty == 1)
					{
						cout << "X";
					}
					else if (ty == 0)
					{
						cout << "!";
					}
				}
				else if (vvv)
				{
					cout << "o";
				}
				else
				{
					cout << " ";
				}
				zxc = false;
				vvv = false;
			}
		}
		cout << endl;
	}
	cout << "оз:" << a.HP << "|" << a.MAXHP << endl;
	cout << "оп:" << a.XP << "|" << a.MAXXP << endl;
	cout << "лвл:" << a.LV << endl;
}
int main()
{
	setlocale(LC_ALL, "ru");
	start();
	while (game)
	{
		system("cls");
		grafon();
		at();
		gamepley();
		games();
		save();
		Sleep(100);
	}
	cout << "востановение оз до " << a.MAXHP << endl;
	a.HP = a.MAXHP;
	save();
}