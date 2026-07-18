#include <iostream>
using namespace std;

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int nb = 5, np = 4;
    bool used[10] = {false};

    cout << "Best Fit Fixed Partition:\n";
    for (int i = 0; i < np; i++)
    {
        int chosen = -1;
        for (int j = 0; j < nb; j++)
        {
            if (!used[j] && block[j] >= process[i])
            {
                if (chosen == -1 || block[j] < block[chosen])
                    chosen = j;
            }
        }
        if (chosen != -1)
            used[chosen] = true;
        cout << "Process " << i + 1 << " -> Block " << (chosen == -1 ? -1 : chosen + 1) << "\n";
    }
    return 0;
}