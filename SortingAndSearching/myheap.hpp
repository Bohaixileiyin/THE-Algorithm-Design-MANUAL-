#ifndef MY_HEAP_HPP
#define MY_HEAP_HPP
#include <stdio.h>
template<typename item_type, unsigned PQ_SIZE>
class priority_queue{
    public:
        item_type q[PQ_SIZE + 1];
        int n;

    static int pq_parent(int n){
        if(n == 1)
            return -1;
        else
            return n / 2;   //隐式向下取整
    }
    static int pq_young_child(int n){
        return 2 * n;
    }
    //建堆
    static void pq_insert(priority_queue *q, item_type x){
        if(q->n >= PQ_SIZE)
            printf("Warning: priority queue overflow insert x = %d\n", x);
        else{
            q->n = (q->n) + 1;
            q->q[q->n] = x;
            bubble_up(q, q->n);
        }
    }
    static void bubble_up(priority_queue *q, int p){
        if(pq_parent(p) == -1)
            return
        if(q->q[pq_parent(q)] > q->q[n]){
            pq_swap(q, p, pq_parent(p));
            bubble_up(q, pq_parent(p));
        }
    }
    static void pq_init(priority_queue *q){
        q->n = 0;
    }
    static void make_heap(priority_queue *q, item_type s[], int n){
        int i;
        pq_init(q);
        for(i = 0; i < n; ++i){
            pq_insert(q, s[i]);
        }
    }
    //取出最小元
    static item_type extract_min(priority_queue *q){
        int min = -1;

        if(q->n <= 0)
            printf("Warning: empty priority queue.\n");
        else{
            min = q->q[1];
            q->q[1] = q->q[q->n];
            q->n = q->n - 1;
            bubble_down(q, 1);
        }

        return min;
    }
    bubble_down(priority_queue *q, int p){
        int c;
        int i;
        int min_index;

        c = pq_young_child(p);
        min_index = p;

        for(i = 0; i <= 1; ++i)
            if((c + i) <= q->n){
                if(q->q[min_index] > q->q[c + i])
                    min_index = c + i;
            }
        
        if(min_index != p){
            pq_swap(q, p, min_index);
            bubble_down(q, min_index);
        }
    }
    //堆排序
    static void heapsort(item_type s[], int n){
        int i;
        priority_queue q;
        make_heap(&q, s, n);

        for(i = 0; i < n; ++i){
            s[i] = extract_min(&q);
        }
    }

    static void pq_swap(priority_queue *q, int p1, int p2){
        item_type tmp = q->q[p1];
        q->q[p1] = q->q[p2];
        q->q[p2] = tmp;
    }
};

#endif