#include <iostream>
using namespace std;

int main()
{
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};

    cout << "Best Fit (Variable):\n";
    for (int i = 0; i < 4; i++)
    {
        int best = -1;
        for (int j = 0; j < 5; j++)
        {
            if (block[j] >= process[i])
            {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        if (best != -1)
        {
            cout << "Process " << i + 1 << " -> Block " << best + 1 << "\n";
            block[best] = block[best] - process[i];
        }
        else
        {
            cout << "Process " << i + 1 << " -> Not Allocated\n";
        }
    }

    cout << "\nRemaining sizes: ";
    for (int j = 0; j < 5; j++)
        cout << block[j] << " ";
    cout << "\n";
    return 0;
}