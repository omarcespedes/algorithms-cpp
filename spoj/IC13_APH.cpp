//
// Created by Omar Cespedes on 10/24/17.
//
#include <cstdio>
#include <string>

using namespace std;

int n;
int left[101];
int right[101];
int dp[101][33];

int getInt(string word) {
    int r = 0;
    for(int i = 0 ; i < word.length(); i++) {
        if(word[i] == 'a') {
            r = r | 16;
        } else if(word[i] == 'e') {
            r = r | 8;
        } else if(word[i] == 'i') {
            r = r | 4;
        } else if(word[i] == 'o') {
            r = r | 2;
        } else if(word[i] == 'u') {
            r = r | 1;
        }
    }
    return r;
}

int findMatch(int i, int ac) {
    if(ac == 31) return 2;
    if(i == n) return 1;

    if(!dp[i][ac]) {
       return 0;
    }


    return findMatch(i + 1, ac | left[i] || findMatch(i + 1, ac | right[i]));
}

int main () {
    printf("s: %d %d", dp[0][0], 2 || 2);
    while( true ) {
        char x[10],y[10];
        scanf("%d", &n);
        if(n == 0) {
            break;
        }
        for (int i = 0 ; i < n ; i++) {
            scanf("%s %s", &x , &y);
            left[i] = getInt(x);
            right[i] = getInt(y);
        }
        if(findMatch(0, 0)) {
            printf("EXISTE");
        } else {
            printf("NO EXISTE");
        }
    }
    return 0;
}