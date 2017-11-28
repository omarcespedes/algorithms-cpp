#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long sz, p;
    while(true) {
        long x, y, center, r, corner, r2, oddN;
        scanf("%ld %ld", &sz, &p);
        if(!sz && !p) break;

        center = (sz >> 1) + 1;
        r = ceil(sqrt(p));
        if(r % 2 == 0) r += 1;
        oddN = ((r + 1)/2) - 1;
        corner = center + oddN;

        r2 = r*r;
        if(p == 1) {
            x = center;
            y = center;
        } else if(p > (r2 - (r - 1) )) {
            y = corner;
            x = corner - (r2 - p);
        } else if(p > (r2 - 2*(r-1))) {
            x = corner - r + 1;
            y = corner - (r2 - (r - 1) - p);
        } else if(p > (r2 - 3*(r-1))) {
            y = corner - r + 1;
            x = (r2 - 2*(r-1) - p) + (sz - center - oddN + 1);
        } else {
            x = corner;
            y = (r2 - 3*(r-1) - p) + (sz - center - oddN + 1);
        }

        printf("Line = %ld, column = %ld.\n", x, y);
    }
    return 0;
}
