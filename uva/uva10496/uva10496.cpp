#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

int dist[11][11];
int x[12];
int y[12];
int dp[12][2049];
int t = 0;
int maxV;

int tsp(int pos, int bitmask) {
    int m = 2147483000;
    int tmp;
    if(bitmask == maxV) {
        return dist[0][pos];
    }
    if(dp[pos][bitmask]) {
         return dp[pos][bitmask];
    }

    for(int i = 0 ; i < t ; i++) {
        if (!(bitmask & (1 << i))) {
            tmp = dist[pos][i] + tsp( i, bitmask | (1 << i));
            m = min(m, tmp);
        }
    }

    dp[pos][bitmask] = m;

    return m;
}

int main() {
    int n;
    int c;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &c, &c);
        scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &c);
        t = c + 1;
        maxV = (1 << t) - 1;
        for(int i = 1 ; i <= c; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        for(int i = 0 ; i < t ; i++) {
            for(int j = i + 1 ; j < t; j++) {
                dist[i][j] = dist[j][i] =  abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        printf("The shortest path has length %d\n", tsp(0,1));
    }
    return 0;
}
