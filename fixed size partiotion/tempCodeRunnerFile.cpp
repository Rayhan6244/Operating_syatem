#include <iostream>
using namespace std;

int main()
{
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};

    cout << "Worst Fit:\n";
    for (int i = 0; i < 4; i++)
    {
        int worst = -1;
        for (int j = 0; j < 5; j++)
        {
            if (block[j] >= process[i])
            {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }
        if (worst != -1)
        {
            cout << "Process " << i + 1 << " -> Block " << worst + 1 << "\n";
            block[worst] = 0;
        }
        else
        {
            cout << "Process " << i + 1 << " -> Not Allocated\n";
        }
    }
    return 0;
}