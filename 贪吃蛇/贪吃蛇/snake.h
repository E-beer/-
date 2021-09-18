#ifndef SNAKE_H
#define SNAKE_H

#include<deque>
#include"point.h"
#include"food.h"

class Food;
class Snake
{
public:
	enum Driection(UP, DOWN, LEFT, RIGHT);

	Snake() {
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;
	}
	void InitSnake();
	void Move();
	void NormalMove();
	bool OverEdge();
	bool HitItselt();
	bool ChangeDirection();
	bool GetFood(const Food&);
	bool GetBigFood(Food&);
private:
	std::deque<Point>snake;
	Direction direction;
	friend class Food;//��FOOD����Ϊ��Ԫ���Ա������Ϊ˽��Ԫ��
};
#endif//SNAKE_H 1
