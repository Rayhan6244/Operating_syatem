#include <iostream>
using namespace std;

int pages[13] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
int frame[3] = {-1, -1, -1};

int findReplace(int index)
{
    int farthest = -1, replace = 0;
    for (int i = 0; i < 3; i++)
    {
        int j;
        for (j = index; j < 13; j++)
        {
            if (frame[i] == pages[j])
                break;
        }
        if (j == 13)
            return i;
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
            int empty = -1;
            for (int j = 0; j < 3; j++)
            {
                if (frame[j] == -1)
                {
                    empty = j;
                    break;
                }
            }
            int replace = (empty != -1) ? empty : findReplace(i + 1);
            frame[replace] = pages[i];
            faults++;
        }

        cout << "Page " << pages[i] << " -> ";
        cout << frame[0] << " " << frame[1] << " " << frame[2] << "\n";
    }
    cout << "\nTotal Page Faults = " << faults << "\n";
    return 0;
}