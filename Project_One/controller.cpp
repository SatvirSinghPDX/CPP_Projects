/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 1/31/2018
 Assignment: 1
 This is the .cpp file for the controller class. This is where I will implement the controller class as well as
 the graph and adjacency list classes. The implementations of all of the constructors and functions for said
 classes can be found in this file.
 */
#include <stdio.h>
#include <iostream>
#include "controller.h"
// default constructor
using namespace std;
controller::controller()
{
    
}
// destructor
controller::~controller()
{
    
}
// function that moves a drone up
void controller::move_up()
{
    cout << "Drone was moved up one unit\n";
}
// function that moves a drone down
void controller::move_down()
{
    cout << "Drone was moved down one unit\n";
}
// function that moves a drone left
void controller::move_left()
{
    cout << "Drone was moved left one unit\n";
}
// function that moves a drone right
void controller::move_right()
{
    cout << "Drone was moved right one unit\n";
}
// default constructor for adj_list_node class
adj_list_node::adj_list_node():drone_to_add(),next(NULL),count(0)
{
    
}
// destructor for adj_list_node class
adj_list_node::~adj_list_node()
{
    delete next;
}
// function that updates the drone
void adj_list_node::set_drone(drone &to_add)
{
    drone_to_add = to_add;
}
// function that returns the drone
drone & adj_list_node::get_drone()
{
    return drone_to_add;
}
// function that updates the next pointer
void adj_list_node::set_next(adj_list_node *new_next)
{
    next = new_next;
}
// function that returns the next pointer
adj_list_node *& adj_list_node::get_next()
{
    return next;
}
// function that updates the count variable
void adj_list_node::set_count(int new_count)
{
    count = new_count;
}
// function that returns the count variable
int adj_list_node::get_count()
{
    return count;
}
// function that updates the occupied variable
void adj_list_node::set_occupied(bool new_occupation)
{
    occupied = new_occupation;
}
// function that returns the occupied variable
bool adj_list_node::get_occupation()
{
    return occupied;
}
// default constructor for adj_list class
adj_list::adj_list():head(NULL)
{
    
}
// destructor
adj_list::~adj_list()
{
    delete head;
}
// function that updates the head pointer
void adj_list::set_head(adj_list_node *new_head)
{
    head = new_head;
}
// function that returns the head pointer
adj_list_node *& adj_list::get_head()
{
    return head;
}
// default constructor for graph class
graph::graph(int a)
{
    this->size = a;
    a_list = new adj_list[a];
    for(int i = 0; i < a; ++i)
    {
        a_list[i].set_head(NULL);
    }
}
// destructor
graph::~graph()
{
    adj_list_node * curr = NULL;
    for(int i = 0; i < size; ++i)
    {
        curr = a_list[i].get_head();
        while (curr) {
            curr = curr->get_next();
            delete a_list[i].get_head();
            a_list[i].set_head(NULL);
            //a_list[i].set_head(curr);
        }
    }
    size = 0;
    delete curr;
    curr = NULL;
    delete [] a_list;
    a_list = NULL;
}
// function that creates a new adj_list_node with given parameters
adj_list_node * graph::new_adj_list_node(drone &a_drone, int a_count)
{
    adj_list_node * new_node = new adj_list_node;
    new_node->set_drone(a_drone);
    new_node->set_count(a_count);
    return new_node;
}
void graph::add_edge(int a, int b, drone &to_add, bool check)
{
    adj_list_node * new_node = new_adj_list_node(to_add, b);
    new_node->set_next(a_list[a].get_head());
    a_list[a].set_head(new_node);
    new_node = new_adj_list_node(to_add, a);
    new_node->set_next(a_list[b].get_head());
    a_list[b].set_head(new_node);
    new_node->set_occupied(true);
}
