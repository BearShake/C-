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
		T x,dz;
		elem * first = NULL, *last = NULL, *p = NULL, *node = NULL;
		int length = 0;
		
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
			length += 1 ;
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
		
		
		
		
		void printXML(){
			cout << "<list>" << endl; 
			for(p = first; p !=NULL; p=p->next){ 
				cout << " <record>" << endl; 
				cout << " <item>"<< p->num << "</item>" << endl; 
				cout << " <link_on_item>"<< p << "</link_on_item>"<< endl; 
				cout << " <next_link>" << p->next <<"</next_link>"<< endl; 
				cout << " </record>" << endl; 
			} 
			cout << "</list>" << endl; 
			cout << endl << "Length - " << this->length << endl; 
	
		}
		
		void printJSON(){
			
			cout<< "{" << endl; 
			for(p = first; p !=NULL; p=p->next){ 
				cout << " {" << endl; 
				cout << " 'Item': " << p->num << "," << endl; 
				cout << " 'Link on item': "<< p << "," << endl; 
				cout << " 'Next link': "<< p->next << "," << endl; 
				if(p!=last) cout << " }," << endl; 
				else  cout << " }" << endl; 
	
			} 
			cout << "}" << endl; 
			cout << endl << "Length - " << this->length << endl; 
		} 
			
			
		

		//JUMP ON GAP LENGTH FUNC
		elem* jmp(elem* begin, int n){
			
			elem* jump = NULL;
			
			for(int i = 0; i < n; i++){
				
				begin = begin->next;
					
			}
			jump = begin;
			return jump;
				
		}
		
		elem* getFirst(){
		
			elem *f = this->first;
			//cout << f->num;
			return f;
		}
		
		elem* getLast(){
			
			elem *l = this->last;
			return l;
		}

		
		void shellSort(){
			int lengt = 9;
				elem* t_first = NULL, *t_last = NULL, *t_temp = NULL;
			
				t_first = first;
				t_last = last;
				cout << "First: " << t_first->num << " LASt: " << t_last->num; 
				int gap = 4;
				
				t_temp = jmp(first,4);
				
				//PRECHECK
				if(t_first->num > t_temp->num){
						swap(t_first,t_temp);
						cout << t_first->num <<  "  || " << t_temp->num << endl;
					}
				for(int i = gap;i<lengt; i+=1){

					if(t_first->num > t_temp->num){
						swap(t_first,t_temp);
					}
					if(t_temp == last){
						cout << "LAST";	
						t_temp = last;
						//!!!
					}else{
						t_temp = t_temp->next;
					t_first = t_first->next;
						
					}
					
					
				}
				
			}
			
			
			void remove(T x){
				int lgt = 0;
				if(first == 0){
					cout << "saraksts ir tuks" << endl;
					
				}else{
					if(x > length){
						cout << " Saraksta nav tik daudz elementu" << endl;
					}else{
						if(x == 0){
							elem *temp = first->next;
							delete first;
							first = temp;	
						}else{
							
							p = first;
							while(lgt+1 != x){
								p = p->next;
								lgt += 1;	
							}
							elem *t = p->next;
							p->next = p->next->next;
							delete t;	
						}		
					}
	
				}
	
			}	
			
			
			void addAfter(int pos){
				
				if(pos >= this->length){
					
					p = first;
					cout << " Saraksta nav tik daudz elementu un jusu skaitlis tiks pievienots beigas" << endl;
					elem *n = new elem;
					n->num = 1;
					last->next = n;
					last = n;
				}else{
					if(pos == 0){
						elem *t = new elem;
						t->num = 1;
						elem* t_next = first->next;
						first->next = t;
						t->next = t_next;
					
					}else{
						p = first;
						int count = 0;
						while(count+1 != pos){
							p = p->next;
							count += 1;
						}
						
						elem *temp = p->next;
						elem *f = new elem;
						f->num = 1;
						p->next = f;
						f->next = temp;
	
					}	
				}
				//length
				this->length += 1;
			}
			
			
			// !!
			elem* findElement(T el){
				
				
				
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
	
	
	//TEST FOR SORT LINEAR
	
	x.pievien(14);
	x.pievien(18);
	x.pievien(19);
	x.pievien(37);
	x.pievien(23);
	x.pievien(40);
	x.pievien(29);
	x.pievien(30);
	x.pievien(11);
	cout << endl;
	x.izvad();
	cout << endl;
	x.jmp(x.getFirst(),4);
	x.shellSort();
	cout << "SHELL SORT" <<  endl;
	x.izvad();
	
	
	
	
	
	
	
	
    
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
