#include "viksn0w_library.h"

unsigned long long int Factorizer(unsigned long long int Number);
bool PrimeChecker(unsigned long long int Number);

int main()
{
    unsigned long long int Number = 0;

    char repeat = 0;

    while(repeat != 'n')
    {
        system("cls");
        vik::TextColor(0x0B);
        std::cout << "Pro/g/ramming Challenges, V4" << std::endl;

        vik::TextColor(0x0A);
        std::cout << "53: Highest Prime Factor Calculator" << std::endl;

        vik::TextColor(0x09);
        std::cout << "viksn0w" << std::endl;

        vik::TextColor(0x0F);
        std::cout << "Enter number to: ";
        std::cin >> Number;
        long long int prime_factor = Factorizer(Number);

        vik::TextColor(0x0F);
        std::cout << "The Highest Prime Number is: " << prime_factor << std::endl << std::endl;
        std::cout << "Do you want to try another number? Y/n" << std::endl;
        repeat = getch();
        if(repeat == 'N') repeat = 'n';
    }

    system("PAUSE");
    return 0xA113;
}


unsigned long long int Factorizer(unsigned long long int Number)
{
    unsigned long long int PrimeFactor = 0;

    if(PrimeChecker(Number))
    {
        PrimeFactor = Number;
    }
    else
    {
        for(unsigned long long int i = Number/2; i >= 2; i--)
        {
            if(Number%i == 0)
            {
                if(PrimeChecker(i))
                {
                    PrimeFactor = i;
                    break;
                }
            }
        }
    }
    return PrimeFactor;
}


bool PrimeChecker(unsigned long long int Number)
{
    bool flag = true;    
  
    for(unsigned long long int i = 2; i <= Number/2; i++)    
    {    
        if(Number%i == 0)    
        {    
            flag = false;    
            break;    
        }    
    }
    return flag;
}