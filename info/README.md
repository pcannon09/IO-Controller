# IO Contoller
## 1.1.1

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
