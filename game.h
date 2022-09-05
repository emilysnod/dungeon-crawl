/*
Emily Snodgrass
cs202 program 3
game.h
8/2/22
this file contains all the possible spaces that can be added to the board, all derived form an event
*/

/*
Notes
essentially candyland
3 obstacle, 1 shield, 1 prize(here more of a shortcut), all derives form the base class with same funtionality all must have: activate,
display, disable. all pure virtual functions
one function must be differnt than those 3 funcitons, and be in either shieled of prize
virtual destructor in base class
*/
#include<string>
#include<random>
#include<iostream>

using namespace std;

void menu();
string intro();

class Event // each space has an event
{
	public:
		Event();
		virtual ~Event();
		int getReward();
		virtual int activate() = 0;
		virtual void display() = 0;
		virtual int disable() = 0;

	private:
		int reward;

};

class Frozen : public Event // lose a turn
{
	public:
		Frozen();
		~Frozen();
		int activate();
		void display();
		int disable();

	private:
		int losePoints;
};

class Thief : public Event // lose points
{
	public:
		Thief();
		~Thief();
		int activate();
		void display();
		int disable();

	private:
		int losePoints;
};

class Backtrack : public Event // go back to the beginning
{
	public:
		Backtrack();
		~Backtrack();
		int activate();
		void display();
		int disable();

	private:
		int backSpaces;
		int losePoints;
};

class RainbowTrail : public Event //skip the next space and extra points!
{
	public:
		RainbowTrail();
		~RainbowTrail();
		int activate();
		void display();
		int disable();

	private:
		int points;

};

class Shield : public Event // protected form both good and bad events, but extra points!
{
	public:
		Shield();
		~Shield();
		int activate();
		void display();
		int disable();

	private:
		int points;
};
