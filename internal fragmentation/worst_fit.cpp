#include <iostream>
using namespace std;

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int nb = 5, np = 4;
    bool used[10] = {false};
    int total = 0;

    cout << "Internal Fragmentation - Worst Fit\n";
    cout << "Process\tBlock\tFragmentation\n";
    for (int i = 0; i < np; i++)
    {
        int chosen = -1;
        for (int j = 0; j < nb; j++)
        {
            if (!used[j] && block[j] >= process[i])
            {
                if (chosen == -1 || block[j] > block[chosen])
                    chosen = j;
            }
        }
        if (chosen != -1)
        {
            used[chosen] = true;
            int frag = block[chosen] - process[i];
            total += frag;
            cout << i + 1 << "\t" << chosen + 1 << "\t" << frag << "\n";
        }
        else
        {
            cout << i + 1 << "\tNot Allocated\n";
        }
    }
    cout << "\nTotal Internal Fragmentation = " << total << "\n";
    return 0;
}