#include <iostream>
#include <fstream>

using namespace std;

int isPalindrome(int dex, int b) {
    int arr[100];

    int i = 0;
    while(dex >= b) {
        arr[i] = dex % b;
        dex /= b;
        i++;
    }

    arr[i] = dex;

    for(int j=0; j<(i+1)/2; j++) {
        if(arr[j] != arr[i - j])
            return 0;
    }
    return 1;
}

int main() {
    int numcases;
    ifstream in;
    in.open("input.txt");

    in >> numcases;

    while(numcases--) {
        int dex;
        int isPalin = 0;

        in >> dex;

        for(int i=2;i<=64;i++) {
            if(isPalindrome(dex, i)) {
                cout << 1 << endl;
                isPalin = 1;
                break;
            }
        }
        if(isPalin == 0) {
            cout << 0 << endl;
        }

    }
}