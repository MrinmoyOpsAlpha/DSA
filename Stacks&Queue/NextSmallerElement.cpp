#include <bits/stdc++.h>
using namespace std;

void printNSE(int arr[], int n){
    stack<pair<int, int>> s;
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int next = arr[i];

        if(s.empty()){
            s.push({next,i});
            continue;
        }

        while(!s.empty() && s.top().first > next){
            ans[s.top().second] = next;
            s.pop();
        }

        s.push({next,i});
    }

    while (!s.empty()) {
        ans[s.top().second] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ---> " << ans[i] << endl;
    }
}

int main()
{
    int arr[] = {11, 13, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}