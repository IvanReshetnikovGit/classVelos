#include<iostream>
	
using namespace std;
	
class Bycicle
{
public:
	void OnBike()
	{
		bool PositionOfHuman{ true };
		int i{};
		bool DriveCondition{};
		int CurrentGear{};

		cout << "What`s you`re current gear in range of 1 to 12?: ";
		cin >> CurrentGear;
		while (CurrentGear < 1 || CurrentGear > 12) 
		{
			if (CurrentGear < 1 || CurrentGear > 12)
				cout << "\nGear must be in range of 1 to 12, try again" << endl;

			cout << "Whats you`re current gear in range of 1 to 12?: ";
			cin >> CurrentGear;
		}
		while (PositionOfHuman)
		{
			cout << "\nWhat would you like to do?:" << endl;
			cout << "1.Drive" << endl;
			cout << "2.Change gear" << endl;
			cout << "3.Hit brakes" << endl;
			cout << "4.Get off bike" << endl << endl;
			cout << "Current gear is " << CurrentGear << endl << endl;
			cin >> i;
			switch (i) {
			case 1:
				drive(DriveCondition);
				break;

			case 2:
				if (DriveCondition)
				{
					switchGear(CurrentGear);
				}
				else {
					cout << "You can`t change gears while standing." << endl;
				}
				break;
			case 3:
				if (DriveCondition)
				{
					cout << "Almost fallen while breaking" << endl;
					DriveCondition = false;
				}
				else
				{
					cout << "It`s a good decision to hit brakes while standing" << endl;
				}
				break;

			case 4:
				if (DriveCondition==false)
				{
					cout << "\nYou got off you`re magnificent bike :(" << endl;
					PositionOfHuman = false;
				}
				break;

			}
		}
	}


private:
	void drive(bool& DriveCondition)
	{
		cout << "You`re driving" << endl;
		DriveCondition = true;
	}

	void switchGear(int& CurrentGear)
	{
		int UpDown;
		if (CurrentGear == 1)
		{
			cout << "You can only switch up\n 1.Switch up" << endl;
			cin >> UpDown;
			if (UpDown == 1)
				CurrentGear++;
			else
				cout << "Choose correct option" << endl << endl;
		}
		else if (CurrentGear == 12)
		{
			cout << "You can only switch down\n 1.Switch down" << endl;
			cin >> UpDown;
			if (UpDown == 1)
				CurrentGear--;
			else
				cout << "Choose correct option" << endl << endl;
		}
		else {
			cout << "1.Switch up\n2.Switch down" << endl;
			cin >> UpDown;
			if (UpDown == 1)
				CurrentGear++;
			
			else if(UpDown == 2)
				CurrentGear--;
			else
				cout << "Choose correct option" << endl << endl;
			
		}
	}
};

int main()
{
	bool Pos;
	Bycicle myBike;
	cout << "Get on bike?\nYes = 1 or No = 0: ";
	cin >> Pos;
	if (Pos)
	{
		myBike.OnBike();
	}
	else
	{
		cout << "\nNot good enough? Huh?" << endl;;
	}

	system("pause");
	return 0;
}