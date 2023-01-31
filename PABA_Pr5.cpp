/* Class: CMSC140 20088
* Instructor : Dr. Ahmed Tarek
*Project 5
* Description : Write a program that simulates a magic square
using 3 one dimensional parallel arrays of integer type.
* Due Date : 12/05/2022
*I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here : Pierre Aba*/


#include<iostream>
#include<fstream>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[] , int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

//*****************************************
 // Function main                          
 //*****************************************

int main()
{


	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
	char repeat;

	do //To perform the test atleast once
	{
		cout << "\n**********Lo Shu Magic Square Test**********\n\n";

		fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

		showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

		bool isLoShu = isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

		if (isLoShu == true)
		{
			cout << "\nThis is a Lo Shu magic square.";
		}
		else
		{
			cout << "\nThis is not a Lo Shu magic square.";
		}

		cout << "\n\n\nDo you want to try again? Type y for yes, and n for no.";
		cin >> repeat;

	} while ((repeat == 'y') || (repeat == 'Y'));

	cout << "\nPierre Aba\nProject 5\nDue 12/05\n";


	system("pause");
	return 0;
}

//*****************************************
 // Function fillArray asks for and reads in 
 // numbers for each array argument, which act
 // as rows of the magic Square.                          
 //*****************************************

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int num;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the number for row 0 and column " << i << " :";
		cin >> num;
		arrayRow1[i] = num;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the number for row 1 and column " << i << " :";
		cin >> num;
		arrayRow2[i] = num;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the number for row 2 and column " << i << " :";
		cin >> num;
		arrayRow3[i] = num;
	}
}

//*****************************************
 // Function showArray displays the elements
 // of the three array arguments in order of
 // input in a 3 by 3 format.        
 //*****************************************

void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow3[i] << " ";
	}
}

//*****************************************
 // Function checkRange returns false
 // if any of the elements of the three arrays
 // fall out of the range of 1 through 9.
 // Otherwise the function returns true.                         
 //*****************************************

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		if (!((arrayRow1[i] >= min) && (arrayRow1[i] <= max)))
			return false;
		if (!((arrayRow2[i] >= min) && (arrayRow2[i] <= max)))
			return false;
		if (!((arrayRow3[i] >= min) && (arrayRow3[i] <= max)))
			return false;
	}
	return true;

}

//*****************************************
 // Function checkUnique stores the value of
 // each element in the three arrays in an
 // array. If the new array has duplicate values,
 // the function returns false.
 // Otherwise the function returns true.                       
 //*****************************************

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int checkAll[ROWS * COLS];

	for (int i = 0; i < size; i++)
	{
		checkAll[i] = arrayRow1[i];
	}

	for (int i = 0; i < size; i++)
	{
		checkAll[i + 3] = arrayRow2[i];
	}

	for (int i = 0; i < size; i++)
	{
		checkAll[i + 6] = arrayRow3[i];
	}

	int match;

	for (int i = 0; i < size * ROWS; i++)
	{
		int match = checkAll[i];
		for (int j = i + 1; j < size * ROWS; j++)
		{
			if (checkAll[j] == match)
				return false;
		}
	}

	return true;
}

//*****************************************
 // Function checkRowSum totals the value
 // of each row and returns false if the
 // row doesn't equal 15. 
 // Otherwise the function returns true.                  
 //*****************************************

bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int row1Total = 0, row2Total = 0, row3Total = 0;
	for (int i = 0; i < size; i++)
	{
		row1Total += arrayrow1[i];
		row2Total += arrayrow2[i];
		row3Total += arrayrow3[i];
	}
	if ((row1Total != 15) || (row2Total != 15) || (row3Total != 15))
		return false;

	return true;
}

//*****************************************
 // Function checkColSum totals the value
 // of each column and returns false if the
 // column doesn't equal 15.
 // Otherwise the function returns true.                         
 //*****************************************

bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int columnTotal[ROWS] = { 0 };
	for (int i = 0; i < size; i++)
	{
		columnTotal[i] += arrayrow1[i] + arrayrow2[i] + arrayrow3[i];

		if (columnTotal[i] != 15)
			return false;
	}

	return true;
}

//********************************************
 // Function checkDiagSum returns false if
 // either diagonals of the magic square don't
 // equal 15. Otherwise it returns true.                       
 //*******************************************

bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int diagSum = arrayrow1[size - size] + arrayrow2[size - 2] + arrayrow3[size - 1];
	if (diagSum != 15)
	{
		return false;
	}
	else
	{
		diagSum = arrayrow1[size - 1] + arrayrow2[size - 2] + arrayrow3[size - size];
		if (diagSum != 15)
		{
			return false;
		}
	}
	return true;
}

//*****************************************
 // Function isMagicSquare returns true
 // if all the other functions validating
 // the requirements of a magic square
 // return true, else it returns false                          
 //*****************************************

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	
	int min = MIN;
	int max = MAX;
	bool range = checkRange(arrayRow1, arrayRow2, arrayRow3, size, min, max);
	bool unique = checkUnique(arrayRow1, arrayRow2, arrayRow3, size);
	bool rowSum = checkRowSum(arrayRow1, arrayRow2, arrayRow3, size);
	bool colSum = checkColSum(arrayRow1, arrayRow2, arrayRow3, size);
	bool diagSum = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);
	if ((range == true) && (unique == true) && (rowSum == true) && (colSum == true) && (diagSum == true))
	{
		return true;
	}
	else
	{
		return false;
	}
}