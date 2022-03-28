//INTERLEAVING THE FIRST HALF OF THE QUEUE OF THE QUEUE WITH SECOND HALF

// USING RECURSION

#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& s, int num){
    // base case
    if(s.empty()){
        s.push(num);
        return;
    }

    int x = s.top();
    s.pop();
    // recursive call
    solve(s, num);
    s.push(x);
}

void pushAtBottom(stack<int> &s, int num){
    solve(s, num);

}

void reverse(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    //recursive cALL
    reverse(s);
    
    pushAtBottom(s, num);
}


int main(){
    queue<int> q;
    stack<int> s;
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
        s.push(ch);
    }
    
     reverse(s);
    

    for(int i=0;i<n/2;i++){
        cout<<s.top()<<" "<<q.front()<<" ";
        s.pop();
        q.pop();
    }

    return 0;
}