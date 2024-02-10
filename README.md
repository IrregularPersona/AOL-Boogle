# Building:
# If you want to build a working .exe file of this collection of files, 
# here are some of the things you can do.
# a. Dev-C++ users:
#		If you are a Dev-C++ user, all you have to do is paste all the 
#		files of the repo into a project file. A project is file is made
#		by pressing, "File" at the top left corner, and pressing "New".
#		It'll show 2 options, "Source File", and "New Project". Pick 
#		"New Project", and then press the 2nd option you see, named 
#		"Console Application". Put the contents of "main.cpp" that you 
#		pulled from the repo, and paste it in the first file you have.
#		From there, continue on making new files accordingly, and save 
#		them according to their file extensions and names.
#		(IMPORTANT FOR LINKING).
# b. Visual Studio Code users:
#		If you are using Visual Studio Code as your IDE:
#			1. 	Figure out what compiler you have (either MinGW / GCC).
#			2. 	Figure out where that compiler is saved
#				(usually in your C:// drive).
#			3. 	Save all files that you pulled from the repo to
#				a SEPARATE folder that is INSIDE a COMPILER-CONFIGURED 
#				folder. (IMPORTANT)
#			4. 	Open VSCode, and open said folder.
#			5. 	Make a new file, aptly named "makefile.win", with .win 
#				being its extension.
#			6. 	If you are using a GCC compiler, copy this into the makefile:

CC = g++
CFLAGS = -Wall -Werror

all: my_program

my_program: main.o listnode.o trienode.o extrafunctions.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp listnode.h trienode.h extrafunctions.h
	$(CC) $(CFLAGS) -c -o $@ $<

listnode.o: listnode.cpp listnode.h
	$(CC) $(CFLAGS) -c -o $@ $<

trienode.o: trienode.cpp trienode.h
	$(CC) $(CFLAGS) -c -o $@ $<

extrafunctions.o: extrafunctions.cpp extrafunctions.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f my_program.exe *.o
	
#
#				If you are using a MinGW compiler, copy this:
#
				
CC = g++
CFLAGS = -Wall -Werror

all: my_program

my_program: main.o listnode.o trienode.o extrafunctions.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp listnode.h trienode.h extrafunctions.h
	$(CC) $(CFLAGS) -c -o $@ $<

listnode.o: listnode.cpp listnode.h
	$(CC) $(CFLAGS) -c -o $@ $<

trienode.o: trienode.cpp trienode.h
	$(CC) $(CFLAGS) -c -o $@ $<

extrafunctions.o: extrafunctions.cpp extrafunctions.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	del my_program.exe *.o
	
	
#			7. 	Once you're done with all that, go to your terminal at the 
#				bottom of your screen, and type in:
#				
#				make -f MakeFile
#				
#				Several object files will be created, and you can finally
#				run the final build of the program you pulled from the repo.
