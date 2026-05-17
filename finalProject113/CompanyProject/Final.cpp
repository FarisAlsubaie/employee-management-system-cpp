#include <iostream>
#include <fstream>
#include<string> 
#include<iomanip>
using namespace std;

string fName[20];
string lName[20];
string phone[20];
string eid[20];
string dep[20];
int year[20];
double sal[20];
char gen[20];

ifstream in, infile;
ofstream out,outfile;
string firstName, lastName, phoneNum, depart, id;
int  birthYear;
double salary;
char gender;


//int count  = 0;
void   createCompany()
{



	infile.open("dataProject.txt");
	if (infile.fail())
	{
		cerr << "enable to find the file " << endl;
		exit(1);
	}
	int count = 0;
	string str;
	while (getline(infile, str)) {
		count++;
	}
	infile.close();

	infile.open("dataProject.txt");
	for (int i = 0; i < count; i++)
	{
		infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];

	}
	cout << endl;
	string temp;
	int temp1;
	double temp2;
	char temp3;
	// now sorting data accoring to lname
	for (int i = 0; i < count-1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (fName[i] > fName[j])
			{
				//cout << "chnage happan" << "1 "<<lName[i] << "2. "<<lName[i];
				temp = lName[i];
				lName[i] = lName[j];
				lName[j] = temp;

				temp = fName[i];
				fName[i] = fName[j];
				fName[j] = temp;

				temp = phone[i];
				phone[i] = phone[j];
				phone[j] = temp;

				temp = eid[i];
				eid[i] = eid[j];
				eid[j] = temp;

				temp = dep[i];
				dep[i] = dep[j];
				dep[j] = temp;

				temp1 = year[i];
				year[i] = year[j];
				year[j] = temp1;

				temp2 = sal[i];
				sal[i] = sal[j];
				sal[j] = temp2;

				temp3 = gen[i];
				gen[i] = gen[j];
				gen[j] = temp3;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{

		cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << " " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];//delate
		cout << endl;//dletae

	}

	infile.close();


	cout << endl << "The total Number of Employees are: " << count << endl;


}

