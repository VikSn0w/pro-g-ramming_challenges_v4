#include "viksn0w_library.h"

int main()
{
    char repeat = 0;

    while(repeat != 'n')
    {
        system("cls");
        vik::TextColor(0x0B);
        std::cout << "Pro/g/ramming Challenges, V4" << std::endl;

        vik::TextColor(0x0A);
        std::cout << "66: Text to Hexadecimal/binary" << std::endl;

        vik::TextColor(0x09);
        std::cout << "viksn0w" << std::endl;

        std::string Line = "";

        vik::TextColor(0x0F);
        std::cout << "Enter string: ";
        std::getline(std::cin, Line);
        
        std::cout << std::endl << "Hex:" << std::endl;
        for(int i = 0; i < Line.length(); i++)
        {
            std::cout << std::hex << int(Line[i]) << " "; 
        }

        std::cout << std::endl << "Binary:" << std::endl;
        for(int i = 0; i < Line.length(); i++)
        {
            unsigned __int64 Number = int(Line[i]);
            std::cout << std::bitset<8>{Number} << " "; 
        }

        repeat = getch();
        if(repeat == 'N') repeat = 'n';
    }

    system("PAUSE");
    return 0xA113;
}