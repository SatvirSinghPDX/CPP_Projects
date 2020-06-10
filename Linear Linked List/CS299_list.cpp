#include "CS299_list.h"

bool list::remove_last_two(node *& head)
{
    if(head == NULL)
    {
        return false;
    }
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return true;
    }
    if(head->next->next == NULL)
    {
        delete head->next;
        head->next = NULL;
        delete head;
        head = NULL;
        return true;
    } 
    if(head->next->next->next == NULL)
    {
        tail = head; 
    }
    return remove_last_two(head->next);
}

bool list::remove_last_two()
{
    return remove_last_two(head);
}

int list::average(node * head, int count)
{
    int sum = 0;
    if(head == NULL)
    {
        return 0; 
    }
    sum += head->data; 
    return (count += (sum + average(head->next,count++))); 
}

float list::average()
{
    return average(head,0);
}

int list::move_head(node *& head)
{
    if(!head)
    {
        return 0; 
    }
    if(head->next == NULL)
    {
        node * temp = new node;
        temp->data = this->head->data;
        head->next = temp;
        temp->next = NULL;
        this->tail = temp;
    }
    return move_head(head->next);
}

int list::move_head()
{
    return move_head(head);
}

int list::remove_all_but_last(node *& head)
{
    int count = 0;
    if(!head)
    {
        return 0; 
    }
    count++;
    node * temp = head->next;
    delete head;
    head = NULL;
    head = temp;
    if(head->next == NULL)
    {
        return 0; 
    }
    return count + remove_all_but_last(head);
}

int list::remove_all_but_last()
{
    return remove_all_but_last(head);
}

int list::find_largest(node * head)
{
    int current = head->data;
    int next;
    if(!head->next)
    {
        return head->data; 
    }
    else
    {
        next = find_largest(head->next); 
    }
    if(current > next)
    {
        return current; 
    }
    else
    {
        return next; 
    }
}

int list::find_largest()
{
    return find_largest(head);
}

bool list::remove_lasttwo(node *& head)
{
    if(!head)
    {
        return false; 
    }
    node * curr = head;
    while(curr->next->next)
    {
        curr = curr->next; 
    }
    delete curr->next;
    curr->next = NULL;
    delete curr;
    curr = NULL;
    return true;
}

bool list::remove_lasttwo()
{
    return remove_lasttwo(head);
}

bool list::exists(node * head, int match)
{
    if(!head)
    {
        return false; 
    }
    if(head->data == match)
    {
        return true; 
    }
    return exists(head->next, match);
}

bool list::exists(int match)
{
    return exists(head,match);
}

bool list::remove_last(node *& head)
{
    if(!head)
    {
        return false; 
    }
    if(!head->next)
    {
        if(exists(head->data) == false)
        {
            delete head;
            head = NULL;
            return true; 
        }
        return false; 
    }
    return remove_last(head->next);
}

bool list::remove_last()
{
    return remove_last(head);
}

int list::display_last(node * head)
{
    if(!head)
    {
        return 0; 
    }
    if(head->next == NULL && head->data != this->head->data)
    {
        cout << head->data << endl; 
        return head->data; 
    }
    return display_last(head->next);
}

int list::display_last()
{
    return display_last(head);
}

int list::move_head_to_end(node *& head)
{
    int sum = 0;
    if(!head)
    {
        return 0; 
    }
    node * temp = new node;
    temp->data = this->head->data;
    if(head->next == NULL)
    {
        head->next = temp;
        temp->next = NULL;
        return sum;
    }
    sum+=head->data;
    return sum + move_head_to_end(head->next);
}

int list::move_head_to_end()
{
    node * temp = head->next;
    delete head;
    head = NULL;
    head = temp;
    return move_head_to_end(head);
}

int list::copy_all_but_2s(node *& new_list, node * original)
{
    int count = 0;
    if(!original)
    {
        new_list = NULL;
        return 0;
    }
    new_list = new node;
    if(original->data != 2)
    { 
        new_list->data = original->data; 
        count++; 
    } 
    return count + copy_all_but_2s(new_list->next,original->next);
}

int list::copy_all_but_2s(list & new_list)
{
    return copy_all_but_2s(this->head,new_list.head);
}

node *& list::find_second_to_last(node *& head)
{
    if(!head)
    {
        return head; 
    }
    if(!head->next)
    {
        return head; 
    }
    if(!head->next->next)
    {
        return head; 
    }
    return find_second_to_last(head->next);
}

node *& list::find_second_to_last()
{
    return find_second_to_last(head);
}

int list::remove_greater(node *& head, node *& tail)
{
    int count = 0;
    if(!head)
    {
        return 0; 
    }
    if(!head->next)
    {
        return 0; 
    }
    node * temp = head->next;
    if(head->next->data > tail->data)
    {
        delete head;
        head = NULL;
        head = temp;
        count++;
    }
    return count + remove_greater(temp,tail);
}

int list::remove_greater()
{
    return remove_greater(head,find_second_to_last());
}
