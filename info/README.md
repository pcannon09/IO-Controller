# IO Contoller
## 1.2.0

---

Started to develop: 15/03/2023
Build with: conio.h
By: Paul Cannon Palacios

Versions:
	
	Release 1.0.0 (17/03/2023)
	
	Release 1.1.0 (26/04/2023)
	{
		DONE:
			Fixed some bugs,
			Added a way to set text backround
	}

	Release 1.1.1 (28/04/2023)
	{
		DONE:
			Added function ioc::start() to start the program and set the some default variables of the program to a default value
			Added functions named (ioc::error("Error message") and ioc::warn("Warn message"))
			Added rules (Like when you change the background of something and then do a warn() / error() message you can do to set background to NONE or set the background that you set before)
		
		BETA:
			Function input() is still in beta, but it does like python (It asks the user something that you want and it stores it in a variable (If you want))
	}

    Release 1.1.2 (29/04/2023)
    {
        Finished doing user input
    }

    Release 1.1.3 (29/05/2023)
    {
        You can now see the line of the error / warning when doing 'ioc::warn()' or 'ioc::error()' [ REMOVED ]
        
        And fixed a bug when resetting color doing 'ioc::color::reset()'
    }

    Release 1.2.0 (10/10/2023)
    {
        You can now make an error without ending program so you can free memory or you can do other things... (Function called: errorNoEnd())
    }
