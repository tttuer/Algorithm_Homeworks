#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");

    int T, H, W, N;

    in >> T;

    while(T--) {
        in >> H >> W >> N;

        int height = N % H;
        int floor;

        if(N % H != 0) floor = N / H + 1;
        else floor = N / H;

        if(height == 0) height = H;
        
        cout << height * 100 + floor << endl;
    }
}