//
// Created by Omar Cespedes on 11/15/17.
//

#include <iostream>
using namespace std;

//number 1
int modulus1(int a, int b) {
    int val;
    val = a & (b - 1);

    cout << "Native: " << a%b << endl;
    cout << "Bits: " << val << endl;
}

// number 2
bool isPowerOf2(int n) {
    if(n == 1 ) return false;
    return ((n & (-n)) == n);
}
//turn off last bit number 3
int offLastBit(int n) {
    int lastBit = (n & (-n));
    return n & (~lastBit);
}

//turn on last zero number 4

int main() {
    cout << modulus1(37, 4) << endl;
    cout << isPowerOf2(5) << endl;
    cout << offLastBit(40) << endl;

    return 0;
}