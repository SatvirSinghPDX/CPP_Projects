/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 11/11/2017
 Assignment: 3
 
 This is the header file for the race class. In this file, I will include the declaration of all the classes
 that have to do with adding races to the BST, the BST itself, as well as the linked list of histroical race
 information.
 */

#include <iostream>
using namespace std;
class race
{
public:
    race();     // default constructor
    race(char * type, int len, int inten);      // parameterized constructor
    ~race();        //  destructor
    race(const race & obj);     // copy constructor
    race & operator=(const race & obj);     // assignment operator
    bool operator<(const race &obj);      // less-than operator
    bool operator>(const race &obj);      // greater-than operator
    bool operator<=(const race &obj);       // less-than or equal-to operator
    bool operator>=(const race &obj);       // greater-than or equal-to operator
    bool operator==(const race &obj);       // equivalence operator
    int report_length();    // function that returns the length
    int report_intensity();     // function that returns the intensity
    char * report_type();       // function that returns the type
    void update_length(int new_length);     // function that updates the length
    void update_intensity(int new_intensity);   // function that updates the intensity
    void update_type(char * new_type);      // function that updates the type
private:
    char * type_of_race;    // name of the type of race
    int length;     // length of the race
    int intensity;      // intensity of the race
};
class previous_race
{
public:
    previous_race();
    previous_race(const previous_race & obj);
    friend ostream & operator<<(ostream & os, const previous_race & obj);
    ~previous_race();
    int get_year();
    void set_year(int new_year);
    int get_pos();
    void set_pos(int new_pos);
    char * get_type();
    void set_type(char * new_type);
private:
    int year;
    char * type;
    int pos;
};
class list_node
{
public:
    list_node();    // default constructor
    ~list_node();   // destructor
    void set_next(list_node * new_next);    // function that sets the next pointer
    list_node *& get_next();    // function that returns the next pointer
    void set_prev(list_node * new_prev);    // function that sets the prev pointer
    list_node *& get_prev();    // function that returns the prev pointer
    previous_race get_pr();     // function that returns the previous race object
    void set_pr(previous_race new_pr);      // function that sets the previous race object
private:
    list_node * next;       // next pointer
    list_node * prev;       // previous pointer
    previous_race pr;       // previous race object
};
class historical_race_list
{
public:
    historical_race_list();     // default constructor
    ~historical_race_list();    // destructor
    void set_head(list_node * new_head);    // function that sets the head pointer
    list_node *& get_head();        // function that returns the head pointer
    bool insert(previous_race to_add);
    void display();
private:
    list_node * head;       // head pointer
    bool insert(list_node *& head, previous_race to_add);   // function that adds races to historical list
    void display(list_node * head);     // function that displays the list of historical races
};
class node
{
public:
    node();     // default constructor
    ~node();    // destructor
    node *& get_left();     // function that returns the left pointer
    node *& get_right();    // function that returns the right pointer
    race get_race();    // function that returns the race object
    historical_race_list get_ht();
    void set_race(race new_race);       // function that sets the race object
    void set_left(node * new_left);     // function that sets the left pointer
    void set_right(node * new_right);   // function that sets the right pointer
    void set_ht(historical_race_list new_ht);
private:
    node * left;    // left pointer
    node * right;   // right pointer
    race race_obj;  // race object
    historical_race_list list;
};
class BST
{
public:
    BST();      // default construtor
    ~BST();     // destructor
    void set_root(node * new_root);     // function that sets the root pointer
    node *& get_root();     // function that returns the root pointer
    bool insert(race to_add);       // insert wrapper function
    void display(node * root);      // function to display the BST
    void display();     // display BST wrapper function
private:
    bool insert(node *& curr, race to_add);     // function to insert a race into the BST
    node * root;    // root pointer
};
