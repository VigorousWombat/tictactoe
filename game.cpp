#include "game.h"

	void Game::Game_Style_Select() {
		
		menu = Print_Menu();
	
		switch (menu) {
			case 0:
				Game_Start_Random();
				break;
			case 1:
				Game_Start();
				break;
			case 2:
				Game_Start();
				break;
			case 3:
				Endgame();
		}
	}

	int Game::Print_Menu() {
		
		unsigned int number = 0;

		while (true) {
			
			cout << "\033[32m" << " Select game style by entering number. Options: \n\n" << "\033[0m";
			cout << " [ 0 ] Dummy computer vs. Dummy computer \n";
			cout << " [ 1 ] Human vs. Human \n";
			cout << " [ 2 ] Human vs. Dummy Computer \n";
			cout << " [ 3 ] Stop program \n";
			//If user input has no number...
			while (!(cin >> number)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << " Bad data. Try again: ";
			}
			if (menu < 0 && number > 3) {
				cout << "\n Bad data. Try again. ";
			}
			else {
				return number;
			}
		}
	}

	void Game::Game_Start_Random() {
		cout << "\n Game start. \n\n";
		Print_table();
		turn = 0;
		while (turn < MAX_TURN) {

			if (turn % 2 == 0) {
				player = 'X';
				Move_Random();
			}
			else {
				player = 'O';
				Move_Random();
			}
			Winner(player);
			turn++;
			cout <<"\033[34m"<< "TURN " << turn << "\033[0m" << "\n";
		}

		cout << "\n Full table, no winner this time.\n";
	}

	void Game::Game_Start() {
		cout << "\n Game start. \n\n";
		Print_table();
		turn = 0;
		while (turn < MAX_TURN) {

			if (turn % 2 == 0) {
				player = 'X';
			}
			else{
				player = 'O';
			}
			if (menu == 2 && player == 'O') {
				cout << "\nComputer turn...";
				Sleep(500); // ms delay
				cout << "massive calculation...\n";
				Sleep(500); // ms delay
				Move_Random();
			}
			else {
				Move(player);
			}
			Winner(player);
			turn++;
			cout << "\033[34m" << "TURN " << turn << "\033[0m" << "\n";
		}
		cout << "\n Full table, no winner this time.\n";
	}

	void Game::Winner(char player) {

		int count = 0;

		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				// vino, vasen kulma
				if (i == 0 && j == 0) {
					if (table[i][j] == player && table[i + 1][j + 1] == player && table[i + 2][j + 2] == player
						&& table[i + 3][j + 3] == player) {
						count++;
						//cout << "\n 1 TESTI ";
					}
				}
				// pysty
				if (i == 0) {
					if (table[i][j] == player && table[i + 1][j] == player && table[i + 2][j] == player
						&& table[i + 3][j] == player) {
						count++;
						//cout << "\n 2 TESTI " << i << j << " " << i + 1 << j << " " << i + 2 << j << " " << i + 3 << j;
					}
				}
				// vino, oikea kulma
				if (i == 0 && j == (COL - 1)) {
					if (table[i][j] == player && table[i + 1][j - 1] == player && table[i + 2][j - 2] == player
						&& table[i + 3][j - 3] == player) {
						count++;
						//cout << "\n 3 TESTI ";
					}
				}
				// vaaka
				if (j == 0) {
					if (table[i][j] == player && table[i][j + 1] == player && table[i][j + 2] == player
						&& table[i][j + 3] == player) {
						count++;
						//cout << "\n 4 TESTI ";
					}
				}
			}
		}
		if (count == 1) {
			cout << "\n The Winner is " << player << "\n";
			Endgame();
		}
	}

	void Game::Print_table() {
		cout << "   A B C D \n";
		for (int i = 0; i < ROW; i++) {
			cout << " " << i;
			for (int j = 0; j < COL; j++) {
				if (table[i][j] == 'X') {
					cout << " " << "\033[91m" << table[i][j] << "\033[0m";
				}
				else if(table[i][j] == 'O'){
					cout << " " << "\033[96m" << table[i][j] << "\033[0m";
				}
				else {
					cout << " " << table[i][j];
				}
			}
			cout << "\n";
		}
	}

	void Game::Endgame()
	{
		cout << " Game over. \n";
		exit(0);
	}

	void Game::Move(char player) {

		char y_select;
		
		while (true) {
			cout << "\n PLAYER " << player << ": \n Choose row [0, 1, 2] and column [A, B, C] : ";
			// For int x this while loop is checking valid input. It should only be numbers.
			while (!(cin >> x)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << " Bad data. Try again: ";
			}
			if (x >= 0 && x <= (ROW - 1)) {
				cin >> y_select;
				while ((y_select < 'A' || y_select > 'D') && (y_select < 'a' || y_select > 'd')) {
					cout << " Bad data. Try again: ";
					cin >> y_select;
				}
				y = Chech_input_character(y_select);
				if (table[x][y] == '-') {
					table[x][y] = player;
				//	cout << " Player " << player << " choise was (" << x << "," << y << ").\n\n";
					break;
				}
				else {
					cout << " Impossible move. Cell not empty. Try again.\n ";
				}
			}
			else {
				cout << " Impossible move. Try again.\n ";
			}
		}
		Print_table();
	}
	//for testing purposes.
	void Game::Move_Random() {

		int error = 1;
		int some_number = 1;
		int some_n = 1;
		
		srand(time(NULL));

		while (error != 0) {
			x = rand() % COL;
			y = rand() % ROW;

			if (table[x][y] == '-') {
				table[x][y] = player;
			//	cout << "\n Computer " << player << " choise was (" << x << "," << y << ").\n";
				error = 0;
			}
			else {
				error = 1;
			}
			//Sleep(100); // ms delay
		}
		Print_table();
	}

	int Game::Chech_input_character(char y) {

		if (y == 'A' || y == 'a') {
			return 0;
		}
		else if (y == 'B' || y == 'b') {
			return 1;
		}
		else if (y == 'C' || y == 'c') {
			return 2;
		}
		else if (y == 'D' || y == 'd') {
			return 3;
		}
	}
