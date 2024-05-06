#include <iostream>
using namespace std;

class TicTacToe
{
private:
	char grid[3][3];
	char player;//'X' or 'Y'
public:
	TicTacToe() {								// constructor.
		player = 'X';
		for (int  i = 0; i < 3; i++)
		{
			for (int  j = 0; j < 3 ; j++)
			{
				grid[i][j] = '-';
			}
		}
	}
	//<------------------------------>
	void display()const {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	//<------------------------------->
	void switchplayer() {
		//player = 'X' ? 'Y' : 'X';		// ternary operator.
		if (player == 'X')
			player = 'Y';
		else
		player = 'X';
	}
	//<------------------------------>
	bool isGameOver() {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] == '-') {
					return false;
				}
			}
		}
		return true;
	}
	//<---------------------------->
	bool Winner  () {
		for (int i = 0; i < 3; i++)
		{
			if ((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) || (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player))
							return true;
			else if (i == 0) {
				if (grid[i][i] == player && grid[i + 1][i + 1] == player && grid[i + 2][i + 2]==player)
					return true;
				if (grid[i][2] == player && grid[i + 1][1] == player && grid[2][i]==player )
					return true;
			}
			
		}
		return false;
	}
	//<--------------------------->
	bool move() {
		cout << "Player " << player << "`s turn is now Enter position:";
		int row = 0;
		int col = 0;
		cin >> row >> col;
		if ((row < 0 || row>2) || (col < 0 || col>2) || grid[row][col] != '-'){
			cout << "Error Try Again ";
			return false;
		}
			
		grid[row][col] = player;
		display();
		return true;
	}
	//<-------------------------->
	void playgame() {
		while (1) {

			if (move()) {

				if (isGameOver()) {
					cout << "Game has been over."<<endl;
					break;
				}
				if (Winner()) {
					cout << "!!!!!!!!!!!Congratulations!!!Player " << player << " has won the game.!!!!!!!!!!!!"<< endl;
					break;
				}
				switchplayer();
			}
		}
	}
	//<---------------------------->
};

int main()
{
	TicTacToe game1;
	game1.display();
	game1.playgame();
	game1.display();
}