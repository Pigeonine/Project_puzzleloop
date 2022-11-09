#include "Cannon.h"
#include <cmath>

enum colors { RED = 0, GREEN = 1, BLUE = 2 };

const float PI = std::acos(-1);

const float Center[3] = { 0.0f,0.0f,0.0f };

Cannon::Cannon()
{
	shooting = false;
	angle = 0.0f;
	CW_rotating=false;
	CCW_rotating=false;
	tick = 3.0f;
}

void Cannon::initialize()
{
	first_sphere.setRadius(Radius);
	first_sphere.setSlice(20);
	first_sphere.setStack(20);
	first_sphere.setCenter(Center[0], Center[1]+2 * Radius, Center[2]+0.0f);
	
	second_sphere.setRadius(Radius);
	second_sphere.setSlice(20);
	second_sphere.setStack(20);
	second_sphere.setCenter(Center[0], Center[1], Center[2]);
	
	shooting_sphere.setRadius(Radius);
	shooting_sphere.setSlice(20);
	shooting_sphere.setStack(20);

	velocity = 30.0f;

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(0, 2);

	int first_color = dis(gen);
	int second_color = dis(gen);

	switch (first_color)
	{
	case RED:
		first_sphere.setMTL(red);
		break;
	case GREEN:
		first_sphere.setMTL(green);
		break;
	case BLUE:
		first_sphere.setMTL(blue);
		break;
	default:
		std::cout << "error wrong color" << std::endl;
		break;
	}
	switch (second_color)
	{
	case RED:
		second_sphere.setMTL(red);
		break;
	case GREEN:
		second_sphere.setMTL(green);
		break;
	case BLUE:
		second_sphere.setMTL(blue);
		break;
	default:
		std::cout << "error wrong color" << std::endl;
		break;
	}
}

void Cannon::sphere_move()
{
	if(shooting)
		shooting_sphere.move();
	if (shooting_sphere.center[0] + shooting_sphere.radius >= boundaryX || shooting_sphere.center[0] - shooting_sphere.radius <= -boundaryX || shooting_sphere.center[1] + shooting_sphere.radius >= boundaryY || shooting_sphere.center[1] - shooting_sphere.radius <= -boundaryY)
		shooting = false;
}

void Cannon::CW_able()
{
	CW_rotating = true;
}

void Cannon::CCW_able()
{
	CCW_rotating = true;
}

void Cannon::CW_disable()
{
	CW_rotating = false;
}

void Cannon::CCW_disable()
{
	CCW_rotating = false;
}

void Cannon::CW_tick()
{
	angle += tick;
	if (angle >= 360.0f)
		angle -= 360.0f;
}

void Cannon::CCW_tick()
{
	angle -= tick;
	if (angle < 0.0f)
		angle += 360.0f;
}

void Cannon::set_tick_sensitivity(float sense)
{
	tick = sense;
}

bool Cannon::Is_CW() const
{
	return CW_rotating;
}

bool Cannon::Is_CCW() const
{
	return CCW_rotating;
}


bool Cannon::Is_shooting() const
{
	return shooting;
}

void Cannon::toogle_shooting()
{
	shooting = true;

	shooting_sphere.setMTL(first_sphere.mtl);
	first_sphere.setMTL(second_sphere.mtl);

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(0, 2);

	int second_color = dis(gen);

	switch (second_color)
	{
	case RED:
		second_sphere.setMTL(red);
		break;
	case GREEN:
		second_sphere.setMTL(green);
		break;
	case BLUE:
		second_sphere.setMTL(blue);
		break;
	default:
		std::cout << "error wrong color" << std::endl;
		break;
	}
	float radian = angle * PI / 180.0f;

  	shooting_sphere.setCenter(Center[0] + 2 * Radius * sin(radian), Center[1] + 2 * Radius * cos(radian), 0.0f);
	shooting_sphere.setVelocity(velocity*sin(radian), velocity * cos(radian), 0.0f);



}

void Cannon::draw() const
{
	glPushMatrix();
	if (shooting)
		shooting_sphere.draw();
	glRotatef(angle, 0.0f, 0.0f, -1.0f);
	first_sphere.draw();
	second_sphere.draw();
	glPopMatrix();
}

float Cannon::getangle()
{
	return angle;
}
