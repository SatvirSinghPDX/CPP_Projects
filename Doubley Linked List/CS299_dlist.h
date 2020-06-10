//doubly linked list
//Notice that there is a head and a tail pointer!!!
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        int display_last_two();        
        int remove_last_two();
        float add_average();
        bool duplicate_last();
        int count_same();
        int remove_larger();
      /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
        int display_last_two(node * head);
        int remove_last_two(node *& head);
        int add_average(node *& head, int sum, int count);
        bool duplicate_last(node *& head);
        int count_same(node * head);
        int remove_larger(node *& head);
};


