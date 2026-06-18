
#include <bits/stdc++.h>
using namespace std;

void bucketSort(float arr[], int n)
{
    vector<float> bucket[n];
    for (int i = 0; i < n; i++)
    {
        int idx = n * arr[i];
        bucket[idx].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[idx] = bucket[i][j];
            idx++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    float arr[n]; // 0 to 1
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bucketSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}
