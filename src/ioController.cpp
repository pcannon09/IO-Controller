#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>

extern "C"
{
#include "../vendor/conio-master/conio.h"
}

#include "../include/stdioc.hpp"

std::string ioc_key_pressed = "";
std::string ioc_last_key_pressed = "";
std::string prKey = "";
std::string exception;

bool ioc_key_is_pressed = false;

#define IOC_getch                               c_getch
#define IOC_getche                              c_getche
#define IOC_kbhit                               c_kbhit

#define IOC_KB_KEY_PRESSED(x)\
    if (ioc_key_pressed == (x))

#define IOC_KB_NOT_PRESSED(x)\
    if (ioc_key_pressed != (x))\
        if (ioc_key_is_pressed == true)

namespace ioc
{
    template <typename T>

    /// @brief Prints text to terminal
    /// @param message (T)
    void print(T message)
    {
        std::cout<<message<<"\n";
    }

    template <typename T, typename... Args>

    /// @brief Prints text to terminal
    /// @param text (T)
    /// @param args (Args...)
    void print(T text, Args... args)
    {
        std::cout<<text<<" ";

        print(args...);
    }

    template <typename T>

    /// @brief Prints text to terminal and does a new line when a new parameter is given 
    /// @param message (T)
    void println(T message)
    {
        std::cout<<message<<"\n";
    }

    template <typename T, typename... Args>

    /// @brief Prints text to terminal and does a new line when a new parameter is given
    /// @param text (T)
    /// @param args (Args...)
    void println(T text, Args... args)
    {
        std::cout<<text<<"\n";

        print(args...);
    }

    template <typename T>

    /// @brief Echoes the exact same thing that you typed
    /// @param message (T)
    void echo(T message)
    {
        std::cout<<message<<"";
    }

    template <typename T, typename... Args>

    /// @brief Echoes the exact same thing that you typed
    /// @param text (T)
    /// @param args (Args...)
    void echo(T text, Args... args)
    {
        std::cout<<text<<"";
        
        echo(args...);
    }
    
    // TODO
    // template <typename Var, typename... Args>

    // /// @brief Formats any datatype
    // /// @param args (Args...)
    // void format(Var *var, Args... args)
    // {
    //     var = args...;
    // }

    namespace kb
    {
        ///  @brief Checks if ioc_key_pressed.size() is bigger than 1 and value not "space"
        void check()
        {
            if (ioc_key_pressed.size() > 1 && ioc_key_pressed != "space" && ioc_key_pressed != "<unknown>")
            {
                stdioc::exception("ioc_key_pressed size is bigger than 1", "", "", "", "", "");
            }
        }

