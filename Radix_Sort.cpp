#include <bits/stdc++.h>
using namespace std;

// Step 1: find maximum value
int getMax(int A[], int n)
{
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

// Step 2: counting sort for each digit (pos)
void countSort(int A[], int n, int pos)
{
    int output[n];    // output array
    int count[10] = {0}; // digits 0–9

    // count frequency of digits
    for (int i = 0; i < n; i++)
        count[(A[i] / pos) % 10]++;

    // prefix sum
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // build output (reverse for stability)
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (A[i] / pos) % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    // copy back
    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

// Step 3: radix sort
void radixSort(int A[], int n)
{
    int m = getMax(A, n);

    for (int pos = 1; m / pos > 0; pos *= 10)
        countSort(A, n, pos);
}

int main()
{
    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    radixSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}