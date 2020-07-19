#include "mylist.hpp"
#include <iostream>
using namespace std;
int main(){
    mylist<int> *listofint = nullptr;//指针记得初始化，不然insert之后的第一个元素next是个未定义值，不能通过判断空指针判断到尾部
    for(int i = 0; i != 10; ++i){
        mylist<int>::insert_list(&listofint, i);
    }

    mylist<int> *p = listofint;
    while(p != nullptr){
        cout << p->item << endl;
        p = p->next;
    }

    cout << mylist<int>::search_list(listofint, 5)->item << endl;

    mylist<int>::delete_list(&listofint, 5);
    p = listofint;
    while(p != nullptr){
        cout << p->item << endl;
        p = p->next;
    }
}