#include <time.h>
#include <iostream>
#include <windows.h>

using namespace std;

#define		ROW			4		
#define		COL			4
#define		MAX_TURN	16

class Game {

private:
	int x;		 // horizontal 
	int y;		 // vertical
	char player; // for X or O
	int turn;	 // keep track
	int menu;	 // value for selectin game style

	char table[ROW][COL] = { '-','-','-','-',
							 '-','-','-','-',
							 '-','-','-','-',
							 '-','-','-','-',};

public:
	int Print_Menu();
	void Game_Style_Select();
	void Game_Start_Random();
	void Game_Start();
	void Winner(char player);
	void Print_table();
	void Endgame();
	void Move(char player);
	void Move_Random();
	int Chech_input_character(char y);
};