#include <bits/stdc++.h>
using namespace std;

int tree[100];
int n;

int height(int i)
{
    if (i > n)
        return 0;

    int left = height(2 * i);
    int right = height(2 * i + 1);

    return max(left, right) + 1;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }

    cout << "\nTree Structure:\n";

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << tree[i];

        if (2 * i <= n)
            cout << " | Left = " << tree[2 * i];

        if (2 * i + 1 <= n)
            cout << " | Right = " << tree[2 * i + 1];

        cout << endl;
    }

    cout << "\nBalancing Factors:\n";

    for (int i = 1; i <= n; i++)
    {
        int leftHeight = height(2 * i);
        int rightHeight = height(2 * i + 1);

        int BF = leftHeight - rightHeight;

        cout << "Node "<< tree[i] << " -> BF = " << BF<< endl;
    }

    return 0;
}