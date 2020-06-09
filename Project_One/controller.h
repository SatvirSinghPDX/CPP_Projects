/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 1/31/2018
 Assignment: 1
 This is the .h file for the controller class as well as the adj list and graph classes. The declarations of all
 of the constructors and functions can be found inside this file.
 */
#ifndef controller_h
#define controller_h
#include "drone.h"
class controller
{
public:
    controller();       // default constructor
    ~controller();      // destructor
    void move_up();     // function that moves the drone up one unit
    void move_down();       // function that moves the drone down one unit
    void move_left();       // function that moves the drone left one unit
    void move_right();      // function that moves the drone right one unit
private:
};
class adj_list_node
{
public:
    adj_list_node();        // default constructor
    ~adj_list_node();       // destructor
    void set_drone(drone &to_add);      // function that sets the drone object
    void set_count(int new_count);      // function that sets the count variable
    void set_next(adj_list_node * new_next);        // function that sets the next variable
    void set_occupied(bool new_occupation);     // function that sets the occupied variable
    drone & get_drone();        // function that returns the drone object by reference
    int get_count();        // function that returns the count variable
    adj_list_node *& get_next();        // function that returns the next pointer
    bool get_occupation();      // function that returns the state of the occupied variable
    
private:
    drone drone_to_add;     // drone object
    adj_list_node * next;       // next pointer
    int count;      // count variable
    bool occupied;      // occupied variable
};
class adj_list
{
public:
    adj_list();     // default constructor
    ~adj_list();        // destructor
    void set_head(adj_list_node * new_head);        // function that sets the head pointer
    adj_list_node *& get_head();        // functiont that returns the head pointer
private:
    adj_list_node * head;       // head pointer
};
class graph
{
public:
    graph(int a);       // default constructor
    ~graph();       // destructor
    adj_list_node * new_adj_list_node(drone & a_drone,int a_count);     // function that creates a new adjacency list node
    void add_edge(int a, int b, drone & to_add, bool check);        // function that adds an edge to the graph
private:
    int size;       // graph size variable
    adj_list * a_list;      // adjacency list variable
};
#endif /* controller_h */
