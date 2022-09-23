#include <iostream>
#include <stdlib.h>
#include <string>

class Date {
private:

    int day;
    int month;
    int year;
    std::string date;
    std::string strings[3];

private:

    int len(std::string str)
    {
        int length = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            length++;
        }
        return length;
    }

    void split()
    {
        std::string str = date;
        char seperator = '/';
        int currIndex = 0, i = 0;
        int startIndex = 0, endIndex = 0;
        while (i <= len(str))
        {
            if (str[i] == seperator || i == len(str))
            {
                endIndex = i;
                std::string subStr = "";
                subStr.append(str, startIndex, endIndex - startIndex);
                strings[currIndex] = subStr;
                currIndex += 1;
                startIndex = endIndex + 1;
            }
            i++;
        }
    }

    void convertToInt() {
        year = std::stoi(strings[0]);
        month = std::stoi(strings[1]);
        day = std::stoi(strings[2]);
    }

    void checkYear() {
        if (year < 1)
        {
            std::cout << "Ingresa otro annio." << std::endl;
        }
        else if (year%4 == 0 && year%100 != 0 || year%400 == 0)
        {
            std::cout << year << " El annio SI es bisiesto." << std::endl;
        }
        else
        {
            std::cout << year << " El annio NO es bisiesto." << std::endl;
        }
    }

    void checkMonth() {
        if (month < 1 || month > 12) 
        {
            std::cout << "Ingresa una fecha valida." << std::endl;
        }
        else
        {
            std::cout << month << std::endl;
        }
    }

    void checkDay() {
        if (day < 1 || day > 30 && month==4 || month == 6 || month == 9 || month == 11)
        {
            std::cout << "Fecha NO valida, intenta otra vez." << std::endl;
        }
        else if (day < 1 || day > 31 && month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            std::cout << "Fecha NO valida, intenta otra vez." << std::endl;
        }
        else if (day < 1 || day > 28 && month == 2 && year%4 != 0)
        {
            std::cout << "Fecha NO valida, intenta otra vez." << std::endl;
        }
        else if (day < 1 || day > 29 && month == 2 && year % 4 == 0)
        {
            std::cout << "Fecha NO valida, intenta otra vez." << std::endl;
        }
        else
        {
            std::cout << day << std::endl;
        }
    }

public:
    void setDate(std::string dateChain) {
        date = dateChain;
    }

    std::string getDate() {
        return date;
    }

    void verifyDate() {
        split();
        convertToInt();
        checkYear();
        checkMonth();
        checkDay();
    }
};

int main()
{
    std::string date;
    Date dateDefault = Date();
    char exit = ' ';
    
    do
    {
        std::cout << "Ingrese una fecha con el siguiente formato (YYYY/MM/DD): "; std::cin >> date;
        dateDefault.setDate(date);
        std::cout << "\n";
        std::cout << dateDefault.getDate() << std::endl;
        std::cout << "\n";
        dateDefault.verifyDate();
        std::cout << "Si deseas salir, presiona E, en caso contrario presiona cualquier otra tecla para continuar: "; std::cin >> exit;
    } while (exit != 'e');

    system("pause");

}