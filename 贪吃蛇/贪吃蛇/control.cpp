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

void Controller::Start()//��ʼ����
{
	SetWindowSize(41, 32);//���ô��ڴ�С
	SetColor(2);//���ÿ�ʼ������ɫ
	StartInterface *start = new Startinterface();//��̬����һ��Startinterface��start
	start->Action();//��ʼ����
	delete start;//�ͷ��ڴ�ռ�

	/*���ùؼ�λ�ã��������ʾ��ȴ�������������*/
	SetCursorPosition(13, 26);
	std::cout << "press any key to start,,,";
	SetCursorPosition(13, 27);
	system("pause");
}

void Controller::Select()//ѡ�����
{
	/*��ʼ������ѡ��*/
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "		";
	SetCursorPosition(13, 27);
	std::cout << "		";
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(6, 22);
	std::cout << "�����¼�ѡ�񣬻س�ȷ�ϣ�";
	SetCursorPosition(27, 22);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "��ģʽ";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 28);
	std::cout << "����ģʽ";
	SetCursorPosition(0, 31);
	score = 0;

	/*���·����ѡ��ģ��*/
	int ch;//��¼����ֵ
	key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼֵΪ��
	while ((ch = getch()))
	{
		switch (ch)//��������
		{
		case 72://up�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��up�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);//����ѡ�����ñ���ɫ
					SetBackColor();
					std::cout << "��ģʽ";

					SetCursorPosition(27, 24);//����ѡ����ȡ������ɫ
					SetColor(3);
					std::cout << "��ͨģʽ";

					--key;
					break;

				}
			}
		}
	}
}