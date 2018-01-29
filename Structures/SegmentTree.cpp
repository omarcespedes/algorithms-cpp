//
// Created by Omar Cespedes on 1/26/18.
//

#include "SegmentTree.h"
#include <iostream>

int main() {
    int arr[] = {4,2,1,5,7,5,2,3};
    vector<int> A(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    SegmentTree st(A);
    printf("Segment 4, 7 = %d\n", st.search(4, 7));
    st.update(2, 6);
    printf("Segment 0, 3 = %d\n", st.search(0, 3));
    return 0;
}