/*
 Name: Satvir Singh
 PSU ID: 911285383
 Class: CS202
 Date: 10/30/2017
 Assignment: 2
 */
#include <iostream>
#include <cstring>
#include "interview_prep.h"
#include "textbook_review.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    CLL cl;
    textbook_review tr;
    practice_questions pq;
    powerpoint_slides ps;
    int first_response;
    do{
        cout << "1) Manage Textbooks." << endl
        << "2) Manage Practice Questions." << endl
        << "3) Manage Powerpoints." << endl
        << "4) Display all interview prep material." << endl
        << "5) Quit." << endl;
        cin >> first_response;
        if(first_response == 1)
        {
            int tb_response;
            do{
                cout << "1) Add textbook." << endl
                << "2) Remove textbook." << endl
                << "3) Show all textbooks in the list." << endl
                << "4) Go back to main menu." << endl;
                
                cin >> tb_response;
                if(tb_response == 1)
                {
                    char * response;
                    char buffer[50];
                    response = new char[strlen(buffer)+1];
                    cin.clear();
                    cin.ignore();
                    cout << "Name of textbook you want to add: " << endl;
                    cin.getline(buffer, sizeof(buffer));
                    strcpy(response, buffer);
                    cout << endl;
                    tr.add(response);
                }
                else if (tb_response == 2)
                {
                    char * response;
                    char buffer[50];
                    response = new char[strlen(buffer)+1];
                    cin.clear();
                    cin.ignore();
                    cout << "Name of textbook you want to remove: " << endl;
                    cin.getline(buffer, sizeof(buffer));
                    strcpy(response, buffer);
                    cout << endl;
                    tr.remove(response);
                }
                else if (tb_response == 3)
                {
                    tr.display_all();
                }
                else if(tb_response == 4)
                {
                    cout << endl;
                    cout << "Enter 4 to go back to main menu." << endl;
                    cin >> first_response;
                }
                else
                {
                    cout << "Invalid Response!" << endl;
                }
            }
            while(tb_response < 4);
        }
        else if(first_response == 2)
        {
            int pq_response;
            do{
                cout << "1) Add practice question." << endl
                << "2) Remove practice question." << endl
                << "3) Show all practice questions in the list." << endl
                << "4) Go back to main menu." << endl;
                cin >> pq_response;
                if(pq_response == 1)
                {
                    char * response;
                    char buffer[50];
                    response = new char[strlen(buffer)+1];
                    cin.clear();
                    cin.ignore();
                    cout << "Enter the question you want to add: " << endl;
                    cin.getline(buffer, sizeof(buffer));
                    strcpy(response, buffer);
                    cout << endl;
                    pq.add(response);
                }
                else if (pq_response == 2)
                {
                    char * response;
                    char buffer[50];
                    response = new char[strlen(buffer)+1];
                    cin.clear();
                    cin.ignore();
                    cout << "Enter the question you want to remove: " << endl;
                    cin.getline(buffer, sizeof(buffer));
                    strcpy(response, buffer);
                    cout << endl;
                    pq.remove(response);
                }
                else if (pq_response == 3)
                {
                    pq.display_all();
                }
                else if(pq_response == 4)
                {
                    //return 0;
                    cout << endl;
                    cout << "Enter 4 to go back to main menu." << endl;
                    cin >> first_response;
                }
                else
                {
                    cout << "Invalid Response!" << endl;
                }
            }
            while(pq_response < 4);
        }
        else if(first_response == 3)
        {
            int ps_response;
            do{
                cout << "1) Add powerpoint." << endl
                << "2) Remove powerpoint." << endl
                << "3) Show all powerpoints in the list." << endl
                << "4) Go back to main menu." << endl;
                cin >> ps_response;
                if(ps_response == 1)
                {
                    char * response;
                    char buffer[50];
                    response = new char[strlen(buffer)+1];
                    cin.clear();
                    cin.ignore();
                    cout << "Name of powerpoint you want to add: " << endl;
                    cin.getline(buffer, sizeof(buffer));
                    strcpy(response, buffer);
                    cout << endl;
                    ps.add(response);
                }
                else if (ps_response == 2)
                {
                    char * response;
                    char buffer[50];
                    response = new char[strlen(buffer)+1];
                    cin.clear();
                    cin.ignore();
                    cout << "Name of powerpoint you want to remove: " << endl;
                    cin.getline(buffer, sizeof(buffer));
                    strcpy(response, buffer);
                    cout << endl;
                    ps.remove(response);
                }
                else if (ps_response == 3)
                {
                    ps.display_all();
                }
                else if(ps_response == 4)
                {
                    cout << endl;
                    cout << "Enter 4 to go back to main menu." << endl;
                    cin >> first_response;
                }
                else
                {
                    cout << "Invalid Response!" << endl;
                }
            }
            while(ps_response < 4);
        }
        else if (first_response == 4)
        {
            interview_prep *text;
            interview_prep *prac;
            interview_prep *power;
            text = &tr;
            prac = &pq;
            power = &ps;
            cl.insert(text);
            cl.insert(prac);
            cl.insert(power);
            cl.display();
        }
        else if(first_response == 5)
        {
            return 0;
        }
        else
        {
            cout << "Invalid Response!" << endl;
            return 0;
        }
    }
    while(first_response < 5);
    return 0;
}
