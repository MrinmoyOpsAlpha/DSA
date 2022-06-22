#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int N;
    queue<int> q1, q2;

    Stack()
    {
        N = 0;
    }

    void push(int x)
    {
        q2.push(x);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop()
    {
        q1.pop();
        N--;
    }

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return N;
    }
};

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.pop();
    cout<<st.size()<<endl;
    return 0;
}