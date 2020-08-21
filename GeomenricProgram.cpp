#include "Detail.h"
#include "CollisionManager.h"

void GeometricProgram::Geometric()
{
	std::cout << "Привет, это четвертая лабораторная работа :) Приступим!" << std::endl;
	bool stopMenu = false;
	while (!stopMenu)
	{
		MenuCommand userChoice = (MenuCommand)tools::GetValidValueFromUser<uint16_t>(PrintMenu(), 
							[](auto const& val) {return val >= 0 && val < 4; });
		switch (userChoice)
		{
			case MenuCommand::Rectangle:
			{
				system("cls");
				DemoRectangleWithPoint();
				break;
			}
			case MenuCommand::Ring:
			{
				system("cls");
				DemoRing();
				break;
			}
			case MenuCommand::Collusion:
			{
				system("cls");
				CollisionManager::DemoCollision();
				break;
			}
			case MenuCommand::Exit:
			{
				system("cls");
				std::cout << "Досвидания :(" << std::endl;
				stopMenu = true;
				break;
			}
		}
	}
}