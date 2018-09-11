#include <iostream>
#include <fstream>

using namespace std;

int Factorial(int num) {
    if(num == 0)
        return 1;
    return num * Factorial(num - 1);
}

int main() {
    ifstream in;
    in.open("input.txt");

    int numcases;
    in >> numcases;

    while(numcases--) {
        int num;
        in >> num;

        cout << Factorial(num) << endl;
    }
}