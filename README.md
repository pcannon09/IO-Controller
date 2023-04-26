# IO-Controller

## 1.1.0

### By: Paul Cannon
---

First, you need to create a Makefile to do it easier, just copy the IO Controller Makefile and change the .o files to the ones that you want (DON'T GET RID OF 'ioController.o' and 'stdioc.o')

How to IO:

```cpp

 ioc::print("This prints what you want to the terminal"); 
 ioc::echo("This prints to the terminal the exact thing that you wrote");
 ioc::println("Does ioc::print() but it makes a new line when you do a new parameter")

```

How to terminal info:

```cpp
int terminalW = ioc::terminalW(); // Returns the terminal width
int terminalH = ioc::terminalH(); // Returns the terminal height

// To print it to the terminal directly, you can do this:

ioc::printTerminalW();
ioc::printTerminalH();
```

You can compare keys and ascii key numbers doing:

```cpp
bool key1IsKey2 = ioc::compare::key("w", "j"); // In this case, it will return false / 0, because key1 is not the same as key2
bool key1IsKey2Ascii = ioc::compare::asciiKey(90, 90); // In this case, it will return true / 1, because key1 is the same as key2
```

How to key press

```cpp
ioc::kb::update(); // Do this to get any key character (You need to use it in a while / for loop to do it right)
int variable1 = getAscii(); // It will get the ascii key that you pressed
ioc::kb::emulateKey("w"); // In this case, it will emulate key 'w' (It will do that key (x) will be pressed)
ioc::kb::clear(); // Resets the update

// To get the key press, you need to do this:

while (1)
{
    ioc::kb::update();
    
    IOC_KB_KEY_PRESSED("2")
    {
        ioc::print("You pressed the 2 key");
    }
    
    IOC_KB_NOT_KEY_PRESSED("2")
    {
        ioc::print("You didn't pressed the 2 key");
    }

    ioc::kb::emulateKey("w");
    
    if (ioc_key_is_pressed)
    {
        ioc::print("You pressed a key");
        
        if (ioc_key_pressed == "w")
        {
            ioc::print("You pressed the w key");
        }
        
        else
        {
            ioc::print("You didn't press the w key");
        }
    }
}

```

How to cursor info:

```cpp
ioc::cursor::gotoxy(3, 4); // Goes to character 3, 4 of the terminal
ioc::cursor::printWhereX(); // Prints the cursor X
ioc::cursor::printWhereY(); // Prints the cursor Y

int cursorX = ioc::cursor::whereX(); // Returns where is the cursor X
int cursorY = ioc::cursor::whereY(); // Returns where is the cursor Y
```

How to color:

```cpp
ioc::color::help(); // Prints all the colors avadable of the terminal
ioc::color::set("red"); // Sets the text color to red

ioc::print("This text is red! :)");

ioc::color::setBackground("blue"); // Sets the color background to blue

ioc::print("The text background is blue and the text color is red!");

ioc::color::reset(); // Resets the text background and text color of the terminal
```

Hope it helps!
