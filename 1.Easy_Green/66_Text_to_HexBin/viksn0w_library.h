//---------------------START LIBRARIES-------------------------------
#include <iostream>
#include <iomanip>

#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <cstdio>

#include <fstream>
#include <sstream>
#include <bitset>

#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>

#include <Wincon.h>

#include <typeinfo>


//---------------------END LIBRARIES----------------------------------

namespace vik
{
    //---------------------START SUBROUTINES------------------------------
    void Gotoxy(int x, int y);
    void TextColor(int Colore);

    template <class Type>
    Type getMax(Type V[], Type N);
    template <class Type>
    Type getMin(Type V[], Type N);
    template <class Type>
    Type caricaVettore(Type V[], int N);
    template <class Type>
    void stampaVettore(Type V[], int N);
    template <class Type>
    Type getMedia(Type V[], int N);

    template <class Type>
    void sortingIngenuo(Type V[], int N);
    template <class Type>
    void selectionSort(Type V[], int N);
    template <class Type>
    void insertionSort(Type V[], int N);
    template <class Type>
    void mergeSort(Type V[], int N);
    void countingSort(int V[], int N);

    //-----------------------VETTORI-------------------------------------
    //Generali
    template <class Type>
    Type getMax(Type V[], Type N)
    {
        Type Max = -2147483648;
        for(int i = 0; i < N; i++)
        {
            if(V[i]>V[i++])Max = V[i];
        }
        return Max;
    }

    template <class Type>
    Type getMin(Type V[], Type N)
    {
        Type Min = 2147483647;
        for(Type i = 0; i < N; i++)
        {
            if(V[i]<V[i++])Min = V[i];
        }
        return Min;
    }

    template <class Type>
    void stampaVettore(Type V[], int N)
    {
        for(int i = 0; i < N; i++)
        std::cout << std::setw(8) << V[i] ;
        std::cout << "\n-------------------------------------\n";
    }

    template <class Type>
    Type caricaVettore(Type V[], int N)
    {
        int i;
        for(i = 0; i < N; i++)
        {
            V[i] = rand();
        }
    }

    template <class Type>
    Type getMedia(Type V[], int N)
    {
        Type Number = 0;
        for(int i = 0; i < N; i++)Number += V[i];
        return Number/double(N);
    }


    //Ordinamenti
    template <class Type>
    void sortingIngenuo(Type V[], int N)
    {
        int i, s;
        Type App;

        for(i = 0; i < N - 1; i++)
        {
            for(s = i + 1; s < N; s++)
            {
                if(V[i] > V[s])
                {
                    App  = V[i];
                    V[i] = V[s];
                    V[s] = App;
                }
            }
        }
    }

    template <class Type>
    void selectionSort(Type V[], int N)
    {
        int i, m, j;
        Type app;
        for(i = 0; i < N - 1; i++)
        {
            m = i;
            for(j = i + 1; j < N; j++) if(V[j] < V[m])  m = j;
            app  = V[i];
            V[i] = V[m];
            V[m] = app;
        }
    }

    template <class Type>
    void insertionSort(Type V[], int N)
    {
        int i, m;
        Type Prec, App;
        for(i = 1; i < N; i++)
        {
            App = V[i];
            for(Prec = i-1; Prec >= 0 and V[Prec] > App; V[Prec + 1] = V[Prec], Prec--);
            V[Prec + 1] = App;
        }
    }

    template <class Type>
    void mergeSort(Type V[], int N)
    {
        int I, Sx, Dx, k;

        if(N > 1)
        {
            I = N/2;
            mergeSort(V, I);
            mergeSort(V+I, N-I);

            Type W[N];
            for(Sx = 0, Dx = I, k = 0; k < N; k++)
            {
                     if(Sx == I)    W[k] = V[Dx++];
                else if(Dx == N)    W[k] = V[Sx++];
                else                W[k] = (V[Sx] <= V[Dx]) ? V[Sx++] : V[Dx++];
            }
            for(k = 0; k < N; V[k] = W[k] ,k++);
        }
    }

    void countingSort(int V[], int N)
    {
        int Min = getMin(V, N);
        int Max = getMax(V, N);
        int i, k;
        int *C;
        C = new (std::nothrow) int [N+100];

        for(k = 0; k < Max++; k++)C[k] = 0;
        for(i = Min; i < N; i++)    C[V[i]]++;
        for(k = 0; k < Max++; k++)
        {
            while(C[k]>0)
            {
                V[i] = k; i++; C[k]--;
            }
        }

    }
    //---------------------GENERALI-------------------------------------
    void Gotoxy(int x, int y)
    {
        COORD Cur = {SHORT(x), SHORT(y)};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
    }

    void TextColor(int Colore)
    {
        HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute ( h, Colore );
    }

    //---------------------END SUBROUTINES--------------------------------


    //---------------------START CLASS--------------------------------
    //------------------------------------ARRAY
    #define MAX 1000000
    /*
        Questa classe crea un oggetto di tipo vettore che permette di eseguire azioni simili ad uno Stack come
        Pop(togliere l'ultimo elemento inserito) e Push(inserire un elemnto nello Stack)
    */
    template <class T>
    class ARRAY
    {
        private:
                int  PhysicalSize;
                T* MainArray;
                int N;

