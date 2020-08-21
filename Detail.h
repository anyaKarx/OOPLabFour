#pragma once
#include<iostream>
#include <string>
#include <time.h>
#include <map>
namespace tools
{
    inline double random(double min, double max)
    {
        return (double)(rand()) / RAND_MAX * (max - min) + min;
    }

    inline uint16_t randomUI(uint16_t min, uint16_t max)
    {
        return (uint16_t)(rand() % (max - min) + min);
    }

    template<typename valueType, typename isTheValueValidFunction>
    inline valueType GetValidValueFromUser(std::string message, isTheValueValidFunction isTheValueValid)
    {
        valueType value = 0;
        bool isInvalid = true;

        while (isInvalid)
        {
            std::cout << message;
            std::cin >> value;
            bool isStreamFail = std::cin.fail();
            isInvalid = isStreamFail || !isTheValueValid(value) || std::cin.peek() != '\n';
            if (isInvalid)
            {
                if (isStreamFail)
                    std::cin.clear();

                std::cout << "Значение недопустимо, попробуйте еще раз:" << std::endl;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

        system("cls");
        return value;
    }
}



static class GeometricProgram
{
    static enum class MenuCommand
    {
        Rectangle,
        Ring,
        Collusion,
        Exit
    };
    static const std::string PrintMenu()
    {
        return "\n Выберите пункт в меню:\n\n\t0: Прямоугольники"
            "\n\t1: Кольца\n\t2: Коллизии\n\t3: Выход\nВвeдите команду:\n";
    }
public:
    static void Geometric();
};