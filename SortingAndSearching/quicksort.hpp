#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#define Gene template<typename item_type>

Gene
int partition(item_type s[], int l, int h){
    int i;
    int p;
    int firsthigh;
    p = h;
    firsthigh = l;
    for(int i = l; i < h; ++i){
        if(s[i] < s[p]){
            item_type tmp = s[i];
            s[i] = s[firsthigh];
            s[firsthigh] = tmp;

            ++firsthigh;
        }
    }
    item_type tmp = s[p];
    s[p] = s[firsthigh];
    s[firsthigh] = tmp;
    return firsthigh;
}

Gene
void quicksort(item_type s[], int l, int h){
    int p;
    if((h - l) > 0){
        p = partition(s, l, h);
        quicksort(s, l, p - 1);
        quicksort(s, p + 1, h);
    }
}

#endif