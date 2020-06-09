/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 11/11/2017
 Assignment: 3
 
 This is the .cpp file for the race class, the BST, and the historical race list, as well as their
 corresponding node classes. This is where I will do the implementation of each class as well as the
 implemenetation of all of the overloaded operators I felt would be useful.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "race.h"
#include "training.h"

using namespace std;
// default constructor
race::race():type_of_race(NULL),length(NULL),intensity(NULL)
{
    
}
// parameterized constructor
race::race(char * type, int len, int inten)
{
    type_of_race = new char[strlen(type)+1];
    strcpy(type_of_race, type);
    length = len;
    intensity = inten;
}
// destructor
race::~race()
{
    type_of_race = NULL;
    delete type_of_race;
}
// copy constructor
race::race(const race & obj)
{
    type_of_race = new char[strlen(obj.type_of_race)+1];
    strcpy(type_of_race, obj.type_of_race);
    length = obj.length;
    intensity = obj.intensity;
}
// assignment operator
race & race::operator=(const race & obj)
{
    if(this == &obj)
    {
        return *this;
    }
    if(type_of_race)
    {
        delete [] type_of_race;
    }
    type_of_race = new char[strlen(obj.type_of_race)+1];
    strcpy(type_of_race, obj.type_of_race);
    length = obj.length;
    intensity = obj.intensity;
    return *this;
}
// less-than operator
bool race::operator<(const race &obj)
{
    return this->report_length() < obj.length;
}
// greater-than operator
bool race::operator>(const race &obj)
{
    return this->report_length() > obj.length;
}
// less-than or equal-to operator
bool race::operator<=(const race &obj)
{
    return this->report_length() <= obj.length;
}
// greater-than or equal-to operator
bool race::operator>=(const race &obj)
{
    return this->report_length() >= obj.length;
}
// equivalence operator
bool race::operator==(const race &obj)
{
    if(this->report_intensity() == obj.intensity && strcmp(this->report_type(), obj.type_of_race) == 0 && this->report_length() == obj.length)
    {
        return true;
    }
    return false;
}
// function that updates the length of a race
void race::update_length(int new_length)
{
    length = new_length;
}
// function that updates the intensity of a race
void race::update_intensity(int new_intensity)
{
    intensity = new_intensity;
}
// function that updates the type of race
void race::update_type(char *new_type)
{
    type_of_race = new char[strlen(new_type)+1];
    strcpy(type_of_race, new_type);
}
// function that returns the type of race
char * race::report_type()
{
    return type_of_race;
}
// function that returns the length of a race
int race::report_length()
{
    return length;
}
// function that returns the intensity of a race
int race::report_intensity()
{
    return intensity;
}
// default constructor
node::node():left(NULL),right(NULL),race_obj()
{
    
}
// destructor
node::~node()
{
    left = NULL;
    delete left;
    right = NULL;
    delete right;
}
// function that sets the left pointer
void node::set_left(node *new_left)
{
    left = new_left;
}
// function that sets the right pointer
void node::set_right(node *new_right)
{
    right = new_right;
}
// function that sets the race object
void node::set_race(race new_race)
{
    race_obj = new_race;
}
// function that sets the historical list for each race
void node::set_ht(historical_race_list new_ht)
{
    list = new_ht;
}
// function that returns the left pointer
node *& node::get_left()
{
    return left;
}
// function that returns the right pointer
node *& node::get_right()
{
    return right;
}
// function that returns the race object
race node::get_race()
{
    return race_obj;
}
historical_race_list node::get_ht()
{
    return list;
}
// default constructor
BST::BST():root(NULL)
{
    
}
// destructor
BST::~BST()
{
    root = NULL;
    delete root;
}
// insert function for BST
bool BST::insert(node *&root,race to_add)
{
    if(root == NULL)
    {
        root = new node;
        root->set_race(to_add);
        return true;
    }
    else if(to_add <= root->get_race())
    {
        if(root->get_left() != NULL)
        {
            insert(root->get_left(), to_add);
        }
        else
        {
            root->set_left(new node);
            root->get_left()->set_race(to_add);
            root->get_left()->set_left(NULL);
            root->get_left()->set_right(NULL);
        }
    }
    else if(to_add > root->get_race())
    {
        if(root->get_right() != NULL)
        {
            insert(root->get_right(), to_add);
        }
        else
        {
            root->set_right(new node);
            root->get_right()->set_race(to_add);
            root->get_right()->set_left(NULL);
            root->get_right()->set_left(NULL);
        }
    }
    else
    {
        cout << to_add.report_type() << " is already in the list!" << endl;
    }
    return false;
}
// wrapper function for insert function
bool BST::insert(race to_add)
{
    return insert(root, to_add);
}
// display function for BST
void BST::display(node *root)
{
    if(root)
    {
        if(root->get_left())
        {
            display(root->get_left());
        }
        cout << "Type of Race: " << root->get_race().report_type()
             << "  Length of Race: " << root->get_race().report_length() << " miles"
             << "  Intensity of Race: " << root->get_race().report_intensity() << endl;
        if(root->get_right())
        {
            display(root->get_right());
        }
    }
    else
    {
        cout << "The tree is empty!" << endl;
    }
}
// wrapper function for BST display function
void BST::display()
{
    display(root);
}
// default constructor
previous_race::previous_race():year(0),type(NULL),pos(0)
{
    
}
// copy constructor
previous_race::previous_race(const previous_race & obj)
{
    year = obj.year;
    type = new char[strlen(obj.type)+1];
    strcpy(type, obj.type);
    pos = obj.pos;
}
// overloaded '<<' operator
ostream & operator<<(ostream & os, const previous_race & obj)
{
    os << setw(3) << "Type of race: " << obj.type
    << setw(8) << right << "  Year: " << obj.year
    << right << "  Position: ";
    if(obj.pos == 1)
        os << obj.pos << "st place" << endl;
    else if(obj.pos == 2)
        os << obj.pos << "nd place" << endl;
    else if(obj.pos == 3)
        os << obj.pos << "rd place" << endl;
    else if(obj.pos > 3)
        os << obj.pos << "th place" << endl;
    return os;
}
// destructor
previous_race::~previous_race()
{
    type = NULL;
    delete type;
}
// function that sets the year of the race
void previous_race::set_year(int new_year)
{
    year = new_year;
}
// function that returns the year of the race
int previous_race::get_year()
{
    return year;
}
// function that sets the type of the race
void previous_race::set_type(char *new_type)
{
    type = new char[strlen(new_type)+1];
    strcpy(type, new_type);
}
// function that returns the type of the race
char * previous_race::get_type()
{
    return type;
}
// function that sets the position the person came in the race
void previous_race::set_pos(int new_pos)
{
    pos = new_pos;
}
// function that returns the position that the person came in the race
int previous_race::get_pos()
{
    return pos;
}
// default constructor
list_node::list_node():next(NULL),prev(NULL)
{
    
}
// destructor
list_node::~list_node()
{
    next = NULL;
    delete next;
    prev = NULL;
    delete prev;
}
// function that sets the next pointer
void list_node::set_next(list_node *new_next)
{
    next = new_next;
}
// function that returns the next pointer
list_node *& list_node::get_next()
{
    return next;
}
// function that sets the previous pointer
void list_node::set_prev(list_node *new_prev)
{
    prev = new_prev;
}
// function that returns the previous pointer
list_node *& list_node::get_prev()
{
    return prev;
}
// function that sets the previous race object
void list_node::set_pr(previous_race new_pr)
{
    pr = new_pr;
}
// function that returns the previous race object
previous_race list_node::get_pr()
{
    return pr;
}
// default constructor
historical_race_list::historical_race_list():head(NULL)
{
    
}
// destructor
historical_race_list::~historical_race_list()
{
    list_node * curr = this->get_head();
    while (curr)
    {
        list_node * temp = curr->get_next();
        delete curr;
        curr = temp;
    }
}
// function that sets the head pointer
void historical_race_list::set_head(list_node *new_head)
{
    head = new_head;
}
// function that returns the head pointer
list_node *& historical_race_list::get_head()
{
    return head;
}
// function that inserts a race into the historical race list
bool historical_race_list::insert(list_node *& head, previous_race to_add)
{
    // checks to see if the list is empty and inserts a previous race
    if(head == NULL)
    {
        head = new list_node;
        head->set_pr(to_add);
        return true;
    }
    // checks to see if the race we are trying to add occured before the race we are
    // currently at, if so, it enters it before said race
    if(to_add.get_year() <= head->get_pr().get_year())
    {
        list_node * temp = new list_node;
        temp->set_pr(to_add);
        temp->set_next(head);
        head->set_prev(temp);
        head = temp;
        return true;
    }
    // recursive call
    return insert(head->get_next(), to_add);
}
// wrapper function for historical race list insert
bool historical_race_list::insert(previous_race to_add)
{
    return insert(head, to_add);
}
// function that displays the historical race list
void historical_race_list::display(list_node * head)
{
    ofstream output;
    output.open("history.txt");
    list_node * curr = head;
    if(!curr)
    {
        cout << "The list of historical data is empty!" << endl;
        return;
    }
    cout << "The data for historical races for this person" << endl;
    cout << "------------------------------------------------------" << endl;
    output << "The data for historical races for this person" << endl;
    output << "------------------------------------------------------" << endl;
    while (curr) {
        // we are able to do this because we overloaded the '<<' operator
        // for the 'previous_race' class
        cout << curr->get_pr();
        output << curr->get_pr();
        curr = curr->get_next();
    }
    cout << "-------------------------------------------------------" << endl;
    output << "-------------------------------------------------------" << endl;
}
// wrapper function for historical race list display
void historical_race_list::display()
{
    display(head);
}
