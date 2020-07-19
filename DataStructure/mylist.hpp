#ifndef MY_LIST_HPP
#define MY_LIST_HPP

#include <stdio.h>
template<typename item_type>
class mylist
{
    public:
    item_type item;
    mylist *next;

    static mylist *search_list(mylist *l, item_type x){
        if(l == nullptr)
            return nullptr;
        if(l->item == x)
            return l;
        else
            return search_list(l->next, x);
    }
    static void insert_list(mylist **l, item_type x){//c语言没有引用，必须通过指针实现，此处我用引用来改写了
        mylist*p;
        p = new mylist;
        p->item = x;
        p->next = *l;
        *l = p;
    }
    static mylist *predecessor_list(mylist *l, item_type x){
        if((l == nullptr) || (l->next == nullptr)){
            printf("Error:predecessor sought on null list.\n");
            return nullptr;
        }
        if((l->next)->item == x)
            return l;
        else
            return predecessor_list(l->next, x);
    }
    static void delete_list(mylist **l, item_type x){
        mylist *p;
        mylist *pred;
        //mylist *search_list(), *predecessor_list();
        p = search_list(*l, x);
        if(p != nullptr){
            pred = predecessor_list(*l, x);
            if(pred == nullptr)
                *l = p->next;
            else
                pred->next = p->next;
            delete p;
        }
    }
};

#endif