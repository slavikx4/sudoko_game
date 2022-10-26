#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "conio.h"
#include <utility>
#include <ctime>

#pragma warning(disable: 4996);

using namespace std;

void TableVisible(string table[4][4]);
bool check();
bool ReadyYesOrNo();
bool Right(int x, int y);
bool Left(int x, int y);
bool Down(int x, int y);
bool Up(int x, int y);
char Take(int x, int y, string table[4][4]);

int main() {

	srand(time(NULL));

	int x = 0;
	int y = 0;

	string tempTable[16] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
							"11", "12", "13", "14", "15", "..." };
	for (int i = 0; i < 16; i++) {
		int a = rand() % 16;
		int b = rand() % 16;
		if (a == b) {
			if (b == 15) {
				b--;
			}
			else {
				b++;
			}
		}
		swap(tempTable[a], tempTable[b]);
	}
	int index = 0;
	string table[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			table[i][j] = tempTable[index];
			index++;
		}
	}
	if (table[0][0] == "...") {
		swap(table[0][0], table[0][1]);
	}
	table[0][0] = "!" + table[0][0] + "!";
	
	if (!ReadyYesOrNo()) {
		cout << "You left, Bye";
		exit(1);
	}

	bool win = 0;
	do {
		TableVisible(table);
		int flag = getch();
		switch (flag) {
		case(75):
			if (Left(x, y)) {

				if (table[x][y].length() == 3) {
					table[x][y] = table[x][y][1];
				}
				else if (table[x][y].length() == 4) {
					table[x][y] = table[x][y].substr(1, 2);
				}
				else {
					table[x][y] = "...";
				}

				y--;
				table[x][y] = "!" + table[x][y] + "!";
			}
			break;
		case(77):
			if (Right(x, y)) {

				if (table[x][y].length() == 3) {
					table[x][y] = table[x][y][1];
				}
				else if (table[x][y].length() == 4) {
					table[x][y] = table[x][y].substr(1, 2);
				}
				else {
					table[x][y] = "...";
				}

				y++;
				table[x][y] = "!" + table[x][y] + "!";
			}
			break;
		case(72):
			if (Up(x, y)) {

				if (table[x][y].length() == 3) {
					table[x][y] = table[x][y][1];
				}
				else if (table[x][y].length() == 4) {
					table[x][y] = table[x][y].substr(1, 2);
				}
				else {
					table[x][y] = "...";
				}

				x--;
				table[x][y] = "!" + table[x][y] + "!";
			}
			break;
		case(80):
			if (Down(x, y)) {


				if (table[x][y].length() == 3) {
					table[x][y] = table[x][y][1];
				}
				else if (table[x][y].length() == 4) {
					table[x][y] = table[x][y].substr(1, 2);
				}
				else {
					table[x][y] = "...";
				}

				x++;
				table[x][y] = "!" + table[x][y] + "!";
			}
			break;
		case(13):
			switch (Take(x, y, table)) {
			case('R'):
				y++;
				break;
			case('L'):
				y--;
				break;
			case('U'):
				x--;
				break;
			case('D'):
				x++;
				break;
			}
			break;
		}
	} while (!win);
} 
bool ReadyYesOrNo() {
	bool ok = true;
	int flag = 75;
	while (flag != 13) {
		switch (flag) {
		case(75):
			cout << "\n\t\t Hello, my friend!!!\n\n" <<
				"\t\t It`s sudoko game.\n\n" <<
				"\t\t\tReady?\n\n" <<
				"\t\t\tYES/no" << endl;
			ok = true;
			break;
		case(77):
			cout << "\n\t\t Hello, my friend!!!\n\n" <<
				"\t\t It`s sudoko game.\n\n" <<
				"\t\t\tReady?\n\n" <<
				"\t\t\tyes/NO" << endl;
			ok = false;
			break;
		}
		flag = getch();
		system("cls");
	}
	system("cls");
	return ok;
}

void TableVisible(string table[4][4]) {
	system("cls");
	cout << "\t\tTable\n\n";
	cout << "\t";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << table[i][j] << '\t';
		}
		cout << endl;
		cout << "\t";
	}
}

bool Right(int x, int y) {

	if (y+ 1 == 4) {
		return 0;
	}
	else {
		return 1;
	}
}
bool Left(int x, int y) {
	if (y - 1 == -1) {
		return 0;
	}
	else {
		return 1;
	}
}
bool Up(int x, int y) {
	if (x - 1 == -1) {
		return 0;
	}
	else {
		return 1;
	}
}
bool Down(int x, int y) {
	if (x + 1 == 4) {
		return 0;
	}
	else {
		return 1;
	}
}
char Take(int x, int y, string table[4][4]) {

	if (Right(x, y) && (table[x][y + 1] == "...")) {
		string temp = table[x][y];
		table[x][y] = "...";
		y++;
		table[x][y] = temp;
		return 'R';
	}
	else if (Left(x, y) && (table[x][y - 1] == "...")) {
		string temp = table[x][y];
		table[x][y] = "...";
		y--;
		table[x][y] = temp;
		return 'L';
	}
	else if (Up(x, y) && (table[x - 1][y] == "...")) {
		string temp = table[x][y];
		table[x][y] = "...";
		x--;
		table[x][y] = temp;
		return 'U';
	}
	else if (Down(x, y) && (table[x + 1][y] == "...")) {
		string temp = table[x][y];
		table[x][y] = "...";
		x++;
		table[x][y] = temp;
		return 'D';
	}
}