#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int i, j, t, sum, num;
    while(cin >> i >> j)
    {
        cout << i << " " << j << " ";
        if(i > j)
        {
            t = i;
            i = j;
            j = t;
        }
        int max = 0;
        for(i = i; i <= j; i++)
        {
            num = 0;
            sum = i;
            while(sum != 1)
            {
                if(sum % 2 == 0)
                {
                    sum = sum / 2;
                }
                else
                {
                    sum = 3 * sum + 1;
                }
                num++;
            }
            if(num > max)
            {
                max = num;
            }
        }
        cout << max + 1 << endl;;
    }
    return 0;
}
