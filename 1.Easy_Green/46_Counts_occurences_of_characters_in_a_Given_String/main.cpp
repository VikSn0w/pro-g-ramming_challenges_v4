#include "viksn0w_library.h"

struct Char
{
    char Character = 0;
    int Occurences = 0;
};

void OccurencesChecker(Char ASCII[], std::string Line);

int main()
{
    Char ASCII[96];
    
    for(int i = 0; i < 96; i++)
    {
        ASCII[i].Character = ' '+i;
    }

    char repeat = 0;

    while(repeat != 'n')
    {
        system("cls");
        vik::TextColor(0x0B);
        std::cout << "Pro/g/ramming Challenges, V4" << std::endl;

        vik::TextColor(0x0A);
        std::cout << "46: Counts occurences of characters in a Given String" << std::endl;

        vik::TextColor(0x09);
        std::cout << "viksn0w" << std::endl;

        std::string Line = "";

        vik::TextColor(0x0F);
        std::cout << "Enter string: ";
        std::getline(std::cin, Line);
        OccurencesChecker(ASCII, Line);

        for(int i = 0; i < 96; i++)
        {
            if(ASCII[i].Occurences > 0)
            {
                std::cout << char(ASCII[i].Character) << ": " << ASCII[i].Occurences << " times\n";
            }
        }

        repeat = getch();
        if(repeat == 'N') repeat = 'n';
    }

    system("PAUSE");
    return 0xA113;
}

void OccurencesChecker(Char ASCII[], std::string Line)
{
    for(int i = 0; i < Line.length(); i++)
    {
        ASCII[Line[i]-32].Occurences++;
    }
}