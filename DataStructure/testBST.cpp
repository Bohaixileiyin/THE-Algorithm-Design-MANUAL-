#include "myBST.hpp"
#include <iostream>
using namespace std;
int main(){
    myBST<int> *bst = nullptr;

    myBST<int>::insert_tree(&bst, 4, bst);
    myBST<int>::insert_tree(&bst, 2, nullptr);
    myBST<int>::insert_tree(&bst, 5, nullptr);
    myBST<int>::insert_tree(&bst, 1, nullptr);
    myBST<int>::insert_tree(&bst, 3, nullptr);
    myBST<int>::insert_tree(&bst, 6, nullptr);
    //中序遍历为123456
    myBST<int>::traverse_tree(bst);
    cout << endl;
    //删去有两个子节点的节点2后输出13456
    myBST<int> *two = myBST<int>::search_tree(bst, 2);
    myBST<int>::delete_tree(two);
    myBST<int>::traverse_tree(bst);
    cout << endl;
    //删去只有一个子节点的节点5输出1346
    two = myBST<int>::search_tree(bst, 5);
    myBST<int>::delete_tree(two);
    myBST<int>::traverse_tree(bst);
    cout << endl;
    //删去无字节点的节点1输出346
    two = myBST<int>::search_tree(bst, 1);
    myBST<int>::delete_tree(two);
    myBST<int>::traverse_tree(bst);
    cout << endl;
    //输出最小值，可实现优先队列
    cout << myBST<int>::find_min(bst)->item << endl;
}