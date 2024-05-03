 # Building:
 ----------
 If you want to build a working .exe file of this collection of files,
 here are some of the things you can do.


### Dev-C++ users:
If you are a Dev-C++ user, all you have to do is paste all the files of the repo into a project file:
1. A project is file is made by pressing, "File" at the top left corner, and pressing "New".
2. It'll show 2 options, "Source File", and "New Project". Pick
 	"New Project", and then press the 2nd option you see, named
	"Console Application". 
3. Put the contents of "main.cpp" that you pulled from the repo,
  	and paste it in the first file you have.
4. From there, continue on making new files accordingly, and save
 	them according to their file extensions and names.
	(IMPORTANT FOR LINKING).

### For Non Dev-C++ users:

If you are using mingw, you have a built in script called "mingw32-make.exe" inside.
> First, You would want to make sure you have mingw installed and set in your environment path.

1. First, head over to vscode/any code editor you want.
2. Second, get a terminal that is already set to the directory where you compiled. Usually in vscode, yuo can just do Ctrl + J
3. and type in mingw32-make on the terminal
4. It'll take a while to build (depending on systems)
5. The final exe can be found on the preset 'build' folder
