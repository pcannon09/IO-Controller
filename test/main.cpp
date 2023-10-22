#include "ioController.hpp"

#include <iostream>
#include <unistd.h>

int main()
{
    ioc::start();
    
    ioc::color::help();
    ioc::color::set("red");
    ioc::kb::update();
    ioc::echo("Hello world\nThere is no new line here\n ");

    // Emulation

    ioc::kb::emulateKey("h", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("e", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("l", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("l", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("o", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("space", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("w", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("o", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("r", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("l", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ioc::kb::emulateKey("d", true);

    if (ioc_key_is_pressed)
    {
        ioc::print("You emulated the", ioc_key_pressed, "key");
    }

    ///

    ioc::println("Hi!", "Type number 2");

    loop
    {
        ioc::kb::update();

        IOC_KB_KEY_PRESSED("2")
        {

            ioc::print("Done!");

            break;
        }

        IOC_KB_NOT_PRESSED("2")
        {
            if (ioc_key_is_pressed == true)
            {
                ioc::print("You typed the", ioc_key_pressed, "key, press the 2 key!");
            }
        }
    }

    ioc::print("Press the enter key");

    loop
    {
        ioc::kb::update();

        IOC_KB_KEY_PRESSED("return")
        {

            ioc::print("Done!");

            break;
        }

        IOC_KB_NOT_PRESSED("return")
        {
            if (ioc_key_is_pressed == true)
            {
                ioc::print("You didn't pressed the return key");
            }
        }
    }

    ioc::print("Press any key");

    loop
    {
        ioc::kb::anyKey();

        if (ioc_key_is_pressed)
        {
            ioc::print("Ascii key: ", ioc::kb::getAscii());
            ioc::print("Done!");

            break;
        }
    }

    ioc::color::set("blue");
    ioc::print("Press any key to continue");

    loop
    {
        IOC_IS_KEY_PRESSED
        {
            break;
        }
    }

    system("clear");

    ioc::print("Last text color was: ", ioc_last_textColor);

    ioc::color::set("white");
    ioc::print("Now it's: ", ioc_last_textColor);
    ioc::cursor::gotoxy(5, 6);
    ioc::print("Your current terminal window width is", ioc::terminalW(), "and the current window height is", ioc::terminalH());
    ioc::cursor::gotoxy(30, 10);
    ioc::print("Your last key press was", ioc_last_key_pressed);
    ioc::cursor::gotoxy(1, 11);

    ioc::color::set("blue");
    ioc::print("Press any key to continue");

    loop
    {
        IOC_IS_KEY_PRESSED
        {
            break;
        }
    }
    
    ioc::color::set("white");
    ioc::color::setBackground("blue");

    const char *message = "Bye!";

    ioc::rules.setLastColorBgWhenErrorOrWarnEnds = false;
    ioc::rules.errorColorReset = true;
    ioc::rules.warnColorReset = false;

    ioc::color::reset();

    std::string echoThing = "{NONE}";

    echoThing = ioc::input("Type something and i will echo it: ", echoThing);

    ioc::print("You typed:", echoThing, "\n");

    ioc::print("This is what you typed in lowercase: ", ioc::lower::stringType(echoThing));
    ioc::print("And this is what you typed in uppercase: ", ioc::upper::stringType(echoThing));

    ioc::warn("Program is going", "to", "close, but as you can see, the warning background is set to a color and the error below is normal, you can set rules in the code (Go to main.cpp)");
    ioc::error("Program closed", "\n", message);
}

