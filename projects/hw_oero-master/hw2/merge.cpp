#include <iostream>
#include <cstdlib>

using namespace std;



struct Node
	{
		int value;
		Node *next;
	};

Node* merge(Node*& first, Node*& second)
{

	Node* temp;
	//first check if the list is empty, if so return NULL
	if(first == NULL && second == NULL)
	{
		return NULL;
	}

	//if the first list is empty just return the second list
	if(first == NULL)
	{
		Node* kanye;
		kanye = second;
		return kanye;
	}

	//if the second list is empty, return the first list
	if(second == NULL)
	{
		Node* rose;
		rose = first;
		return rose;
	}
	//first check which one of the two nodes is smaller
	if(first->value < second->value)
	{
		temp = first;
		first->next = merge(temp->next, second);
		first = NULL;
		second = NULL;
		return temp;
		
		
	}
	else
	{
		temp = second;
		second->next = merge(first, temp->next);
		first = NULL;
		second = NULL;
		return temp;

		
		
	}


}

int main()
{
	Node *a = new Node;
	Node *b = new Node;
	Node *c = new Node;

	a->next = b;
	a->value = 10;
	b->next = c;
	b->value = 20;
	c->next = NULL;
	c->value = 100;

	Node *j = new Node;
	Node *k = new Node;
	Node *l = new Node;

	j->next = k;
	j->value = 15;
	k->next = l;
	k->value = 20;
	l->next = NULL;
	l->value = 35;

	Node *order;

	order = merge(a, j);
	while(order != NULL)
	{
		cout << order->value << endl;
		order = order->next;
	}



	


}