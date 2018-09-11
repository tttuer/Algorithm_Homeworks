#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
    int numcases;
    int truck_count, w, L;

    ifstream in;
    in.open("input.txt");

    in >> numcases;

    for (int index = 0; index < numcases; index++)
    {
        queue<int> trucks;

        in >> truck_count >> w >> L;

        int sumW = 0;
        int time = 0;
        int count = 0;
        int truck_weight;

        for (int i = 0; i < truck_count; i++)
        {
            in >> truck_weight;

            for (;;)
            {
                time++;

                if (count == w)
                {
                    count--;
                    sumW -= trucks.front();
                    trucks.pop();
                }
                if (sumW + truck_weight > L)
                {
                    count++;
                    sumW += 0;
                    trucks.push(0);
                }
                else
                {
                    count++;
                    sumW += truck_weight;
                    trucks.push(truck_weight);
                    break;
                }
            }
        }
        cout << time + w << endl;
    }
}
