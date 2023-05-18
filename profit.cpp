int profit()
{
	ofstream fout("profits.dat", ios::app | ios::binary | ios::out);
	prof = cd1.amount / 100 * 10;
	fout << cd1.bday << "-" << cd1.bm << cd1.byear << "-" << cd1.service << "-" << prof;
	fout << endl;
	fout.close();
return 0;}

int dayprofit()
{
	cout << "Please enter the day\n";
	cin >> cday;
	cout << "Now enter month\n";
	cin >> cm;
	cout << "Enter year\n";
	cin >> cyear;
	ifstream fin("profits.dat", ios::binary | ios::in);
	while (!fin.eof())
	{
		fin >> cd1.bday >> cd1.bm >> cd1.byear >> cd1.service >> prof;
		if (cd1.bday == cday && cd1.bm == cm && cd1.byear == cyear)
			mprof = mprof + prof;
	}
	cout << "Profit made in the day is:" << mprof << "Rs\n";
	fin.close();
return 0;}

int dailyprofit()
{
	int pd = 0;
	cout << "Enter the  begining day and ending day\n";
	cin >> cday >> dday;
	cout << "Enter the  begining month and ending month\n";
	cin >> cm >> dm;
	cout << "Enter the  begining year and ending year\n";
	cin >> cyear >> dyear;
	ifstream fin("profits.dat", ios::binary | ios::in);
	while (!fin.eof())
	{
		fin >> cd1.bday >> cd1.bm >> cd1.byear;
		fin >> prof;
		if (cd1.bday == cday && cd1.bm == cm && cd1.byear == cyear)
		{
			while (cd1.bday != dday && cd1.bm != dm && cd1.byear != dyear)
			{
				fin >> cd1.bday >> cd1.bm >> cd1.byear;
				fin >> prof;
				if (pd == 0 || pd != cd1.bday)
					mprof = prof;
				pd = cd1.bday;
				cout << cd1.bday << "-" << cd1.bm << "-" << cd1.byear << ":profit=" << mprof << "\n";
				if (pd != 0)
					mprof = mprof + prof;
			}
		}
	}
	fin.close();
return 0;}

int monthprofit()
{
	cout << "Enter month\n";
	cin >> cm;
	cout << "Enter year\n";
	cin >> cyear;
	ifstream fin("profits.dat", ios::binary | ios::in);
	while (!fin.eof())
	{
		fin >> cd1.bm >> cd1.byear;
		fin >> prof;
		if (cd1.bm == cm && cd1.byear == cyear)
			mprof = mprof + prof;
	}
	cout << cd1.bm << "-" << cd1.byear << ":profit=" << mprof << "\n";
	fin.close();
return 0;}

int monthlyprofit()
{
	int pd = 0;
	cout << "Enter the  begining month and ending month\n";
	cin >> cm >> dm;
	cout << "Enter the  begining year and ending year\n";
	cin >> cyear >> dyear;
	ifstream fin("profits.dat", ios::binary | ios::in);
	while (!fin.eof())
	{
		fin >> cd1.bm >> cd1.byear;
		fin >> prof;
		if (cd1.bm == cm && cd1.byear == cyear)
		{
			while (cd1.bm != dm && cd1.byear != dyear)
			{
				fin >> cd1.bm >> cd1.byear;
				fin >> prof;
				if (pd == 0 || pd != cd1.bm)
					mprof = prof;
				pd = cd1.bm;
				cout << cd1.bm << "-" << cd1.byear << ":profit=" << mprof << "\n";
				if (pd != 0)
					mprof = mprof + prof;
			}
		}
	}
	fin.close();
return 0;}

int yearprofit()
{
	cout << "Enter year\n";
	cin >> cyear;
	ifstream fin("profits.dat", ios::binary | ios::in);
	while (!fin.eof())
	{
		fin >> cd1.byear;
		fin >> prof;
		if (cd1.byear == cyear)
			mprof = mprof + prof;
	}
	cout << cd1.byear << ":profit=" << mprof << "\n";
	fin.close();
return 0;}

int yearlyprofit()
{
	int pd = 0;
	cout << "Enter the  begining year and ending year\n";
	cin >> cyear >> dyear;
	ifstream fin("profits.dat", ios::binary | ios::in);
	while (!fin.eof())
	{
		fin >> cd1.byear;
		fin >> prof;
		if (cd1.byear == cyear)
		{
			while (cd1.byear != dyear)
			{
				fin >> cd1.byear;
				fin >> prof;
				if (pd == 0 || pd != cd1.byear)
					mprof = prof;
				pd = cd1.byear;
				cout << cd1.byear << ":profit=" << mprof << "\n";
				if (pd != 0)
					mprof = mprof + prof;
			}
		}
	}
	fin.close();
return 0;}