                int  cryptoFunc();
                int  decryptoFunc();
                bool mergeActive(T Array[], int N);


        public:
                 ARRAY();
                ~ARRAY();

            void Print ();
            void Help();

            int Mirror();

            bool pushBack      (T x);
            bool pushFront     (T x);
            bool popBack       (int x);
            bool popFront      (int x);

            bool getMinimum    (T &Minimum);
            bool extractMinimum();

            bool Sort          ();

            int spaceControl   ();

            T   getSum         ();
            int getSize        ();
            T   Research       (T key);
            int setSize        (int M);

            double getAverage  ();
    };
    //CONSTRUCTOR
    template <typename T>
    ARRAY<T>::ARRAY()
    {
        PhysicalSize = 100;
        MainArray = new (std::nothrow) T [PhysicalSize];
        N = 0;
        std::ifstream F; T x; T y;

        F.open("$$ARRAY$$.save");
        if(F.is_open())
        {
            F >> x;
            y = x -(4*((53*4)/3));
            while(!F.eof())
            {
                y = x -(4*((53*4)/3));
                pushBack(y);
                F >>y;
            }
            F.close();
        }
    }
    template <typename T>
    ARRAY<T>::~ARRAY()
    {
        std::ofstream F;
        F.open("$$ARRAY$$.save");
        if(F.is_open())
        {
            for(int i = 0; i < N; i++, F << MainArray[i] + (4*((53*4)/3)) << std::endl);
            F.close();
        }
        delete []MainArray;
    }

    //VOID SEGMENT
    template <typename T>
    void ARRAY<T>::Print()
    {
        for(int i = 0; i < N; i++)
        {
            std::cout << std::setw(15) << MainArray[i];
        }
    }

    template <typename T>
    void ARRAY<T>::Help()
    {
        std::cout << "Here is a list of all the methods that you can use within this class" << std::endl << std::endl;
        std::cout << "Help           ()        = Prints the all the methods on the road" << std::endl;
        std::cout << "Print          ()        = Prints the Array " << std::endl;
        std::cout << "Mirror         ()        = Mirrors the Array" << std::endl;
        std::cout << "Sort           ()        = Sorts the Array (Merge Sort)" << std::endl;
        std::cout << "Research       (int key) = Researches a number in the Array " << std::endl << std::endl;

        std::cout << "pushBack       (int x)   = Inserts new numbers from the last cell of the Array" << std::endl;
        std::cout << "pushFront      (int x)   = Inserts new numbers from the first cell of the Array" << std::endl;
        std::cout << "popBack        (int x)   = Deletes the last element in the last cell of the Array" << std::endl;
        std::cout << "popFront       (int x)   = Deletes the first element in the first cell of the Array" << std::endl<< std::endl;

        std::cout << "spaceControl   ()        =  Verifies if the Array has been resized" << std::endl<< std::endl;

        std::cout << "getMinimum     ()        = Gets the minimum number in the Array" << std::endl;
        std::cout << "getAverage     ()        = Calculates the average number of the Array" << std::endl;
        std::cout << "getSum         ()        = Calculates the sum of the numbers in the Array" << std::endl;
        std::cout << "getSize        ()        = Gets the current size of the Array" << std::endl << std::endl;

        std::cout << "extractMinimum ()        = Exctracts the minimum number in the array and deletes it " << std::endl << std::endl;

        std::cout << "setSize        (int M)   = Sets the size of the Array" << std::endl;
    }

    //BOOL SEGMENT
    template <typename T>
    bool ARRAY<T>::mergeActive(T Array[], int N)
    {
        if(N > 1)
        {
            int Center, Sx, Dx, k;
            T* W; //Prende lo spazio dall'heap

            Center = N/2; //Met� del vettore
            mergeActive(Array, Center);
            mergeActive(Array+Center, N-Center);

            W = new (std::nothrow) int[N];

            for(Sx = 0, Dx = Center, k = 0; k < N; k++)
            {
                     if(Sx == Center)   W[k] =  Array[Dx++];                              //Se la parte sinistra � finita allora prendi dalla parte destra
                else if(Dx == N)        W[k] =  Array[Sx++];                              //Se la parte destra � finita allora prendi dalla parte sinistra
                else                    W[k] = (Array[Sx] <= Array[Dx]) ? Array[Sx++] : Array[Dx++]; //Prendi �l pi� piccolo
            }

            for(k = 0; k < N; Array[k] = W[k], k++);//Ricopia vettore

            delete[]W; //Cedi lo spazio nuovamente

                return true;
            }
            else return false;
    }

    template <typename T>
    bool ARRAY<T>::pushBack(T x)
    {
        if(N == PhysicalSize)
        {
            T* SecondaryArray;
            SecondaryArray =  new (std::nothrow) T [PhysicalSize + 100];

            for(int i = 0; i < N; i++) SecondaryArray[i] = MainArray[i];

            delete[]MainArray;
            MainArray = SecondaryArray;
            PhysicalSize += 100;
        }
        MainArray[N]=x;
        N++;

        return true;
    }

