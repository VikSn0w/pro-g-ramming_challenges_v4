#include "viksn0w_library.h"

int main()
{
    std::string Numbers[11][5]; 

    Numbers[0][0] = " ### ";
    Numbers[0][1] = "#   #";
    Numbers[0][2] = "#   #";
    Numbers[0][3] = "# # #";
    Numbers[0][5] = "# # #";
    Numbers[0][6] = "#   #";
    Numbers[0][7] = "#   #";
    Numbers[0][8] = " ### ";

    Numbers[1][0] = "  #  ";
    Numbers[1][1] = " ##  ";
    Numbers[1][2] = "# #  ";
    Numbers[1][3] = "  #  ";
    Numbers[1][5] = "  #  ";
    Numbers[1][6] = "  #  ";
    Numbers[1][7] = "  #  ";
    Numbers[1][8] = "#####";

    Numbers[2][0] = " ### ";
    Numbers[2][1] = "#   #";
    Numbers[2][2] = "    #";
    Numbers[2][3] = "   # ";
    Numbers[2][5] = "  #  ";
    Numbers[2][6] = " #   ";
    Numbers[2][7] = "#   #";
    Numbers[2][8] = "#####";

    Numbers[3][0] = " ### ";
    Numbers[3][1] = "#   #";
    Numbers[3][2] = "    #";
    Numbers[3][3] = " ### ";
    Numbers[3][5] = "    #";
    Numbers[3][6] = "    #";
    Numbers[3][7] = "#   #";
    Numbers[3][8] = " ### ";

    Numbers[4][0] = "#   #";
    Numbers[4][1] = "#   #";
    Numbers[4][2] = "#   #";
    Numbers[4][3] = " ####";
    Numbers[4][5] = "    #";
    Numbers[4][6] = "    #";
    Numbers[4][7] = "    #";
    Numbers[4][8] = "    #";

    Numbers[4][0] = "#   #";
    Numbers[4][1] = "#   #";
    Numbers[4][2] = "#   #";
    Numbers[4][3] = " ####";
    Numbers[4][5] = "    #";
    Numbers[4][6] = "    #";
    Numbers[4][7] = "    #";
    Numbers[4][8] = "    #";

    Numbers[5]  = " ### \n#   #\n#    \n ### \n    #\n    #\n    #\n#####\n";
    Numbers[6]  = " ### \n#    \n#    \n#    \n#### \n#   #\n#   #\n ### \n";
    Numbers[7]  = "#### \n#  # \n   # \n ####\n   # \n   # \n   # \n   # \n";
    Numbers[8]  = " ### \n#   #\n#   #\n ### \n#   #\n#   #\n#   #\n ### \n";
    Numbers[9]  = " ### \n#   #\n#   #\n ####\n    #\n    #\n    #\n ### \n";
    Numbers[10] = "     \n     \n ### \n ### \n     \n ### \n ### \n     \n";

    char repeat = 0;

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    int hour = 0;
    int minutes = 0;

    system("cls");
    vik::TextColor(0x0B);
    std::cout << "Pro/g/ramming Challenges, V4" << std::endl;

    vik::TextColor(0x0A);
    std::cout << "145: ASCII Digital Clock" << std::endl;

    vik::TextColor(0x09);
    std::cout << "viksn0w" << std::endl;
    
    while(true)
    {
        
        hour = tm_struct->tm_hour;
        minutes = tm_struct->tm_min;

        int dec_hour = (hour%100)/10;
        int onc_hour = hour%10;

        int dec_min = (minutes%100)/10;
        int onc_min = minutes%10;

        vik::Gotoxy(0, 5);
        std::cout << dec_hour;
        vik::Gotoxy(10, 5);
        std::cout << Numbers[onc_hour];
        /*vik::Gotoxy(14, 5);
        std::cout << Numbers[10];

        vik::Gotoxy(21, 5);
        std::cout << Numbers[dec_min];
        vik::Gotoxy(28, 5);
        std::cout << Numbers[onc_min];*/
    }

    system("PAUSE");
    return 0xA113;
}