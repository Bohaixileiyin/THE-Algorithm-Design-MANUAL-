#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#define Gene template<typename item_type>
Gene
int binary_search(item_type s[], item_type key, int low, int high){
    int middle;
    if(low > high)
        return -1;
    middle = low + (high - low) / 2;
    if(s[middle] == key)
        return middle;
    if(s[middle] > key)
        return binary_search(s, key, low, middle - 1);
    else
        return binary_search(s, key, middle + 1, high);
}

#endif