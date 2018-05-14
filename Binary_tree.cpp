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
		cout << tr->x << "  ";
		print(tr->r);	
	}
	
}



void print_treev2(Node *p, int level)
{
	{
        if(p){
                for(int i = 0; i < level; i++) cout << "--";
                cout << "Level: " << level << "; Element = " << p->x << endl; 
 				
                print_treev2(p->l, level);        
                print_treev2(p->r, level + 1);   
				   
        }
	}
}

void printv3(Node *tr, int x) {
    if (tr == NULL)
        return;  
    else {  
        printv3(tr->l, ++x);  
        for (int i = 0; i < x; ++i)
            cout << "|";
        cout << tr->x << endl; 
        x--;
        printv3(tr->r, ++x);  
    }
}



//tirisana
void del(Node *&tr)
{
	if(tr!= NULL ){
		del(tr->l);
		del(tr->r);
		delete tr;
		tr = NULL;
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


//return pointer
Node *search(int x, Node *&tr)
{
	
	if(tr!=NULL){
		if(tr->x == x) return tr;
		else {
			if(x < tr->x) search(x, tr->l);
			else return search(x, tr->r);
		}	
	}else{
		return NULL;
	}
	
	
}

//Test func
int main(){
	Node *tree = NULL;
	
	int t = 1;
	while (t != 0){
		cin >> t;
		add(t,tree);
	}
	printv3(tree, 0);

	cout << "search of 10 = " << search(10,tree)->x << endl;
	del(tree);
	return 0;	
}
	
	
	
	
	

