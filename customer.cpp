int custdetinput()
{
	cout << "\nEnter today's date :";
	cout << "Enter day :";
	cin >> cd1.bday;
	cout << "Enter month :";
	cin >> cd1.bm;
	cout << "Enter year :";
	cin >> cd1.byear;
	cd1.cs = se;
	cout << "Enter your details :\n";
	cout << "First Name :";
	gets(cd1.firstname);
	cout << "Last Name :";
	gets(cd1.lastname);
	cout << "House no.,street :";
	gets(cd1.address1);
	cout << "Area :";
	gets(cd1.address2);
	cout << "City :";
	gets(cd1.city);
	cout << "State :";
	gets(cd1.state);
	cout << "Pincode :";
	cin >> cd1.pin;
	cout << "Email-address :";
	gets(cd1.emailaddress);
	cout << "Mobile number : ";
	gets(cd1.mobilenumber);
	return 0;
}
int custdetdisplay()
{
	cout << "Date : " << cd1.bday << "-" << cd1.bm << "-" << cd1.byear;
	cout << "\nRegistration Number :" << cd1.cs;
	cout << "\nYour details are :\n";
	cout << "\nFirst Name : " << cd1.firstname;
	cout << "\nLast Name : " << cd1.lastname;
	cout << "\nHouse no.,street : " << cd1.address1;
	cout << "\nArea : " << cd1.address2;
	cout << "\nCity : " << cd1.city;
	cout << "\nState : " << cd1.state;
	cout << "\nPincode : " << cd1.pin;
	cout << "\nEmail-address : " << cd1.emailaddress;
	cout << "\nMobile number : " << cd1.mobilenumber;
	return 0;
}
int customerdetinpf()
{
	ofstream clout("cust_details.dat", ios::app | ios::binary | ios::out);
	custdetinput();
	clout.write((char *)&cd1, sizeof(custdetails));
	clout << endl;
	clout.close();
	se++;
return 0;}

int customerdetdisplay()
{
	ifstream clin("cust_details.dat", ios::binary | ios::in);
	while (clin.read((char *)&cd1, sizeof(custdetails)))
	{
		custdetdisplay();
		clin.close();
	}
return 0;}

int customerlistdisplay()
{
	cout << "1-Want to get list of customer of a particular car\n";
	cout << "2-List of customer who bought a car on a particular date\n";
	cout << "3-List of customer who came for reparing and other particular on a day\n";
	cout << "4-List of all customer who bought a car\n";
	cout << "5-List of all customer who came fo repairing etc.\n";
	cout << "6-List of customers on a particular day\n";
	cout << "7-List of all customers\n";
	cout << "Enter serial number:";
	cin >> a;
	ifstream clin("cust_details.dat", ios::binary | ios::in);
	switch (a)
	{
	case 1:
		char vt[50];
		cout << "\nEnter car varient name:";
		gets(vt);
		while (clin.read((char *)&cd1, sizeof(cd1)))
		{
			if (strcmpi(vt, cd1.service) == 0)
				cout << cd1.cs << " " << cd1.firstname << " " << cd1.lastname << endl;
		}
		break;
	case 2:
		cout << "Please enter the day\n";
		cin >> cday;
		cout << "Now enter month\n";
		cin >> cm;
		cout << "Enter year\n";
		cin >> cyear;
		while (clin.read((char *)&cd1, sizeof(cd1)))
		{
			if (cd1.bday == cday && cd1.bm == cm && cd1.byear == cyear)
			{
				if (strcmp(cd1.service, ser) != 0 && strcmpi(cd1.service, serv) != 0)
					cout << cd1.cs << " " << cd1.firstname << " " << cd1.lastname << endl;
			}
		}
		break;
	case 3:
		cout << "Please enter the day\n";
		cin >> cday;
		cout << "Now enter month\n";
		cin >> cm;
		cout << "Enter year\n";
		cin >> cyear;
		while (clin.read((char *)&cd1, sizeof(cd1)))
		{
			if (cd1.bday == cday && cd1.bm == cm && cd1.byear == cyear)
			{
				if (strcmp(cd1.service, ser) == 0 || strcmpi(cd1.service, serv) == 0)
					cout << cd1.cs << " " << cd1.firstname << " " << cd1.lastname << endl;
			}
		}
		break;
	case 4:
		while (clin.read((char *)&cd1, sizeof(cd1)))
		{
			if (strcmp(cd1.service, ser) != 0 && strcmpi(cd1.service, serv) != 0)
				cout << cd1.cs << " " << cd1.firstname << " " << cd1.lastname;
		}
		break;
	case 5:
		while (clin.read((char *)&cd1, sizeof(cd1)))
		{
			if (cd1.bday == cday && cd1.bm == cm && cd1.byear == cyear)
			{
				if (strcmp(cd1.service, ser) == 0 || strcmpi(cd1.service, serv) == 0)
					cout << cd1.cs << " " << cd1.firstname << " " << cd1.lastname << endl;
			}
		}
		break;
	case 6:
		cout << "Please enter the day\n";
		cin >> cday;
		cout << "Now enter month\n";
		cin >> cm;
		cout << "Enter year\n";
		cin >> cyear;
		while (clin.read((char *)&cd1, sizeof(cd1)))
		{
			if (cd1.bday == cday && cd1.bm == cm && cd1.byear == cyear)
				cout << cd1.cs << " " << cd1.firstname << " " << cd1.lastname << endl;
		}
		break;
	case 7:
		while (clin.read((char *)&cd1, sizeof(cd1)))
			cout << cd1.cs << " " << cd1.firstname << " " << cd1.lastname << endl;
		break;
	default:
		cout << "\n!!!!!!!!!!!Wrong input!!!!!!!!!!!!!\n";
		break;
	}
	cout << "Enter 'y' if you want complete details a particular customer  else enter 'N' \n";
	cin >> reply;
	if (toupper(reply) == 'Y')
	{
		cout << "\nEnter serial No of the customer:";
		cin >> a;
		while (clin.read((char *)&cd1, sizeof(cd1)))
		{
			if (cd1.cs == a)
				custdetdisplay();
			else
				exit(0);
		}
		clin.close();
	}
	else
		exit(0);
return 0;}
