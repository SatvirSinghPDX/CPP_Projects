/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 11/11/2017
 Assignment: 3
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "race.h"
#include "training.h"

using namespace std;

int main(int argc, const char * argv[])
{
    BST bst;
    race r;
    previous_race pr;
    historical_race_list ht;
   cout << "Welcome to your race preperation application!\n"
        << "Please begin by entering historical data for each\n"
        << "type of race, all of which will be stored.\n\n";
   cout << "Here is a list of the different types of races\n"
        << "we will be dealing with:\n\n";
   cout << "1) Swimming\n"
        << "2) Running\n"
        << "3) Walking\n"
        << "4) Sprinting\n\n";
    int response;
    cout << "Are you ready to continue?\n"
    << "1) Yes\n"
    << "2) No\n";
    cin >> response;
    do{
        if (response == 1)
        {
           cout << "What type of race are you entering information for?\n";
               char buffer[50];
               char * swim_type;
               swim_type = new char[strlen(buffer)+1];
               cin >> buffer;
               strcpy(swim_type, buffer);
               pr.set_type(swim_type);
           cout << "What year did this race occur in?\n";
               int swim_year;
               cin >> swim_year;
               pr.set_year(swim_year);
           cout << "What position did you end up coming in the race?\n";
               int swim_pos;
               cin >> swim_pos;
               pr.set_pos(swim_pos);
               ht.insert(pr);
               ht.display();
            cout << "\nWould you like to add information for another race?\n"
                 << "1) Yes\n"
                 << "2) No\n";
            cin >> response;
        }
        else if (response == 2)
        {
            break;
        }
    }
    while (response != 2);
    ht.display();
    cout << "Now that we have the historic data stored in a file named 'history.txt', let's continue!\n";
    int response2;
    cout << "Are you ready to continue?\n"
         << "1) Yes\n"
         << "2) No\n";
    cin >> response2;
    do{
        if(response2 == 1)
        {
            cout << "Which type of race are you planning for?\n";
            cout << "Your options include:\n\n";
            cout << "Swimming\n"
                 << "Running\n"
                 << "Walking\n"
                 << "Sprinting\n\n";
            
            cout << "Enter an option: \n";
            char buffer2[50];
            char * race_type;
            race_type = new char[strlen(buffer2)+1];
            cin >> buffer2;
            strcpy(race_type, buffer2);
            r.update_type(race_type);
            int race_length;
            cout << "Enter the length of the race (in miles):\n";
            cin >> race_length;
            r.update_length(race_length);
            int race_intensity;
            cout << "Enter the intensity level (on a scale from 1-3):\n";
            cin >> race_intensity;
            r.update_intensity(race_intensity);
            bst.insert(r);
            if (r.report_length() <= 2)
            {
                if(r.report_intensity() == 1)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(30);
                    jog.update_days(2);
                    jog.update_intensity(1);
                    jog.update_distance(1);
                    jog.update_speed(1);
                    wt.update_duration(60);
                    wt.update_days(2);
                    wt.update_intensity(1);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(45);
                    ct.update_days(3);
                    ct.update_intensity(2);
                    ct.update_num_of_activities(2);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
                if(r.report_intensity() == 2)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(30);
                    jog.update_days(4);
                    jog.update_intensity(2);
                    jog.update_distance(2);
                    jog.update_speed(2);
                    wt.update_duration(60);
                    wt.update_days(4);
                    wt.update_intensity(2);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(60);
                    ct.update_days(4);
                    ct.update_intensity(3);
                    ct.update_num_of_activities(4);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
                if(r.report_intensity() == 3)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(60);
                    jog.update_days(5);
                    jog.update_intensity(3);
                    jog.update_distance(3);
                    jog.update_speed(3);
                    wt.update_duration(120);
                    wt.update_days(5);
                    wt.update_intensity(3);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(60);
                    ct.update_days(7);
                    ct.update_intensity(3);
                    ct.update_num_of_activities(5);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
            }
            else if(r.report_length() > 2 && r.report_length() <= 5)
            {
                if(r.report_intensity() == 1)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(45);
                    jog.update_days(4);
                    jog.update_intensity(1);
                    jog.update_distance(1);
                    jog.update_speed(1);
                    wt.update_duration(30);
                    wt.update_days(4);
                    wt.update_intensity(1);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(30);
                    ct.update_days(3);
                    ct.update_intensity(2);
                    ct.update_num_of_activities(2);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
                if(r.report_intensity() == 2)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(60);
                    jog.update_days(5);
                    jog.update_intensity(2);
                    jog.update_distance(2);
                    jog.update_speed(2);
                    wt.update_duration(60);
                    wt.update_days(3);
                    wt.update_intensity(2);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(60);
                    ct.update_days(5);
                    ct.update_intensity(3);
                    ct.update_num_of_activities(5);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
                if(r.report_intensity() == 3)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(120);
                    jog.update_days(5);
                    jog.update_intensity(3);
                    jog.update_distance(5);
                    jog.update_speed(3);
                    wt.update_duration(120);
                    wt.update_days(2);
                    wt.update_intensity(3);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(60);
                    ct.update_days(7);
                    ct.update_intensity(3);
                    ct.update_num_of_activities(8);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
            }
            else
            {
                if(r.report_intensity() == 1)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(60);
                    jog.update_days(5);
                    jog.update_intensity(3);
                    jog.update_distance(10);
                    jog.update_speed(3);
                    wt.update_duration(60);
                    wt.update_days(5);
                    wt.update_intensity(2);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(60);
                    ct.update_days(3);
                    ct.update_intensity(2);
                    ct.update_num_of_activities(2);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
                if(r.report_intensity() == 2)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(60);
                    jog.update_days(4);
                    jog.update_intensity(2);
                    jog.update_distance(2);
                    jog.update_speed(2);
                    wt.update_duration(120);
                    wt.update_days(5);
                    wt.update_intensity(2);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(120);
                    ct.update_days(5);
                    ct.update_intensity(3);
                    ct.update_num_of_activities(7);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
                if(r.report_intensity() == 3)
                {
                    training_plan tp;
                    training * t;
                    training * t2;
                    training * t3;
                    jogging jog;
                    weight_training wt;
                    circuit_training ct;
                    jog.update_duration(180);
                    jog.update_days(7);
                    jog.update_intensity(3);
                    jog.update_distance(10);
                    jog.update_speed(3);
                    wt.update_duration(120);
                    wt.update_days(7);
                    wt.update_intensity(3);
                    cout << "Which muscle group would you like to focus on?\n";
                    char buffer3[50];
                    char * muscle;
                    muscle = new char[strlen(buffer3)+1];
                    cin >> buffer3;
                    strcpy(muscle, buffer3);
                    wt.update_muscle_group(muscle);
                    ct.update_duration(120);
                    ct.update_days(7);
                    ct.update_intensity(3);
                    ct.update_num_of_activities(10);
                    t = &jog;
                    t2 = &wt;
                    t3 = &ct;
                    tp.insert(t);
                    tp.insert(t2);
                    tp.insert(t3);
                    tp.display();
                }
            }
            cout << "\nWould you like to train for another race?\n"
            << "1) Yes\n"
            << "2) No\n";
            cin >> response2;
        }
        else if(response2 == 2)
        {
            break;
        }
    }
    while(response2 != 2);
    cout << "                       The races you have added\n"
         << "                       ************************\n"
         << "----------------------------------------------------------------------\n";
    
    bst.display();
    cout << "----------------------------------------------------------------------\n";
    return 0;
}
