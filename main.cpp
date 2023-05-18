"""
Author: Abhilash

Description: This source code implements car showroom inventory management.
"""
#include <iostream>
#include <string>
using namespace std;

#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

#include <stdlib.h>

int sr = 1, se = 1, r, a;
int c = 0, cm, dm, cday, dday, cyear, dyear, b;
char reply, ser[] = "wash&sevicing";
char serv[] = "painting";
long int bud, mprof = 0, prof, pcost;

struct custdetails
{
	int cs;
	int bday, bm, byear;
	char firstname[20];
	char lastname[20];
	char address1[20];
	char address2[20];
	char city[15];
	char state[20];
	char pin[6];
	char emailaddress[40];
	char mobilenumber[11];
	char service[50];
	long int amount;
} cd1;

class carstock
{
public:
	int s;
	char CN[20];
	char MN[50];
	char VN[50];
	char CT[10];
	char EP[6];
	char EC[6];
	long int cost;
	float EM;
	int SC;
	char FT[6];
	int NOC;
	int stockinput()
	{
		s = sr;
		cout << "Enter company name :\n";
		gets(CN);
		cout << "Enter model name of the car :\n";
		gets(MN);
		cout << "Enter type of car :\n";
		gets(CT);
		cout << "Enter varient name :\n";
		gets(VN);
		cout << "Enter the cost of the car :\n";
		cin >> cost;
		cout << "Enter the mileage of the engine :\n";
		cin >> EM;
		cout << "Enter engine power :\n";
		gets(EP);
		cout << "Engine capacity :\n";
		gets(EC);
		cout << "Seating capacity of the car :\n";
		cin >> SC;
		cout << "Fuel type :\n";
		cin >> FT;
		cout << "Number of cars :\n";
		cin >> NOC;
		return 0;
	}

	int stockdisplay()
	{
		cout << s;
		cout << "\nCompany name :" << CN;
		cout << "\nModel name of the car :" << MN;
		cout << "\nType of car :" << CT;
		cout << "\nVarient name :" << VN;
		cout << "\nThe cost of the car :" << cost;
		cout << "\nMileage of the engine :" << EM;
		cout << "\nEngine power :" << EP;
		cout << "\nEngine capacity :" << EC;
		cout << "\nSeating capacity of the car :" << SC;
		cout << "\nFuel type :" << FT;
		cout << "\nNumber of cars :" << NOC;
		return 0;
	}
} c1;



