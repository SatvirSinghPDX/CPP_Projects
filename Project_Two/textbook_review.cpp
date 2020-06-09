/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 10/30/2017
 Assignment: 2
 
 This is the cpp file for the textbook_review class, the practice_questions class, and the
 powerpoint_slides class. This is where I will implement the linked lists for each type of review
 material as well as the corresponding nodes for each linked list.
 */
#include <iostream>
#include <cstring>
#include "textbook_review.h"

// default constructor
textbook_node::textbook_node():next(NULL),name_of_textbook(NULL)
{
    
}
// destructor
textbook_node::~textbook_node()
{
    if(name_of_textbook)
        delete [] name_of_textbook;
}
// function that sets the next pointer
void textbook_node::set_next(textbook_node *new_next)
{
    next = new_next;
}
// function that returns the next pointer
textbook_node *& textbook_node::get_next()
{
    return next;
}
// function that sets the name of the textbook
void textbook_node::set_textbook_name(char *new_textbook_name)
{
    name_of_textbook = new char[strlen(new_textbook_name)+1];
    strcpy(name_of_textbook, new_textbook_name);
}
// function that returns the name of the textbook
char * textbook_node::get_textbook_name()
{
    return name_of_textbook;
}

// default constructor
textbook_review::textbook_review():head(NULL)
{
    
}
// destructor
textbook_review::~textbook_review()
{
    textbook_node * curr = head;
    while(curr)
    {
        textbook_node * temp = curr->get_next();
        delete curr;
        curr = temp;
    }
    head = NULL;
}
// add function for textbook_review class
bool textbook_review::add(textbook_node *&head, char *textbook_to_add)
{
    if(head == NULL)
    {
        head = new textbook_node;
        head->set_textbook_name(textbook_to_add);
        return true;
    }
    else
    {
        return add(head->get_next(), textbook_to_add);
    }
    return true;
}
// wrapper function for textbook_review add function
bool textbook_review::add(char *textbook_to_add)
{
    return add(head, textbook_to_add);
}
// function that removes the specified textbook from the list
textbook_node * textbook_review::remove(textbook_node *&head, char *textbook_to_remove)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(strcmp(head->get_textbook_name(), textbook_to_remove) == 0)
    {
        textbook_node * temp;
        temp = head->get_next();
        delete head;
        return temp;
    }
    head->set_next(remove(head->get_next(), textbook_to_remove));
    return head;
}
// wrapper function for textbook_review remove function
bool textbook_review::remove(char *textbook_to_remove)
{
    if(head == NULL)
    {
        cout << "'" << textbook_to_remove << "' is not in the list!" << endl;
        return false;
    }
    head = remove(head, textbook_to_remove);
    cout << "'" << textbook_to_remove << "' has been removed from the list!" << endl;
    return true;
}
// function that displays all textbook review material
void textbook_review::display_all()
{
    textbook_node * curr = head;
    if(!curr){
        cout << "There are no textbooks in the list!" << endl;
        return;
    }
    cout << "The textbooks in the list are: " << endl;
    while(curr)
    {
        cout << curr->get_textbook_name() << endl;
        curr = curr->get_next();
    }
    cout << endl;
}
// default constructor
practice_questions::practice_questions():head(NULL),tail(NULL)
{
    
}
// destructor
practice_questions::~practice_questions()
{
    question_node * curr = head;
    while(curr)
    {
        question_node * temp = curr->get_next();
        delete curr;
        curr = temp;
    }
    head = NULL;
}

// default constructor
question_node::question_node():next(NULL),pq(NULL)
{
    
}
// destructor
question_node::~question_node()
{
    if(pq)
        delete [] pq;
}
// function that sets the next pointer
void question_node::set_next(question_node *new_next)
{
    next = new_next;
}
// function that returns the next pointer
question_node *& question_node::get_next()
{
    return next;
}
// function that updates the question variable
void question_node::set_question(char * new_ques)
{
    pq = new char[strlen(new_ques)+1];
    strcpy(pq, new_ques);
}
// function that returns the question object
char * question_node::get_question()
{
    return pq;
}

