#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int Henry(int fraction_a, int fraction_b, int gcd_value, int unit_fraction) {
    if((fraction_a * unit_fraction) / gcd_value - gcd_value == 0)
        return fraction_b * gcd_value;
    else if((fraction_a * unit_fraction) / gcd_value - gcd_value < 0)
        return Henry(fraction_a, fraction_b, gcd(fraction_b, unit_fraction + 1), unit_fraction + 1);
    else
        return Henry((fraction_a * unit_fraction) / gcd_value - gcd_value, fraction_b * unit_fraction / gcd_value, gcd(fraction_b * (unit_fraction + 1) / gcd_value, unit_fraction + 1), unit_fraction + 1);
}

int main() {
    ifstream in;
    in.open("input.txt");

    int numcases;
    in >> numcases;

    while(numcases--) {
        int a,b;

        in >> a >> b;

        int unit_fraction = 2;

        cout << Henry(a, b, gcd(b, unit_fraction), unit_fraction) << endl;
    }
}