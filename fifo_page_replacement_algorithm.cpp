#include <iostream>
using namespace std;

int main()
{
    int pages[13] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int frame[3] = {-1, -1, -1};
    int faults = 0, next = 0;

    for (int i = 0; i < 13; i++)
    {
        int found = 0;
        for (int j = 0; j < 3; j++)
        {
            if (frame[j] == pages[i])
                found = 1;
        }

        if (found == 0)
        {
            frame[next] = pages[i];
            next = (next + 1) % 3;
            faults++;
        }

        cout << "Page " << pages[i] << " -> ";
        cout << frame[0] << " " << frame[1] << " " << frame[2] << "\n";
    }
    cout << "\nTotal Page Faults = " << faults << "\n";
    return 0;
}