//HireStaff function add an new employee data into the txt file
void HireStaff()
{


	firstName = "", lastName = "", depart = "", phoneNum = "", id = "", birthYear = 0, salary = 0;


	infile.open("dataProject.txt");// opening file in append mode so that the previous data is not deleted
	if (infile.fail())
	{
		cerr << "enable to find the file " << endl;
		exit(1);
	}
	string str;
	int count = 0;
	while (getline(infile, str)) {
		count++;
	}
	count -= 1;
	if (count >= 20)
	{
		cout << "the maximum number of employees reached " << endl;
		cout << "in order to to hair staff you must fire at least one to hair" << endl;
		cout << "the number of the currnt employees     " << count << endl;
		exit(1);
	}
	out.open("dataProject.txt", ios::app);// opening file in append mode so that the previous data is not deleted



	cout << "Enter First name of Employee:";
	cin >> firstName;
	cout << endl;
	cout << "Enter Last name of Employee: ";
	cin >> lastName;
	cout << endl;
	cout << "Enter Department of Employee: ";
	cin >> depart;
	cout << endl;
	while (id.length() != 6) // loop checks if the lenth of id is 6 or not if it is not 6 user has to enter it again
	{
		cout << "Enter Employee ID (6 digits): ";
		cin >> id;
		cout << endl;
	}

	cout << "Enter salary of this Employee: ";
	cin >> salary;
	cout << endl;
	while (phoneNum.length() != 10) // loop checks if the lenth of phone number is 10 or not if it is not 10 user has to enter it again
	{

		cout << "Enter Phone Number of Employee (10 digits) : ";
		cin >> phoneNum;
		cout << endl;
	}
	cout << "Enter Gender (F for Female, M for Male) : ";
	cin >> gender;
	cout << endl;
	while (birthYear < 1960)//  loop check if the birthYear should be greater than 1960
	{

		cout << "Enter Birth Year (Not less than 1960) : ";
		cin >> birthYear;
		cout << endl;
	}
	//aftert taking all the data from the user of new employee 
	// the date is written in the file 

	out << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
		<< phoneNum << " " << gender << " " << birthYear;


	out.close();
	//closing file




}
void fireStaff()
{
	int ch = 0;
	ofstream outfile;
	ifstream infile;
	infile.open("dataProject.txt");// checkinh the phone number or id there  or not 
	outfile.open("newdata.txt");// send all staff that not you faired 
	string line;
	int count = 0;

	cout << "How you wnat to remove Employee?:\n";
	cout << "1.using Phone number" << endl;
	cout << "2.using Employee ID" << endl;

	string delid;//to store the id OR phone number  in string delid 
	cin >> ch;
	if (ch == 1)
	{
		//system("cls");
		while (delid.length() != 10)//loop to check the id not less or more than 6 number 
		{
			cout << "Enter the phone number" << endl;
			cin >> delid;
			cout << endl;
		}
		for (int i = 0; i < 20; i++)// change to 20 to number of empolyees in file 
		{
			infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];
			if (phone[i] == delid && (dep[i] == "Exec" || dep[i] == "exec"))
			{
				cout << "NOT authorized to fire EXECUTIVE employees" << endl;
				exit(1);
			}
			else if (phone[i] != delid)
			{
				outfile << fName[i] << " " << lName[i] << " " << dep[i] << "  " << eid[i] << " " << sal[i] << "  " << phone[i] << "  " << gen[i] << "  " << year[i] << endl;
			}
		}
	}

	else if (ch == 2)
	{
		while (delid.length() != 6)//loop to check the id not less or more than 6 number 
		{
			cout << "Enter the ID number" << endl;
			cin >> delid;
			cout << endl;
		}
		for (int i = 0; i < 20; i++)// change to 20 to number of empolyees in file 
		{
			infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];
			if (eid[i] == delid && (dep[i] == "Exec" || dep[i] == "exec"))

			{
				cout << "NOT authorized to fire EXECUTIVE employees" << endl;
				exit(1);
			}
			else if (eid[i] != delid)
			{
				outfile << fName[i] << " " << lName[i] << " " << dep[i] << "  " << eid[i] << " " << sal[i] << "  " << phone[i] << "  " << gen[i] << "  " << year[i] << endl;
			}
		}

	}
	outfile.close();
	infile.close();

	if (remove("dataProject.txt") == 0)
	{
		cout << "The employee that his/her phone number is " << delid << "has been removed " << endl;

	}
	else
		cout << "cant delate file " << endl;

	if (rename("newdata.txt", "dataProject.txt") != 0)
	{
		perror("There is an error!!!");
	}

	else
	{
		cout << "The operation was done successfully" << endl;
	}

}
void SortEmployee()
{
	char choice;
	// asks the user which attribute they want to use while sorting
	cout << "Enter your choice how you want to sort list of Employees?\n"
		<< "1. By First Name\n"
		<< "2. By Last Name\n"
		<< "3. By Employee Id\n"
		<< "4. Phone Number\n"
		<< "5. Birth Year\n\n";
	cin >> choice;
	cout << endl;

	infile.open("dataProject.txt");// to store number of line which is count number of Employee. 
	if (!infile)
	{
		cout << "unable to open the file" << endl;
		exit(1);
	}
	string ch;
	int count = 0;
	while (getline(infile, ch))
	{
		count++;
	}

	


	infile.close();
	// makes the dynamic arrays equal to number of data in file
	string* fname = new string[count];
	string* lname = new string[count];
	string* phone = new string[count];
	string* dep = new string[count];
	string* eid = new string[count];
	int* year = new int[count];
	double* sal = new double[count];
	char* gen = new char[count];



	infile.open("dataProject.txt");//opens file secound time to store a data 

	
		for (int i = 0; i < count; i++)
		{
			infile >> fname[i] >> lname[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];//store data in the arrays
		}
	

	infile.close();

	string temp;
	int temp1;
	double temp2;
	char temp3;
	
	if (choice == '1')
	{
	
		for (int i = 0; i < count - 1; i++)
		{
			
			for (int j = i + 1; j < count; j++)
			{
			
				if (fname[i] > fname[j])
				{
			
					temp = fname[i];
					fname[i] = fname[j];
					fname[j] = temp;

					temp = lname[i];
					lname[i] = lname[j];
					lname[j] = temp;

					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}
		// after sorting data it will simply print the sorted data


		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";
		for (int i = 0; i < count; i++)
		{
			cout << " " << fname[i] << "\t    " << lname[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
			cout << endl;
		}

		cout << endl << "The total Number of Employees are: " << count << endl;
	}
	else if (choice == '2')
	{

		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (lname[i] > lname[j])
				{

					temp = lname[i];
					lname[i] = lname[j];
					lname[j] = temp;

					temp = fname[i];
					fname[i] = fname[j];
					fname[j] = temp;


					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}

		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";
		for (int i = 0; i < count; i++)
		{
			cout << " " << fname[i] << "\t    " << lname[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
			cout << endl;
		}

		cout << endl << "The total Number of Employees are: " << count << endl;
	}
	else if (choice == '3')
	{

		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (eid[i] > eid[j])
				{
					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = lname[i];
					lname[i] = lname[j];
					lname[j] = temp;

					temp = fname[i];
					fname[i] = fname[j];
					fname[j] = temp;


					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;


					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}

		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";
		for (int i = 0; i < count; i++)
		{
			cout << " " << fname[i] << "\t    " << lname[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
			cout << endl;
		}

		cout << endl << "The total Number of Employees are: " << count << endl;

	}
	else if (choice == '4')
	{

		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (phone[i] < phone[j])
				{

					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = lname[i];
					lname[i] = lname[j];
					lname[j] = temp;

					temp = fname[i];
					fname[i] = fname[j];
					fname[j] = temp;




					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}

		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";
		for (int i = 0; i < count; i++)
		{
			cout << " " << fname[i] << "\t    " << lname[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
			cout << endl;
		}

		cout << endl << "The total Number of Employees are: " << count << endl;
	}
	else if (choice == '5')
	{


		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (year[i] > year[j])
				{

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = lname[i];
					lname[i] = lname[j];
					lname[j] = temp;

					temp = fname[i];
					fname[i] = fname[j];
					fname[j] = temp;


					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;


					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;


					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}

		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";
		for (int i = 0; i < count; i++)
		{
			cout << " " << fname[i] << "\t    " << lname[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
			cout << endl;
		}

		cout << endl << "The total Number of Employees are: " << count << endl;
	}
	else
	{
		cout << "Wrong Choice, Enter again!\n\n";
		SortEmployee();
	}
	infile.close();
}
void HighLowSalary()
{
	char opt, cat;
	double sal;
	cout << "Which category you want to search?\n"
		<< "1. Male\n"
		<< "2. Female\n\n";
	// asks user if they want male data or female (filtering data gender wise)
	cin >> opt;
	if (opt == '1')
	{
		system("cls");
		char g = 'M';
		cout << "Enter salary amount: ";
		cin >> sal;
		cout << "\nHow you wanted to select Employee based on salary?\n"
			<< "1. Above than this amount.\n"
			<< "2. Lower than this amount.\n\n";
		// asks if user want to print data higher from a specific value or lesser from it
		cin >> cat;
		cout << endl << endl;
		if (cat == '1')
		{
			ifstream check;
			check.open("dataProject.txt");
			cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

			while (!check.eof())
			{
				check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;// read data line by line

				if ((salary > sal) && (gender == g))// check gender and salary if it is greater than the specific amount the user has enter if yes it prints data
				{
					cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
					cout << endl;

				}

			}

			check.close();// close file

		}

		else if (cat == '2')
		{
			ifstream check;
			check.open("dataProject.txt");
			cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

			while (!check.eof())
			{
				check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

				if ((salary < sal) && (gender == g)) // check gender and salary if it is less than the specific amount the user has enter if yes it prints data

				{
					cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
					cout << endl;

				}

			}
			check.close();
		}

	}
	// same code for the other gender
	else if (opt == '2')
	{
		system("cls");
		char g = 'F';
		cout << "Enter salary amount: ";
		cin >> sal;
		cout << "How you wanted to select Employee based on salary?\n"
			<< "1. Above than this amount.\n"
			<< "2. Lower than this amount.\n\n";
		cin >> cat;
		cout << endl << endl;

		if (cat == '1')
		{
			ifstream check;
			check.open("dataProject.txt");
			cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

			while (!check.eof())
			{
				check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

				if ((salary > sal) && (gender == g))
				{
					cout << " " << firstName << "\t     " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
					cout << endl;

				}

			}
			check.close();
		}

		else if (cat == '2')
		{
			ifstream check;
			check.open("dataProject.txt");
			cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

			while (!check.eof())
			{
				check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

				if ((salary < sal) && (gender == g))
				{
					cout << " " << firstName << "\t     " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
					cout << endl;

				}

			}
			check.close();
		}


	}
	else
	{
		cout << "Wrong selection, Enter 1 for Male and 2 for Female.\n";
		HighLowSalary();
	}
}

//EmployeeGender function prints data of gender or female
void EmployeeGender()
{
	int line = 0;
	char ch;
	cout << "Which category you want to search?\n"
		<< "1. Male\n"
		<< "2. Female\n\n"
		<< " Enter 1, M or m for male\n"
		<< " Enter 2, F or f for female\n";
	// asks the user to select between male or female
	cin >> ch;
	int count = 0;
	if (ch == '1' || ch == 'M' || ch == 'm')
	{//if user select male
		char g = 'M';
		ifstream check;
		check.open("dataProject.txt");//opens file
		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

		while (!check.eof())
		{
			check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;//read data line by line

			if (gender == g)//checks if data is of male if yes then prints it
			{
				cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;

				cout << endl;
				count++;//count the number of male data

			}

		}
		check.close();
		cout << "\nTotal Employees of this category = " << count << ".\n\n";
	}
	else if (ch == '2' || ch == 'F' || ch == 'f')
	{//if user select female 
		char g = 'F';
		ifstream check;

		check.open("dataProject.txt");//opens file
		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

		while (!check.eof())
		{
			check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;// reads data line by line
			if (gender == g)  //checks if data is of female if yes then prints it
			{
				cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
				cout << endl;
				count++;//count female data

			}

		}
		check.close();
		cout << "\nTotal Employees of this category = " << count << ".\n\n";
	}
	else
	{
		cout << "Wrong selection. Enter again\n\n";
		// if the user select an invalid option again calls the functionn
		EmployeeGender();
	}

}
//prints the employess that are eligible for bonus
void EmployeeBonus()
{
	int yearBonus = 0;
	while (yearBonus < 1960)// checks if age is grater than 1960 or not

	{
		cout << "Enter age in years ( Not less than 1960)\n";
		cin >> yearBonus;
	}
	int i = 0;
	int count = 0;
	infile.open("dataProject.txt");
	cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

	while (!infile.eof())
	{

		infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];// reads data line by line


		if (year[i] >= yearBonus)//checks if year in the data is greater then equal to the year that user entered
		{
			cout << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
			cout << endl;
			count++;
			//count the number of employes eligible	

		}
		i++;
	}
	infile.close();//close file
	cout << "\nThese Employees are eligible for Bonus\n";
	cout << "\nTotal Employees eligible for bonus are = " << count << ".\n\n";
}
void MinMaxDepartment()
{
	char m;
	cout << "\nHow you want to see number  of Employees by Department?\n"
		<< "1. Department with maximum Employees?\n"
		<< "2. Department with minimum Employees?\n"
		<< " Enter 1 or 2.\n\n";
	cin >> m;
	int acct = 0, exec = 0, sales = 0, hr = 0, it = 0, mkt = 0;

	ifstream check;
	check.open("dataProject.txt");
	cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

	while (!check.eof())
	{
		check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

		if (depart == "Acct")
		{

			acct++;

		}
		else if (depart == "Exec")
		{

			exec++;

		}
		else if (depart == "Sales")
		{

			sales++;

		}
		else if (depart == "HR")
		{

			hr++;

		}
		else if (depart == "IT")
		{

			it++;

		}
		else if (depart == "Mkt")
		{

			mkt++;

		}

	}
	check.close();
	int temp;
	int arr[6];
	arr[0] = acct;
	arr[1] = exec;
	arr[2] = sales;
	arr[3] = hr;
	arr[4] = it;
	arr[5] = mkt;
	string department[6] = { "Acct", "Exec", "Sales", "HR", "IT", "Mkt" };
	string d;
	for (int i = 0; i < 6 - 1; i++)// change  to 5 just as  fine 
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				d = department[i];
				department[i] = department[j];
				department[j] = d;
			}
		}
	}

	if (m == '1')
	{
		if (m == '1')
		{
			cout << "The maximum Number of Employees is in department: " << department[5] << endl;
			cout << "The number of Employees in this depatment is/are: " << arr[5] << endl << endl;

		}
		else if (m == '2')
		{

			cout << "The minimum Number of Employees is in department: " << department[0] << endl;
			cout << "The number of Employees in this depatment is/are: " << arr[0] << endl << endl;

		}
		else
		{
			cout << "Wrong Choice!\n\n";
			MinMaxDepartment();
		}
	
	}
}
// UpdateEmployee function updates the  data of an existing employee
/*void UpdateEmployee()
{
	int c;
	ifstream infile;
	infile.open("dataProject.txt");
	ofstream newout;
	newout.open("new.txt");
	char ch, w = 'y';// w will be yes for the first run and will be updateed once the loop done , user will have the choice yes or no .ch for 1 or 2 either by phone or id 
	string emp;// emp for id number that user will entered. ph for phone number 
	string line;
	int count = 0;
	while (getline(infile, line))
	{

		infile >> fName[count] >> lName[count] >> dep[count] >> eid[count] >> sal[count] >> phone[count] >> gen[count] >> year[count];
		count++;
	}
	count -= 1;

	while (w == 'y')
	{
		cout << "How you want to find the information of the  Employees?\n"
			<< "1. By Employee Id\n";
		//<< "2. By Phone Number\n"
		//<< " Enter 1 or 2\n\n";
	//asks if we want to search a

		cin >> ch;
		if (ch == '1')
		{
			system("cls");
			cout << "Enter Employee Id: ";
			cin >> emp;
			cout << endl << endl;


			//using two files to update a record 
			//fisrt we start reading data line by line from file 1 and the same time we write data to new file
			//between copying(reading) and writing data we check that the data we are copying is not the data we want to update

			//after copying it sucessfully we rename the new file with the name of the first file

			for (int i = 0; i < count; i++)
			{


				if (eid[i] == emp)
				{
					cout << "This Employee has this  " << emp << endl;
					cout << fName[i] << "  " << lName[i] << "  " << dep[i] << "  " << eid[i] << "  " << "  " << sal[i] << "  " << "  " << phone[i] << "  " << "  " << gen[i] << "  " << year[i] << endl;
					cout << endl;


					c = 0;
					cout << "Which information you want to alter/update?\n"
						<< "1. First Name\n"
						<< "2. Last Name\n"
						<< "3. Department\n"
						<< "4. Employee ID number  \n"
						<< "5. Phone Number\n"
						<< "6. Salary\n"
						<< "7. Gender\n"
						<< "8. BirthYear\n"
						<< " Enter from 1-8\n\n";
					cin >> c;


					if (c == 1)

					{
						cout << "Enter First Name: ";
						cin >> fName[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
						//wrtes that record to new file but with the updated value
						//same happens for all the other option
					}

					else if (c == 2)
					{
						cout << "Enter last Name: ";
						cin >> lName[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
					}
					else if (c == 3)
					{
						cout << "Enter the department : ";
						cin >> dep[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
					}
					else if (c == 4)
					{
						cout << "Enter the Employee ID   : ";
						cin >> eid[i];
						emp = eid[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
					}
					else if (c == 5)
					{
						cout << "Enter the Salary   : ";
						cin >> sal[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
					}
					else if (c == 6)
					{
						cout << "Enter the    phone		Number : ";
						cin >> phone[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
					}
					else if (c == 7)
					{
						cout << "Enter the   gender : ";
						cin >> gen[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
					}
					else// if (c == 8)
					{
						cout << "Enter the   year : ";
						cin >> year[i];
						newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						newout << endl;
						cout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
						cout << endl;
					}

				}
				else if (eid[i] != emp)
				{
					//cout << "Employee Not found " << endl;
					//infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];
					newout << fName[i] << " " << lName[i] << " " << dep[i] << " " << eid[i] << "  " << sal[i] << " " << phone[i] << " " << gen[i] << " " << year[i];
					newout << endl;
				}


			}
		}
		newout.close();
		infile.close();
		//close both files

		remove("dataProject.txt"); //del the old file
		rename("new.txt", "dataProject.txt");//rename the new file with file one name






		cout << "You further want to modify? (Enter y for yes and n for no)\n";
		cin >> w;
		cout << endl;

	}
}
*/
// UpdateEmployee function updates the data of an existing employee
void UpdateEmployee()
{
	char ch, w = 'y';
	string emp, ph;
	while (w == 'y')
	{
		cout << "How you want to find  information of Employees?\n"
			<< "1. By Employee Id\n"
			<< "2. By Phone Number\n"
			<< " Enter 1 or 2\n\n";
		//asks if we want to search a

		cin >> ch;
		if (ch == '1')
		{
			
			while (emp.length() != 6) // loop checks if the lenth of id is 6 or not if it is not 6 user has to enter it again
			{
				system("cls");
				cout << "Enter Employee ID (6 digits): ";
				cin >> emp;
				cout << endl;
			}
			
			cout << endl << endl;
			ifstream oldin;
			oldin.open("dataProject.txt");
			ofstream newout;
			newout.open("new.txt");
			//using two files to update a record 
			//fisrt we start reading data line by line from file 1 and the same time we write data to new file
			//between copying(reading) and writing data we check that the data we are copying is not the data we want to update

			//after copying it sucessfully we ewname the new file with the name of the first file

			while (!oldin.eof())
			{
				oldin >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;//reads data line by line

				if (id != emp)
				{// copyies all the data to the new file except the data of the employee we want to update


					newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
						<< phoneNum << " " << gender << " " << birthYear;
					newout << endl;
				}
				else if (id == emp)
				{ //after finding the line withe record we want to update

					char  c;



					cout << "Which information you want to alter/update?\n"
						<< "1. First Name\n"
						<< "2. Last Name\n"
						<< "3. Department\n"
						<< "4. Phone Number\n"
						<< "5. Salary\n"
						<< "6. Gender\n"
						<< "7. BirthYear\n"
						<< " Enter from 1-7\n\n";

					// askes user what part of the record wants to update
					cin >> c;
					if (c == '1')
					{
						cout << "Enter First Name: ";
						string name;
						cin >> name;
						newout << name << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
						//wrtes that record to new file but with the updated value
						//same happens for all the other option
					}
					else if (c == '2')
					{
						cout << "Enter Last Name: ";
						string name;
						cin >> name;
						newout << firstName << " " << name << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '3')
					{
						cout << "Enter Department name: ";
						string dep;
						cin >> dep;
						newout << firstName << " " << lastName << " " << dep << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '4')
					{
						cout << "Enter Phone Number: ";
						string p;
						cin >> p;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< p << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '5')
					{
						cout << "Enter Salary: ";
						double sal;
						cin >> sal;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << sal << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '6')
					{
						cout << "Enter gender: ";
						char g;
						cin >> g;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << g << " " << birthYear;
						newout << endl;
					}
					else if (c == '7')
					{
						cout << "Enter Birth Year: ";
						int b;;
						cin >> b;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << b;
						newout << endl;

					}

				}



			}

			newout.close();
			oldin.close();
			//close both files

			remove("dataProject.txt"); //del the old file
			rename("new.txt", "dataProject.txt");//rename the new file with file one name

		}

		//option 2 is same as above
		else if (ch == '2')
		{
			system("cls");
			cout << "Enter phone number of Employee: ";
			cin >> ph;
			cout << endl << endl;
			ifstream oldin;
			oldin.open("dataProject.txt");
			ofstream newout;
			newout.open("new.txt");
			//using two files to update a record 
		//fisrt we start reading data line by line from file 1 and the same time we write data to new file
		//between copying(reading) and writing data we check that the data we are copying is not the data we want to update 

		//after copying it sucessfully we ewname the new file with the name of the first file

			while (!oldin.eof())
			{
				oldin >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;// reading line by line

				if (phoneNum != ph)
				{


					newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
						<< phoneNum << " " << gender << " " << birthYear;
					newout << endl;
				}
				else if (phoneNum == ph)
				{

					char  c;

					cout << "Which information you want to alter/update?\n"
						<< "1. First Name\n"
						<< "2. Last Name\n"
						<< "3. Department\n"
						<< "4. Phone Number\n"
						<< "5. Salary\n"
						<< "6. Gender\n"
						<< "7. BirthYear\n"
						<< " Enter from 1-7\n\n";
					cin >> c;
					if (c == '1')
					{
						cout << "Enter First Name: ";
						string name;
						cin >> name;
						newout << name << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '2')
					{
						cout << "Enter Last Name: ";
						string name;
						cin >> name;
						newout << firstName << " " << name << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '3')
					{
						cout << "Enter Department name: ";
						string dep;
						cin >> dep;
						newout << firstName << " " << lastName << " " << dep << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '4')
					{
						cout << "Enter Phone Number: ";
						string p;
						cin >> p;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< p << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '5')
					{
						cout << "Enter Salary: ";
						double sal;
						cin >> sal;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << sal << " "
							<< phoneNum << " " << gender << " " << birthYear;
						newout << endl;
					}
					else if (c == '6')
					{
						cout << "Enter gender: ";
						char g;
						cin >> g;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << g << " " << birthYear;
						newout << endl;
					}
					else if (c == '7')
					{
						cout << "Enter Birth Year: ";
						int b;;
						cin >> b;
						newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
							<< phoneNum << " " << gender << " " << b;
						newout << endl;

					}

				}



			}

			newout.close();
			oldin.close();

			remove("dataProject.txt");
			rename("new.txt", "dataProject.txt");
		}

		else
		{
			cout << "Wrong Choice, Enter again.\n\n";
			UpdateEmployee();
		}
		cout << "You further want to modify? (Enter y for yes and n for no)\n";
		cin >> w;
		cout << endl << endl;
	}
}
void minMaxSalary()
{

	infile.open("dataProject.txt");
	string str;
	int count = 0;
	while (getline(infile, str))
	{

		count++;

	}
	infile.close();
	infile.open("dataProject.txt");//opens file secound time to store a data 

	while (!infile.eof())
	{
		for (int i = 0; i < count; i++)
		{
			infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];//store data in the arrays
		}
	}

	infile.close();


	int opt;
	cout << "make choice between 1,2" << endl;
	cout << "1. Max salary " << endl;
	cout << "2. Min  salary" << endl;
	cin >> opt;
	
	




	string temp;
	int temp1;
	double temp2;
	char temp3;
	//according  to the choice seleted above sort data 
	// example if choice was 1 then it will sort data accoring to first name and so on 
	if (opt == 1)
	{

		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (sal[i] <sal[j])
				{

					temp = fName[i];
					fName[i] = fName[j];
					fName[j] = temp;

					temp = lName[i];
					lName[i] = lName[j];
					lName[j] = temp;

					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}
		
		cout << "the Employees with  highest salray is " << endl;
		cout << " " << fName[0] << "\t    " << lName[0] << "\t " << dep[0] << "\t  " << eid[0] << "\t " << sal[0] << "\t  " << phone[0] << "\t" << gen[0] << "\t " << year[0];
		cout << endl;
	
}
	if (opt == 2)
	{

		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (sal[i] > sal[j])
				{

					temp = fName[i];
					fName[i] = fName[j];
					fName[j] = temp;

					temp = lName[i];
					lName[i] = lName[j];
					lName[j] = temp;

					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}

		cout << "the Employees with  lowest  salray is " << endl;
		cout << " " << fName[0] << "\t    " << lName[0] << "\t " << dep[0] << "\t  " << eid[0] << "\t " << sal[0] << "\t  " << phone[0] << "\t" << gen[0] << "\t " << year[0];
		cout << endl;

	}


}
void EmployeesAge ()
{

	infile.open("dataProject.txt");
	string str;
	int count = 0;
	while (getline(infile, str))
	{

		count++;

	}
	infile.close();
	infile.open("dataProject.txt");//opens file secound time to store a data 

	while (!infile.eof())
	{
		for (int i = 0; i < count; i++)
		{
			infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];//store data in the arrays
		}
	}

	infile.close();


	int opt;
	cout << "make choice between 1,2" << endl;
	cout << "1.Oldest Employees Age" << endl;
	cout << "2.Youngest Employees Age" << endl;
	cin >> opt;






	string temp;
	int temp1;
	double temp2;
	char temp3;
	//according  to the choice seleted above sort data 
	// example if choice was 1 then it will sort data accoring to first name and so on 
	if (opt == 1)
	{

		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (year[i] > year[j])
				{

					temp = fName[i];
					fName[i] = fName[j];
					fName[j] = temp;

					temp = lName[i];
					lName[i] = lName[j];
					lName[j] = temp;

					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}

		cout << "this Employees is the yongest in the company  " << endl;
		cout << " " << fName[0] << "\t    " << lName[0] << "\t " << dep[0] << "\t  " << eid[0] << "\t " << sal[0] << "\t  " << phone[0] << "\t" << gen[0] << "\t " << year[0];
		cout << endl;

	}
	if (opt == 2)
	{

		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (year[i] < year[j])
				{

					temp = fName[i];
					fName[i] = fName[j];
					fName[j] = temp;

					temp = lName[i];
					lName[i] = lName[j];
					lName[j] = temp;

					temp = phone[i];
					phone[i] = phone[j];
					phone[j] = temp;

					temp = eid[i];
					eid[i] = eid[j];
					eid[j] = temp;

					temp = dep[i];
					dep[i] = dep[j];
					dep[j] = temp;

					temp1 = year[i];
					year[i] = year[j];
					year[j] = temp1;

					temp2 = sal[i];
					sal[i] = sal[j];
					sal[j] = temp2;

					temp3 = gen[i];
					gen[i] = gen[j];
					gen[j] = temp3;
				}
			}
		}

		cout << "this Employees is the yongest in the company  " << endl;
		cout << " " << fName[0] << "\t    " << lName[0] << "\t " << dep[0] << "\t  " << eid[0] << "\t " << sal[0] << "\t  " << phone[0] << "\t" << gen[0] << "\t " << year[0];
		cout << endl;

	}


}
void AboveBelowAveSalary()
{
	infile.open("dataProject.txt");
	string str;
	int count = 0;
	while (getline(infile, str))
	{

		count++;

	}
	infile.close();
	infile.open("dataProject.txt");//opens file secound time to store a data 
	while (!infile.eof())
	{
		for (int i = 0; i < count; i++)
		{
			infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];//store data in the arrays
		}
	}

	infile.close();
	
	int opt;
	cout << "make choice between 1,2" << endl;
	cout << "1. above the avarage salary " << endl;
	cout << "2. below the avarage   salary" << endl;
	cin >> opt;
	double ave = 0;
	for (int i = 0; i < count; i++)
	{
		ave += sal[i];

	}
	
	ave /= count;
	cout << "the average of salalry is " << ave << endl;
	cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

	int temp = 0;
	if (opt == 1)
	{
		
		for (int i=0;i<count ;i++)
		{
			
			if (sal[i] >=ave) 
			{
				
				cout << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i] << endl;
				temp++;
			}
		}

	}

	else if (opt == 2)
	{
		

		for (int i = 0; i < count; i++)
		{
			if (sal[i] <= ave)
			{
				cout << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i] << endl;
				temp++;
			}
		}
		

	}
	else
	{
		cout << "wrong input " << endl;
		AboveBelowAveSalary();
	}
	cout << "there are " << temp << " from the option you have choose " << endl;


}
void EmployeeSearch () 
{
	infile.open("dataProject.txt");
	string str;
	int count = 0;
	while (getline(infile, str))
	{

		count++;

	}
	infile.close();
	infile.open("dataProject.txt");//opens file secound time to store a data 
	while (!infile.eof())
	{
		for (int i = 0; i < count; i++)
		{
			infile >> fName[i] >> lName[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];//store data in the arrays
		}
	}

	infile.close();
	int opt;
	infile.open("dataProject.txt");
	cout << "How you want to find the Employee  " << endl;
	cout<<"1.By phone number " << endl;
	cout << "2. By ID number  " << endl;
	cin >> opt;
	if (opt==1)
	{
		string phoneNum;
		while (phoneNum.length() !=10)
		{
			cout << "Enter the phone number of the Employee you wnat search " << endl;
			cin >> phoneNum;
		}
		for (int i=0;i<count ;i++)
		{
			if (phoneNum == phone[i])
			{
				cout << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				cout << endl;

			}
		}
	}
	if (opt == 2)
	{
		string Id;
		while (Id.length() != 6)
		{
			cout << "Enter the ID number of the Employee you wnat search " << endl;
			cin >> Id;
		}
		for (int i = 0; i < count; i++)
		{
			if (Id == eid[i])
			{
				cout << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				cout << endl;

			}
		}
	}
	

}
void SalaryDept()
{
	/*
	In this function I am trying to do is taking in the name of a department and asks the user to make a choice between
	seeing the highest or lowest earner, and based on the user’s choice, displays the entire information of the corresponding employee.  
	It should display an appropriate message if a department that does not exist is entered
	steps 1 . open data file of the company get the number of staff and safe for count
	step 2 . ask user to make choice what is the department
	step 3 . beased on the user's choice outfile the data of all empolyyes to new file i called it sort 
	step 4 . get the max index if i Know  where is the line of the employee who has the highst or the lowest I am now trying to figuer out the highest once I get this right I will make the function or both ways.
	Note The program didnt give the right result the I wish could you please profsoer help me with it ?
	*/
	infile.open("dataProject.txt");
	int count = 0;
	while (!infile.eof())
	{
		infile >> fName[count] >> lName[count] >> dep[count] >> eid[count] >> sal[count] >> phone[count] >> gen[count] >> year[count];//store data in the arrays
		count++;
	}
	infile.close();
	cout << "Enter department " << endl;
	cout << "1. Acct " << endl;
	cout << "2. Exec " << endl;
	cout << "3.Sales " << endl;
	cout << "4.HR" << endl;
	cout << "5.Mkt " << endl;
	int opt;
	string str = "";
	cin >> opt;
	int check = 0;
	outfile.open("sort.txt");
	int max = 0;

	if (opt == 1)
	{
		str = "Acct";
		for (int i =0; i<count;i++ )
		{
			if (str == dep[i])
			{
				outfile<<" " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				outfile << endl;
			}
		}
		
	}
	else if (opt == 2) 
	{
		str = "Exec";
		for (int i = 0; i < count; i++) {
			if (str == dep[i])
			{
				outfile << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				outfile << endl;
				
			}
		}
	}
	else if (opt == 3)
	{
		str = "Sales";
		for (int i = 0; i < count; i++) {
			if (str == dep[i])
			{
				outfile << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				outfile << endl;
			}
		}
		
	}
	
	else if (opt == 4)
	{
		str = "HR";
		for (int i = 0; i < count; i++) {
			if (str == dep[i])
			{
				outfile << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				outfile << endl;
			}
		}
		
	}
	else if (opt == 5)
	{
		str = "Mkt";
		for (int i = 0; i < count; i++) {
			if (str == dep[i])
			{
				outfile << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				outfile << endl;
			}
		}
		
	} 
	else if (opt == 6)
	{
		str = "HR";
		for (int i = 0; i < count; i++) {
			if (str == dep[i])
			{
				outfile << " " << fName[i] << "\t    " << lName[i] << "\t " << dep[i] << "\t  " << eid[i] << "\t " << sal[i] << "\t  " << phone[i] << "\t" << gen[i] << "\t " << year[i];
				outfile << endl;
			}
		}

	}
	
	outfile.close();
	infile.open("sort.txt");
	count = 0;
	while (infile.eof())
	{

		infile >> fName[count] >> lName[count] >> dep[count] >> eid[count] >> sal[count] >> phone[count] >> gen[count] >> year[count];//store data in the arrays
		count++;
	}
	

			for (int i = 1; i < count; i++)
			{
					if (sal[max] < sal[i])
					{
						max = i;
					}
				
			}
			infile.close();
			remove("sort.txt");
			
		cout << " " << fName[max] << "\t    " << lName[max] << "\t " << dep[max] << "\t  " << eid[max] << "\t " << sal[max] << "\t  " << phone[max] << "\t" << gen[max] << "\t " << year[max];
		
		

	
		

	}

	