    template <typename T>
    bool ARRAY<T>::pushFront(T x)
    {
        if(N == PhysicalSize)
        {
            T* SecondaryArray;
            SecondaryArray =  new (std::nothrow) T [PhysicalSize + 100];

            for(int i = 0; i < N; i++) SecondaryArray[i] = MainArray[i];

            delete[]MainArray;
            MainArray = SecondaryArray;
            PhysicalSize += 100;

        }
        for(int i=N; i>0; i--)
        {
            MainArray[i]=MainArray[i-1];
        }
        MainArray[0] = x;
        N++;

        return true;
    }

    template <typename T>
     bool ARRAY<T>::popBack(int x)
    {
        if(N > 0)
        {
            for(int i = 0; i < x; i++){N--;}
            return true;
        }
        else return false;

    }
    template <typename T>
    bool ARRAY<T>::popFront(int x)
    {
        if(N > 0)
        {
            for (int i = 0; i < N-1; i++)MainArray[i] = MainArray[i + 1];
            N--;
            return true;
        }
        else return false;
    }

    template <typename T>
    bool ARRAY<T>::getMinimum(T &Minimum)
    {
        if(N > 0)
        {
            for (int i = 1, Minimum = MainArray[0]; i < N; i++)
                if(MainArray[i] < Minimum)Minimum = MainArray[i];
            N--;
            return true;
        }
        else return false;
    }

    template <typename T>
    bool ARRAY<T>::extractMinimum()
    {
        if(N > 0)
        {
            int m, Risp;
            for(int i = 1, m = 0;i < N; i++)
                if(MainArray[i] < MainArray[m]) m = i;
            Risp = MainArray[m];
            while(m < N-1){MainArray[m] = MainArray[m+1]; m++;}

            return true;
        }
        else return false;
    }

    template <typename T>
    bool ARRAY<T>::Sort()
    {
        mergeActive(MainArray, N);
        return true;

    }

    //INT SEGMENT

    template <typename T>
    int ARRAY<T>::spaceControl()
    {
        if(!MainArray) return 0x0;
        else           return 0xA113;
    }
    //------------------END ARRAY--------------------

    //--------------------------------START LISTE-----------------

    template <typename TYPE>
    class LIFO
    {
        private:
            struct NODO
            {
                TYPE Info;
                NODO *Next;
                NODO *Prec;
            };
            NODO *Head;
            void ActiveTailPrint(NODO *H);
            void ActiveHeadPrint(NODO *H);
            void ActiveSaveOnFile(NODO *H, std::ofstream &F);
            void SaveOnFile();
            void TakeFromFile();
        public:
                ~LIFO();
                 LIFO();
            void Push(TYPE Notizia);
            bool Pop (TYPE &NotiziaEstratta);
            void HeadPrint();
            void TailPrint();
            void FreeMemory();
            bool isEmpty();
    };

    template <typename TYPE>
    LIFO<TYPE>::LIFO ()
    {
        Head = nullptr;
        TakeFromFile();
    }

    template <typename TYPE>
    LIFO<TYPE>::~LIFO()
    {
        SaveOnFile();
        FreeMemory();
    }

    template <typename TYPE>
    void LIFO<TYPE>::Push(TYPE Notizia)
    {
        NODO *Nuovo;
        Nuovo = new (std::nothrow) NODO;
        /*(*Nuovo).Info = Notizia;*/
        Nuovo -> Info=Notizia;
        Nuovo -> Next = Head;
        Head = Nuovo;
    }

    template <typename TYPE>
    bool LIFO<TYPE>::Pop(TYPE &NotiziaEstratta)
    {
        NODO *P;
        if(Head)
        {
            P = Head;
            Head = Head -> Next;
            NotiziaEstratta = P -> Info;
            delete P;
            return true;
        }
        else return false;
    }

    template <typename TYPE>
    void LIFO<TYPE>::HeadPrint()
    {
        NODO *H = Head;
        ActiveHeadPrint(H);
    }

    template <typename TYPE>
    void LIFO<TYPE>::ActiveHeadPrint(NODO *H)
    {
        while(H)
        {
            std::cout << H -> Info << std::endl;
            H = H -> Next;
        }
    }

    template <typename TYPE>
    void LIFO<TYPE>::ActiveTailPrint(NODO *H)
    {
        if(H)
        {
            ActiveTailPrint(H->Next);
            std::cout << H->Info << std::endl;
        }
    }

    template <typename TYPE>
    void LIFO<TYPE>::TailPrint()
    {
        ActiveTailPrint(Head);
    }

    template <typename TYPE>
    void LIFO<TYPE>::FreeMemory()
    {
        NODO *P;
        while(Head)
        {
            P = Head;
            Head = Head -> Next;
            delete P;
        }
    }

    template <typename TYPE>
    bool LIFO<TYPE>::isEmpty()
    {
        if(!Head)return true;
        else     return false;
    }

    //------------------------------------------
    template <typename TYPE>
    void LIFO<TYPE>::ActiveSaveOnFile(NODO *H, std::ofstream &F)
    {
        if(H)
        {
            ActiveSaveOnFile(H->Next, F);
            F << H->Info << std::endl;
        }
    }
    template <typename TYPE>
    void LIFO<TYPE>::SaveOnFile()
    {
        NODO *H = Head;
        std::ofstream F;
        F.open("$$SAVECODA$$.txt");
        if(F.is_open())
        {
            ActiveSaveOnFile(Head, F);
            F.close();
        }
    }

