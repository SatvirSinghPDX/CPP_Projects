/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 11/11/2017
 Assignment: 3
 
 This is the .cpp file for the training class, this is where I will implement all of the classes including
 training and all of its derived classes (jogging, weight_training, circuit_training), as well as the
 training_plan class, which is a linked list of the information regarding a recommended training plan for any
 given race.
 */

#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include "training.h"
using namespace std;
// default constructor
training::training():duration(0),days_per_week(0),intensity(0)
{
    
}
// parameterized constructor
training::training(int new_dur, int new_days, int new_inten):duration(new_dur),days_per_week(new_days),intensity(new_inten)
{
    
}
// destructor
training::~training()
{
    
}
// function that updates the duration of a training session
void training::update_duration(int new_duration)
{
    duration = new_duration;
}
// function that returns the duration of a training session
int training::report_duration()
{
    return duration;
}
// function that updates the days per week a training session is recommended
void training::update_days(int new_days)
{
    days_per_week = new_days;
}
// function that returns the days per week a training session is recommended
int training::report_days()
{
    return days_per_week;
}
// function that updates the intensity of a training session
void training::update_intensity(int new_intensity)
{
    intensity = new_intensity;
}
// function that returns the intensity of a training session
int training::report_intensity()
{
    return intensity;
}
// default constructor
jogging::jogging():training(0,0,0),distance(0),speed(0)
{
    
}
// destructor
jogging::~jogging()
{
    
}
// derived virtual function
void jogging::type()
{
    cout << "           Jogging \n"
         << "           -------\n";
}
// derived virtual function
int jogging::type_id()
{
    return 1;
}
// derived virtual function
void jogging::display_extra()
{
    cout << "Distance of jog: " << this->report_distance() << " miles" << endl;
    cout << "Speed of jog: " << this->report_speed() << " mph" << endl;
}
// function that updates the distance of a jog
void jogging::update_distance(int new_distance)
{
    distance = new_distance;
}
// function that returns the distance of a jog
int jogging::report_distance()
{
    return distance;
}
// function that updates the speed recommended for a jog
void jogging::update_speed(int new_speed)
{
    speed = new_speed;
}
// function that returns the speed recommended for a jog
int jogging::report_speed()
{
    return speed;
}
// default constructor
weight_training::weight_training():training(0,0,0),muscle_group(NULL)
{
    
}
// destructor
weight_training::~weight_training()
{
    muscle_group = NULL;
    delete muscle_group;
}
// derived virtual function
void weight_training::type()
{
    cout << "        Weight training\n"
         << "        ---------------\n";
}
// derived virtual function
void weight_training::display_extra()
{
    cout << "Muscle group to work out: " << this->report_muscle_group() << endl;
}
// derived virtual function
int weight_training::type_id()
{
    return 2;
}
// function that updates the muscle group being worked on
void weight_training::update_muscle_group(char *new_muscle_group)
{
    muscle_group = new char[strlen(new_muscle_group)+1];
    strcpy(muscle_group, new_muscle_group);
}
// function that returns the muscle group being worked on
char * weight_training::report_muscle_group()
{
    return muscle_group;
}
// default constructor
circuit_training::circuit_training():training(0,0,0),num_of_activities(0)
{
    
}
// destructor
circuit_training::~circuit_training()
{
    
}
// derived virtual function
void circuit_training::type()
{
    cout << "       Circuit training\n"
         << "       ----------------\n";
}
// derived virtual function
void circuit_training::display_extra()
{
    cout << "Number of activities: " << this->report_num_of_activities() << endl;
}
// derived virtual function
int circuit_training::type_id()
{
    return 3;
}
// function that updates the number of activities in the circuit training
void circuit_training::update_num_of_activities(int new_num)
{
    num_of_activities = new_num;
}
// function that returns the number of activities in the circuit training
int circuit_training::report_num_of_activities()
{
    return num_of_activities;
}
// default constructor
tp_node::tp_node():next(NULL),training_obj(NULL)
{
    
}
// destructor
tp_node::~tp_node()
{
    next = NULL;
    delete next;
}
// function that sets the next pointer
void tp_node::set_next(tp_node *new_next)
{
    next = new_next;
}
// function that returns the next pointer
tp_node *& tp_node::get_next()
{
    return next;
}
// function that sets the pointer to the abstract base class
void tp_node::set_training_obj(training *new_obj)
{
    training_obj = new_obj;
}
// function that returns the pointer to the abstract base class
training * tp_node::get_training_obj()
{
    return training_obj;
}
// default constructor
training_plan::training_plan():head(NULL)
{
    
}
// destructor
training_plan::~training_plan()
{
    tp_node * curr = this->get_head();
    while (curr)
    {
        tp_node * temp = curr->get_next();
        delete curr;
        curr = temp;
    }
}
// function that sets the head pointer
void training_plan::set_head(tp_node *new_head)
{
    head = new_head;
}
// function that returns the head pointer
tp_node * training_plan::get_head()
{
    return head;
}
// insert function for training plan LLL
bool training_plan::insert(tp_node *&head, training *to_add)
{
    if(head == NULL)
    {
        head = new tp_node;
        head->set_training_obj(to_add);
        return true;
    }
    else{
        return insert(head->get_next(), to_add);
    }
    return false;
}
// wrapper function for training plan insert
bool training_plan::insert(training *to_add)
{
    return insert(head, to_add);
}
// function that displays the entire training plan
void training_plan::display(tp_node *head)
{
    tp_node * curr = head;
    if(!curr)
    {
        cout << "The plan is empty!" << endl;
        return;
    }
    cout << "   Recommended Training plan\n"
         << "*******************************\n" << endl;
    while(curr)
    {
        curr->get_training_obj()->type();
        cout << "Duration of workout: " << curr->get_training_obj()->report_duration() << " minutes" << endl;
        cout << "Days per week: " << curr->get_training_obj()->report_days() << " days" << endl;
        cout << "Intensity of workout: " << curr->get_training_obj()->report_intensity() << endl;
        curr->get_training_obj()->display_extra();
        cout << endl;
        curr = curr->get_next();
    }
}
// wrapper function for training plan display
void training_plan::display()
{
    display(head);
}
