#include "Chapter1.h"

void swap(item* a,item* b){
    item tmp = *a;
    *a = *b;
    *b = tmp;
}