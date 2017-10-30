#include <cstdio>
#include <string>
#include <cstring>

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
    int r;
    if(ac == 31) return 1;
    if(i == n) return 0;

    if(dp[i][ac] != -1) {
       return dp[i][ac];
    }

    r = findMatch(i + 1, ac | left[i]) | findMatch(i + 1, ac | right[i]);
    dp[i][ac] = r;
    return r;
}

int main () {
    while( true ) {
        char x[10],y[10];
        scanf("%d", &n);
        if(n == 0) {
            break;
        }
        memset(dp, -1, sizeof(dp));
        for (int i = 0 ; i < n ; i++) {
            scanf("%s %s", &x , &y);
            left[i] = getInt(x);
            right[i] = getInt(y);
        }
        if(findMatch(0, 0)) {
            printf("EXISTE\n");
        } else {
            printf("NO EXISTE\n");
        }
    }
    return 0;
}