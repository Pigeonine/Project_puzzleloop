#include "Cannon.h"

void Cannon::initialize()
{
	first_sphere.setRadius(Radius);
	first_sphere.setSlice(20);
	first_sphere.setStack(20);
	first_sphere.setCenter(0.0f, 2 * Radius, 0.0f);
	
	second_sphere.setRadius(Radius);
	second_sphere.setSlice(20);
	second_sphere.setStack(20);
	second_sphere.setCenter(0.0f, 0.0f, 0.0f);

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

void Cannon::cannon_move()
{
}

void Cannon::sphere_move()
{
}

void Cannon::draw() const
{
	first_sphere.draw();
	second_sphere.draw();
}
