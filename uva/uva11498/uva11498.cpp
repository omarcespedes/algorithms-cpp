
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n, x0, y0, xi, yi;
    string d;
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d %d", &x0, &y0);
        for(int i = 0 ; i < n ; i++) {
            d = "";
            scanf("%d %d", &xi, &yi);
            if(xi == x0 || yi == y0) {
                puts("divisa");
                continue;
            }
            d += yi > y0? "N" : "S";
            d += xi > x0? "E" : "O";
            cout << d << endl;
        }
    }

    return 0;
}
