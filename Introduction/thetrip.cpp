#include <iostream>
#include <stdio.h>
 
using namespace std;
 
const int N = 1000;
double a[N], sum, ave, ans1, ans2;
 
int main()
{
    int n;
 
    while(~scanf("%d", &n) && n) {
        sum = 0;
 
        for(int i=0; i<n; i++) {
            scanf("%lf", &a[i]);
            sum += a[i];
        }
 
        ave = ((int)((sum / n + 0.005) * 100)) / 100.0;
        ans1 = ans2 = 0;
        for(int i=0; i<n; i++)
            if(a[i] > ave)
                ans1 += a[i] - ave;
            else
                ans2 += ave - a[i];
 
        printf("$%.2f\n", min(ans1, ans2));
    }
 
    return 0;
}
