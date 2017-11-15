#include <bitset>
#include <iostream>

using namespace std;
#define M 100000

int arr[M] = {1,2,3,4,4,5,6,6};

//O(N) Complexity

int main() {
    bitset<M> S;
    for(int i = 0 ; i < M ; i++) {
        if(arr[i] != 0 && S[arr[i]] == true) {
            cout << "Duplicate : " << arr[i] << endl;
        } else {
            S[arr[i]] = true;
        }
    }

    return 0;
}