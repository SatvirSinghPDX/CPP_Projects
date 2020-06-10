//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
   public:
   //These functions are already written for you
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied
    
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    bool remove_last_two();    
    float average();
    int move_head();
    int remove_all_but_last();
    int find_largest();
    bool remove_lasttwo();
    bool remove_last();
    bool exists(int match);
    int display_last();
    int move_head_to_end();
    int copy_all_but_2s(list & new_list);
    int remove_greater();
    node *& find_second_to_last();
     
   private:		//notice there is both a head and a tail!
      node * head;
      node * tail;
      bool remove_last_two(node *& head);
      int average(node * head, int count);
        int move_head(node *& head);
        int remove_all_but_last(node *& head);
        int find_largest(node * head);
        bool remove_lasttwo(node *& head);
        bool exists(node * head, int match);
        bool remove_last(node *& head);
        int display_last(node * head);
        int move_head_to_end(node *& head);
        int copy_all_but_2s(node *& new_list, node * original);
        int remove_greater(node *& head, node *& tail); 
        node *& find_second_to_last(node *& head);
};
