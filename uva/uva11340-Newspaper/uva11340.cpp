#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n, k, val, m, l;
    double p;
    char key;
    string s;
    scanf("%d", &n);
    while(n--) {
        p = 0;
        map<char, int> mp;
        map<char, int>::iterator it;
        scanf("%d", &k);
        while(k--) {
            cin >> key;
            cin >> val;
            mp[key] = val;
        }
        scanf("%d", &m);
        cin.ignore();
        while(m--) {
            s = "";
            getline(cin , s);
            l = s.size();
            for(int i = 0 ; i < l ; i++) {
                it = mp.find(s[i]);
                if(it != mp.end()) {
                    p += it -> second;
                }
            }
        }
        p /= 100;
        printf("%0.2lf$\n", p);
        mp.clear();
    }
    return 0;
}

