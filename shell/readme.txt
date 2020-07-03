1 shell.c:
	main() : main() function is just used for taking user input and calling different function
	execute() : execute() function is used to check which command the user entered in main function and then calling the necessary function

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

2 cd.c:
	changeDir(): This changes current working directory when user enters cd command

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

3 pwd.c:
	pwd(): shows path of current working directory

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

4 echo.c:
	echo(): prints the input given by user to stdout

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

5 ls.c:
	ls(): decides what flag is given by user
	list(): executes command ls and ls -a
	listLong(): executes command ls -l and ls -la
	permissions(): determines the various stat of file used to give the output of ls -l

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

6 pinfo.c:
	pinfo(): used to execute pinfo command which prints the process information of given pid

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

7 history.c:
	add_in_history(): It inserts command entered by user into a queue data structure
	read_file(): It inserts commands stored in a file named store.txt into Queue whenever we run the a.out . It is used to show history of previous sessions.
	add_to_file(): used to store commands from queue into file store.txt
	show_history(): used to previously entered commands

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

8 watch.c:
	keyDown(): used to check whether a keyboard interrut was given or not
	rupt(): used to give number of keyboard interrupts. Prints output every n seconds and terminates on pressing q
	dirty(): used to print size of memory which is dirty every n second. Terminate on pressing q
	rupt(): used to decide whether argument given to nightwatch was interrupt or dirty. Calls function accordingly
