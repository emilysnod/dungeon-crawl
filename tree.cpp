/*
Emily Snodgrass
cs202 program 3
game.h
8/8/22
*/
#include"tree.h"

node::node() : event(nullptr), left(nullptr), right(nullptr) {}
node::~node() {}

void node::setEvent(Event* newEvent)
{event = newEvent;}

node *& node::getLeft()
{return left;}

bool node::hasRight()
{
	if(right == nullptr)
		return false;
	return true;
}

bool node::hasLeft()
{
	if(left == nullptr)
		return false;
	return true;
}

node *& node::getRight()
{return right;}

void node::setLeft(node* newLeft)
{
	left = newLeft;
	return;
}

void node::setRight(node* newRight)
{
	right = newRight;
	return;
}
int node::getReward()
{return event->getReward();}

void node::display()
{
	event->display();
	return;
}


/********************************************************************/
Tree::Tree() : root(nullptr) {}
Tree::~Tree(){}
node*& Tree::getRoot()
{return root;}

void Tree::insert(node *& root, Event* toAdd)
{
	//root needs to be a reference but will not bond when calling right and left
	if(root == nullptr)
	{
		root = new node;
		root->setEvent(toAdd);
		root->setLeft(nullptr);
		root->setRight(nullptr);
		return;
	}
	if(toAdd->getReward() >= root->getReward())
		insert(root->getRight(), toAdd);
	else if(toAdd->getReward() < root->getReward())
		insert(root->getLeft(), toAdd);
	return;
}

void Tree::removeAll(){}

void Tree::displayAll()
{
	if(!root)
		cout << "board is empty" << endl;
	else
		displayAll(root);
	return;
}

void Tree::displayAll(node*& root)
{
	if(!root)
		return;

	displayAll(root->getLeft());
	root->display();
	displayAll(root->getRight());

	return;
}

void Tree::buildBoard()
{
	// like 10 spaces?
	int totalSpaces {10};
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,5); // random assignment of which obstacle is added to the node
	int obstacle = distribution(generator);

	for(int addedSpace = 0; addedSpace < totalSpaces; ++addedSpace)
	{
		// make a node with random event and add it to the tree
		switch(obstacle)
		{
			case 1:
				//frozen event object, insert and sort by number of points
				Event* freeze;
				freeze = new Frozen;
				insert(root, freeze);
				break;
			case 2:
				Event* thief;
				thief = new Thief;
				insert(root, thief);
				break;
			case 3:
				Event* backtrack;
				backtrack = new Backtrack;
				insert(root, backtrack);
				break;
			case 4:
				Event* trail;
				trail = new RainbowTrail;
				insert(root, trail);
				break;
			case 5:
				Event* shield;
				shield = new Shield;
				insert(root, shield);
				break;
		}

		obstacle = distribution(generator);
	}
	return;
}

