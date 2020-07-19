#include <iostream>
#include <cmath>
using namespace std;
//此实现只为易读，性能优化在Writing Efficient Program中有很好的讲述
void NearestNeighbor(int points[][2],bool *visited,int *res,int total){
    int ith = 0;
    res[ith++] = 0;
    visited[0] = true;
    unsigned mindist = -1;
    int minidx = 0;
    while(ith != total){
        for(int i = 0;i != total;++i){
            if(visited[i] == false && (pow(points[i][0],2) + pow(points[i][1],2)) < mindist){
                minidx = i;
                mindist =  (pow(points[i][0],2) + pow(points[i][1],2));
            }
        }
        res[ith++] = minidx;
        visited[minidx] = true;
        mindist = -1;
    }
}
int main(){
    int p[5][2];
    p[0][0] = 0;p[0][1] = 0;
    p[1][0] = 1;p[1][1] = 0;
    p[2][0] = -1;p[2][1] = 0;
    p[3][0] = 3;p[3][1] = 0;
    p[4][0] = -5;p[4][1] = 0;
    bool vis[5] = {};
    int res[5] = {};
    int total = 5;
    NearestNeighbor(p,vis,res,total);
    //验证可知顺序无误
    for(int i = 0;i != 5;++i){
        cout << res[i];
    }




}

