int discount()
{
	switch (cd1.bm)
	{
	case 1:
		if (cd1.bday < 5)
		{
			cout << "         *******NEW YEAR OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 2:
		if (cd1.bday > 20)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 3:
		if (cd1.bday < 10)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 4:
		if (cd1.bday < 15 && cd1.bday > 4)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 5:
		if (cd1.bday > 25)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 6:
		if (cd1.bday < 5)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 7:
		if (cd1.bday > 20)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 8:
		if (cd1.bday < 10)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 9:
		if (cd1.bday < 5)
		{
			cout << "         *******BUMPER OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	case 10:
		if (cd1.bday < 25 && cd1.bday > 18)
		{
			cout << "         *******DUSSEHRA OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 12);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 12% discount\n";
		}
		break;
	case 11:
		if (cd1.bday < 15 && cd1.bday > 1)
		{
			cout << "         *******DIWALI OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 15);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 15% discount\n";
		}
		break;

	case 12:
		if (cd1.bday < 26 && cd1.bday > 20)
		{
			cout << "         *******CHRISTMAS OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 9);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 9% discount\n";
		}
		else if (cd1.bday <= 31 && cd1.bday > 28)
		{
			cout << "         *******NEW YEAR OFFER*******\n";
			cout << "Real price of car is : " << c1.cost << "Rs";
			cd1.amount = c1.cost - (c1.cost / 100 * 10);
			cout << "\nBut you have to pay :" << cd1.amount << "Rs";
			cout << "\nYou are getting 10% discount\n";
		}
		break;
	default:
		cout << "\n!!!!!!!!!!!!!Wrong input!!!!!!!!!!!!!!\n";
		break;
	}
	cout << "!!!!!!!!!!!!!!!!THANK YOU!!!!!!!!!!!!!!!!!\n";
	cout << "__________@@__________@@____ VISIT AGAIN ____@@__________@@__________@@";
return 0;}
