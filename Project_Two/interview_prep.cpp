/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 10/30/2017
 Assignment: 2
 This the cpp file for the interview prep class, this is where I will implement all of the constructors
 in the interview prep class, as well as where I will implement the circular linked list that will hold
 the pointers to the abstract base class.
 */
#include <iostream>
#include "interview_prep.h"

using namespace std;

// default constructor
interview_prep::interview_prep()
{
    
}
// destructor
interview_prep::~interview_prep()
{
    
}
// default constructor
node::node():next(NULL),ip(NULL)
{
    
}
// destructor
node::~node()
{
    delete next;
    delete ip;
}
// function that sets the next pointer
void node::set_next(node *new_next)
{
    next = new_next;
}
// function that returns the next pointer
node *& node::get_next()
{
    return next;
}
// function that sets the pointer to the abstract base class
void node::set_ip(interview_prep *new_ip)
{
    ip = new_ip;
}
// function that returns the pointer to the abstract base class
interview_prep * node::get_ip()
{
    return ip;
}
// default constructor
CLL::CLL():head(NULL),tail(NULL)
{
    
}
// destructor
CLL::~CLL()
{
    
}
// function that inserts an abstract base class pointer into the CLL
bool CLL::insert(node *&head, interview_prep *ip_to_add)
{
    node * temp = new node;
    temp->set_ip(ip_to_add);
    //temp->set_next(NULL);
    if(head == NULL)
    {
        head = temp;
        head->set_next(head);
        return true;
    }
    if(head->get_next() == head)
    {
        head->set_next(temp);
        temp->set_next(head);
        return true;
    }
    if(head->get_next()->get_next() == head)
    {
        head->get_next()->set_next(temp);
        temp->set_next(head);
        return true;
    }
    delete temp;
    return true;
    
}
bool CLL::insert(interview_prep *ip_to_add)
{
    return insert(head, ip_to_add);
}
// function that displays the contents of the CLL
void CLL::display(node *& head)
{
    if(head == NULL)
    {
        cout << "There is nothing in the CLL!" << endl;
    }
    else{
        head->get_ip()->display_all();
        if(head->get_next()){
            head->get_next()->get_ip()->display_all();
        }
        if(head->get_next()->get_next()){
            head->get_next()->get_next()->get_ip()->display_all();
        }
    }
}
void CLL::display()
{
    return display(head);
}
