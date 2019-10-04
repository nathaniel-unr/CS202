# Intro
My project successfully passes the test inputs. I developed this using g++, nano, and clang-format. 
The purpose of this program is to read in a file specified by the user through the command line. 
Then, the program should read 10 names from the file, each with a max length of 8 characters. 

# Use
When run, my program will prompt the user for the filename. 
After, it will load the names from the file in a 2D array and sort them by length and alphabetically, 
printing out the results to the standard out as it does so.

# Design
My program loads the data using the name specified through the terminal. 
The data is stored in a 2d character array. A dedicated function is used to print this data. 
Stored with the 2d array is an “order” array of ints to specify the order of names when printing. 
This exists so no copies of the 2d char array have to be made and so that switching two strings is a less intensive process. 
For sorting, a bubble sort function is used. It accepts a function pointer that tells it whether to swap two strings’ order. 

# Problems
One limitation my program has is its inability to read in files with names longer than 255. 
The instructions specified that the use of dynamic memory was disallowed, 
yet the program should be able to read in a file with a name that is an unspecified length. 
I used a buffer for the filename that is 256 chars in length.

Another limitation is how my program reads in filenames, 
as it fails to read in files that have spaces in their names because it uses std::cin. 

Another possible flaw in my program is styling. 
I tried to adhere to the C++ style used in the examples, but no standard style guide was provided. 
I ran my code through clang-format, but I am unsure about my naming style.

Another area where my program may have deviated from the instructions was the use of a function pointer for my sorting algorithm. 
The function pointier’s purpose is to provide a way to change the sorting algorithm logic without duplicating the entire sort algorithm, 
allowing me to use one function to sort both alphabetically and by length with no code duplication. 
It would be trivial to create copies of the sorting algorithm that inline the necessary logic, 
but it would require a fair amount of code duplication. 
I used function pointers in this instance because while the use of pointers are disallowed, 
the rule was most likely used in the context of dynamic memory as arrays are constructs that wrap pointers that were allowed in this context.

If given more time, I would document my code better. I would also try to read up on Google’s official C++ coding style so I can conform better to standards. 
I would also do more testing on a variety of different inputs to look for bugs.
