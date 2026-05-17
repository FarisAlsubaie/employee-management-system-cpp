#include <iostream>
#include <fstream>
#include <string>

using namespace std;


ifstream in;
ofstream out;
string firstName, lastName, phoneNum, depart, id;
int  birthYear;
double salary;
char gender;

void HireStaff()
{


	firstName = "", lastName = "", depart = "", phoneNum = "", id = "", birthYear = 0, salary = 0;
	out.open("employees.txt", ios::app);



	cout << "Enter First name of Employee: ";
	cin >> firstName;
	cout << endl;
	cout << "Enter Last name of Employee: ";
	cin >> lastName;
	cout << endl;
	cout << "Enter Department of Employee: ";
	cin >> depart;
	cout << endl;
	while (id.length() != 6)// name.length()  for string gives the programmer the ability  to know the  length for the string 
	{
		cout << "Enter Employee ID (6 digits): ";
		cin >> id;
		cout << endl;
		
	}

	cout << "Enter salary of this Employee: ";
	cin >> salary;
	cout << endl;
	while (phoneNum.length() != 10)
	{

		cout << "Enter Phone Number of Employee (10 digits) : ";
		cin >> phoneNum;
		cout << endl;
	}
	cout << "Enter Gender (F for Female, M for Male) : ";
	cin >> gender;
	cout << endl;
	while (birthYear < 1960)
	{

		cout << "Enter Birth Year (Not less than 1960) : ";
		cin >> birthYear;
		cout << endl;
	}

	out << endl;
	out << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
		<< phoneNum << " " << gender << " " << birthYear;


	out.close();





}

void FireStaff()
{
	char ch = ' ';

	cout << "How you want to remove Employee:\n"
		<< "1. By Employee Id\n"
		<< "2. By Phone Number\n";
	cin >> ch;

	if (ch == '1')
	{
		system("cls");
		string delid; 
		
		while (delid.length() != 6)
		{
			cout << "Enter Employee ID (6 digits): ";
			cin >> delid;
			cout << endl;
		}
		ifstream check;
		check.open("employees.txt");
		while (!check.eof())
		{
			check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;
			if (id == delid && (depart == "Exec" || depart == "exec"))
			{
				cout << "You cannot remove Executive!\n. Enter your choice again\n\n";
				FireStaff();
			}

		}
		check.close();
// ??
		ifstream oldin;
		oldin.open("employees.txt");
		ofstream newout;
		newout.open("new.txt");


		while (!oldin.eof())
		{
			oldin >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

			if (id != delid)
			{


				newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
					<< phoneNum << " " << gender << " " << birthYear;
				newout << endl;
			}


		}

		newout.close();
		oldin.close();
		if (remove("employees.txt") == 0)
		{
			cout << "Employee fired. No record of his/her exist anymore\n\n";
		}

		rename("new.txt", "employees.txt");

	}
	else if (ch == '2')
	{
		system("cls");
		string delphone;
		while (delphone.length() != 10)
		{
			cout << "Enter Employee's Phone Number (10 digits): ";
			cin >> delphone;
			cout << endl;
		}
		ifstream oldin;
		oldin.open("employees.txt");
		ofstream newout;
		newout.open("new.txt");


		while (!oldin.eof())
		{
			oldin >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

			if (phoneNum != delphone)
			{


				newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
					<< phoneNum << " " << gender << " " << birthYear;
				newout << endl;
			}


		}

		newout.close();
		oldin.close();
		if (remove("employees.txt") == 0)
		{
			cout << "Employee fired. No record of his/her exist anymore\n\n";
		}

		rename("new.txt", "employees.txt");


	}
	else
	{
		cout << "Wrong choice. select again!\n\n";
		FireStaff();
	}
}

