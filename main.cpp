/******************************************************************************
C++
Visual Studio
(simple) tictactoe game

author
E. Kristo
2022

This game works in terminal. Coordinates for character are form, example, 1A, 1a, 1 a...
Invalid input are tested. 
There is opponent, which is very stupid. It's just make pure random movements.

notes for future:
-'table' should have various sizes
- Make harder opposite
- Also coordinates need fixing (it works though, but presentation should be better)
*******************************************************************************/

#include "game.h"

int main() {

	Game tictac;

	tictac.Game_Style_Select();
	
	return 0;
}