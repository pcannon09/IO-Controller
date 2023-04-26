#pragma once

#include "ioController.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>

extern "C"
{
#include "../vendor/conio-master/conio.h"
}

#include "../include/stdioc.hpp"

extern std::string NONE;

extern std::string ioc_key_pressed;
extern std::string ioc_last_key_pressed;
extern std::string ioc_last_textColor;
extern std::string ioc_last_bgColor;
extern std::string exception;

extern bool ioc_key_is_pressed;

#define IOC_getch                               c_getch
#define IOC_getche                              c_getche
#define IOC_kbhit                               c_kbhit

/// @brief Checks if any key is pressed
#define IOC_IS_KEY_PRESSED\
    if (IOC_kbhit())

/// @brief Does a infinite loop
#define loop\
    while (1)

/// @brief Repeats (x) times
#define repeat(x)\
    for (int i = 0 ; i < x ; i++)

/// @brief Must be a char
#define IOC_KB_KEY_PRESSED(x)\
    if (ioc_key_pressed == (x))

/// @brief Must be a char
#define IOC_KB_NOT_PRESSED(x)\
    if (ioc_key_pressed != (x) && ioc_key_is_pressed == true)

namespace ioc
{
    template <typename T>

    void print(T message)
    {
        std::cout<<message<<"\n";
    }

    template <typename T, typename... Args>

    void print(T text, Args... args)
    {
        std::cout<<text<<" ";

        print(args...);
    }

    template <typename T>

    void println(T message)
    {
        std::cout<<message<<"\n";
    }

    template <typename T, typename... Args>

    void println(T text, Args... args)
    {
        std::cout<<text<<"\n";

        print(args...);
    }
    
    template <typename T>

    void echo(T message)
    {
        std::cout<<message<<"";
    }

    template <typename T, typename... Args>

    void echo(T text, Args... args)
    {
        std::cout<<text<<"";
        
        echo(args...);
    }

    int terminalW();
    int terminalH();
    void printTerminalW();
    void printTerminalH();


    namespace compare
    {
        bool key(std::string key1, std::string key2);
        bool asciiKey(int key1, int key2);
    }

    namespace kb
    {
        int getAscii();
        void emulateKey(std::string whatKey, bool isKeyPressed);
        void anyKey();
        void update();
        void clear();


        template <typename T>

        void updateAddAscii(T addedNum)
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                if (IOC_getche() && addedNum)
                {
                    ioc_key_pressed = addedNum;
                    ioc_key_is_pressed = false;
                }
            }
        }

        template <typename T>

        void updateAddChar(T addedChar)
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                if (IOC_getche() && addedChar)
                {
                    ioc_key_pressed = addedChar;
                    ioc_key_is_pressed = false;
                }
            }
        }
    }

    namespace cursor
    {
        void gotoxy(int x, int y);
        void printWhereX();
        void printWhereY();
        void printWhereXY();
        int whereX(void);
        int whereY(void);
        
    }

    namespace color
    {
        void help();
        void set(std::string color);
        void setBackground(std::string color);
        void reset();
    }

    void end(int status);
}
