#include <iostream>
#include <Windows.h>
#include <fstream>

#define ColorCode_DarkBlue		0
#define ColorCode_DarkGreen		1
#define ColorCode_DarkCyan		2
#define ColorCode_DarkRed		3
#define ColorCode_DarkPink		4
#define ColorCode_DarkYellow	5
#define ColorCode_DarkWhite		6
#define ColorCode_Grey			7
#define ColorCode_Blue			8
#define ColorCode_Green			9
#define ColorCode_Cyan			10
#define ColorCode_Red			11
#define ColorCode_Pink			12
#define ColorCode_Yellow		13
#define ColorCode_White			14

using namespace std;

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	int i = -1;
	while (true)
	{
		clrscr();
		i = (i + 1) % 15;
		textColor(i);
		ifstream input("heart.txt");
		char st[500];
		while (input.getline(st, 500))
		{
			cout << st << endl;
		}
		Sleep(300);
		input.close();
	}
}