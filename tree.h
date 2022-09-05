/*
Emily Snodgrass
cs202 program 3
tree.h
8/2/22

*/
#include"game.h"

class node
{
	public:
		node();
		~node();
		void setEvent(Event*);
		node*& getLeft();
		node*& getRight();
		void setLeft(node*);
		void setRight(node*);
		bool hasRight();
		bool hasLeft();
		int getReward();
		void display();

	private:
		Event * event;
		node * left;
		node * right;
};


class Tree
{
	public:
		Tree();
		~Tree();
		void removeAll();
		void displayAll();
		void buildBoard();
		node*& getRoot();

	private:
		void displayAll(node*&);
		void insert(node*&, Event*);
		void removeAll(node*);
		node * root;
};


class Player // keeps track of players points, if playing with more than one player this determines who wins
{
	public:
		Player();
		Player(string, node*);
		int move(int);
		void changePoints(int);
		int comparePts(int);
		void displaySpace();
		void displayPlayer();
		bool atEnd();

	private:
		string name;
		int totalPoints;
		int movesMade;
		node * currentSpace;
};
