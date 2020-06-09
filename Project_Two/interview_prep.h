/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 10/30/2017
 Assignment: 2
 
 This is the header file for the interview_prep class. This is where I will declare this class as an
 abstract base class by having the functions be pure virtual. This way, all of the derived classes
 (textbook_review,practice_questions, and powerpoint_slides) will be required to implement said
 functions. If any class fails to do so, it too becomes an abstract base class.
 */
#include <iostream>
#ifndef interview_prep_h
#define interview_prep_h

using namespace std;

class interview_prep    // abstract base class
{
    public:
         interview_prep();       // default constructor
         virtual ~interview_prep();      // destructor
         virtual bool add(char * item_to_add) = 0;      // pure virtual add function
         virtual bool remove(char * item_to_remove) = 0;      // pure virtual remove function
         virtual void display_all() = 0;        // pure virtual display_all function
    private:
    
};
class node
{
    public:
        node();     // default constructor
        ~node();    // destructor
        void set_next(node * new_next);     // function that sets the next pointer
        node *& get_next();      // function that returns the next pointer
        void set_ip(interview_prep * new_ip);     // function that sets the interview_prep pointer
        interview_prep * get_ip();      // function that returns the interview_prep pointer
    private:
        node * next;    // next pointer
        interview_prep * ip;    // pointer to abstract base class;
};
class CLL
{
    public:
        CLL();      // default constructor
        ~CLL();     // destructor
        bool insert(interview_prep * ip_to_add);
        void display(node *& head);     // function that displays contents of CLL
        void display();
    private:
        bool insert(node *& tail, interview_prep * ip_to_add);      // function that inserts pointers
        node * head;    // head pointer
        node * tail;    // tail pointer
};
#endif /* interview_prep_h */
