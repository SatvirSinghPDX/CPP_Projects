#include "CS299_clist.h"
int list::add_before(node *& current_rear)
{
    int count = 0;
    if(current_rear == this->rear) 
    {
        return 0; 
    }
    if(current_rear->next->data % 2 == 0)
    {
        node * temp = new node;
        temp->data = 100;
        temp->next = current_rear->next;
        current_rear->next = temp;
        count++;
        return count + add_before(current_rear->next->next);
    }
    return count + add_before(current_rear->next);
}

int list::add_before()
{
    if(!rear)
        return 0;  
    if(rear->next->data % 2 == 0)
    {
        node * temp = new node;
        temp->data = 100;
        temp->next = rear->next;
        rear->next = temp;
        return 1+add_before(rear->next->next);
    }
    return add_before(rear->next);
}

bool list::remove_same(node *& rear)
{
    if(rear == this->rear)
    {
        return false; 
    }
    if(rear->next->data == this->rear->data)
    {
        node * temp = rear->next->next;
        delete rear->next;
        rear->next = NULL;
        rear->next = temp;
        return true;
    }
    return remove_same(rear->next);
}

bool list::remove_same()
{
    if(!rear)
        return false;
    if(rear->next->data == rear->data)
    {
        node * temp = rear->next->next;
        delete rear->next;
        rear->next = NULL;
        rear->next = temp;
    } 
    return remove_same(rear->next);
}

int list::count_even(node * rear)
{
    int count = 0;
    if(!rear)
    {
        return 0; 
    }
    if(rear == this->rear)
    {
        if(this->rear->data % 2 == 0)
            return count + 1; 
        return count; 
    }
    if(rear->data % 2 == 0)
    {
        count++;  
    }
    return count + count_even(rear->next);
}

int list::count_even()
{
    return count_even(rear->next);
}

bool list::add_end(node *& rear)
{
    if(!rear)
    {
        return false; 
    }
    node * temp = new node;
    temp->data = 9;
    if(rear == this->rear)
    {
        rear->next = temp;
        temp->next = rear;
        return true; 
    }
    if(rear->data == temp->data)
    {
        return false; 
    }
    if(rear->next == this->rear)
    {
        rear->next = temp;
        temp->next = this->rear;
    }
    return add_end(rear->next);
}

bool list::add_end()
{
    return add_end(rear->next);
}

int list::copy(node *& new_list, node * original)
{
    int count = 0;
    if(!original)
    {
        new_list = NULL;
        return 0;
    }
    if(original->next == NULL)
    {
        return 1; 
    }
    new_list = new node;
    new_list->data = original->data;
    new_list->next = original->next; 
    count++;
    return count + copy(new_list->next,original->next);
}

int list::copy(list & new_list)
{
    return copy(this->rear->next,new_list.rear->next);
}

bool list::add_before_even(node *& rear)
{
    if(!rear)
    {
        return false; 
    }
    if(rear == this->rear)
    {
        return false; 
    }
    node * temp = new node;
    temp->data = 1000;
    if(rear->data % 2 == 0)
    {
        node * temp2 = rear->next; 
        rear->next = temp;
        temp->next = temp2;
        return add_before_even(rear->next->next); 
    }
    return add_before_even(rear->next);
}

bool list::add_before_even()
{
    return add_before_even(rear->next);
}

int list::remove_every_other(node *& rear)
{
    int count = 0;
    if(!rear)
    {
        return 0; 
    }
    if(rear == this->rear)
    {
        return count; 
    }
    if(rear->next->next == this->rear->next)
    {
        return count; 
    }
    node * temp = rear->next->next;
    delete rear->next;
    rear->next = NULL;
    rear->next = temp;
    count++;
    return count + remove_every_other(rear->next);
}

int list::remove_every_other()
{
    return remove_every_other(rear->next);
}
