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

extern std::string ioc_key_pressed;
extern std::string ioc_last_key_pressed;
extern std::string exception;

extern bool ioc_key_is_pressed;

#define IOC_getch                               c_getch
#define IOC_getche                              c_getche
#define IOC_kbhit                               c_kbhit

#define IOC_KB_KEY_PRESSED(x)\
    if (ioc_key_pressed == (x))

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


    // TODO
    // template <typename Var, typename... Args>
    
    // void format(Var *var, Args... args)
    // {
    //     var = arr;
    // }

    int terminalW();
    int terminalH();
    void printTerminalW();
    void printTerminalH();

    namespace kb
    {
        void emulateKey(std::string whatKey, bool isKeyPressed);
        void anyKey();
        void update();
        void clear();
    }

    namespace cursor
    {
        void gotoxy(int x, int y);
        void printWhereX();
        void printWhereY();
        void printWhereXY(std::string type);
        int whereX(void);
        int whereY(void);
        
    }
    
    namespace color
    {
        void help();
        void set(std::string color);
    }
}
