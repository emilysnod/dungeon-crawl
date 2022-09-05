/*
Emily Snodgrass
cs202 program 3
game.h
8/8/22
main file for game
*/
#include"tree.h"

int main()
{
	string name = intro();
	Tree board;
	board.buildBoard();
	// to see whole board
	//board.displayAll();

	Player player1(name, board.getRoot());

	//start while player pointer has eather a right or a left
	while(player1.atEnd() == false)
	{
		int movesLeft = player1.move(1); //hewp
		player1.changePoints(5);
		player1.displaySpace();
	}
	
	cout<< "Congrats, youve made it to the end. Here are your player stats." << endl;
	player1.displayPlayer();

	return 0;
}


string intro()
{
	string name {"\000"};

	cout << "\nWelcome to Dungeon crawler, where you can crawl through a dungeon all by\n";
	cout << "yourself and see if you can make it to the end without fainting!\n";
	cout << "If you run out of points, you'll faint and have to be carried out of the dungeon\n\n";
	cout << "To start out, enter your player name: ";
	getline(cin, name);
	cout << name << endl;;
	return name;
}

