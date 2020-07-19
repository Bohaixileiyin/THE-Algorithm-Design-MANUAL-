#ifndef MY_BST_HPP
#define MY_BST_HPP

#include <iostream>
template<typename itemtype>
class myBST{
    public:
    itemtype item;
    myBST *parent = nullptr;
    myBST *left = nullptr;
    myBST *right = nullptr;

    static myBST *search_tree(myBST *l, itemtype x){//O(h)
        if(l == nullptr)return nullptr;
        if(l->item == x)return l;
        if(x < l->item)
            return search_tree(l->left, x);
        else
            return search_tree(l->right, x);
    }
    static myBST *find_min(myBST *t){
        myBST *min;
        if(t == nullptr)return nullptr;
        min = t;
        while(min->left != nullptr)
            min = min->left;
        return min;
    }
    static void traverse_tree(myBST *l){//O(n)
        if(l != nullptr){
            traverse_tree(l->left);
            std::cout << l->item << " ";//此处可以换成任意处理函数，放在中间即为中序遍历，改变处理函数的位置即可得前序后序遍历
            traverse_tree(l->right);
        }
    }
    static void insert_tree(myBST **l, itemtype x, myBST *parent){//O(h)
        myBST *p;
        if(*l == nullptr){
            p = new myBST;
            p->item = x;
            p->left = p->right = nullptr;
            p->parent = parent;
            *l = p;
            return;
        }
        if(x < (*l)->item)
            insert_tree(&((*l)->left), x, *l);
        else
            insert_tree(&((*l)->right), x, *l);
    }
    static void delete_tree(myBST *l){//O(h)
        //先获取指向父节点的指针，在判断是父节点的左/右节点
        myBST *p;
        p = l->parent;
        bool isleft = false;
        if(p->left == l){
            isleft = true;
        }else{
            isleft = false;
        }
        //无子节点
        if(l->left == nullptr && l->right == nullptr){
            if(isleft){
                p->left = nullptr;
            }else{
                p->right = nullptr;
            }
            delete l;
            return;
        }
        //有一个子节点
        if(l->left != nullptr && l->right == nullptr){
            if(isleft){
                p->left = l->left;
            }else{
                p->right = l->left;
            }
            delete l;
            return;
        }
        if(l->left == nullptr && l->right != nullptr){
            if(isleft){
                p->left = l->right;
            }else{
                p->right = l->right;
            }
            delete l;
            return;
        }
        //有两个子节点
        myBST *tmp = l->right;
        while(tmp->left){
            tmp = tmp->left;
        }
        l->item = tmp->item;
        delete_tree(tmp);
    }
};

#endif