#include "CS299_dlist.h"
int list::display_last_two(node * head)
{
    int sum = 0;
    if(!head)
    {
        return 0; 
    }
    if(head->next == NULL)
    {
        cout << head->data << " -> ";
        cout << head->previous->data << endl;
        sum+=head->data;
        sum+=head->previous->data;
    }
    return sum + display_last_two(head->next);
}

int list::display_last_two()
{
    return display_last_two(head);
}

int list::remove_last_two(node *& head)
{
    int count = 0;
    if(!head)
    {
        return 0; 
    }
    if(head->next == NULL)
    {
        return 0; 
    }
    ++count;
    if(head->next->next == NULL)
    {
        delete head->next; 
        head->next = NULL;
        delete head;
        head = NULL;
        return 1; 
    }
    return count + remove_last_two(head->next);
}

int list::remove_last_two()
{
    return remove_last_two(head->next);
}

int list::add_average(node *& head, int sum, int count)
{
    if(!head)
    {
        return (float)sum/(float)count; 
    }
    return add_average(head->next,sum + head->data,count + 1); 
}

float list::add_average()
{
    this->tail->next = new node;
    this->tail->next->data = add_average(head,0,0);
    return 0;
}

bool list::duplicate_last(node *& head)
{
    if(!head)
    {
        return false; 
    }
    if(!head->next)
    {
        node * temp = new node;
        temp->data = head->data;
        head->next = temp;
        temp->previous = head;
        temp->next = NULL;
        return true;
    }
    return duplicate_last(head->next);
}

bool list::duplicate_last()
{
    return duplicate_last(head);
}

int list::count_same(node * head)
{
    int count = 0;
    if(!head)
    {
        return 0; 
    }
    if(head->next == NULL)
    {
        return count; 
    }
    if(head->data == this->tail->data)
    {
        count++; 
    }
    return count + count_same(head->next);
}

int list::count_same()
{
    return count_same(head);
}

int list::remove_larger(node *& head)
{
    int count = 0;
    if(!head)
    {
        return 0; 
    }
    if(!head->next)
    {
        if(head->data > this->head->data)
        {
            delete head;
            head = NULL;;
            count++;
        }
        return count; 
    }
    if(head->data > this->head->data)
    {
        node * temp = head->next;
        node * temp2 = head->previous;
        delete head;
        head = NULL;
        head = temp;
        head->previous = temp2;
        count++;
        return count + remove_larger(head); 
    }
    return count + remove_larger(head->next);
}

int list::remove_larger()
{
    return remove_larger(head);
}