void PrintList()
{
	ifstream in;

	in.open("employees.txt");

	string ch;
	int count = 0;
	while (getline(in, ch))
	{
		count++;

	}
	in.close();


	string* fname = new string[count];
	string* lname = new string[count];
	string* phone = new string[count];
	string* dep = new string[count];
	string* eid = new string[count];
	int* year = new int[count];
	double* sal = new double[count];
	char* gen = new char[count];


	ifstream read;
	read.open("employees.txt");

	while (!read.eof())
	{
		for (int i = 0; i < count; i++)
		{
			read >> fname[i] >> lname[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];
		}
	}

	read.close();

	string temp;
	int temp1;
	double temp2;
	char temp3;
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
void CreateCompany()
{
	PrintList();
}


void SortEmployee()
{
	char choice;

	cout << "Enter your choice how you want to sort list of Employees?\n"
		<< "1. By First Name\n"
		<< "2. By Last Name\n"
		<< "3. By Employee Id\n"
		<< "4. Phone Number\n"
		<< "5. Birth Year\n\n";
	cin >> choice;

	cout << endl;
	ifstream in;

	in.open("employees.txt");

	string ch;
	int count = 0;
	while (getline(in, ch))
	{
		count++;

	}
	in.close();


	string* fname = new string[count];
	string* lname = new string[count];
	string* phone = new string[count];
	string* dep = new string[count];
	string* eid = new string[count];
	int* year = new int[count];
	double* sal = new double[count];
	char* gen = new char[count];


	ifstream read;
	read.open("employees.txt");

	while (!read.eof())
	{
		for (int i = 0; i < count; i++)
		{
			read >> fname[i] >> lname[i] >> dep[i] >> eid[i] >> sal[i] >> phone[i] >> gen[i] >> year[i];
		}
	}

	read.close();

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
}

void HighLowSalary()
{
	char opt, cat;
	double sal;
	cout << "Which category you want to search?\n"
		<< "1. Male\n"
		<< "2. Female\n\n";
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
		cin >> cat;
		cout << endl << endl;
		if (cat == '1')
		{
			ifstream check;
			check.open("employees.txt");
			cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

			while (!check.eof())
			{
				check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

				if ((salary > sal) && (gender == g))
				{
					cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
					cout << endl;

				}

			}

			check.close();

		}

		else if (cat == '2')
		{
			ifstream check;
			check.open("employees.txt");
			cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

			while (!check.eof())
			{
				check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

				if ((salary < sal) && (gender == g))
				{
					cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
					cout << endl;

				}

			}
			check.close();
		}

	}
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
			check.open("employees.txt");
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
			check.open("employees.txt");
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

void EmployeeGender()
{
	char ch;
	cout << "Which category you want to search?\n"
		<< "1. Male\n"
		<< "2. Female\n\n"
		<< " Enter 1, M or m for male\n"
		<< " Enter 2, F or f for female\n";
	cin >> ch;
	int count = 0;
	if (ch == '1' || ch == 'M' || ch == 'm')
	{
		char g = 'M';
		ifstream check;
		check.open("employees.txt");
		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

		while (!check.eof())
		{
			check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

			if (gender == g)
			{
				cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;

				cout << endl;
				count++;

			}

		}
		check.close();
		cout << "\nTotal Employees of this category = " << count << ".\n\n";
	}
	else if (ch == '2' || ch == 'F' || ch == 'f')
	{
		char g = 'F';
		ifstream check;
		check.open("employees.txt");
		cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

		while (!check.eof())
		{
			check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

			if (gender == g)
			{
				cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;
				cout << endl;
				count++;

			}

		}
		check.close();
		cout << "\nTotal Employees of this category = " << count << ".\n\n";
	}
	else
	{
		cout << "Wrong selection. Enter again\n\n";

		EmployeeGender();
	}

}

void EmployeeBonus()
{
	int year = 0;
	while (year < 1960)
	{
		cout << "Enter age in years ( Not less than 1960)\n";
		cin >> year;
	}
	int count = 0;
	ifstream check;
	check.open("employees.txt");
	cout << " First Name  LastName  Department  Employee Id  Salary  Phone Number  Gender  Birth Year\n\n";

	while (!check.eof())
	{
		check >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

		if (birthYear >= year)
		{
			cout << " " << firstName << "\t    " << lastName << "\t " << depart << "\t  " << id << "\t " << salary << "\t  " << phoneNum << "\t" << gender << "\t " << birthYear;

			cout << endl;
			count++;

		}

	}
	check.close();
	cout << "\nThese Employees are eligible for Bonus\n";
	cout << "\nTotal Employees eligible for bonus are = " << count << ".\n\n";
}
void MinMaxDepartment()
{
	char m;
	cout << "\nHow you want to see no. of Employees by Department?\n"
		<< "1. Department with maximum Employees?\n"
		<< "2. Department with minimum Employees?\n"
		<< " Enter 1 or 2.\n\n";
	cin >> m;
	int acct = 0, exec = 0, sales = 0, hr = 0, it = 0, mkt = 0;

	ifstream check;
	check.open("employees.txt");
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
	for (int i = 0; i < 6 - 1; i++)
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


void UpdateEmployee()
{
	char ch, w = 'y';
	string emp, ph;
	while (w == 'y')
	{
		cout << "How you want to update information of Employees?\n"
			<< "1. By Employee Id\n"
			<< "2. By Phone Number\n"
			<< " Enter 1 or 2\n\n";

		cin >> ch;
		if (ch == '1')
		{
			system("cls");
			cout << "Enter Employee Id: ";
			cin >> emp;
			cout << endl << endl;
			ifstream oldin;
			oldin.open("employees.txt");
			ofstream newout;
			newout.open("new.txt");


			while (!oldin.eof())
			{
				oldin >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

				if (id != emp)
				{


					newout << firstName << " " << lastName << " " << depart << " " << id << " " << salary << " "
						<< phoneNum << " " << gender << " " << birthYear;
					newout << endl;
				}
				else if (id == emp)
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

			remove("employees.txt");
			rename("new.txt", "employees.txt");

		}
		else if (ch == '2')
		{
			system("cls");
			cout << "Enter phone number of Employee: ";
			cin >> ph;
			cout << endl << endl;
			ifstream oldin;
			oldin.open("employees.txt");
			ofstream newout;
			newout.open("new.txt");


			while (!oldin.eof())
			{
				oldin >> firstName >> lastName >> depart >> id >> salary >> phoneNum >> gender >> birthYear;

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

			remove("employees.txt");
			rename("new.txt", "employees.txt");
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
int main()
{

	char opt = 'c';

	while (opt == 'c')
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


		char choose;
		cin >> choose;

		if (choose == '1')
		{
			CreateCompany();
		}
		else if (choose == '2')
		{
			SortEmployee();
		}
		else if (choose == '3')
		{
			HighLowSalary();
		}
		else if (choose == '4')
		{
			MinMaxDepartment();
		}
		else if (choose == '5')
		{
			EmployeeGender();
		}
		else if (choose == '6')
		{
			HireStaff();
		}
		else if (choose == '7')
		{
			UpdateEmployee();
		}
		else if (choose == '8')
		{
			FireStaff();

		}
		else if (choose == '9')
		{
			EmployeeBonus();
		}

		cout << "\n\nEnter c to continue with Main menu or e to end\n";
		cin >> opt;
	}

	system("pause");
	return 0;
}


