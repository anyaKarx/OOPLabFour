#include "CollisionManager.h"
#include "Detail.h"
#include <vector>
#include <iterator>

bool CollisionManager::IsCollisionRectangle(Rectangle& first, Rectangle& second)
{
    double dX = abs(first.GetPoint().GetX() - second.GetPoint().GetX());
    double dY = abs(first.GetPoint().GetY() - second.GetPoint().GetY());
    double length = abs(first.GetLength() + second.GetLength()) / 2;
    double width = abs(first.GetWidth() + second.GetWidth()) / 2;

    return (dX < length && dY < width);
}

bool CollisionManager::IsCollisionRing(Ring& first, Ring& second)
{
    double dX = abs(first.GetCenter().GetX()
        - second.GetCenter().GetX());
    double dY = abs(first.GetCenter().GetY()
        - second.GetCenter().GetY());
    double C = sqrt(dX * dX + dY * dY);
    double radiusSum = first.GetOuterRadius() + second.GetOuterRadius();

    return (C < radiusSum);
}

void CollisionManager::DemoCollision()
{
    int number = tools::GetValidValueFromUser<int>("\t\tМЕНЮ:\n\n\t№1 Прямоугольники\n\t№2 Кольца\n\nВыберите функцию: ",
        [](auto const& val) {return val == 1 || val == 2; });

    switch (number)
    {
        case 1:
        {
            std::vector<Rectangle> rectangles;
            rectangles.emplace_back(Rectangle(9.0, 3.0, 0.0, 0.0));
            rectangles.emplace_back(Rectangle(2.0, 12.0, 1.0, 1.0));
            rectangles.emplace_back(Rectangle(1.0, 3.0, 10.0, 19.0));

            std::copy(rectangles.begin(), rectangles.end(),
                std::ostream_iterator<Rectangle>(std::cout, "\n"));
            for (size_t i =1; i<3;i++)
            IsCollisionRectangle(rectangles[0], rectangles[i])
                ? std::cout << "Прямоугольники 1 и "<< i+1 <<" пересекаются." << std::endl
                : std::cout << "Прямоугольники 1 и " << i+1 << " не пересекаются." << std::endl;
            
            break;
        }
        case 2:
        {
            std::vector<Ring> rings;
            rings.emplace_back(Ring(7.0, 0.0, 1.0, 1.0));
            rings.emplace_back(Ring(7.0, 0.0, 4.0, 1.0));
            rings.emplace_back(Ring(7.0, 0.0, 19.0, 15.0));

            std::copy(rings.begin(), rings.end(),
                std::ostream_iterator<Ring>(std::cout, "\n"));
            for (size_t i = 1; i < 3; i++)
                IsCollisionRing(rings[0], rings[i])
                ? std::cout << "Кольца 1 и " << i+1 << " пересекаются." << std::endl
                : std::cout << "Кольца 1 и " << i+1 << " не пересекаются." << std::endl;

            break;
        }
    }
}