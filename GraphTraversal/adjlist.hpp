#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP

#include <iostream>
#define MAXV 1000   //最大顶点数
struct  edgenode{
    int y = -1;      //节点
    int weight = 0; //权值，如果是加权图
    edgenode *next = nullptr;//列表中的下一条边
};
struct graph{
    edgenode *edges[MAXV + 1];
    int degree[MAXV + 1];
    int nvertices = 0;
    int nedges = 0;
    bool directed = false;
};

void initialize_graph(graph *g, bool directed){
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for(int i = 0; i < MAXV; ++i){
        g->degree[i] = 0;
    }
    for(int i = 0; i < MAXV; ++i){
        g->edges[i] = nullptr;
    }
}
void insert_edge(graph *g, int x, int y, bool directed){
    edgenode *p = new edgenode;
    
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;
    g->degree[x]++;
    if(directed == false)
        insert_edge(g, y, x, true);
    else
        g->nedges++;
}
//假设图文件格式为：首行 设定图中顶点数和边数，随后是边的列表，每行代表一对顶点
void read_graph(graph *g, bool directed){
    int m = 0;//边的条数
    int x = 0, y = 0;
    initialize_graph(g, directed);

    std::cin >> g->nvertices >> m;
    for(int i = 0; i != m; ++i){
        std::cin >>x >> y;
        insert_edge(g, x, y, directed);
    }
}

void print_graph(graph *g){
    for(int i = 1; i != g->nvertices; ++i){
        std::cout << i << ": ";
        edgenode *p = g->edges[i];
        while(p){
            std::cout << " " << p->y;
            p = p->next;
        }
        std::cout << std::endl;
    }
}

#endif