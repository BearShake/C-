#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "WinDef.h"
#include  "time.h"

using namespace std;

namespace LIFO
{
    template<class T>
class Sarakststemplate{
	struct elem{
		T num;
		elem *next;
	};
	private:
		T x,dz,length;
		elem * first = NULL, *last = NULL, *p = NULL, *node = NULL;
		int lg;
	public:

		BYTE getByteofStruct(){
			return sizeof(struct elem);
		}

		void pievien(T x)
		{
			p = new elem;
			p->num = x;
			p->next = NULL;

			if(first == 0){
				first = last = p;
			}else{
				last->next = p;
				last = last ->next;
			}
			lg++;
		}

		void izvad()
		{
			for (p = first; p != NULL; p = p->next){
				cout << p->num << endl;
			}
			cout << endl;
		}

		void del()
		{
			p = first;
			while(p != NULL){
				first = first->next;
				delete p;
				p = first;
			}
		}

		void deleteelem(T dz) //te noradita vieta,kura bus nodzesta ar elementu taja
		{
			int temp = 0;
			int i;

				for (p = first; p != NULL; p = p->next){
					temp++;
				}
				this->length = temp;

				if (dz > temp ) cout << "Saraksta nav elemena ar tadu vietas numuru "<< endl;
				else{
					p = first;
					i = 0;
					if(dz == 1){
						elem *p3 = p->next;
						delete p;
						first = p3;
					}else{
						i = 0;
						while(i+2 < dz){
							p=p->next;
							i++;
						}
						elem *p2 = p->next;
						p->next=p->next->next;
						delete p2;
					}
				}
		}

		void delelementv2(T dz)//Nav pabeigts,strada nepareizi,   metode ir paredzeta nodzesanai visiem elementiem, kuri vienadi ar lietotaja ievadito
		{
			int count = 0;
			int temp = 0;
			int i = 0;
			p = first;
			elem *ped = NULL;
			if(first->num == dz){
				first = p->next;
				delete first;
			}else{
				for(p = first;p->next != NULL; p = p->next){
					count++;
					ped = p;
				}
					if(ped->num == dz) delete ped;
					else{

						p = first;
						while(p->next != NULL){
							p = p->next;
							if(p->next->num == dz ){
								elem *p2 = p->next;
								p->next = p->next->next;
								delete p2;
								cout << "Tika izdests elements ar vietu " << i << endl;

							}
							temp++;
							i++;
						}

						if (temp == 0){
							cout << "Jusu saraksta nav tada elementa" << endl;
						}

					}
			}
		}

	

		void push(T el){

            p = new elem();
            p->num = el;
            p->next = first;
            first = p;


		}

	


        T popLIFO(){

            if (first == NULL){
 					return 0;
 					
            }else{
                elem *rt = new elem();
                rt = first;
                T ret = rt->num;
               
                first = first->next;
                delete rt;
                return ret;
            }

        }


        void pushLIFO(T n){
        	
        	if(first == NULL){
        		
        		elem *temp = new elem();
            	temp->num = n;
            	first = last = temp;
			}else{
				elem *temp = new elem();
            	temp->num = n;
            	temp->next = first;
            	first = temp;
			}  
        }
        
        

        void addFIFO(T a){
        	
        	elem *temp = last;
        	last = new elem();
        	last->num = a;
        	
        	if(first == NULL){
        		first = last;
			}else{
				
        		temp->next = last;		
			}
        	

            
        }

        T popFIFO(){


            elem *temp = new elem();
            T i = 0;
            i = first->num;
            temp = first->next;
            delete first;
            if(first == NULL) first == NULL;
            first = temp;
            return i;
            
        }



        void sortList(){
        	
        elem *t1;	
        
        	for(p = first; p!=NULL; p=p->next){
        		for(t1 = first; t1->next!=NULL; t1 = t1->next){
        			if(p->num < t1->num){
        				swap(t1,p);
					}
				}
			}	
		}
		
		void Merge(elem *p, elem *first, elem *last){
			
			
		}
	
	/*	
		void mergeSort(elem* p, elem *first , elem *last){
			elem *center = NULL;
			if(first->num < last->num){
			
				lg/2-1
				mergeSort();
				mergeSort();
				Merge(elem*p, elem* first, elem *last);
			}
			
			
		}
	*/	
		void swap(elem *t1, elem *t2){
			T temp = NULL;
			temp = t1->num;
			t1->num = t2->num;
			t2->num = temp;
			
		}

};




}




int main(){
	int xx,del,vieta,el,piev;
	LIFO::Sarakststemplate <int>x;
    
    /*
    for(int i = 0;i<1500000;i++){
		x.addFIFO(rand() % 20);
			
	}
	
	
	for(int j = 0;j<1500000;j++){
		x.popFIFO();
	}
	*/
	
	
	
	//TEST FOR LIFO
	/*
	for(int i = 0;i<5;i++){
		cin >> xx;
		x.pushLIFO(xx);
	}
	cout << endl;
	x.izvad();
	cout << x.popLIFO();
	x.izvad();
	*/
	
	for (int i = 0;i<1500000;i++){
		x.pushLIFO(rand() %20);
	}
	
	for(int j = 0 ;j<1500000;j++){
		x.popLIFO();
	}
	
	
	
    
    /*
    for(int i = 0;i<50000;i++){
    	x.pushFIFO(rand( ) % 20);    	
	}
	
	for( int j; j<50000;j++){
		x.popFIFO();
	}
	*/
	
	
	



	return 0;
}
