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
