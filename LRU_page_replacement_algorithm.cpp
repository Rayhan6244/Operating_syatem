#include <iostream>
using namespace std;

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = 13, frames = 3;
    int frame[3] = {-1, -1, -1};
    int lastUsed[3] = {-1, -1, -1};
    int faults = 0;

    for (int i = 0; i < n; i++)
    {
        int found = -1;
        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i])
                found = j;

        if (found != -1)
        {
            lastUsed[found] = i;
        }
        else
        {
            int empty = -1;
            for (int j = 0; j < frames; j++)
                if (frame[j] == -1)
                {
                    empty = j;
                    break;
                }

            int replace;
            if (empty != -1)
                replace = empty;
            else
            {
                replace = 0;
                for (int j = 1; j < frames; j++)
                    if (lastUsed[j] < lastUsed[replace])
                        replace = j;
            }
            frame[replace] = pages[i];
            lastUsed[replace] = i;
            faults++;
        }

        cout << "Page " << pages[i] << " -> ";
        for (int j = 0; j < frames; j++)
            cout << frame[j] << " ";
        cout << "\n";
    }
    cout << "\nTotal Page Faults = " << faults << "\n";
    return 0;
}