// function that inserts a given question into the list recursively
bool practice_questions::add(question_node *& head, char * question_to_add)
{
    if(head == NULL)
    {
        head = new question_node;
        head->set_question(question_to_add);
        tail = head;
        return true;
    }
    else
    {
        return add(head->get_next(), question_to_add);
    }
    return true;
}
// wrapper function for practice_question add function
bool practice_questions::add(char * question_to_add)
{
    return add(head, question_to_add);
}
// function that removes the specified question from the list
question_node * practice_questions::remove(question_node *&head, char *question_to_remove)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(strcmp(head->get_question(), question_to_remove) == 0)
    {
        question_node * temp;
        temp = head->get_next();
        delete head;
        return temp;
    }
    head->set_next(remove(head->get_next(), question_to_remove));
    return head;
}
// wrapper function for practice_question remove function
bool practice_questions::remove(char *question_to_remove)
{
    if(head == NULL)
    {
        cout << "'" << question_to_remove << "' was not in the list!" << endl;
        return false;
    }
    head = remove(head, question_to_remove);
    cout << "'" << question_to_remove << "' has been removed from the list!" << endl;
    return true;
}
// function that displays the contents of the question list
void practice_questions::display_all()
{
    question_node * curr = head;
    if(!curr){
        cout << "There are no questions in the list!" << endl;
        return;
    }
    cout << "The questions in the list are: " << endl;
    while (curr) {
        cout << curr->get_question() << endl;
        curr = curr->get_next();
    }
    cout << endl;
}
// default constructor
powerpoint_node::powerpoint_node():next(NULL),name_of_powerpoint(NULL)
{
    
}
// destructor
powerpoint_node::~powerpoint_node()
{
    if(name_of_powerpoint)
        delete [] name_of_powerpoint;
}
// function that sets the next pointer
void powerpoint_node::set_next(powerpoint_node *new_next)
{
    next = new_next;
}
// function that returns the next pointer
powerpoint_node *& powerpoint_node::get_next()
{
    return next;
}
// function that sets the name of the powerpoint slideshow
void powerpoint_node::set_powerpoint_name(char *new_powerpoint_name)
{
    name_of_powerpoint = new char[strlen(new_powerpoint_name)+1];
    strcpy(name_of_powerpoint, new_powerpoint_name);
}
// function that returns the name of the powerpoint slideshow
char * powerpoint_node::get_powerpoint_name()
{
    return name_of_powerpoint;
}
// default constructor
powerpoint_slides::powerpoint_slides():head(NULL)
{
    
}
// destructor
powerpoint_slides::~powerpoint_slides()
{
    powerpoint_node * curr = head;
    while(curr)
    {
        powerpoint_node * temp = curr->get_next();
        delete curr;
        curr = temp;
    }
    head = NULL;
}
// function that adds a powerpoint slideshow to the list
bool powerpoint_slides::add(powerpoint_node *&head, char *powerpoint_to_add)
{
    if(head == NULL)
    {
        head = new powerpoint_node;
        head->set_powerpoint_name(powerpoint_to_add);
        return true;
    }
    else
    {
        return add(head->get_next(), powerpoint_to_add);
    }
    return true;
}
// wrapper function for powerpoint_slide add function
bool powerpoint_slides::add(char *powerpoint_to_add)
{
    return add(head, powerpoint_to_add);
}
// function that removes the specified powerpoint from the list
powerpoint_node * powerpoint_slides::remove(powerpoint_node *&head, char *powerpoint_to_remove)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(strcmp(head->get_powerpoint_name(), powerpoint_to_remove) == 0)
    {
        powerpoint_node * temp;
        temp = head->get_next();
        delete head;
        return temp;
    }
    head->set_next(remove(head->get_next(), powerpoint_to_remove));
    return head;
}
// wrapper function for powerpoint_slides remove function
bool powerpoint_slides::remove(char *powerpoint_to_remove)
{
    if(head == NULL)
    {
        cout << "'" << powerpoint_to_remove << "' was not in the list!" << endl;
        return false;
    }
    head = remove(head, powerpoint_to_remove);
    cout << "'" << powerpoint_to_remove << "' has been removed from the list!" << endl;
    return true;
}
// function that displays the list of all powerpoint slideshows
void powerpoint_slides::display_all()
{
    powerpoint_node * curr = head;
    if(!curr)
    {
        cout << "There are no powerpoints in the list!" << endl;
        return;
    }
    cout << "The powerpoints in the list are: " << endl;
    while(curr)
    {
        cout << curr->get_powerpoint_name() << endl;
        curr = curr->get_next();
    }
    cout << endl;
}
