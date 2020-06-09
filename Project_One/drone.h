/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 1/31/2018
 Assignment: 1
 This is the .h file for the drone class as well as the photography_drone class, delivery_drone class, toy_drone
 class, and the gps class. This is where I will establish the "is a" single inheritance heirarchy between the
 drone class and all of the specific types of drones using derivation lists to achieve public derivation.
 */
#ifndef drone_h
#define drone_h
class drone
{
public:
    drone();        // default constructor
    drone(const drone & obj);       // copy constructor
    ~drone();       // destructor
    void update_battery_life(int new_battery_life);         // function that updates the battery life
    void update_size(const char * new_size);          // function that updates the size of the drone
    void update_motor_size(const char * new_motor_size);    // function that updates the size of the motor
    int retrieve_battery_life();        // function that returns the battery life
    char * retrieve_size();         // function that returns the size of the drone
    char * retrieve_motor_size();       // function that updates the size of the motor
private:
    int battery_life;       // battery life variable
    char * size;        // variable for the size of the drone
    char * size_of_motor;       // variable for the size of the drones motor
};
class photography_drone: public drone
{
public:
    photography_drone();        // default constructor
    ~photography_drone();       // destructor
    void update_camera_quality(int new_camera_quality);         // function that updates the camera quality
    int retrieve_camera_quality();      // function that returns the camera quality
    void update_video_state(bool new_state);    // function that updates the state of the video flag
    bool retrieve_video_state();    // function that returns the state of the video flag
    void update_photo_state(bool new_state);    // function that updates the state of the photo flag
    bool retrieve_photo_state();    // function that returns the state of the photo flag
private:
    double camera_quality;         // variable for camera megapixels
    bool video;
    bool photo;
};
class gps
{
public:
    gps();      // default constructor
    ~gps();     // destructor
    gps(const gps & obj);       // copy constructor
    char * get_address();       // function that returns the address of the delivery location
    void set_address(char * new_address);       // function that updates the address of the delivery location
private:
    char * address;     // address variable
};

class delivery_drone: public drone
{
public:
    delivery_drone();       // default constructor
    ~delivery_drone();      // destructor
    void set_gps(gps & new_gps);        // function that puts gps in delivery drone
    gps & get_gps();    // function that returns the reference to the gps
private:
    gps gps_to_add;     // the gps in the delivery drone
};
class toy_drone: public drone
{
public:
    toy_drone();        // default constructor
    ~toy_drone();       // destructor
    void update_speed(int new_speed);       // function that updates the speed
    void update_racing_state(bool new_state);       // function that updates the state of the racing flag
    void update_general_state(bool new_state);      // function that updates the state of the general flag
    int retrieve_speed();       // function that returns the speed
    bool retrieve_racing_state();       // function that returns the state of the racing flag
    bool retrieve_general_state();         // function that returns the state of the general flag
private:
    int speed;      // speed variable
    bool racing;        // racing variable
    bool general_use;       // general_use variable
};
#endif /* drone_h */
