#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int vals[3];
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d %d %d", &vals[0], &vals[1], &vals[2]);
        sort(vals, vals+3);
        printf("Case %d: %d\n", i + 1, vals[1]);
    }

    return 0;
}
