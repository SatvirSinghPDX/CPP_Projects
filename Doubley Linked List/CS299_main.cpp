#include "CS299_dlist.h"
//Please place your name here:
//
//
using namespace std;


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the functions
    //cout << "SUM OF THE LAST TWO NODES: " << object.display_last_two();
    //cout << "NUM OF ITEMS AFTER REMOVAL: " << object.remove_last_two();
    //cout << object.add_average(); 
    //object.duplicate_last(); 
    cout << "NUM OF NODES SAME AS LAST: " << object.count_same() << endl;
    cout << "NUM OF NODES REMOVED: " << object.remove_larger();
    object.display();
    
    return 0;
}
