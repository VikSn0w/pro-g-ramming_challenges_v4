#include "viksn0w_library.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

int main()
{
    const auto CLOCKGUI_START = 2;

    std::string Numbers[11][8];

    Numbers[0][0] = " ### ";
    Numbers[0][1] = "#   #";
    Numbers[0][2] = "#   #";
    Numbers[0][3] = "# # #";
    Numbers[0][4] = "# # #";
    Numbers[0][5] = "#   #";
    Numbers[0][6] = "#   #";
    Numbers[0][7] = " ### ";

    Numbers[1][0] = "  #  ";
    Numbers[1][1] = " ##  ";
    Numbers[1][2] = "# #  ";
    Numbers[1][3] = "  #  ";
    Numbers[1][4] = "  #  ";
    Numbers[1][5] = "  #  ";
    Numbers[1][6] = "  #  ";
    Numbers[1][7] = "#####";

    Numbers[2][0] = " ### ";
    Numbers[2][1] = "#   #";
    Numbers[2][2] = "    #";
    Numbers[2][3] = "   # ";
    Numbers[2][4] = "  #  ";
    Numbers[2][5] = " #   ";
    Numbers[2][6] = "#   #";
    Numbers[2][7] = "#####";

    Numbers[3][0] = " ### ";
    Numbers[3][1] = "#   #";
    Numbers[3][2] = "    #";
    Numbers[3][3] = " ### ";
    Numbers[3][4] = "    #";
    Numbers[3][5] = "    #";
    Numbers[3][6] = "#   #";
    Numbers[3][7] = " ### ";

    Numbers[4][0] = "#   #";
    Numbers[4][1] = "#   #";
    Numbers[4][2] = "#   #";
    Numbers[4][3] = " ####";
    Numbers[4][4] = "    #";
    Numbers[4][5] = "    #";
    Numbers[4][6] = "    #";
    Numbers[4][7] = "    #";

    Numbers[5][0] = " ### ";
    Numbers[5][1] = "#    ";
    Numbers[5][2] = "#    ";
    Numbers[5][3] = " ### ";
    Numbers[5][4] = "    #";
    Numbers[5][5] = "    #";
    Numbers[5][6] = "    #";
    Numbers[5][7] = "####";

    Numbers[6][0] = " ### ";
    Numbers[6][1] = "#    ";
    Numbers[6][2] = "#    ";
    Numbers[6][3] = "#    ";
    Numbers[6][4] = "#### ";
    Numbers[6][5] = "#   #";
    Numbers[6][6] = "#   #";
    Numbers[6][7] = " ### ";

    Numbers[7][0] = "#### ";
    Numbers[7][1] = "#  # ";
    Numbers[7][2] = "   # ";
    Numbers[7][3] = " ####";
    Numbers[7][4] = "   # ";
    Numbers[7][5] = "   # ";
    Numbers[7][6] = "   # ";
    Numbers[7][7] = "   # ";

    Numbers[8][0] = " ### ";
    Numbers[8][1] = "#   #";
    Numbers[8][2] = "#   #";
    Numbers[8][3] = " ### ";
    Numbers[8][4] = "#   #";
    Numbers[8][5] = "#   #";
    Numbers[8][6] = "#   #";
    Numbers[8][7] = " ### ";

    Numbers[9][0] = " ### ";
    Numbers[9][1] = "#   #";
    Numbers[9][2] = "#   #";
    Numbers[9][3] = " ####";
    Numbers[9][4] = "    #";
    Numbers[9][5] = "    #";
    Numbers[9][6] = "    #";
    Numbers[9][7] = " ### ";

    Numbers[10][0] = "     ";
    Numbers[10][1] = " ### ";
    Numbers[10][2] = " ### ";
    Numbers[10][3] = "     ";
    Numbers[10][4] = " ### ";
    Numbers[10][5] = " ### ";
    Numbers[10][6] = "     ";
    Numbers[10][7] = "     ";

    system("cls");
    vik::TextColor(0x0B);
    std::cout << "Pro/g/ramming Challenges, V4" << std::endl;

    vik::TextColor(0x0A);
    std::cout << "145: ASCII Digital Clock" << std::endl;

    vik::TextColor(0x09);
    std::cout << "viksn0w";

    vik::TextColor(0x0C);
    while(true)
    {
        time_t now = time(nullptr);
        struct tm *tm_struct = localtime(&now);

        int hour = tm_struct->tm_hour;
        int minutes = tm_struct->tm_min;

        int dec_hour = (hour%100)/10;
        int onc_hour = hour%10;

        int dec_min = (minutes%100)/10;
        int onc_min = minutes%10;

        for(int i = 0; i < 8; i++)
        {
            vik::Gotoxy(CLOCKGUI_START, 5+i);
            std::cout << Numbers[dec_hour][i];

            vik::Gotoxy(CLOCKGUI_START+6, 5+i);
            std::cout << Numbers[onc_hour][i];

            vik::Gotoxy(CLOCKGUI_START+(6*2), 5+i);
            std::cout << Numbers[10][i];

            vik::Gotoxy(CLOCKGUI_START+(6*3), 5+i);
            std::cout << Numbers[dec_min][i];

            vik::Gotoxy(CLOCKGUI_START+(6*4), 5+i);
            std::cout << Numbers[onc_min][i];
        }
    }

    system("PAUSE");
    return 0xA113;
}
#pragma clang diagnostic pop