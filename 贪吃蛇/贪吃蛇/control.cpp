#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"controller.h"
#include"tools.h"
#include"startinterface.h"
#include"map.h"
#include"snake.h"
#include"food.h"

void Controller::Start()//开始界面
{
	SetWindowSize(41, 32);//设置窗口大小
	SetColor(2);//设置开始动画颜色
	StartInterface *start = new Startinterface();//动态分配一个Startinterface类start
	start->Action();//开始动画
	delete start;//释放内存空间

	/*设置关键位置，并输出提示语，等待任意键输出结束*/
	SetCursorPosition(13, 26);
	std::cout << "press any key to start,,,";
	SetCursorPosition(13, 27);
	system("pause");
}

void Controller::Select()//选择界面
{
	/*初始化界面选项*/
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "		";
	SetCursorPosition(13, 27);
	std::cout << "		";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(6, 22);
	std::cout << "（上下键选择，回车确认）";
	SetCursorPosition(27, 22);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	std::cout << "简单模式";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "普通模式";
	SetCursorPosition(27, 26);
	std::cout << "困难模式";
	SetCursorPosition(27, 28);
	std::cout << "炼狱模式";
	SetCursorPosition(0, 31);
	score = 0;

	/*上下方向键选择模块*/
	int ch;//记录键入值
	key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始值为否
	while ((ch = getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://up上方向键
			if (key > 1)//当此时选中项为第一项时，up上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);//给待选中设置背景色
					SetBackColor();
					std::cout << "简单模式";

					SetCursorPosition(27, 24);//将已选中项取消背景色
					SetColor(3);
					std::cout << "普通模式";

					--key;
					break;

				}
			}
		}
	}
}