int stockinp()
{
	int A;
	ofstream sout("stock.dat", ios::app | ios::binary | ios::in);
	cout << "How many records you want to enter\n";
	cin >> A;
	for (int i = 0; i < A; i++)
	{
		c1.stockinput();
		sout.write((char *)&c1, sizeof(c1));
		sr++;
	}
	sout.close();
	return 0;
}
int stockse()
{
	char cmpny[50], FT1[6], CT1[6];
	ifstream fin("stock.dat", ios::binary | ios::in);
	cout << "Please select the filter option from below:\n";
	cout << "1-Budget\n"
		 << "2-Company\n"
		 << "3-Car Type(SUV,etc)\n"
		 << "4-Fuel Type\n";
	cout << "5-Both Budget and Company\n"
		 << "6-Budget and Car type\n"
		 << "7-Budget, Company, Car and Fuel type\n";
	cout << "Please enter the serial number of filter option which you want to use\n";
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "Please enter your budget \n";
		cin >> bud;
		while (fin.read((char *)&c1, sizeof(c1)))
		{
			if (c1.cost < bud || c1.cost == bud)
			{
				if (c1.NOC != 0)
					c1.stockdisplay();
				c++;
			}
		}
		if (c == 0)
			cout << "Sorry! car not available\n";
		break;

	case 2:
		cout << "Please enter company name \n";
		gets(cmpny);
		while (fin.read((char *)&c1, sizeof(c1)))
		{
			if (strcmpi(cmpny, c1.CN) == 0)
			{
				if (c1.NOC != 0)
					c1.stockdisplay();
				c++;
			}
		}
		if (c == 0)
			cout << "sorry! car not available";
		break;

	case 3:
		cout << "Please enter car type\n";
		gets(CT1);
		while (fin.read((char *)&c1, sizeof(c1)))
		{
			if (strcmpi(CT1, c1.CT) == 0)
			{
				if (c1.NOC != 0)
					c1.stockdisplay();
				c++;
			}
		}
		if (c == 0)
			cout << "sorry! car not available";
		break;

	case 4:
		cout << "Please enter Fuel type\n";
		gets(FT1);
		while (fin.read((char *)&c1, sizeof(c1)))
		{
			if (strcmpi(FT1, c1.FT) == 0)
			{
				if (c1.NOC != 0)
					c1.stockdisplay();
				c++;
			}
		}
		if (c == 0)
			cout << "sorry! car not available";
		break;

	case 5:
		cout << "Please enter your budget \n";
		cin >> bud;
		cout << "Please enter company name \n";
		gets(cmpny);
		while (fin.read((char *)&c1, sizeof(c1)))
		{
			if (strcmpi(cmpny, c1.CN) == 0 && c1.cost < bud || c1.cost == bud)
			{
				if (c1.NOC != 0)
					c1.stockdisplay();
				c++;
			}
		}
		if (c == 0)
			cout << "sorry! car not available";
		break;

	case 6:
		cout << "Please enter your budget \n";
		cin >> bud;
		cout << "Please enter car type\n";
		gets(CT1);
		while (fin.read((char *)&c1, sizeof(c1)))
		{
			if (c1.cost < bud || c1.cost == bud && strcmpi(CT1, c1.CT) == 0)
			{
				if (c1.NOC != 0)
					c1.stockdisplay();
				c++;
			}
		}
		if (c == 0)
			cout << "sorry! car not available";
		break;

	case 7:
		cout << "Please enter your budget \n";
		cin >> bud;
		cout << "Please enter company name \n";
		gets(cmpny);
		cout << "Please enter car type\n";
		gets(CT1);
		cout << "Please enter Fuel type\n";
		gets(FT1);
		while (fin.read((char *)&c1, sizeof(c1)))
		{
			if (strcmpi(CT1, c1.CT) == 0 && strcmpi(cmpny, c1.CN) == 0 && c1.cost < bud || c1.cost == bud && strcmpi(FT1, c1.FT) == 0)
			{
				if (c1.NOC != 0)
					c1.stockdisplay();
				c++;
			}
		}
		if (c == 0)
			cout << "sorry! car not available";
		break;

	default:
		cout << "!!!!!!!!!!!WRONG INPUT!!!!!!!!!!!";
		break;
	}
	fin.close();
	return 0;
}

int stockdisplayf()
{
	cout << "stock details are:-\n";
	ifstream fin("stock.dat", ios::binary | ios::in);
	while (!fin.eof())
	{
		fin.read((char *)&c1, sizeof(c1));
		c1.stockdisplay();
	}
	fin.close();
return 0;}

int carselected()
{
	cout << "\nEnter the serial number of the car which you want to buy :\n";
	cin >> r;
	ifstream fin("stock.dat", ios::binary | ios::in);
	if (r == c1.s)
	{
		fin.read((char *)&c1, sizeof(c1));
		cout << "Details of the car which you have selected are :-\n";
		c1.stockdisplay();
	}
	fin.close();
return 0;}

int stockdelfile()
{
	ofstream sout("stock1.dat", ios::binary | ios::out);
	ifstream sin("stock.dat", ios::binary | ios::in);
	while (sin.read((char *)&c1, sizeof(c1)))
	{
		if (c1.s == r)
			c1.NOC = c1.NOC - 1;
		sout.write((char *)&c1, sizeof(c1));
		sout << endl;
	}
	sin.close();
	sout.close();
	remove("stock.dat");
	rename("stock1.dat", "stock.dat");
return 0;}

