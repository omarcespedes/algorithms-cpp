

#include <bitset>
#include <iostream>
#include <string>

using namespace std;
#define M 15

int n = 5;
int arr[M] = {8,7,9,6,5,3,2,4,10,11};

//O(N) Complexity

int main() {
    int f[M];
    memset(f, 0, sizeof(f));
    for(int i = 0 ; i < M ; i++) {
        f[arr[i]] += 1;
    }

    for(int i = 0 ; i < M ; i++) {
        if(i >= n) break;
        if( f[i] && f[n-i]) {
            f[i] -= 1;
            f[n-i] -= 1;
            cout << "Pair: " << i << "-" << n-i << endl;
        }
    }
    return 0;
}