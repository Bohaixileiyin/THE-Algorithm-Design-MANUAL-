#ifndef PRIM_HPP
#define PRIM_HPP

#include "../GraphTraversal/adjlist.hpp"

#define MAXINT INT8_MAX

int parent[MAXV + 1];
void prim(graph *g, int start){
    int intree[MAXV + 1];
    int distance[MAXV + 1];
    for(int i = 0; i <= g->nvertices; ++i){
        intree[i] = false;
        distance[i] = MAXINT;
        parent[i] = -1;
    }

    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
        edgenode *p = g->edges[v];
        while(p != nullptr){
            int w = p->y;
            int weight = p->weight;
            if((distance[w] > weight) && (intree[w] == false)){
                distance[w] = weight;
                parent[w] = v;
            }
            p = p->next;
        }
        v = 1;
        int dist = MAXINT;
        for(int i = 1; i <= g->nvertices; ++i){
            if((intree[i] == false) && (dist > distance[i])){
                dist = distance[i];
                v = i;
            }
        }
    }
}

#endif