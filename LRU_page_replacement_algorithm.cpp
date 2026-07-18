#include <iostream>
using namespace std;

int main()
{
    int pages[13] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int frame[3] = {-1, -1, -1};
    int time[3] = {-1, -1, -1};
    int faults = 0;

    for (int i = 0; i < 13; i++)
    {
        int found = -1;
        for (int j = 0; j < 3; j++)
        {
            if (frame[j] == pages[i])
                found = j;
        }

        if (found != -1)
        {
            time[found] = i;
        }
        else
        {
            int replace = 0;
            for (int j = 1; j < 3; j++)
            {
                if (time[j] < time[replace])
                    replace = j;
            }
            frame[replace] = pages[i];
            time[replace] = i;
            faults++;
        }

        cout << "Page " << pages[i] << " -> ";
        cout << frame[0] << " " << frame[1] << " " << frame[2] << "\n";
    }
    cout << "\nTotal Page Faults = " << faults << "\n";
    return 0;
}