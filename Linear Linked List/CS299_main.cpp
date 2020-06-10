#include "CS299_list.h"
//Place your name here

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the functions

   // object.remove_last_two();
    //cout << "average is: " << object.average(); 
   // object.move_head();
    //cout << "NUMBER OF ITEMS: " << object.remove_all_but_last();
    cout << "LARGEST ITEM: " << object.find_largest(); 
    //object.remove_lasttwo(); 
    //object.remove_last(); 
    //cout << object.exists(5); 
    //cout << "LAST ITEM IS: " << object.display_last() << endl; 
    //object.move_head_to_end(); 
    //list object2;
    //object2.build();
    //object2.copy_all_but_2s(object); 
    //cout << "SECOND TO LAST: " << object.find_second_to_last()->data << endl;
   // cout << "NUM OF ITEMS REMOVED: " << object.remove_greater(); 
    object.display();  //displays the LLL again!
   
    
    return 0;
}
