/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 10/30/2017
 Assignment: 2
 
 This is the header file for the textbook_review class, the practice_questions class, and the
 powerpoint_slides class. This is where I will declare the linked list for each class that will hold
 the data for each type of review material.
 */
#include <iostream>
#include "interview_prep.h"
#ifndef textbook_review_h
#define textbook_review_h
using namespace std;
class textbook_node
{
    public:
        textbook_node();    // default constructor
        ~textbook_node();   // destructor
        void set_next(textbook_node * new_next);    // function that sets the next variable
        textbook_node *& get_next();    // function that returns the next variable
        void set_textbook_name(char * new_textbook_name);   // function that sets the textbook name
        char * get_textbook_name();     // function that returns the textbook name
    private:
        textbook_node * next;   // next pointer
        char * name_of_textbook;    // textbook name variable
};
class textbook_review: public interview_prep    // derived from abstract base class
{
    public:
        textbook_review();  // default constructor
        ~textbook_review(); // destructor
        bool add(textbook_node *& head, char * textbook_to_add);    // function that adds a textbook
        bool add(char * textbook_to_add);   // wrapper add function for textbook_review
        textbook_node * remove(textbook_node *& head, char * textbook_to_remove);   // remove
        bool remove(char * textbook_to_remove);     // wrapper function for remove
        void display_all();     // function that displays all textbooks in the list
    private:
        textbook_node * head;   // head pointer
};

class question_node
{
    public:
        question_node();     // default constructor
        ~question_node();    // destructor
        void set_next(question_node * new_next);     // function that sets the next pointer
        question_node *& get_next();      // function that returns the next pointer
        void set_question(char * new_ques);     // function that updates the question object
        char * get_question();      // function that returns a question
    private:
        question_node * next;    // next pointer
        char * pq;     // practice_question variable
};

class practice_questions: public interview_prep     // derived from abstract base class
{
    public:
        practice_questions();    // default constructor
        ~practice_questions();   // destructor
        bool add(question_node *& head, char * question_to_add);     // insert function
        bool add(char * question_to_add);     // wrapper function
        question_node * remove(question_node *& head, char * question_to_remove);
        bool remove(char * question_to_remove);
        void display_all();     // function that displays all questions
    private:
        question_node * head;    // head pointer
        question_node * tail;    // tail pointer
};

class powerpoint_node
{
public:
    powerpoint_node();     // default constructor
    ~powerpoint_node();    // destructor
    void set_next(powerpoint_node * new_next);      // function that sets the next pointer
    powerpoint_node *& get_next();      // function that returns the next pointer
    void set_powerpoint_name(char * new_powerpoint_name);      // function that sets the powerpoint name
    char * get_powerpoint_name();       // function that returns the powerpoint name
private:
    powerpoint_node * next;     // next pointer
    char * name_of_powerpoint;  // powerpoint name variable
};


class powerpoint_slides: public interview_prep      // derived from abstract base class
{
    public:
        powerpoint_slides();    // default constructor
        ~powerpoint_slides();   // destructor
        bool add(powerpoint_node *& head, char * powerpoint_to_add);    // function that adds powerpoint
        bool add(char * powerpoint_to_add);     // wrapper function for powerpoint add function
        powerpoint_node * remove(powerpoint_node *& head, char * powerpoint_to_remove);     // remove
        bool remove(char * powerpoint_to_remove);       // wrapper function for powerpoint remove
        void display_all();     // function that displays all powerpoints in the list
    private:
        powerpoint_node * head;     // head pointer
};
#endif /* textbook_review_h */
