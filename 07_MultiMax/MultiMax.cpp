#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int MAX = 10000;

int MultiMax(vector<int> v, int size) {
    // 2개의 숫자로 계산할 경우
    int case1 = v[size - 1] * v[size - 2];
    int case2 = v[0] * v[1];
    int case3 = v[0] * v[size - 1];

    // 3개의 숫자로 계산할 경우
    int case4 = v[size - 1] * v[size - 2] * v[size - 3];
    int case5 = v[size - 1] * v[0] * v[1];
    int case6 = v[0] * v[1] * v[2];
    int case7 = v[size - 1] * v[size - 2] * v[0];

    int max = case1;

    if(max < case2) max = case2;
    if(max < case3) max = case3;
    if(max < case4) max = case4;
    if(max < case5) max = case5;
    if(max < case6) max = case6;
    if(max < case7) max = case7;

    return max;
}

int main() {
    ifstream in;
    in.open("input.txt");

    int numcases;

    in >> numcases;

    while(numcases--) {
        int numCount;
        in >> numCount;

        vector<int> v;

        for(int i = 0;i<numCount;i++) {
            int num;
            in >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());

        cout << MultiMax(v, numCount) << endl;
    }
}



