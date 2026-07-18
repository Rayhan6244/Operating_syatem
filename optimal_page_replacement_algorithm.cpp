#include <iostream>
using namespace std;

int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
int n = 13, frames = 3;
int frame[3] = {-1, -1, -1};

int findReplace(int index)
{
    int farthest = index, replace = 0;
    for (int i = 0; i < frames; i++)
    {
        int j;
        for (j = index; j < n; j++)
        {
            if (frame[i] == pages[j])
                break;
        }
        if (j == n)
            return i; // this page never used again
        if (j > farthest)
        {
            farthest = j;
            replace = i;
        }
    }
    return replace;
}

int main()
{
    int faults = 0;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i])
                found = true;

        if (!found)
        {
            int empty = -1;
            for (int j = 0; j < frames; j++)
                if (frame[j] == -1)
                {
                    empty = j;
                    break;
                }

            int replace = (empty != -1) ? empty : findReplace(i + 1);
            frame[replace] = pages[i];
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