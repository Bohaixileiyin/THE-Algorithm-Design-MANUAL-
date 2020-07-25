#ifndef BFS_HPP
#define BFS_HPP

#include "adjlist.hpp"
#include <queue>
#include <iostream>
using std::queue;

bool  processed[MAXV + 1];
bool  discovered[MAXV + 1];
int parent[MAXV + 1];

int color[MAXV + 1];
#define UNCOLORED 0
#define WHITE 1
#define BLACK 2

bool bipartite;

void initialize_search(graph *g){
    for(int i = 1; i != g->nvertices; ++i){
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}
//可以根据需要修改以下三个函数
void process_vertex_late(int v){}
void process_vertex_early(int v){
    //std::cout << "processed vertex " << v << std::endl;
}
void process_edge(int x, int y){
    //std::cout << "processed edge " << x << " " << y << std::endl; 
}

void bfs(graph *g, int start){
    queue<int> q;
    q.push(start);
    discovered[start] = true;

    while(!q.empty()){
        int v = q.front();q.pop();
        process_vertex_early(v);
        processed[v] = true;
        edgenode *p = g->edges[v];
        while(p){
            int y = p->y;
            if((processed[y] == false) || g->directed){
                process_edge(v, y);
            }
            if(discovered[y] == false){
                q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
}
//---------------------------------寻找路径-----------------------------------
void find_path(int start, int end, int parents[]){
    if((start == end) || (end == -1)){
        std::cout << std::endl << start;
    }else{
        find_path(start, parents[end], parents);
        std::cout << " " << end;
    }
}
//----------------------------------连通分量-----------------------------------
void connected_components(graph *g){
    initialize_search(g);
    int c = 0;
    for(int i = 0; i <= g->nvertices; ++i){
        ++c;
        std::cout << "Component " << c;
        bfs(g, i);
        std::cout << std::endl;
    }
}
//----------------------------------双色图---------------------------------------
void twocolor(graph *g){
    for(int i = 0; i <= g->nvertices; ++i){
        color[i] = UNCOLORED;
    }
    bipartite = true;
    initialize_search(g);
    for(int i = 1; i <= g->nvertices; ++i){
        if(discovered[i] = false){
            color[i] = WHITE;
            bfs(g, i);
        }
    }
}

int complement(int color){
    if(color == WHITE){
        return BLACK;
    }
    if(color == BLACK){
        return WHITE;
    }
    return UNCOLORED;
}

void process_edge(int x, int y){
    if(color[x] == color[y]){
        bipartite = false;
    }
    color[y] = complement(color[x]);
}

#endif