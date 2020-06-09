#include "CS299_bst.h"
int table::remove_largest(node *& root)
{
    if(!root)
        return 0;
    if(!root->right)
    {
        int largest = root->data;
        node * temp = root->left;
        delete root;
        root = NULL;
        root = temp;
        return largest;
    }
    return remove_largest(root->right);
}
int table::remove_largest()
{
    return remove_largest(root);
}
int table::display_smaller(node * root)
{
    int count = 0;
    if(!root)
        return 0;
    if(root->data < this->root->data)
    {
        cout << root->data << "  ";
        count++;
    }
    return count + display_smaller(root->left) + display_smaller(root->right);
}
int table::display_smaller()
{
    return display_smaller(root->left);
}
int table::count_larger(node * root, int small)
{
    int count = 0;
    if(!root)
        return 0;
    if(root->data > small)
        count++;
    return count + count_larger(root->left,small) + count_larger(root->right,small);
}
int table::count_larger(node * root)
{
    return count_larger(root,smallest(root));
}
int table::count_larger()
{
    return count_larger(root);
}
int table::smallest(node * root)
{
    if(!root)
        return 0;
    if(!root->left)
        return root->data;
    return smallest(root->left);
}
int table::smallest()
{
    return smallest(root);
}
int table::remove_leaf(node *& root)
{
    int count = 0;
    if(!root)
    {
        return 0;
    } 
    if(!root->left && !root->right)
    {
        if(root->data == this->root->data)
        {
            return count; 
        }
        delete root;
        root = NULL;
        count++;
        return count; 
    }
    return count + remove_leaf(root->left) + remove_leaf(root->right);
}
int table::remove_leaf()
{
    return remove_leaf(root);
}
int table::copy_multiples(node *& new_root, node * source_root)
{
    int count = 0;
    if(!source_root)
    {
        return 0;
    }
    if(source_root->data % 3 == 0)
    {
        this->insert(source_root->data);
        count++; 
        return count + copy_multiples(new_root->left,source_root->left) + copy_multiples(new_root->right,source_root->right);
    }
    return copy_multiples(new_root,source_root->left) + copy_multiples(new_root,source_root->right);
}
int table::copy_multiples(table & new_copy)
{
    return copy_multiples(this->root,new_copy.root);
}
bool table::insert(node *& root, int to_add)
{
    if(!root)
    {
        root = new node;
        root->data = to_add;
        return true;
    }
    if(to_add < root->data)
    {
        insert(root->left,to_add); 
        return true; 
    }
    insert(root->right,to_add); 
    return true;
}
bool table::insert(int to_add)
{
    return insert(root,to_add);
}
int table::copy(node *& new_root, node * source_root)
{
    int count = 0;
    if(!source_root)
    {
        new_root = NULL;
        return 0;
    }
    new_root = new node;
    new_root->data = source_root->data;
    count++;
    return count+copy(new_root->left,source_root->left)+copy(new_root->right,source_root->right);
}
int table::copy(table & new_copy)
{
    return copy(this->root,new_copy.root);
}
int table::copy_average(node *& new_root, node * source_root, float sum, int count)
{
    if(!source_root)
    {
        new_root = NULL;
        return sum/count;
    }
    new_root = new node;
    new_root->data = source_root->data;
    sum+=new_root->data + copy_average(new_root->left,source_root->left,sum,count)+copy_average(new_root->right,source_root->right,sum,count);
    return sum; 
}
int table::copy_average(node *& new_root, node * source_root)
{
    return copy_average(new_root,source_root,0,0);
}
int table::copy_average(table & new_copy)
{
    return copy_average(this->root,new_copy.root);
}
int table::transform(node * root, node *& root_lll)
{
    if(!root)
    {
        root_lll = NULL;
        return 0;
    }
    transform(root->left,root_lll);
    //insert(root_lll,root->data);
    root_lll = new node;
    root_lll->data = root->data;
    transform(root->right,root_lll);
    return 1;
}
int table::transform(table & to_copy)
{
    return transform(to_copy.root,this->root);
}
int table::sum(node * root, int sum_total)
{
    if(!root)
        return sum_total;
    sum_total+=root->data + sum(root->left,sum_total) + sum(root->right,sum_total);
    return sum_total;
}
int table::sum()
{
    return sum(root,0);
}
int table::remove_two_largest(node *& root)
{
    if(!root)
        return 0;
    if(!root->right)
    {
        node * temp = root->left;
        delete root;
        root = NULL;
        root = temp;
        if(root->left && !root->left->right)
        {
            node * temp2 = root->left;
            delete root;
            root = NULL;
            root = temp2;
        }
        if(root->left && root->left->right)
        {
            if(root->left->right->left)
            {
                node * temp = root->left->right->left;
                delete root->left->right;
                root->left->right = NULL;
                root->left->right = temp;
                return 1;
            }
            delete root->left->right;
            root->left->right = NULL;
        }
        return 1;
    } 
    return remove_two_largest(root->right);
}
int table::remove_two_largest()
{
    return remove_two_largest(root);
}
int table::remove_inorder_right(node *& root)
{
    int count = 0;
    if(!root)
        return 0;
    if(!root->left)
    {
        delete root;
        root = NULL;
        return count++;
    }
    return remove_inorder_right(root->left);
}
int table::remove_inorder_right()
{
    return remove_inorder_right(root->right);
}
int table::remove_all_but_inorder(node *& root)
{
    if(!root)
        return 0;
    if(!root->left)
    {
        return 1; 
    }
    if(root->left)
    {
        node * temp = root->left;
        delete root;
        root = NULL;
        root = temp;
    }
    return remove_all_but_inorder(root->left);
}
int table::remove_all_but_inorder()
{
    delete root->left;
    root->left = NULL;
    return remove_all_but_inorder(root->right); 
}
int table::remove_non_leaves(node *& root)
{
    int count = 0;
    if(!root)
        return 0;
    if(is_leaf(root))
    {
        return count; 
    }
    if(root->left && !root->right)
    {
        if(is_leaf(root->left))
        {
            node * temp = root->left;
            delete root;
            root = NULL;
            root = temp;
            return count; 
        }
        node * temp = root->left;
        delete root;
        root = NULL;
        root = temp;
        count++;
    }
    if(root->right && !root->left)
    {
        if(is_leaf(root->right))
        {
            node * temp = root->right;
            delete root;
            root = NULL;
            root = temp;
            return count;
        }
        node * temp = root->right;
        delete root;
        root = NULL;
        root = temp;
        count++;
    }
    if(root->left && root->right)
    {
        if(is_leaf(root->left))
        {
            node * temp = root->left;
            delete root;
            root = NULL;
            root = temp;
            return count;
        }
        if(is_leaf(root->right))
        {
            node * temp = root->right;
            delete root;
            root = NULL;
            root = temp;
            return count;
        }
    }
    return count + remove_non_leaves(root->left) + remove_non_leaves(root->right);
}
int table::remove_non_leaves()
{
    return remove_non_leaves(root);
}
int table::count_leaves(node * root)
{
    int count = 0;
    if(!root)
        return 0;
    if(!root->left && !root->right)
        count++;
    return count + count_leaves(root->left) + count_leaves(root->right);
}
int table::count_leaves()
{
    return count_leaves(root);
}
bool table::is_leaf(node * root)
{
    if(!root)
        return false;
    if(!root->left && !root->right)
        return true;
    return is_leaf(root->left) && is_leaf(root->right);
}
float table::average(node * root, int& count)
{
    if(!root)
    {
        return 0; 
    }
    count++;
    return root->data + average(root->left,count) + average(root->right,count);
}
float table::average()
{
    int count = 0;
    return average(root,count)/count;
}
