#ifndef BACKTRACK_HPP
#define BACKTRACK_HPP

#define DIMENSION 9                                                //数独维度为9
#define NCELLS DIMENSION * DIMENSION    //共81个格子
struct point{                                                                   //点的坐标
    int x,y;
};
struct boardtype{                                                       //数独矩阵
    int m[DIMENSION + 1][DIMENSION + 1];        //存储数独的矩阵
    int freecount;                                                              //剩余的空格
    point move[NCELLS + 1];                                     //怎么去填充空格
};

void construct_candidate(int a[], int k, boardtype *board, int c[], int *ncandidates){
    /**/
}

#endif