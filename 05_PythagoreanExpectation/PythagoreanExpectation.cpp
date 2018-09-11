#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int PythagoreanExpectation(int S, int A)
{
    return 1000 * (S * S) / ((S * S) + (A * A));
}

int max_result(int **arr, int total_team)
{
    int max = PythagoreanExpectation(arr[0][0], arr[0][1]);

    for (int i = 1; i < total_team; i++)
    {
        if (PythagoreanExpectation(arr[i][0], arr[i][1]) > max)
            max = PythagoreanExpectation(arr[i][0], arr[i][1]);
    }

    return max;
}

int min_result(int **arr, int total_team)
{
    int min = PythagoreanExpectation(arr[0][0], arr[0][1]);

    for (int i = 1; i < total_team; i++)
    {
        if (PythagoreanExpectation(arr[i][0], arr[i][1]) < min)
            min = PythagoreanExpectation(arr[i][0], arr[i][1]);
    }

    return min;
}

int main()
{
    int numcases, total_team, total_play;
    int team_a, team_b, score_a, score_b;

    ifstream in;
    in.open("input.txt");

    in >> numcases;

    while (numcases--)
    {
        in >> total_team >> total_play;
        int **arr = new int *[total_team];
        for (int i = 0; i < total_team; i++)
        {
            arr[i] = new int[2];
            memset(arr[i], 0, sizeof(int) * total_team);
        }

        while (total_play--)
        {
            in >> team_a >> team_b >> score_a >> score_b;

            for(int i=0;i<total_team;i++) {
                if(i == team_a - 1) {
                    arr[team_a - 1][0] += score_a;
                    arr[team_a - 1][1] += score_b;
                }
                if(i == team_b - 1) {
                    arr[team_b - 1][0] += score_b;
                    arr[team_b - 1][1] += score_a;
                }
            }
        }

        cout << max_result(arr, total_team) << endl;
        cout << min_result(arr, total_team) << endl;
    }
}