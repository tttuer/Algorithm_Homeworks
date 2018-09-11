#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void card_convr(int x, int n, vector<char>& v)
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz+-";

    if(x >= n)
    {
        v.push_back(dchar[x % n]);
        card_convr(x / n, n, v);
    }
    else {
        v.push_back(dchar[x]);
    }
}

int isPalindrome(int begin, int end, const vector<char> v) {
    if(begin >= end)
        return 1;
    if(v[begin] != v[end])
        return 0;
    return isPalindrome(begin + 1, end - 1, v);
}

int main()
{
    ifstream in;
    in.open("input.txt");

    int numcases;
    in >> numcases;

    while (numcases--)
    {
        int isPalin = 0;
        vector<char> v;

        int num;

        in >> num;

        for(int i=2;i<=64;i++) {
            v.clear();
            card_convr(num, i, v);

            if(isPalindrome(0, v.size() - 1, v)) {
                isPalin = 1;
                cout << 1 << endl;
                break;
            }
        }
        if(isPalin == 0) {
            cout << 0 << endl;
        }
        
    }

    return 0;
}