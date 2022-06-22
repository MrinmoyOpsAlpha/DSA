#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int x){
    if(s.size()==0){
        s.push(x);
    }

    else{
        int a=s.top();
        s.pop();
        insert_at_bottom(s,x);
        s.push(a);
    }
}

void reverse(stack<int> &s){
    if(s.empty()) return ;
    int x=s.top();
    s.pop();
    reverse(s);
    insert_at_bottom(s,x);
}

int main()
{   
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack" << endl;

    // print the elements
    // of original stack
    cout << "1"
         << " "
         << "2"
         << " "
         << "3"
         << " "
         << "4"
         << endl;

    reverse(st);
       cout<<"Reversed Stack"
        <<endl;

     while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
     }    

}