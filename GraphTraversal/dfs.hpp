#ifndef DFS_HPP
#define DFS_HPP

#include "adjlist.hpp"
bool  processed[MAXV + 1];
bool  discovered[MAXV + 1];
int parent[MAXV + 1];

void initialize_search(graph *g){
    for(int i = 1; i != g->nvertices; ++i){
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}
//可以根据需要修改以下三个函数
void process_vertex_late(int v);
void process_vertex_early(int v);
void process_edge(int x, int y);

void dfs(graph *g, int v){
    edgenode *p;
    discovered[v] = true;
    process_vertex_early(v);

    p = g->edges[v];
    while(p != nullptr){
        int y = p->y;
        if(discovered[y] == false){
            parent[y] = v;
            process_edge(v, y);
            dfs(g, y);
        }else if((!processed[y]) || (g->directed)){
            process_edge(v, y);
        }
        p = p->next;
    }

    process_vertex_late(v);
    processed[v] = true;
}

#endif