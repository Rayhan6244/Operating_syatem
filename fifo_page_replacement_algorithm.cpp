#include <iostream>
using namespace std;

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = 13, frames = 3;
    int frame[3] = {-1, -1, -1};
    int faults = 0, front = 0;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i])
                found = true;

        if (!found)
        {
            frame[front] = pages[i];
            front = (front + 1) % frames;
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