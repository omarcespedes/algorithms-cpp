#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, b, h, w, p, v, minV;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
        minV = b+1;
        for(int i = 0 ; i < h; i++) {
            scanf("%d", &p);
            for(int j = 0 ; j < w ; j++) {
                scanf("%d", &v);
                if(v >= n && p*n <= b) {
                    minV = min(p*n, minV);
                }
            }
        }
        if(minV == b+1) {
            puts("stay home");
        } else {
            printf("%d\n", minV);
        }
    }
    return 0;
}
