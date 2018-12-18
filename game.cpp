#include <iostream>
#include <string.h>
using namespace std;

class PLAYER {
	int age;
	char name[20];
public:
	PLAYER();
	PLAYER(int a, char _name[20]);
	char* getPlayerName();
	int getPlayerAge();
};

class GAME {//:public FileManager{
	char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
	int checkWin();
	void drawBoard();
public:
	void start();
};


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/
void GAME::drawBoard() {
	system("clear");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

/*********************************************

	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/
int GAME::checkWin() {
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}

void GAME::start() {
	int cur = 1,i,choice;
	char mark;

	PLAYER players[2] = {PLAYER(2, "Jamie"), PLAYER(4, "Jack")};
	do
	{
		try {
			drawBoard();
		} catch(...) {
			cout << "Unable to draw a board" << endl;
			exit(0);
		}
		cur=(cur%2)?1:2;

		cout << "Player: " << players[cur-1].getPlayerName() << ", enter a number:  ";
		cin >> choice;

		mark=(cur == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			cur--;
			cin.ignore();
			cin.get();
		}
		i=checkWin();

		cur++;
	}while(i==-1);
	drawBoard();
	if(i==1)

		cout<<"==>\aPlayer "<<players[cur--].getPlayerName()<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
}

PLAYER::PLAYER() {
	age = 10;
	strcpy(name, "Rohan");
}
PLAYER::PLAYER(int a, char _name[20]) {
	age = a;
	strcpy(name, _name);
}
char* PLAYER::getPlayerName(){
	return name;
}
int PLAYER::getPlayerAge() {
	return age;
}

int main() {
	GAME g;
	g.start();

	return 0;
}
