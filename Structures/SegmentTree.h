//
// Created by Omar Cespedes on 1/26/18.
//

#ifndef ALGORITHMS_CPP_SEGMENTTREE_H
#define ALGORITHMS_CPP_SEGMENTTREE_H

#include <vector>

using namespace std;

class SegmentTree {
private: vector<int> st, A;
    int n;
    int left(int p) {return p << 1;}
    int right(int p) {return (p << 1) + 1;}

    void build(int p, int L, int R) {
        int M = (L+R)/2;
        if(L == R ) {
            st[p] = A[L];
        } else {
            build(left(p) , L, M);
            build(right(p), M+1, R);
            st[p] = merge(st[left(p)], st[right(p)]);
        }
    }

    //Customize merging strategy
    int merge(int a, int b) {
        return a >= b? a : b;
    }

    int search(int p, int L, int R, int i, int j) {
        int M = (L+R)/2;
        if(i <= L && R <= j ) {
            return st[p];
        }
        else if(j <= M) return search(left(p), L, M, i, j);
        else if(i > M) return search(right(p), M+1, R, i, j);
        else {
            return merge(
                    search(left(p), L, M, i, j),
                    search(right(p), M+1, R, i, j)
            );
        }
    }

    void update(int p, int L, int R, int pos, int val) {
        if(L == R) {
            A[pos] = val;
            st[p] = val;
        } else {
            int M = (L+R)/2;
            if(pos <= M) update(left(p), L, M, pos, val);
            else update(right(p), M+1, R, pos, val);
            st[p] = merge(st[left(p)], st[right(p)]);
        }
    }

public:
    SegmentTree(const vector<int> &_A) {
        A = _A;
        n = (int) A.size();
        st.assign(4*n, 0);
        build(1, 0, n - 1);
        printf("done constructing");
    }

    int search(int i, int j) {
        return search(1, 0, n - 1, i, j);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

};


#endif //ALGORITHMS_CPP_SEGMENTTREE_H
