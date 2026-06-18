#include <bits/stdc++.h>
using namespace std;

void countingSort(int A[], int n)
{
    int maxVal = A[0];

    // Step 1: find max value
    for (int i = 1; i < n; i++)
        if (A[i] > maxVal)
            maxVal = A[i];

    // Step 2: count array
    int count[maxVal + 1]={0};

    // Step 3: frequency count
    for (int i = 0; i < n; i++)
        count[A[i]]++;

    // Step 4: prefix sum
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Step 5: output array
   int output[n];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    // Step 6: copy back
    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

int main()
{
    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    countingSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}