//INTERLEAVING THE FIRST HALF OF THE QUEUE OF THE QUEUE WITH SECOND HALF

#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int> q;
    stack<int> s1,s2;
    int n;
    cout<<"Enter Size of queue (must be even size) \n";
    cin>>n;
    for(int i=0;i<n;i++){
        int ch;
        cin>>ch;
        q.push(ch);
    }

    for(int i=0;i<n/2;i++){
        int ch = q.front();
        q.pop();
        s1.push(ch);
    }
    for(int i=0;i<n/2;i++){
        int ch = s1.top();
        s1.pop();
        s2.push(ch);
    }
    for(int i=0;i<n/2;i++){
        cout<<s2.top()<<" "<<q.front()<<" ";
        s2.pop();
        q.pop();
    }


    return 0;
}