int main()
{

	char opt = 'c';

	while (opt == 'c'|| opt == 'C')
	{
		system("cls");

		cout << "\n Enter your choice!\n\n";
		cout << "\n1. Enlist all Employees' data\n\n";
		cout << "2. Enlist Employees in order\n\n";
		cout << "3. Enlist Employees with different salaries\n\n";
		cout << "4. Enlist Employees according to department\n\n";
		cout << "5.Enlist Employees according to gender\n\n";
		cout << "6. Hire Staff\n\n";
		cout << "7. Update the information of Employees\n\n";
		cout << "8. Fire Staff\n\n";
		cout << "9. Check Bonus eligibility\n\n";
		cout << "10.Min max  \n\n";
		cout << "11.Employees Age  \n\n";
		cout << "12.Above Below Ave Salary \n\n";
		cout << "13.EmployeeSearch  \n\n";
		cout << "14. Salary & Dept  \n\n";




		int choose;
		cin >> choose;

		if (choose == 1)
		{
			createCompany();

		}

		else if (choose == 2)
		{
			SortEmployee();
		}

		else if (choose == 3)
		{
			HighLowSalary();
		}

		else if (choose == 6)
		{
			HireStaff();
		}


		else if (choose == 4)
		{
			MinMaxDepartment();
		}
		else if (choose == 5)
		{
			EmployeeGender();
		}
		else if (choose == 6)
		{
			HireStaff();
		}


		else if (choose == 7)
		{
			UpdateEmployee();
		}
		

		else if (choose == 8)
		{
			fireStaff();

		}

		else if (choose == 9)
		{
			EmployeeBonus();
		}
		else if (choose ==10)
		{
			minMaxSalary();
		}
		else if (choose == 11)
		{
			EmployeesAge();

		}
		else if (choose == 12)
		{
			AboveBelowAveSalary();

		}
		else if (choose ==13 )
		{
			EmployeeSearch();
		}
		else if (choose == 14)
		{

			SalaryDept();
		}
		cout << "\n\nEnter c to continue with Main menu or e to end\n";
		cin >> opt;
	}
	system("pause");
	return 0;
}


