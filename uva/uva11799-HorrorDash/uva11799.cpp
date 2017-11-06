#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, c, maxV, tmp;
    scanf("%d", &n);
    for(int j = 0 ; j < n ; j++) {
        maxV = 0;
        scanf("%d", &c);
        for(int i = 0 ; i < c ; i++) {
            scanf("%d", &tmp);
            maxV = max(maxV, tmp);
        }
        printf("Case %d: %d\n", j+1, maxV);
    }
    return 0;
}
