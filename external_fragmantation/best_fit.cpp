#include <iostream>
using namespace std;

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int nb = 5, np = 4;

    for (int i = 0; i < np; i++)
    {
        int chosen = -1;
        for (int j = 0; j < nb; j++)
        {
            if (block[j] >= process[i])
            {
                if (chosen == -1 || block[j] < block[chosen])
                    chosen = j;
            }
        }
        if (chosen != -1)
            block[chosen] -= process[i];
    }

    int total = 0;
    cout << "External Fragmentation - Best Fit\n";
    for (int j = 0; j < nb; j++)
    {
        cout << "Block " << j + 1 << ": " << block[j] << "\n";
        total += block[j];
    }
    cout << "\nTotal External Fragmentation = " << total << "\n";
    return 0;
}