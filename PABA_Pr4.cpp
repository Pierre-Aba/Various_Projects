/*
 * Class: CMSC140 20088
 * Instructor: Dr. Ahmed Tarek
 * Project #4
 * Description: (Give a brief description for Project)
 * Due Date: 11/14/2022
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Pierre Aba
*/
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;
int numOfEmployees();
int totDaysAbsent(int                                                                                     
	
	
	
	
	
-&);
double averageAbsent(int   &, int   &);

ofstream employees;//ofstream employees is a global variable to make sure all functions can access it.

//*****************************************
 // Function main                          
 //*****************************************

int main()
{
	cout << "Calculate the average number of days a company's employees are absent.\n" << endl;
	employees.open("employeeAbsences.txt");
	employees << "EMPLOYEE ABSENCE REPORT" << endl
		<< "employee id   days absent" << endl;

	int employeeCount = numOfEmployees();
	
	int totalDaysAbsent = 0, //Initialize totalDaysAbsent to zero to keep a running total.
		daysAbsent;
	for (int i = 0; i < employeeCount; i++)
	{
		totalDaysAbsent += totDaysAbsent(daysAbsent);
	}
	
	employees << "The " << employeeCount << " employees were absent a total of " << totalDaysAbsent
		<< " days." << endl << "The average number of days absent is "
		<< showpoint << fixed << setprecision(1) // To format the average days absent per employee
		<< averageAbsent(totalDaysAbsent, employeeCount) << " days." << endl << endl
		<< "Programmer: Pierre Aba";
	
	cout << "Programmer: Pierre Aba\n";
	
	
	employees.close();/*Good practice to close files.
					  unsaved data in file buffer can be saved to its file.*/
	system("pause");
	return 0;
}
//*****************************************
// Function numOfEmployees defined below,
// reads in the number of employees at a company,
// and uses a while loop to read in atleast a value of
// atleast one. The function returns the employees read in.                        
//*****************************************

int numOfEmployees()
{
	cout << "Please enter the number of employees in the company: ";
	int employees;
	cin >> employees;
	while (employees < 1) 
	{
		cout << "Please enter at least one employee. ";
		cin >> employees;
	}
	return employees;
}
//*****************************************
 // Function totDaysAbsent defined below,
 // reads in an employees ID and their days absent,
 // and writes it into the employeeAbsences text file.
 // The input for employees ID and days absent 
 // use while loops to validate the input, 
 // by only reading in positive values.                 
 //*****************************************

int totDaysAbsent(int & absent)
{
	
	cout << "Please enter an employee ID: ";
		int employeeID;
		cin >> employeeID;
		while (employeeID < 0)
		{
			cout << "An employee's ID is a positive integer.\n"
				<< "Please re-enter the employee's ID: ";
			cin >> employeeID;
		}
		employees  << "   " << setw(4) << employeeID;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> absent;
		while (absent < 0)
		{
			cout << "The number of days must not be negative.\n"
				<< "Please re-enter the number of days absent: ";
			cin >> absent;
		}
		employees << setw(10)  << absent << endl;
		return absent;

}

 //*****************************************
 // Function averageAbsent defined below, 
 // returns the average number of days absent 
 // for each employee.
 //*****************************************

double averageAbsent(int& total, int& employeeCount)
{
	return (total / static_cast<double>(employeeCount));
	/* static_cast<double> to return a double value,
	   and avoid integer division*/
}