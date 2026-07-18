#include <iostream>
using namespace std;

int main()
{
    int alloc[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int maxm[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[3] = {3, 3, 2};

    int need[5][3];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    int finish[5] = {0, 0, 0, 0, 0};
    int work[3] = {avail[0], avail[1], avail[2]};
    int safe[5], count = 0;

    while (count < 5)
    {
        int found = 0;
        for (int i = 0; i < 5; i++)
        {
            if (finish[i] == 0)
            {
                int canRun = 1;
                for (int j = 0; j < 3; j++)
                {
                    if (need[i][j] > work[j])
                        canRun = 0;
                }
                if (canRun == 1)
                {
                    for (int j = 0; j < 3; j++)
                        work[j] = work[j] + alloc[i][j];
                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0)
            break;
    }

    if (count == 5)
    {
        cout << "System is in SAFE state.\nSafe Sequence: ";
        for (int i = 0; i < 5; i++)
            cout << "P" << safe[i] << " ";
        cout << "\n";
    }
    else
    {
        cout << "System is NOT in a safe state.\n";
    }
    return 0;
}