/*
Emily Snodgrass
cs202 program 3
game.h
8/8/22
*/
#include"tree.h"

Player::Player() : name(NULL), totalPoints(0), movesMade(0), currentSpace(nullptr) {}

Player::Player(string theName, node * root) :
name(theName), totalPoints(0), movesMade(0), currentSpace(root) {}

bool Player::atEnd()
{
	if(currentSpace->hasRight() || currentSpace->hasLeft())
		return false;
	return true;
}

int Player::move(int spacesToMove)
{
	int move {0};
	do
	{
		while(move < 1 || move > 2)
		{
			cout << "Which passage do you take, (1) right or (2) left?" << endl;
			cin >> move;
			cin.ignore(100, '\n');
		}
		--spacesToMove;
		++movesMade;

		if(move == 1)
		{
			currentSpace = currentSpace->getRight();
		}
		else 
			currentSpace = currentSpace->getRight();
	} while(spacesToMove > 0);
	return spacesToMove;
}

void Player::changePoints(int add)
{
	totalPoints += add;
}

void Player::displaySpace()
{
	currentSpace->display();
}

void Player::displayPlayer()
{
	cout << "Name: " << name << endl;
	cout << "Total moves made: " << movesMade << endl;
	cout << "Total points: " << totalPoints << endl;
	return;
}

int Player::comparePts(int)
{ return 0;}



/********************************************************************/
Event::Event() : reward(0)
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(3,10);
	reward = distribution(generator);
}
Event::~Event() {}

int Event::getReward()
{return reward;}


Frozen::Frozen()
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(-4,-1);
	losePoints = distribution(generator);
}
Frozen::~Frozen(){}
int Frozen::activate() {return 0;}
void Frozen::display()
{
	cout << "Oh no! The ice cold room has frozen you for a turn and your point stack as changed by " << losePoints << " points." << endl;
}
int Frozen::disable() { return 0;}


/********************************************************************/
Thief::Thief(){}
Thief::~Thief(){}
int Thief::activate(){return 0;}
void Thief::display()
{
	cout << "Thief stole " << losePoints << " points." << endl;
	return;
}

int Thief::disable(){return 0;}


/********************************************************************/
Backtrack::Backtrack(){}
Backtrack::~Backtrack(){}
int Backtrack::activate(){return 0;}
void Backtrack::display()
{
	cout << "Looks like a this path loops back to the beginning :(" << endl;
	return;
}
int Backtrack::disable(){return 0;}


/********************************************************************/
RainbowTrail::RainbowTrail(){}
RainbowTrail::~RainbowTrail(){}
int RainbowTrail::activate(){return 0;}
void RainbowTrail::display()
{
	cout << "You've found a secret passage, congrats, you get to skip a room." << endl;
	return;
}
int RainbowTrail::disable(){return 0;}


/********************************************************************/
Shield::Shield(){}
Shield::~Shield(){}
int Shield::activate(){return 0;}
void Shield::display()
{
	cout << "Shield activated! Nothing bad will happen to you in the next room\n";
	cout << "(but nothing good either)\n" << endl;
	return;
}
int Shield::disable(){return 0;}