    template <typename TYPE>
    void LIFO<TYPE>::TakeFromFile()
    {
        TYPE Notizia;
        NODO *Nuovo;
        std::ifstream INPUT;
        INPUT.open("$$SAVECODA$$.txt");
        if(INPUT.is_open())
        {
            while(!INPUT.eof())
            {
                INPUT >> Notizia;
                Push(Notizia);
            }
        }
    }
    //---------------------END LISTE--------------------------------

    //---------------------START TEXTFIELD--------------------------------
    class TEXTFIELD
    {
        private:
                std::string MainText;
                int MainColor; int SizeX, SizeY; int PositionX, PositionY;

        public:
            void TextField       (std::string Text);
            void SetColor        (std::string TextColor, std::string BackColor);
          //void SetSize         (int Width, int Height);
            void SetPosition     (int X, int Y);
            void Print           ();
            void Help            ();

            TEXTFIELD();
    };

    /*
    void TEXTFIELD::SetSize(int Width, int Height)
    {
        HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);//you don't have to call this function every time
        CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
        GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
        font.dwFontSize.X = Width;
        font.dwFontSize.Y = Height;
        SetCurrentConsoleFontEx(outcon, false, &font);
        SizeX = Width; SizeY = Height;
    }
    */

    //Cambia la posizione
    void TEXTFIELD::SetPosition(int X, int Y)
    {
        COORD Cur = {SHORT(X), SHORT(Y)};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
        PositionX = X; PositionY = Y;
    }

