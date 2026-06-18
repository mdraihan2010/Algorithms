#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    cin >> x;
    int low = 0, high = n - 1;
    int pos = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            pos = mid;
            break;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (pos == -1)
        cout << "Not Found";
    else
        cout << "Found at index " << pos;

    return 0;
}