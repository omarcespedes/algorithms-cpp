#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 500

using namespace std;

int n1, n2;
char big[MAX][MAX];
char small[MAX][MAX];

int match() {
    int total = 0;
    int t = n1 - n2 + 1;
    for( int i = 0 ; i < t ; i++) {
        for(int j = 0 ; j < t ; j++) {
            bool match = true;
            for(int i2 = 0 ; i2 < n2 ; i2++) {
                for(int j2 = 0 ; j2 < n2 ; j2++) {
                    if(small[i2][j2] != big[i+i2][j+j2]) {
                        match = false;
                        break;
                    }
                    if(!match) break;
                }
            }
            if(match) total += 1;
        }
    }
    return total;
}

void rotate() {
    char tmp[MAX][MAX];
    for(int i = 0 ; i < n2 ; i++) {
        for(int j = 0 ; j < n2 ; j++) {
            tmp[i][j] = small[n2-j-1][i];
        }
    }
    for(int i = 0 ; i < n2 ; i++) {
        for(int j = 0 ; j < n2 ; j++) {
            small[i][j] = tmp[i][j];
        }
    }
}

int main() {
    int i;
    while(true) {
        scanf("%d %d", &n1, &n2);
        if(!n1 || !n2) break;

        for(i = 0 ; i < n1 ; i++) {
            scanf("%s", big[i]);
        }
        for(i = 0 ; i < n2 ; i++) {
            scanf("%s", small[i]);
        }
        for(i = 0 ; i < 4 ; i++) {
            printf("%d", match());
            if( i != 3 ) {
                rotate();
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
