//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   		//These functions are already written
   		list();			//supplied
   		~list();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
        int add_before();
        bool remove_same();
        int count_even();
        bool add_end();
        int copy(list & new_list);
        bool add_before_even();
        int remove_every_other();
	private:
		node * rear;
        int add_before(node *& current_rear);
        bool remove_same(node *& rear);
        int count_even(node * rear);
        bool add_end(node *& rear);
        int copy(node *& new_list,node * original);
        bool add_before_even(node *& rear);
        int remove_every_other(node *& rear);
};


