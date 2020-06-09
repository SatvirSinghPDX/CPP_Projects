#include "CS299_clist.h"
//Please place your name here
//
//

int main()
{
    list object;
    object.build();	//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the functions

   // cout << "Number of nodes added: " << object.add_before() << endl;
   // object.remove_same(); 
    cout << "NUM OF EVEN ITEMS: " << object.count_even() << endl; 
    //object.add_end(); 
    //list object2; 
    //object2.build();
    //cout << "NUM OF ITEMS COPIED: " << object2.copy(object);
    //object.add_before_even(); 
    cout << "NUM OF NODES REMOVED: " << object.remove_every_other(); 
    object.display(); //resulting list after your function call!
    
    return 0;
}
