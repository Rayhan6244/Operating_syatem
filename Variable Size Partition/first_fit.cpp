#include <iostream>
using namespace std;

int main()
{
    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};

    cout << "First Fit (Variable):\n";
    for (int i = 0; i < 4; i++)
    {
        int flag = 0;
        for (int j = 0; j < 5; j++)
        {
            if (block[j] >= process[i])
            {
                cout << "Process " << i + 1 << " -> Block " << j + 1 << "\n";
                block[j] = block[j] - process[i];
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }

    cout << "\nRemaining sizes: ";
    for (int j = 0; j < 5; j++)
        cout << block[j] << " ";
    cout << "\n";
    return 0;
}