/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 11/11/2017
 Assignment: 3
 
 This is the .h file for the training class, it is where I will develop the single inheritance relationship
 between the training class and all of its derived classes (jogging, weight_training, and circuit_training).
 This is also where I will declare the training_plan class, which will be a linked list to hold the contents of
 the training plan.
 */

#include <iostream>
using namespace std;
class training  // abstract base class
{
protected:
    training();     // default constructor
    training(int new_dur, int new_days, int new_inten);     // parameterized constructor
public:
    ~training();    // destructor
    void update_duration(int new_duration);     // function that updates the duration of training
    int report_duration();      // function that returns the duration of a training session
    void update_days(int new_days);     // function that updates the days per week for this training
    int report_days();      // function that returns the number of days per week for this training
    void update_intensity(int new_intensity);       // function that updates the intensity of training
    int report_intensity();     // function that reports the intensity of training
    virtual void type() = 0;    // pure virtual function
    virtual int type_id() = 0;      // pure virtual function
    virtual void display_extra() = 0;       // pure virtual function
private:
    int duration;       // how long training session lasts
    int days_per_week;      // days per week training is recommended
    int intensity;      // intensity of the training session
};
class jogging: public training
{
public:
    jogging();      // default constructor
    ~jogging();     // destructor
    void update_distance(int new_distance);     // function that updates the distance of a jog
    int report_distance();      // function that returns the distance of a jog
    void update_speed(int new_speed);      // function that updates the speed of a jog
    int report_speed();     // function that returns the speed of a jog
    void type();    // derived virtual function
    int type_id();  // derived virtual function
    void display_extra();   // derived virtual function
private:
    int distance;       // distance of a jog
    int speed;      // speed at which jog is recommended
};
class weight_training: public training
{
public:
    weight_training();      // default constructor
    ~weight_training();     // destructor
    void update_muscle_group(char * new_muscle_group);      // function that updates the muscle group being worked out
    char * report_muscle_group();       // function that returns the muscle group being worked out
    void type();    // derived virtual function
    int type_id();  // derived virtual function
    void display_extra();   // derived virtual function
private:
    char * muscle_group;    // muscle group being worked out
};
class circuit_training: public training
{
public:
    circuit_training();     // default constructor
    ~circuit_training();    // destructor
    void update_num_of_activities(int new_num);     // function that updates the number of activities
    int report_num_of_activities();     // function that returns the number of activities
    void type();    // derived virtual function
    int type_id();  // derived virtual function
    void display_extra();   // derived virtual function
private:
    int num_of_activities;      // number of activities in the circuit training
};
class tp_node
{
public:
    tp_node();      // default constructor
    ~tp_node();     // destructor
    void set_next(tp_node * new_next);      // function that sets the next pointer
    tp_node *& get_next();      // function that returns the next pointer
    void set_training_obj(training * new_obj);      // function that sets the training pointer
    training * get_training_obj();      // function that returns the training pointer
private:
    tp_node * next;     // next pointer
    training * training_obj;    // training pointer
};
class training_plan
{
public:
    training_plan();    // default constructor
    ~training_plan();   // destructor
    void set_head(tp_node * new_head);      // function that sets the head pointer
    tp_node * get_head();       // function that returns the head pointer
    bool insert(training * to_add);     // insert wrapper function
    void display();     // display wrapper function
private:
    tp_node * head;     // head pointer
    bool insert(tp_node *& head, training * to_add);    // insert function
    void display(tp_node * head);   // display function
};