        /// @brief Detects if any key is pressed
        void anyKey()
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                ioc_key_is_pressed = true;
                ioc_key_pressed = "<unknown>";
            }
        }

        /// @brief Updates key press
        void update()
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                switch (IOC_getche())
                {
                case '|':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "|";

                    break;

                case '"':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "\"";

                    break;
                    
                case '!':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "!";

                    break;

                case '@':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "@";

                    break;

                case '£':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "£";

                    break;

                case '$':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "$";

                    break;

                case '%':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "%";

                    break;

                case '^':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "^";

                    break;

                
                case '&':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "&";

                    break;

                case '*':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "*";

                    break;

                case '(':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "(";

                    break;

                case ')':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ")";

                    break;

                case '_':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "_";

                    break;

                case '+':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "+";

                    break;    

                case '{':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "{";

                    break;

                case '}':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "}";

                    break;

                case ':':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ":";

                    break;

                case ' ':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "space";

                    break;


                case ';':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ";";

                    break;

                case '[':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "[";

                    break;

                case ']':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "]";

                    break;

                case '/':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "/";

                    break;

                case '\'':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "\\";

                    break;

                case '\\':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "\\";

                    break;

                case ',':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ",";

                    break;

                case '.':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ".";

                    break;

                case '`':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "`";

                    break;

                case '~':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "~";

                    break;

                case '¡':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "¡";

                    break;

                case '¿':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "¿";

                    break;
                
                // Numbers

                case '1':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "1";

                    break;

                case '2':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "2";

                    break;

                case '3':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "3";

                    break;

                case '4':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "4";

                    break;

                case '5':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "5";

                    break;
                
                case '6':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "6";

                    break;

                case '7':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "7";

                    break;

                case '8':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "8";

                    break;

                case '9':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "9";

                    break;

                case '0':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "0";

                    break;

                // Letters

                case 'q':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "q";

                    break;

                case 'w':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "w";

                    break;

                case 'e':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "e";

                    break;

                case 'r':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "r";

                    break;
                
                case 't':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "t";

                    break;

                case 'y':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "y";

                    break;

                case 'u':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "u";

                    break;

                case 'i':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "i";

                    break;

                case 'o':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "o";

                    break;

                case 'p':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "p";

                    break;

                case 'a':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "a";

                    break;

                case 's':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "s";

                    break;
                
                case 'd':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "d";

                    break;

                case 'f':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "f";

                    break;

                case 'g':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "g";

                    break;

                case 'h':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "h";

                    break;

                case 'j':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "j";

                    break;

                case 'k':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "k";

                    break;

                case 'l':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "l";

                    break;
                
                case 'z':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "z";

                    break;

                case 'x':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "x";

                    break;
                
                case 'c':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "c";

                    break;

                case 'v':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "v";

                    break;

                case 'b':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "b";

                    break;

                case 'n':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "n";

                    break;

                case 'm':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "m";

                    break;

                case 'Q':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "q";

                    break;

                case 'W':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "w";

                    break;

                case 'E':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "e";

                    break;

                case 'R':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "r";

                    break;
                
                case 'T':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "t";

                    break;

                case 'Y':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "y";

                    break;

                case 'U':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "u";

                    break;

                case 'I':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "i";

                    break;

                case 'O':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "o";

                    break;

                case 'P':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "p";

                    break;

                case 'A':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "a";

                    break;

                case 'S':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "s";

                    break;
                
                case 'D':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "d";

                    break;

                case 'F':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "f";

                    break;

                case 'G':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "g";

                    break;

                case 'H':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "h";

                    break;

                case 'J':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "j";

                    break;

                case 'K':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "k";

                    break;

                case 'L':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "l";

                    break;
                
                case 'Z':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "z";

                    break;

                case 'X':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "x";

                    break;
                
                case 'C':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "c";

                    break;

                case 'V':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "v";

                    break;

                case 'B':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "b";

                    break;

                case 'N':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "n";

                    break;

                case 'M':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "m";

                    break;

                default:
                    ioc_key_pressed = "";
                    ioc_key_is_pressed = false;

                    break;
                }
            
                ioc_last_key_pressed = ioc_key_pressed;
            }
        }
    
        /// @brief Sets a key press without a key getting pressed
        /// @param whatKey (std::string)
        /// @param isKeyPressed (bool)
        void emulateKey(std::string whatKey, bool isKeyPressed)
        {
            ioc_key_is_pressed = isKeyPressed;
            ioc_key_pressed = whatKey;

            ioc::kb::check();

            if (ioc_key_is_pressed == true)
            {
                ioc_last_key_pressed = whatKey;
            }
        }

        /// @brief Resets the ioc_key_pressed and ioc_key_is_pressed to the original value
        void clear()
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;
        }

    }

    int terminalW()
    {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        return w.ws_row;
    }

    int terminalH()
    {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        return w.ws_col;
    }
    
    void printTerminalH()
    {
        print(terminalH());
    }

    void printTerminalW()
    {
        print(terminalW());
    }

    namespace cursor
    {
        /// @brief Set terminal cursor to the given x and y position
        /// @param x (int)
        /// @param y (int)
        void gotoxy(int x, int y)
        {
            c_gotoxy(x, y);
        }

        /// @brief Prints to the screen where the terminal cursor x is
        void printWhereX()
        {
            print(c_wherex());
        }

        /// @brief Prints to the screen where the terminal cursor y is
        void printWhereY()
        {
            print(c_wherey());
        }
        
        /// @brief Prints to the screen where the terminal cursor x is
        /// @param type (std::string)
        void printWhereXY(std::string type)
        {
            print(c_wherex());
            print(c_wherey());
        }

        /// @brief Set a variable to cursor x in terminal
        int whereX(void)
        {
            return c_wherex();
        }
        
        /// @brief Set a variable to cursor y in terminal
        int whereY(void)
        {
            return c_wherey();
        }
    }

    /// @brief Gets the text info
    /// @param r
    void getTextInfo(struct text_info *r)
    {
        c_gettextinfo(r);
    }

    /// @brief Sets console text attribute
    /// @param newattr
    void textattr(int newattr)
    {
        c_textattr(newattr);
    }

    namespace color
    {
        /// @brief Sets the color of text in terminal
        /// @param color (std::string)
        void set(std::string color)
        {
            if (color == "black" || color == "0")
            {
                c_textcolor(BLACK);
            }

            else if (color == "blue" || color == "1")
            {
                c_textcolor(BLUE);
            }

            else if (color == "green" || color == "2")
            {
                c_textcolor(GREEN);
            }

            else if (color == "cyan" || color == "3")
            {
                c_textcolor(CYAN);
            }
            
            else if (color == "red" || color == "4")
            {
                c_textcolor(RED);
            }

            else if (color == "magenta" || color == "5")
            {
                c_textcolor(MAGENTA);
            }

            else if (color == "brown" || color == "6")
            {
                c_textcolor(BROWN);
            }

            else if (color == "light gray" || color == "light grey" || color == "7")
            {
                c_textcolor(LIGHTGRAY);
            }

            else if (color == "dark gray" || color == "light grey" || color == "8")
            {
                c_textcolor(DARKGRAY);
            }

            else if (color == "light blue" || color == "9")
            {
                c_textcolor(LIGHTBLUE);
            }

            else if (color == "light green" || color == "10")
            {
                c_textcolor(LIGHTGREEN);
            }

            else if (color == "light cyan" || color == "11")
            {
                c_textcolor(LIGHTCYAN);
            }

            else if (color == "light red" || color == "12")
            {
                c_textcolor(LIGHTRED);
            }

            else if (color == "light magenta" || color == "13")
            {
                c_textcolor(LIGHTMAGENTA);
            }

            else if (color == "yellow" || color == "14")
            {
                c_textcolor(YELLOW);
            }

            else if (color == "white" || color == "15")
            {
                c_textcolor(WHITE);
            }

            else if (color == "blink" || color == "none" || color == "reset" || color == "128")
            {
                c_textcolor(BLINK);
            }

            else
            {
                stdioc::exception("No color named ", color.c_str(), "", "", "", "");
            }
        }


        /// @brief Gives you all the colors of the ioc::color::set();
        void help()
        {
            for (int i = 0 ; i < 14 ; i++)
            {
                c_textcolor(i);
            
                ioc::print("The quick brown fox jumps over the lazy dog");
            }

            c_textcolor(BLINK);

            ioc::print("The quick brown fox jumps over the lazy dog");
        }
    }
}
