#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ifstream in;
    in.open("input.txt");

    int numcases;
    in >> numcases;

    while(numcases--) {
        int a,b;

        in >> a >> b;
        int x;
        while(a != 1) {
            x = (b % a == 0) ? (b / a) : (b / a + 1);
            a = a*x - b;
            b *= x;
            int gcd_value = gcd(a,b); 
            a /= gcd_value;
            b /= gcd_value;
        }
        cout << b << endl;
    }
}