long int painting()
{
	char paint[50];
	strcpy(cd1.service, serv);
	cout << "Enter the paint which u want to have on  your car :-";
	gets(paint);
	a = rand();
	if (a == 0)
		a = 1;
	pcost = 300 * a + 500;
	return (pcost);
}

  int main()
{
	cout << "                       welcome to CAR'S HEAVEN \n";
	cout << "1-you are customer\n"
		 << "2-login as administrater\n"
		 << "3-exit\n";
	cout << "please enter serial number \n";
	cin >> a;
	if (a == 1)
	{
		cout << "1-Car reparing & servicing of car\n"
			 << "2-Want to buy new car\n"
			 << "3-exit\n";
		cout << "\nEnter the serial number :";
		cin >> b;
		if (b == 1)
		{
			cout << "\nSERVICES ARE:-\n"
				 << "1-Painting the car\n"
				 << "2-Washing, servicing and lubriction etc\n"
				 << "3-Exit\n";
			cout << "\nEnter the serial number of the service :";
			int g;
			cin >> g;
			switch (g)
			{
			case 1:
				cd1.amount = painting();
				customerdetinpf();
				cout << "\nYou have to pay :" << cd1.amount << " Rs";
				cout << "\n!!!!!!!!!!!!!!!!Thank you!!!!!!!!!!!!!!!!!!!!!!!!!";
				cout << "\n__________@@__________@@____ VISIT AGAIN ____@@__________@@__________@@";
				break;
			case 2:
			{
				cd1.amount = 5000;
				customerdetinpf();
				strcpy(cd1.service, ser);

				cout << "\nYou have to pay :" << cd1.amount << " Rs";
				cout << "\n!!!!!!!!!!!!!!!!Thank you !!!!!!!!!!!!!!!!!!!!!!!!!";
				cout << "\n__________@@__________@@____ VISIT AGAIN ____@@__________@@__________@@";
				break;
			case 3:
				exit(0);
				break;
			default:
				cout << "\n!!!!!!!!!!!!!!!!!!!!Wrong input!!!!!!!!!!!!!11";
				break;
			}
			}
		}
		else if (b == 2)
		{
			stockse();
			carselected();
			stockdelfile();
			strcpy(cd1.service, c1.VN);
			customerdetinpf();
			discount();
			profit();
		}

		else if (b == 3)
			exit(0);
	}

	else if (a == 2)
	{
		cout << "\nEnter password";
		char pass[25];
		char password[] = "Cspractical";
		cin>>pass;
		if (strcmp(pass, password) == 0)
		{
			int d;
			cout << "1-stock input\n"
				 << "2-To display stock details\n"
				 << "3-To display customer list\n"
				 << "4-Get profit details\n"
				 << "5-EXIT\n";
			cout << "Please enter serial number of the service which you want :\n";
			cin >> d;
			switch (d)
			{
			case 1:
				stockinp();
				break;
			case 2:
				stockdisplayf();
				break;
			case 3:
				int e;
				cout << "Enter 1 to get full details of all customer else enter 2:";
				cin >> e;
				if (e == 1)
					customerdetdisplay();
				else
					customerlistdisplay();
				break;
			case 4:
				int f;
				cout << "Choose the option:-\n";
				cout << "1-Want to get daily profit\n"
					 << "2-Want to get monthly profit\n"
					 << "3-Want to get annual profit"
					 << "4-Exit\n";
				cin >> f;
				if (f == 1)
				{
					cout << "Do you want to get only one day profit then enter Y else enter N\n";
					cin >> reply;
					if (toupper(reply) == 'Y')
						dayprofit();
					else if (toupper(reply) == 'N')
						dailyprofit();
				}
				else if (f == 2)
				{
					cout << "Do you want to get only one month profit then enter Y else enter N\n";
					cin >> reply;
					if (toupper(reply) == 'Y')
						monthprofit();
					else if (toupper(reply) == 'N')
						monthlyprofit();
				}
				else if (f == 3)
				{
					cout << "Do you want to get only one year profit then enter Y else enter N\n";
					cin >> reply;
					if (toupper(reply) == 'Y')
						yearprofit();
					else if (toupper(reply) == 'N')
						yearlyprofit();
				}
				else
					cout << "!!!!!!!!!!!!!!!!wrong input!!!!!!!!!!!!!!!!!\n";
				break;
			default:
				cout << "!!!!!!!!!!Wrong inoput!!!!!!!!!!!!\n";
				break;
			}
		}
		else if (strcmp(pass, password) != 0)
			cout << "!!!!!!!!!!!!!!!!!!!Wrong Password!!!!!!!!!!!!!!!!!";
	}

	else if (a == 3)
		exit(0);
	return 0;
}