    //Cambia il colore
    void TEXTFIELD::SetColor(std::string TextColor, std::string BackColor)
    {
        int Color;

        //ciclo per la normalizzazione dei caratteri a tutto maiuscolo
        for(int i = 0; i < TextColor.length(); i++){TextColor[i] = toupper(TextColor[i]);}
        for(int i = 0; i < BackColor.length(); i++){BackColor[i] = toupper(BackColor[i]);}

        //Cicli di controllo per il colore e relativo "mixagio"
        if(BackColor == "BLACK")
        {
            if(TextColor == "BLACK")     Color = 0x00;
            if(TextColor == "BLUE")      Color = 0x01;
            if(TextColor == "GREEN")     Color = 0x02;
            if(TextColor == "CYAN")      Color = 0x03;
            if(TextColor == "RED")       Color = 0x04;
            if(TextColor == "MAGENTA")   Color = 0x05;
            if(TextColor == "BROWN")     Color = 0x06;
            if(TextColor == "WHITE")     Color = 0x07;
            if(TextColor == "GRAY")      Color = 0x08;
            if(TextColor == "BBLUE")     Color = 0x09;
            if(TextColor == "BGREEN")    Color = 0x0A;
            if(TextColor == "BCYAN")     Color = 0x0B;
            if(TextColor == "BRED")      Color = 0x0C;
            if(TextColor == "BMAGENTA")  Color = 0x0D;
            if(TextColor == "BYELLOW")   Color = 0x0E;
            if(TextColor == "BWHITE")    Color = 0x0F;
        }
        if(BackColor == "BLUE")
        {
            if(TextColor == "BLACK")     Color = 0x10;
            if(TextColor == "BLUE")      Color = 0x11;
            if(TextColor == "GREEN")     Color = 0x12;
            if(TextColor == "CYAN")      Color = 0x13;
            if(TextColor == "RED")       Color = 0x14;
            if(TextColor == "MAGENTA")   Color = 0x15;
            if(TextColor == "BROWN")     Color = 0x16;
            if(TextColor == "WHITE")     Color = 0x17;
            if(TextColor == "GRAY")      Color = 0x18;
            if(TextColor == "BBLUE")     Color = 0x19;
            if(TextColor == "BGREEN")    Color = 0x1A;
            if(TextColor == "BCYAN")     Color = 0x1B;
            if(TextColor == "BRED")      Color = 0x1C;
            if(TextColor == "BMAGENTA")  Color = 0x1D;
            if(TextColor == "BYELLOW")   Color = 0x1E;
            if(TextColor == "BWHITE")    Color = 0x1F;
        }
        if(BackColor == "GREEN")
        {
            if(TextColor == "BLACK")           Color = 0x20;
            if(TextColor == "BLUE")            Color = 0x21;
            if(TextColor == "GREEN")           Color = 0x22;
            if(TextColor == "CYAN")            Color = 0x23;
            if(TextColor == "RED")             Color = 0x24;
            if(TextColor == "MAGENTA")         Color = 0x25;
            if(TextColor == "BROWN")           Color = 0x26;
            if(TextColor == "WHITE")           Color = 0x27;
            if(TextColor == "GRAY")            Color = 0x28;
            if(TextColor == "BBLUE")           Color = 0x29;
            if(TextColor == "BGREEN")    Color = 0x2A;
            if(TextColor == "BCYAN")     Color = 0x2B;
            if(TextColor == "BRED")      Color = 0x2C;
            if(TextColor == "BMAGENTA")  Color = 0x2D;
            if(TextColor == "BYELLOW")   Color = 0x2E;
            if(TextColor == "BWHITE")    Color = 0x2F;
        }
        if(BackColor == "CYAN")
        {
            if(TextColor == "BLACK")           Color = 0x30;
            if(TextColor == "BLUE")            Color = 0x31;
            if(TextColor == "GREEN")           Color = 0x32;
            if(TextColor == "CYAN")            Color = 0x33;
            if(TextColor == "RED")             Color = 0x34;
            if(TextColor == "MAGENTA")         Color = 0x35;
            if(TextColor == "BROWN")           Color = 0x36;
            if(TextColor == "WHITE")           Color = 0x37;
            if(TextColor == "GRAY")            Color = 0x38;
            if(TextColor == "BBLUE")     Color = 0x39;
            if(TextColor == "BGREEN")    Color = 0x3A;
            if(TextColor == "BCYAN")     Color = 0x3B;
            if(TextColor == "BRED")      Color = 0x3C;
            if(TextColor == "BMAGENTA")  Color = 0x3D;
            if(TextColor == "BYELLOW")   Color = 0x3E;
            if(TextColor == "BWHITE")    Color = 0x3F;
        }
        if(BackColor == "RED")
        {
            if(TextColor == "BLACK")           Color = 0x40;
            if(TextColor == "BLUE")            Color = 0x41;
            if(TextColor == "GREEN")           Color = 0x42;
            if(TextColor == "CYAN")            Color = 0x43;
            if(TextColor == "RED")             Color = 0x44;
            if(TextColor == "MAGENTA")         Color = 0x45;
            if(TextColor == "BROWN")           Color = 0x46;
            if(TextColor == "WHITE")           Color = 0x47;
            if(TextColor == "GRAY")            Color = 0x48;
            if(TextColor == "BBLUE")     Color = 0x49;
            if(TextColor == "BGREEN")    Color = 0x4A;
            if(TextColor == "BCYAN")     Color = 0x4B;
            if(TextColor == "BRED")      Color = 0x4C;
            if(TextColor == "BMAGENTA")  Color = 0x4D;
            if(TextColor == "BYELLOW")   Color = 0x4E;
            if(TextColor == "BWHITE")    Color = 0x4F;
        }
        if(BackColor == "MAGENTA")
        {
            if(TextColor == "BLACK")           Color = 0x50;
            if(TextColor == "BLUE")            Color = 0x51;
            if(TextColor == "GREEN")           Color = 0x52;
            if(TextColor == "CYAN")            Color = 0x53;
            if(TextColor == "RED")             Color = 0x54;
            if(TextColor == "MAGENTA")         Color = 0x55;
            if(TextColor == "BROWN")           Color = 0x56;
            if(TextColor == "WHITE")     Color = 0x57;
            if(TextColor == "GRAY")      Color = 0x58;
            if(TextColor == "BBLUE")     Color = 0x59;
            if(TextColor == "BGREEN")    Color = 0x5A;
            if(TextColor == "BCYAN")     Color = 0x5B;
            if(TextColor == "BRED")      Color = 0x5C;
            if(TextColor == "BMAGENTA")  Color = 0x5D;
            if(TextColor == "BYELLOW")   Color = 0x5E;
            if(TextColor == "BWHITE")    Color = 0x5F;
        }
        if(BackColor == "BROWN")
        {
            if(TextColor == "BLACK")           Color = 0x60;
            if(TextColor == "BLUE")            Color = 0x61;
            if(TextColor == "GREEN")           Color = 0x62;
            if(TextColor == "CYAN")            Color = 0x63;
            if(TextColor == "RED")             Color = 0x64;
            if(TextColor == "MAGENTA")         Color = 0x65;
            if(TextColor == "BROWN")           Color = 0x66;
            if(TextColor == "WHITE")           Color = 0x67;
            if(TextColor == "GRAY")            Color = 0x68;
            if(TextColor == "BBLUE")     Color = 0x69;
            if(TextColor == "BGREEN")    Color = 0x6A;
            if(TextColor == "BCYAN")     Color = 0x6B;
            if(TextColor == "BRED")      Color = 0x6C;
            if(TextColor == "BMAGENTA")  Color = 0x6D;
            if(TextColor == "BYELLOW")   Color = 0x6E;
            if(TextColor == "BWHITE")    Color = 0x6F;
        }
        if(BackColor == "WHITE")
        {
            if(TextColor == "BLACK")           Color = 0x70;
            if(TextColor == "BLUE")            Color = 0x71;
            if(TextColor == "GREEN")           Color = 0x72;
            if(TextColor == "CYAN")            Color = 0x73;
            if(TextColor == "RED")             Color = 0x74;
            if(TextColor == "MAGENTA")         Color = 0x75;
            if(TextColor == "BROWN")           Color = 0x76;
            if(TextColor == "WHITE")           Color = 0x77;
            if(TextColor == "GRAY")            Color = 0x78;
            if(TextColor == "BBLUE")     Color = 0x79;
            if(TextColor == "BGREEN")    Color = 0x7A;
            if(TextColor == "BCYAN")     Color = 0x7B;
            if(TextColor == "BRED")      Color = 0x7C;
            if(TextColor == "BMAGENTA")  Color = 0x7D;
            if(TextColor == "BYELLOW")   Color = 0x7E;
            if(TextColor == "BWHITE")    Color = 0x7F;
        }
        if(BackColor == "GRAY")
        {
            if(TextColor == "BLACK")           Color = 0x80;
            if(TextColor == "BLUE")            Color = 0x81;
            if(TextColor == "GREEN")           Color = 0x82;
            if(TextColor == "CYAN")            Color = 0x83;
            if(TextColor == "RED")             Color = 0x84;
            if(TextColor == "MAGENTA")         Color = 0x85;
            if(TextColor == "BROWN")           Color = 0x86;
            if(TextColor == "WHITE")           Color = 0x87;
            if(TextColor == "GRAY")            Color = 0x88;
            if(TextColor == "BBLUE")     Color = 0x89;
            if(TextColor == "BGREEN")    Color = 0x8A;
            if(TextColor == "BCYAN")     Color = 0x8B;
            if(TextColor == "BRED")      Color = 0x8C;
            if(TextColor == "BMAGENTA")  Color = 0x8D;
            if(TextColor == "BYELLOW")   Color = 0x8E;
            if(TextColor == "BWHITE")    Color = 0x8F;
        }
        if(BackColor == "BBLUE")
        {
            if(TextColor == "BLACK")           Color = 0x90;
            if(TextColor == "BLUE")            Color = 0x91;
            if(TextColor == "GREEN")           Color = 0x92;
            if(TextColor == "CYAN")            Color = 0x93;
            if(TextColor == "RED")             Color = 0x94;
            if(TextColor == "MAGENTA")         Color = 0x95;
            if(TextColor == "BROWN")           Color = 0x96;
            if(TextColor == "WHITE")           Color = 0x97;
            if(TextColor == "GRAY")            Color = 0x98;
            if(TextColor == "BBLUE")     Color = 0x99;
            if(TextColor == "BGREEN")    Color = 0x9A;
            if(TextColor == "BCYAN")     Color = 0x9B;
            if(TextColor == "BRED")      Color = 0x9C;
            if(TextColor == "BMAGENTA")  Color = 0x9D;
            if(TextColor == "BYELLOW")   Color = 0x9E;
            if(TextColor == "BWHITE")    Color = 0x9F;
        }
        if(BackColor == "BGREEN")
        {
            if(TextColor == "BLACK")           Color = 0xA0;
            if(TextColor == "BLUE")            Color = 0xA1;
            if(TextColor == "GREEN")           Color = 0xA2;
            if(TextColor == "CYAN")            Color = 0xA3;
            if(TextColor == "RED")             Color = 0xA4;
            if(TextColor == "MAGENTA")         Color = 0xA5;
            if(TextColor == "BROWN")           Color = 0xA6;
            if(TextColor == "WHITE")           Color = 0xA7;
            if(TextColor == "GRAY")            Color = 0xA8;
            if(TextColor == "BBLUE")     Color = 0xA9;
            if(TextColor == "BGREEN")    Color = 0xAA;
            if(TextColor == "BCYAN")     Color = 0xAB;
            if(TextColor == "BRED")      Color = 0xAC;
            if(TextColor == "BMAGENTA")  Color = 0xAD;
            if(TextColor == "BYELLOW")   Color = 0xAE;
            if(TextColor == "BWHITE")    Color = 0xAF;
        }
        if(BackColor == "BCYAN")
        {
            if(TextColor == "BLACK")           Color = 0xB0;
            if(TextColor == "BLUE")            Color = 0xB1;
            if(TextColor == "GREEN")           Color = 0xB2;
            if(TextColor == "CYAN")            Color = 0xB3;
            if(TextColor == "RED")             Color = 0xB4;
            if(TextColor == "MAGENTA")         Color = 0xB5;
            if(TextColor == "BROWN")           Color = 0xB6;
            if(TextColor == "WHITE")           Color = 0xB7;
            if(TextColor == "GRAY")            Color = 0xB8;
            if(TextColor == "BBLUE")     Color = 0xB9;
            if(TextColor == "BGREEN")    Color = 0xBA;
            if(TextColor == "BCYAN")     Color = 0xBB;
            if(TextColor == "BRED")      Color = 0xBC;
            if(TextColor == "BMAGENTA")  Color = 0xBD;
            if(TextColor == "BYELLOW")   Color = 0xBE;
            if(TextColor == "BWHITE")    Color = 0xBF;
        }
        if(BackColor == "BRED")
        {
            if(TextColor == "BLACK")           Color = 0xC0;
            if(TextColor == "BLUE")            Color = 0xC1;
            if(TextColor == "GREEN")           Color = 0xC2;
            if(TextColor == "CYAN")            Color = 0xC3;
            if(TextColor == "RED")             Color = 0xC4;
            if(TextColor == "MAGENTA")         Color = 0xC5;
            if(TextColor == "BROWN")           Color = 0xC6;
            if(TextColor == "WHITE")           Color = 0xC7;
            if(TextColor == "GRAY")            Color = 0xC8;
            if(TextColor == "BBLUE")     Color = 0xC9;
            if(TextColor == "BGREEN")    Color = 0xCA;
            if(TextColor == "BCYAN")     Color = 0xCB;
            if(TextColor == "BRED")      Color = 0xCC;
            if(TextColor == "BMAGENTA")  Color = 0xCD;
            if(TextColor == "BYELLOW")   Color = 0xCE;
            if(TextColor == "BWHITE")    Color = 0xCF;
        }
        if(BackColor == "BMAGENTA")
        {
            if(TextColor == "BLACK")           Color = 0xD0;
            if(TextColor == "BLUE")            Color = 0xD1;
            if(TextColor == "GREEN")           Color = 0xD2;
            if(TextColor == "CYAN")            Color = 0xD3;
            if(TextColor == "RED")             Color = 0xD4;
            if(TextColor == "MAGENTA")         Color = 0xD5;
            if(TextColor == "BROWN")           Color = 0xD6;
            if(TextColor == "WHITE")           Color = 0xD7;
            if(TextColor == "GRAY")            Color = 0xD8;
            if(TextColor == "BBLUE")     Color = 0xD9;
            if(TextColor == "BGREEN")    Color = 0xDA;
            if(TextColor == "BCYAN")     Color = 0xDB;
            if(TextColor == "BRED")      Color = 0xDC;
            if(TextColor == "BMAGENTA")  Color = 0xDD;
            if(TextColor == "BYELLOW")   Color = 0xDE;
            if(TextColor == "BWHITE")    Color = 0xDF;
        }
        if(BackColor == "BYELLOW")
        {
            if(TextColor == "BLACK")           Color = 0xE0;
            if(TextColor == "BLUE")            Color = 0xE1;
            if(TextColor == "GREEN")           Color = 0xE2;
            if(TextColor == "CYAN")            Color = 0xE3;
            if(TextColor == "RED")             Color = 0xE4;
            if(TextColor == "MAGENTA")         Color = 0xE5;
            if(TextColor == "BROWN")           Color = 0xE6;
            if(TextColor == "WHITE")           Color = 0xE7;
            if(TextColor == "GRAY")            Color = 0xE8;
            if(TextColor == "BBLUE")     Color = 0xE9;
            if(TextColor == "BGREEN")    Color = 0xEA;
            if(TextColor == "BCYAN")     Color = 0xEB;
            if(TextColor == "BRED")      Color = 0xEC;
            if(TextColor == "BMAGENTA")  Color = 0xED;
            if(TextColor == "BYELLOW")   Color = 0xEE;
            if(TextColor == "BWHITE")    Color = 0xEF;
        }
        if(BackColor == "BWHITE")
        {
            if(TextColor == "BLACK")           Color = 0xF0;
            if(TextColor == "BLUE")            Color = 0xF1;
            if(TextColor == "GREEN")           Color = 0xF2;
            if(TextColor == "CYAN")            Color = 0xF3;
            if(TextColor == "RED")             Color = 0xF4;
            if(TextColor == "MAGENTA")         Color = 0xF5;
            if(TextColor == "BROWN")           Color = 0xF6;
            if(TextColor == "WHITE")           Color = 0xF7;
            if(TextColor == "GRAY")            Color = 0xF8;
            if(TextColor == "BBLUE")     Color = 0xF9;
            if(TextColor == "BGREEN")    Color = 0xFA;
            if(TextColor == "BCYAN")     Color = 0xFB;
            if(TextColor == "BRED")      Color = 0xFC;
            if(TextColor == "BMAGENTA")  Color = 0xFD;
            if(TextColor == "BYELLOW")   Color = 0xFE;
            if(TextColor == "BWHITE")    Color = 0xFF;
        }

        MainColor = Color;
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, MainColor);
    }

    //Stampa
    void TEXTFIELD::Print()
    {
        std::cout << MainText;
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 0x0F); //Rimette il colore default della console
    }

    //Pone il MainText uguale alla classe
    void TEXTFIELD::TextField(std::string Text){MainText = Text;};

    //
    void TEXTFIELD::Help()
    {
        system("cls");
        std::cout << "The TextField Class creates text fields-like object,\nthat have the following methods:" << std::endl << std::endl;
        std::cout << "Text.SetPosition(PositionX, PositionY): with this method you can place your text field everywhere on the screen" << std::endl << std::endl;
        std::cout << "Text.SetColor(TextColor, BackColor): with this method you can change the color of the text (font and background), for more details see the readme" << std::endl << std::endl;
        std::cout << "Text.TextField(Text): with this method you can write inside the object" << std::endl << std::endl;
        std::cout << "Text.Print(): with this method you can print the final object" << std::endl << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        system("pause");
    }
    //Inizializzazione classe
    TEXTFIELD::TEXTFIELD(){MainText = ""; MainColor = 0x0F; SizeX = SizeY = PositionX = PositionY = 0;};

    //---------------------END TEXTFIELD----------------------------------

    //---------------------START MEMORYTESTER----------------------------------

    template <typename T>
    class MEMORYTESTER
    {
        private:
            T*    Space;
            T     TypeVariable;
            int   Cells;
            int   Counter;

            long long int   ByteSize;
            float KiloByteSize;
            float MegaByteSize;

            long long int   BitSize;
            float KiloBitSize;
            float MegaBitSize;

            int   getSize();

        public:
            int   getByteSize();
            float getKiloByteSize();
            float getMegaByteSize();

            int getBitSize();
            float getKiloBitSize();
            float getMegaBitSize();

            void  tryMaximumSpace();
            void  PrintTable();
            void  Help();
            MEMORYTESTER();
    };

    template <typename T>
    MEMORYTESTER<T>::MEMORYTESTER() //CONSTRUCTOR
    {
        MegaByteSize = 0;
        KiloByteSize = 0;
        ByteSize     = 0;

        BitSize      = 0;
        KiloBitSize  = 0;
        MegaBitSize  = 0;

        Cells        = 0;
        Counter      = 0;
    }

    template <typename T>
    void MEMORYTESTER<T>::tryMaximumSpace()
    {
        Cells = 0;
        Space = new (std::nothrow) T [Cells];
        while(Space) //while the OS gives the OK for more space continue the cycle
        {
            Cells = Cells + 1000;
            Space = new (std::nothrow) T [Cells]; //request more space
            ByteSize = Cells * getSize();
            printf("The operative system gave %d cells for a total of %d Byte \n", Cells, ByteSize);
        }

        KiloByteSize = float(ByteSize)/(1000);
        MegaByteSize = float(ByteSize)/(1000000);

        BitSize      = ByteSize*8;
        KiloBitSize  = KiloByteSize*8;
        MegaBitSize  = MegaByteSize*8;

        Counter++;

        delete []Space; //deletes all the requested space
    }

    template <typename T>
    void MEMORYTESTER<T>::PrintTable()
    {
        if(Counter == 0) //if the user calls this function before any previous calculations, start an automatic calculation
        {
            printf("Cannot show a table if no calculation was started... starting calculation... \n \n");

            tryMaximumSpace();

            printf("\n");
            printf("Cells occupied for %s : %d ", typeid(TypeVariable).name(), Cells);
            printf("Occupied space in Bytes :  \n");
            printf("Byte     : %d Byte \n", ByteSize);
            printf("KiloByte : %f KiloByte \n", KiloByteSize);
            printf("MegaByte : %f MegaByte \n", MegaByteSize);
            printf("-----------------------------------------------------------");
            printf("\n\n");
            printf("Space occupied in bits :  \n");
            printf("Byte     : %d Bit \n", BitSize);
            printf("KiloByte : %f KiloBit \n", KiloBitSize);
            printf("MegaByte : %f MegaBit \n", MegaBitSize);
            printf("-----------------------------------------------------------");
        }
        else
        {
            printf("\n");
            printf("Cells occupied for %s : %d \n", typeid(TypeVariable).name(), Cells);
            printf("Occupied space in Bytes :  \n");
            printf("Byte     : %d Byte \n", ByteSize);
            printf("KiloByte : %f KiloByte \n", KiloByteSize);
            printf("MegaByte : %f MegaByte \n", MegaByteSize);
            printf("-----------------------------------------------------------");
            printf("\n\n");
            printf("Space occupied in bits :  \n");
            printf("Byte     : %d Bit \n", BitSize);
            printf("KiloByte : %f KiloBit \n", KiloBitSize);
            printf("MegaByte : %f MegaBit \n", MegaBitSize);
            printf("-----------------------------------------------------------");
        }
    }
    template <typename T>
    void MEMORYTESTER<T>::Help()
    {
        printf("Hi!  Welcome to the help guide of this class!\n");
        printf("What is it? This class is created for memory test purpose.\nYou can use every type of variable that works on C/C++ \n\n");
        printf("How many methods can I use? So, there are 9 methods aviable:\n\n");
        printf("float/int getXXXSize    : retrieves the last datas that were calculated from the last variable type \n");
        printf("(int) getByteSize       : returns the size in Bytes \n");
        printf("(float) getKiloByteSize : returns the size in KiloBytes \n");
        printf("(float) getMegaByteSize : returns the size in MegaBytes \n");
        printf("(int) getBitSize        : returns the size in bits \n");
        printf("(float) getKiloBitSize  : returns the size in Kilobits \n");
        printf("(float) getMegaBitSize  : returns the size in Megabits \n");
        printf("tryMaximumSpace         : calculates the maximum space (by 1000 cells) that the operative system gives\n");
        printf("PrintTable              : prints a table with the last datas that were calculated from the last variable type\n");
        printf("Help : prints an help guide\n\n");
        printf("This class was provided and developed by viksn0w\n");
    }

    //"Micro-functions" sector
    template <typename T> int   MEMORYTESTER<T>::getByteSize    (){ return ByteSize;             }
    template <typename T> float MEMORYTESTER<T>::getKiloByteSize(){ return KiloByteSize;         }
    template <typename T> float MEMORYTESTER<T>::getMegaByteSize(){ return MegaByteSize;         }
    template <typename T> int   MEMORYTESTER<T>::getBitSize     (){ return BitSize;              }
    template <typename T> float MEMORYTESTER<T>::getKiloBitSize (){ return KiloBitSize;          }
    template <typename T> float MEMORYTESTER<T>::getMegaBitSize (){ return MegaBitSize;          }
    template <typename T> int   MEMORYTESTER<T>::getSize        (){ return sizeof (TypeVariable);}

    //---------------------END   MEMORYTESTER----------------------------------

    //---------------------END CLASS--------------------------------
}
