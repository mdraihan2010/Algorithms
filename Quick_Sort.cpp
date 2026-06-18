#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    while (i < j)
    {
        while (i <= h && A[i] <= pivot)
            i++;
        while (j >= l && A[j] > pivot)
            j--;

        if (i < j)
            swap(A[i], A[j]);
    }

    swap(A[l], A[j]); 
    return j;
}

void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);

        quickSort(A, l, p - 1); 
        quickSort(A, p + 1, h);
    }
}

int main()
{
int n;
cin >> n;
int A[n];
for (int i = 0; i < n; i++) {
    cin >> A[i];
}

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}