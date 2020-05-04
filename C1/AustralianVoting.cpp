#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n,t,ns;
char s[30][100];
char ts[1000];
vector <int> vote[1010];
vector <int> ::iterator it;
int ha[30];
void getnum(int kn)
{
    int i=0;
    while(ts[i])
    {
        while(ts[i]==' '&&ts[i])i++;
        int tt=0;
        while(ts[i]!=' '&&ts[i]){
            tt=tt*10+ts[i]-'0';
            ++i;
        }
        if(tt!=0)vote[kn].push_back(tt);
    }
}
void voted()
{
    for(int i=0;i<ns;i++){
        ha[vote[i][0]]++;
    }
    while(1){
        int ping=1,min=1010,first=-1;
        for(int i=0;i<n;i++){
            if(ha[i+1]>ns/2){
                printf("%s\n",s[i]);
                return ;
            }
            /*
            if(ha[i+1]>=0&&first==-1)first=ha[i+1];
            if(first>=0&&ha[i+1]>=0&&ha[i+1]!=first)ping=0;
            if(ha[i+1]>=0&&ha[i+1]<min)min=ha[i+1];
            */
            ///*
            if(ha[i+1]>=0){
                if(min!=1010&&min!=ha[i+1])ping=0;
                if(min>ha[i+1]) min=ha[i+1];
            }
            //*/
        }
        if(ping){
            for(int i=0;i<n;i++)
                if(ha[i+1]>=0)
                    printf("%s\n",s[i]);
            return ;
        }
        for(int i=0;i<ns;i++){
            int flag= (min==ha[vote[i][0]]);
            for(it=vote[i].begin();it!=vote[i].end();it++)
                if(ha[*it]==min) {
                    vote[i].erase(it);
                    it--;
                }
            if(flag)
                ha[vote[i][0]]++;
        }
        for(int i=0;i<n;i++)
            if(ha[i+1]==min)ha[i+1]=-1;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
 
        for(int i=0;i<1010;i++)vote[i].clear();
        memset(ha,0,sizeof(ha));
 
        for(int i=0;i<n;i++){
            gets(s[i]);
        }
        ns=0;
        while(gets(ts)!=NULL&&strcmp(ts,"")!=0){
            getnum(ns);
            ++ns;
        }
        voted();
        if(t!=0)puts("");
    }
    return 0;
}
