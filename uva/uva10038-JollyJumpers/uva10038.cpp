#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int n, v;
    while(scanf("%d", &n) != EOF ) {
        bool complete = true;
        bool fg[n+1];
        int arr[n];
        memset(fg, false, sizeof(fg));

        for(int i = 0 ; i < n ; i++) {
            scanf("%d", &v);
            arr[i] = v;
        }

        for(int i = 1 ; i < n ; i++) {
            fg[ abs(arr[i-1] - arr[i])] = true;
        }

        for(int i = 1 ; i < n ; i++) {
            if(!fg[i]) {
                complete = false;
                break;
            }

        }
        puts(complete? "Jolly" : "Not jolly");
    }

    return 0;
}

