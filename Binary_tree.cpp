#include <iostream>;
#include "stdlib.h"
using namespace std;

struct Node
{
	int x;
	Node *l, *r;
	
};

void print(Node *&tr){
	
	if(tr!=NULL)
	{
		print(tr->l);
		cout << tr->x;
		print(tr->r);	
	}
	
}

void add(int x, Node *&tr){
	if(NULL == tr){
		tr = new Node;
		tr->x = x;
		tr->l=tr->r=NULL;
	}
	if (x < tr->x)
	{
		if(tr->l!=NULL) add(x,tr->l);
		else
		{
			tr->l = new Node;
			tr->l->l = tr->l->r = NULL;
			tr->l->x = x;	
		}
	}
	
	if(x > tr->x){
		if(tr->r!=NULL) add(x,tr->r);
		else
		{
			tr->r = new Node;
			tr->r->l = tr->r->r=NULL;
			tr->r->x = x;
		}
	}
	
}


int main(){
	Node *tree = NULL;
	print(tree);
	
	for(int i = 5;i>0;i--){
		add(i,tree);
	}
	print(tree);
	cin.get();
	
	
	
	return 0;
}
