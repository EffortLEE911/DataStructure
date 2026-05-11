#include <iostream>
#include <vector>
#include <Windows.h>


using namespace std;

vector<vector<string>> map(9, vector<string>(9, " "));
vector<string> my_hp = { "O", "O" ,"O" ,"O" ,"O" };
vector<string> enemy_hp = { "x", "x" ,"x" ,"x" ,"x", "x", "x" };

void show_hp();
void attack(int t);
void enemy_heal();

int main()
{
	string n = "";

	for (int i = 0; i < 5; i++)
	{
		show_hp();
		cout << "공격하려면 아무 버튼이나 누르시오." << endl;
		cin >> n;

		attack(300);
		show_hp();
		if (i == 2)
		{
			Sleep(1000);
			enemy_heal();
		}
	}
	


}

void show_hp()
{

	system("cls");

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			map[y][x] = " ";
		}
	}

	cout << endl << "   My HP : ";
	for (int i = 0; i < my_hp.size(); i++)
	{
		cout << my_hp[i] << " ";
	}
	cout << endl;
	cout << "Enemy HP : ";
	for (int i = 0; i < enemy_hp.size(); i++)
	{
		cout << enemy_hp[i] << " ";
	}
	cout << endl << endl;


	for (int i = 0; i < my_hp.size(); i++)
	{
		map[8 - i][8] = my_hp[i];
	}

	for (int i = 0; i < enemy_hp.size(); i++)
	{
		map[8 - i][0] = enemy_hp[i];

	}

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cout << map[y][x];
		}

		cout << endl;
	}


}

void attack(int t)
{
	int timer = t;

	for (int i = 6; i > 1; i--)
	{
		Sleep(timer);
		system("cls");

		map[5][i] = "A";
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{

				cout << map[y][x];
			}

			cout << endl;
		}
		map[5][i] = " ";

	}

	for (int i = 0; i < 8; i++)
	{
		Sleep(200);
		system("cls");
		if (i % 2 == 0)
		{

			for (int y = 0; y < 9; y++)
			{
				for (int x = 0; x < 9; x++)
				{
					if (x == 0)
						cout << " ";
					else
						cout << map[y][x];
				}

				cout << endl;
			}
		}
		else
		{

			for (int y = 0; y < 9; y++)
			{
				for (int x = 0; x < 9; x++)
				{

					cout << map[y][x];
				}

				cout << endl;
			}
		}
	}

	enemy_hp.pop_back();
	enemy_hp.pop_back();

}

void enemy_heal()
{

	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		system("cls");
		if (i % 2 == 0)
		{

			for (int y = 0; y < 9; y++)
			{
				for (int x = 0; x < 9; x++)
				{
					if (x == 0)
						cout << " ";
					else
						cout << map[y][x];
				}

				cout << endl;
			}
		}
		else
		{

			for (int y = 0; y < 9; y++)
			{
				for (int x = 0; x < 9; x++)
				{

					cout << map[y][x];
				}

				cout << endl;
			}
		}
	}
	
	enemy_hp.push_back("x");
	enemy_hp.push_back("x");
	enemy_hp.push_back("x");


}
