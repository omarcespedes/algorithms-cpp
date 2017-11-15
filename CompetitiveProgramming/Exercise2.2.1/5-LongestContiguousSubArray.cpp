//increasing
#include <iostream>

using namespace std;

#define N 12

int arr[N] = {12, 13, 14, 15, 4, 7, 8, 1, 10, 11,25,26};

int main(){
    int max = 1, len = 1;
    for(int i = 1 ; i < N ; i++) {
        if(arr[i] > arr[i-1]) {
            len++;
        } else {
            if(len > max) {
                max = len;
            }
            len = 1;
        }
    }
    if(len > max) max = len;
    cout << max << endl;
    return 0;
}