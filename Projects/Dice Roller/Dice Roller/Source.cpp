using namespace std;
#include <iostream>
#include <ctime>
#include <cstdlib>

class die
{
private:
	int values[5];
public:
	void roll()
	{
		int randNum;

		for (int i = 0; i < 5; i++)
		{
			randNum = rand() % 6 + 1;
			values[i] = randNum;
		}
	}
	void showRoll()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << values[i];
		}
	}
	int count(int num)
	{
		int count;
		int roll1 = 0;
		int roll2 = 0;
		int roll3 = 0;
		int roll4 = 0;
		int roll5 = 0;
		int roll6 = 0;

		for (int i = 0; i < 5; i++)
		{
			if (values[i] == 1)
			{
				roll1++;
			}
			if (values[i] == 2)
			{
				roll2++;
			}
			if (values[i] == 3)
			{
				roll3++;
			}
			if (values[i] == 4)
			{
				roll4++;
			}
			if (values[i] == 5)
			{
				roll5++;
			}
			if (values[i] == 6)
			{
				roll6++;
			}
		}
		if (roll6 >= roll5 && roll6 >= roll4 && roll6 >= roll3
			&& roll6 >= roll2 && roll6 >= roll1)
		{
			num = 6;
			count = roll6;
		}
		else if (roll5 > roll6 && roll5 >= roll4 && roll5 >= roll3
			&& roll5 >= roll2 && roll5 >= roll1)
		{
			num = 5;
			count = roll5;
		}
		else if (roll4 > roll6 && roll4 > roll5 && roll4 >= roll3
			&& roll4 >= roll2 && roll4 >= roll1)
		{
			num = 4;
			count = roll4;
		}
		else if (roll3 > roll6 && roll3 > roll5 && roll3 > roll4
			&& roll3 >= roll2 && roll3 >= roll1)
		{
			num = 3;
			count = roll3;
		}
		else if (roll2 > roll6 && roll2 > roll5 && roll2 > roll4
			&& roll2 > roll3 && roll2 >= roll1)
		{
			num = 2;
			count = roll2;
		}
		else if (roll1 > roll6 && roll1 > roll5 && roll1 > roll4
			&& roll1 > roll3 && roll1 > roll2)
		{
			num = 1;
			count = roll1;
		}

		return count;
	}
	int numVal(int num)
	{
		int count;
		int roll1 = 0;
		int roll2 = 0;
		int roll3 = 0;
		int roll4 = 0;
		int roll5 = 0;
		int roll6 = 0;

		for (int i = 0; i < 5; i++)
		{
			if (values[i] == 1)
			{
				roll1++;
			}
			if (values[i] == 2)
			{
				roll2++;
			}
			if (values[i] == 3)
			{
				roll3++;
			}
			if (values[i] == 4)
			{
				roll4++;
			}
			if (values[i] == 5)
			{
				roll5++;
			}
			if (values[i] == 6)
			{
				roll6++;
			}
		}
		if (roll6 >= roll5 && roll6 >= roll4 && roll6 >= roll3
			&& roll6 >= roll2 && roll6 >= roll1)
		{
			num = 6;
			count = roll6;
		}
		else if (roll5 > roll6 && roll5 >= roll4 && roll5 >= roll3
			&& roll5 >= roll2 && roll5 >= roll1)
		{
			num = 5;
			count = roll5;
		}
		else if (roll4 > roll6 && roll4 > roll5 && roll4 >= roll3
			&& roll4 >= roll2 && roll4 >= roll1)
		{
			num = 4;
			count = roll4;
		}
		else if (roll3 > roll6 && roll3 > roll5 && roll3 > roll4
			&& roll3 >= roll2 && roll3 >= roll1)
		{
			num = 3;
			count = roll3;
		}
		else if (roll2 > roll6 && roll2 > roll5 && roll2 > roll4
			&& roll2 > roll3 && roll2 >= roll1)
		{
			num = 2;
			count = roll2;
		}
		else if (roll1 > roll6 && roll1 > roll5 && roll1 > roll4
			&& roll1 > roll3 && roll1 > roll2)
		{
			num = 1;
			count = roll1;
		}

		return num;
	}
	void result(int count, int num)
	{
		cout << "You rolled " << num << " on the die " << count << " time(s)" << endl << endl;
	}
};

void main()
{
	die obj;
	int count = 0;
	int num = 0;
	char key;

	srand(time(0));

	do
	{
		cout << "Roll: ";

		obj.roll();
		obj.showRoll();

		cout << endl;
		count = obj.count(num);
		num = obj.numVal(num);
		obj.result(count, num);

		cout << "Keep rolling? Y/N: ";
		cin >> key;
	} while (key == 'y' || key == 'Y');

	system("pause");
}