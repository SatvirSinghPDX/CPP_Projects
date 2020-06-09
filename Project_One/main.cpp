/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 1/31/2018
 Assignment: 1
 */
#include <iostream>
#include <cstring>
#include "drone.h"
#include "controller.h"

using namespace std;

int main(int argc, const char * argv[]) {
    graph g(20);
    int drone_response;
    do{
        cout << "Welcome to the drone station!\nWhat kind of drone would you like to begin with? (Enter the # of your choice) \n\n";
    cout << "1) PHOTOGRAPHY\n"
         << "2) DELIVERY\n"
    << "3) TOY\n";
    cin >> drone_response;
    if(drone_response == 1)
    {
        photography_drone pd;
        int purpose;
        do
        {
            cout << "Will you be using this drone to shoot videos or take photos?\n\n"
            << "1) VIDEOS\n"
            << "2) PHOTOS\n";
            cin >> purpose;
            if(purpose == 1)
            {
                pd.update_video_state(true);
                pd.update_photo_state(false);
            }
            else if(purpose == 2)
            {
                pd.update_video_state(false);
                pd.update_photo_state(true);
            }
            else
            {
                cout << "\nNOT A VALID RESPONSE!\n\n";
            }
        }while(purpose > 2);
        int pd_size_response;
        do
        {
            cout << "What size photography drone would you like?\n\n"
            << "1) SMALL\n"
            << "2) MEDIUM\n"
            << "3) LARGE\n";
            cin >> pd_size_response;
            if(pd_size_response == 1)
            {
                const char * pds = "SMALL";
                pd.update_size(pds);
                pd.update_motor_size(pds);
                pd.update_battery_life(10);	 
	    }
            else if(pd_size_response == 2)
            {
                const char * pds = "MEDIUM";
                pd.update_size(pds);
                pd.update_motor_size(pds);
                pd.update_battery_life(20);	 
	    }
            else if(pd_size_response == 3)
            {
                const char * pds = "LARGE";
                pd.update_size(pds);
                pd.update_motor_size(pds);
                pd.update_battery_life(25);	 
	    }
        }while(pd_size_response > 3);
        int megapixel_response;
        do
        {
            cout << "How many megapixels would you like the camera on the drone to be?\n\n"
            << "1) 10 Megapixels\n"
            << "2) 12 Megapixels\n"
            << "3) 15 Megapixels\n"
            << "4) 20 Megapixels\n";
            cin >> megapixel_response;
            if(megapixel_response == 1)
            {
                pd.update_camera_quality(10);
            }
            else if(megapixel_response == 2)
            {
                pd.update_camera_quality(12);
            }
            else if(megapixel_response == 3)
            {
                pd.update_camera_quality(15);
            }
            else if(megapixel_response == 4)
            {
                pd.update_camera_quality(20);
            }
            else
            {
                cout << "\nNOT A VALID RESPONSE!\n\n";
            }
        }while(megapixel_response > 4);
        cout << "\nYour drone's information:\n"
        << "-----------------------------\n"
        << "Type of drone: PHOTOGRAPHY." << endl;
        cout << "Using for: ";
        if(pd.retrieve_video_state())
        {
            cout << "VIDEOS.\n";
        }
        else if(pd.retrieve_photo_state())
        {
            cout << "PHOTOS.\n";
        }
        cout << "Size of drone: " << pd.retrieve_size() << endl
        << "Battery Life: " << pd.retrieve_battery_life() << " HOURS." << endl
        << "Size of motor: " << pd.retrieve_motor_size() << endl
        << "Camera Quality: " << pd.retrieve_camera_quality() << " MEGAPIXELS.\n";
        g.add_edge(1, 0, pd, true);
        cout << "Drone added to graph at (1,0)\n\n";
    }
    else if(drone_response == 2)
    {
        delivery_drone dd;
        int dd_size_response;
        do
        {
        cout << "What size delivery drone would you like?\n\n"
        << "1) SMALL\n"
        << "2) MEDIUM\n"
        << "3) LARGE\n";
        cin >> dd_size_response;
        if(dd_size_response == 1)
        {
            const char * dds = "SMALL";
            dd.update_size(dds);
            dd.update_motor_size(dds);
            dd.update_battery_life(10);
        }
        else if(dd_size_response == 2)
        {
            const char * dds = "MEDIUM";
            dd.update_size(dds);
            dd.update_motor_size(dds);
            dd.update_battery_life(20);
        }
        else if(dd_size_response == 3)
        {
            const char * dds = "LARGE";
            dd.update_size(dds);
            dd.update_motor_size(dds);
            dd.update_battery_life(25);
        }
        else
        {
            cout << "\nNOT A VALID RESPONSE!\n\n";
        }
    }while(dd_size_response > 3);
        int delivery_response;
        cout << "What is this a delivery of?\n"
            << "1) Amazon Air\n"
        << "2) Food\n";
        cin >> delivery_response;
        char buffer[50];
        char * order_response = new char[strlen(buffer)+1];
        cout << "What did you order?\n";
        cin >> buffer;
        strcpy(order_response, buffer);
        gps gp;
        //cin.clear();
        cin.ignore();
        cout << "What is the address?\n";
        char buffer2[50];
        char * address_response = new char[strlen(buffer2)+1];
         cin.getline(buffer2, sizeof(buffer2));
        strcpy(address_response, buffer2);
        gp.set_address(address_response);
        dd.set_gps(gp);
        cout << "\nYour drone's information:\n"
        << "----------------------------\n"
        << "Type of drone: DELIVERY." << endl
        << "Size of drone: " << dd.retrieve_size() << endl
        << "Battery Life: " << dd.retrieve_battery_life() << " HOURS." << endl
        << "Size of motor: " << dd.retrieve_motor_size() << endl
        << "Order of: " << order_response << endl
        << "Address to deliver to: " << dd.get_gps().get_address() << endl;
        g.add_edge(1, 1, dd, true);
         cout << "Drone added to graph at (1,1)\n\n";
    }
    else if(drone_response == 3)
    {
        toy_drone td;
        int td_size_response;
        do
        {
            cout << "What size toy drone would you like?\n\n"
            << "1) SMALL\n"
            << "2) MEDIUM\n"
            << "3) LARGE\n";
            cin >> td_size_response;
            if(td_size_response == 1)
            {
                const char * tds = "SMALL";
                td.update_size(tds);
                td.update_motor_size(tds);
                td.update_battery_life(10);
            }
            else if(td_size_response == 2)
            {
                const char * tds = "MEDIUM";
                td.update_size(tds);
                td.update_motor_size(tds);
                td.update_battery_life(20);
            }
            else if(td_size_response == 3)
            {
                const char * tds = "LARGE";
                td.update_size(tds);
                td.update_motor_size(tds);
                td.update_battery_life(25);
            }
        }while(td_size_response > 3);
        int use;
        do
        {
            cout << "Will this toy drone be used for racing or general use?\n\n"
            << "1) RACING\n"
            << "2) GENERAL USE\n";
            cin >> use;
            if(use == 1)
            {
                td.update_racing_state(true);
                td.update_general_state(false);
                td.update_speed(25);
            }
            else if(use == 2)
            {
                td.update_racing_state(false);
                td.update_general_state(true);
                td.update_speed(10);
            }
            else
            {
                cout << "\nNOT A VALID RESPONSE!\n\n";
            }
        }while(use > 2);
        g.add_edge(1, 2, td, true);
        cout << "\nYour drone's information:\n"
        << "----------------------------\n"
        << "Type of drone: TOY." << endl;
        cout << "Using for: ";
        if(td.retrieve_racing_state())
        {
            cout << "RACING.\n";
            cout << "Speed: " << td.retrieve_speed() << " MPH." << endl;
        }
        else if(td.retrieve_general_state())
        {
            cout << "GENERAL USE.\n";
            cout << "Speed: " << td.retrieve_speed() << " MPH." << endl;
        }
        cout << "Size of drone: " << td.retrieve_size() << endl
        << "Battery Life: " << td.retrieve_battery_life() << " HOURS." << endl
        << "Size of motor: " << td.retrieve_motor_size() << endl;
         cout << "Drone added to graph at (1,2)\n\n";
    }
    else
    {
        cout << "\nNot a valid response!\n";
    }
    }
    while(drone_response > 3);
    return 0;
}
