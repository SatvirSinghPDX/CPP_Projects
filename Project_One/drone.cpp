/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 1/31/2018
 Assignment: 1
 This is the .cpp file for the drone class. In this file I will implement all of the constructors and functions
 for the drone class, photography_drone class, delivery_drone class, the toy_drone class, and the gps class.
 */
#include <stdio.h>
#include <cstring>
#include "drone.h"
// default constructor
drone::drone():battery_life(0),size(NULL),size_of_motor(NULL)
{
    
}
// copy constructor
drone::drone(const drone & obj)
{
    this->battery_life = obj.battery_life;
    this->size = new char[strlen(obj.size)+1];
    strcpy(this->size, obj.size);
    this->size_of_motor = new char[strlen(obj.size_of_motor)+1];
    strcpy(this->size_of_motor, obj.size_of_motor);
}
// destructor
drone::~drone()
{

}
// function that updates the battery life
void drone::update_battery_life(int new_battery_life)
{
    battery_life = new_battery_life;
}
// function that updates the size of a drone
void drone::update_size(const char *new_size)
{
    size = new char[strlen(new_size)];
    strcpy(size, new_size);
}
// function that updates the size of the motor
void drone::update_motor_size(const char *new_motor_size)
{
    size_of_motor = new char[strlen(new_motor_size)+1];
    strcpy(size_of_motor, new_motor_size);
}
// function that returns the battery life
int drone::retrieve_battery_life()
{
    return battery_life;
}
// function that returns the size of a drone
char * drone::retrieve_size()
{
    return size;
}
// function that returns the size of the motor
char * drone::retrieve_motor_size()
{
    return size_of_motor;
}
// default constructor
photography_drone::photography_drone():camera_quality(0)
{
    
}
// destructor
photography_drone::~photography_drone()
{
    
}
// function that updates the camera quality
void photography_drone::update_camera_quality(int new_camera_quality)
{
    camera_quality = new_camera_quality;
}
// function that returns the camera quality
int photography_drone::retrieve_camera_quality()
{
    return camera_quality;
}
// function that updates the state of the video flag
void photography_drone::update_video_state(bool new_state)
{
    video = new_state;
}
// function that returns the state of the video flag
bool photography_drone::retrieve_video_state()
{
    return video;
}
// function that updates the state of the photo flag
void photography_drone::update_photo_state(bool new_state)
{
    photo = new_state;
}
// function that returns the state of the photo flag
bool photography_drone::retrieve_photo_state()
{
    return photo;
}
// default constructor
delivery_drone::delivery_drone():gps_to_add()
{
    
}
// destructor
delivery_drone::~delivery_drone()
{
    
}
// function that sets the gps object
void delivery_drone::set_gps(gps &new_gps)
{
    gps_to_add = new_gps;
}
// function that returns the reference to the gps
gps & delivery_drone::get_gps()
{
    return gps_to_add;
}
// default constructor
toy_drone::toy_drone():speed(0),racing(false),general_use(false)
{
    
}
// destructor
toy_drone::~toy_drone()
{
    
}
// function that updates the speed
void toy_drone::update_speed(int new_speed)
{
    speed = new_speed;
}
// function that updates the state of the racing flag
void toy_drone::update_racing_state(bool new_state)
{
    racing = new_state;
}
// function that updates the state of the general_use flag
void toy_drone::update_general_state(bool new_state)
{
    general_use = new_state;
}
// function that returns the speed
int toy_drone::retrieve_speed()
{
    return speed;
}
// function that returns the state of the racing flag
bool toy_drone::retrieve_racing_state()
{
    return racing;
}
// function that returns the state of the general_use flag
bool toy_drone::retrieve_general_state()
{
    return general_use;
}
// default constructor
gps::gps():address(NULL)
{
    
}
// copy constructor
gps::gps(const gps & obj)
{
    address = new char[strlen(obj.address)+1];
    strcpy(address, obj.address);
}
// destructor
gps::~gps()
{
    
}
// function that updates the address of the delivery location
void gps::set_address(char *new_address)
{
    address = new char[strlen(new_address)+1];
    strcpy(address, new_address);
}
// function that returns the address of the delivery location
char * gps::get_address()
{
    return address;
}
