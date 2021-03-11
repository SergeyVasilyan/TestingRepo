Description

Current hierarchy of the Project is:
	-bin -contains executable file and data files:
		- ifile - contains the input is the matrix of size [32 x 32 x 1],
		- ffile - contains filter the matrix of size [5 x 5 x 1],
		- ffile1 - contains filter the matrix of size [5 x 5 x 1].
	-obj - contains object files.
	-srs - contains source files:
		- filtr_matrix.h -  the FMatrix class header file, which create filter matrix object,
		- filtr_matrix.cpp - the FMatrix class cpp file,
		- image_matrix.h - the IMatrix class header file, which create input matrix object,
		- image_matrix.cpp - the IMatrix class cpp file,
		- main.cpp.
	-mkfiles -contains makefiles:
		-makefile_project - documents of this project.


FMatrix class
	Class members:
		data -3 dimensional matrix of integers shaped 5x5x1,which holds the filter matrix,
		filename - string,which holds the name of the file that contains the filter matrix,
	Class methods:
		- FMatrix - constructor, creates FMatrix object,
		- read_file:
			input:
				path - string , contains file name.
			output:
				Boolean value, which indicates is the data from the file is in the corresponding format or no.

			Detailed description:
				Checks the number of columns and rows.Reads the data line by line from the file.  After reading one line,
                                adds the value 'row_count' -> increments 'row_value', then checks if the number of the columns in the filter is 
                                equal to the number of  the elements in the  readen row, and then moves on to the next line.
                                And if everything is correct,adds file's data to three-dimensional mass.

		-chenge - changes the filter.


IMatrix class
        Class members:
                data -3 dimensional matrix of integers shaped 5x5x1,which holds the filter matrix,
                filename - string,which holds the name of the file that contains the filter matrix,
        Class method:
                - IMatrix - constructor, creates IMatrix object,
                - read_file:
                        input:
                                path - string , contains file name.
                        output:
				boolean value, which indicates is the data from the file is in the corresponding format or no.

			Detailed description:
				Checks the number of columns and rows.Reads the data line by line from the file.  After reading one line,
                                adds the value 'row_count' -> increments 'row_value', then checks if the number of the columns in the filter is
				equal to the number of  the elements in the  readen row, and then moves on to the next line.
                                And if everything is correct,adds file's data to three-dimensional mass.

Main

First we import the name of the file, where 'Input' matrix is stored․
Then we create an object of the class IMatrix. Then we input the name of the file, where the 'Filter' matrix is sorted 
and create an object of the class FMatrix.
Then we choose one of the four options:
                1.Dot product of two matrices.
                2.Change filte.
                3.Input new filter.
                4.Exit.

If the first option is chosen , then the function mult()function is called,
if the second option is chosen, then the change() function of the class FMatrix is called,
if the third option is chosen, a new filter is imported,
if the forth option is chosen, then we exit the program.
