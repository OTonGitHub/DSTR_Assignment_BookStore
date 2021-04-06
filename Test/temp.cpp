#include <string>
#include <iostream>
#include <sstream>

int main()
{
    std::string line;
    double d;
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if (ss >> d)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Error!" << std::endl;
    }
    std::cout << "Finally: " << d << std::endl;
    }