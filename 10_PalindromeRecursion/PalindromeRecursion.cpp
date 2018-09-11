#include <iostream>
#include <fstream>

using namespace std;

int isPalindrome(const char *arr, int begin, int end)
{
    if(begin >= end)
        return 1;
    if (arr[begin] != arr[end])
        return 0;
    return isPalindrome(arr, begin + 1, end - 1);
}

int main()
{
    ifstream in;
    in.open("input.txt");

    int numcases;
    in >> numcases;

    while (numcases--)
    {
        char arr[1000];
        in >> arr;

        int size = 0;

        for (int i = 0; arr[i] != NULL; i++)
            size++;

        cout << isPalindrome(arr, 0, size - 1) << endl;
    }
    return 0;
}