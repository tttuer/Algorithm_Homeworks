#include <iostream>
#include <fstream>

using namespace std;

int sum_fibonacci(int num) {
    if(num <= 1)
        return num;
    else 
        return sum_fibonacci(num - 1) + sum_fibonacci(num - 2);
}

int main() {
    ifstream in;
    in.open("input.txt");

    int numcases;
    in >> numcases;

    while(numcases--) {
        int num;
        in >> num;
        cout << sum_fibonacci(num) << endl;
    }

    return 0;
}