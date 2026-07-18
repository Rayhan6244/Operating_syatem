#include <iostream>
using namespace std;

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int nb = 5, np = 4;

    cout << "Worst Fit (Variable Partition):\n";
    for (int i = 0; i < np; i++)
    {
        int chosen = -1;
        for (int j = 0; j < nb; j++)
        {
            if (block[j] >= process[i])
            {
                if (chosen == -1 || block[j] > block[chosen])
                    chosen = j;
            }
        }
        if (chosen != -1)
            block[chosen] -= process[i];
        cout << "Process " << i + 1 << " -> Block " << (chosen == -1 ? -1 : chosen + 1) << "\n";
    }

    cout << "\nRemaining block sizes: ";
    for (int j = 0; j < nb; j++)
        cout << block[j] << " ";
    cout << "\n";
    return 0;
}