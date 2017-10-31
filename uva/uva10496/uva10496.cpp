#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int dist[11][11];
int x[12];
int y[12];
int t = 0;

int tsp(int pos, int bitmask) {
    int m = 2147483647;
    int tmp = 0;
    if(t == pos)
        return 2147483647;

    for(int i = pos ; i < t ; i++) {
        tmp = dist[pos][i] + tsp( i + 1, bitmask | 1 << pos + 1);
        m = min(m, tmp);
    }

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
        for(int i = 1 ; i <= c; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        for(int i = 0 ; i < t ; i++) {
            for(int j = i + 1 ; j < t; j++) {
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        int x = tsp(0,0);
        printf("digito = %d", tsp(0,0));
    }
    return 0;
}
