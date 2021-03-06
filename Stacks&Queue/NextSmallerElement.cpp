#include <bits/stdc++.h>
using namespace std;

vector<int> printNSE(int arr[], int n)
{
    vector<int> v;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }

        else if (s.size() > 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }

        else if (s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                v.push_back(-1);
            }

            else
            {
                v.push_back(s.top());
            }
        }

        s.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int arr[] = {11, 9, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = printNSE(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "--->" << v[i] << endl;
    }

    return 0;
}