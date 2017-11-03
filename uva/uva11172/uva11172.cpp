
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        puts(a == b? "=" : a > b? ">" : "<");
    }
    return 0;
}
