"""
Author: Abhilash

Description: This source code implements car showroom inventory management.
"""
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
