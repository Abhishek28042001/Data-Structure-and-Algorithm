#include<bits/stdc++.h>
using namespace std;

void arrange(stack<int> &s, int n){
    // base case
    if(s.empty() || (!s.empty() && s.top()<=n)){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();

    // recursive call
    arrange(s,n);

    s.push(num);
}

void sorted_stack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();

    // resursive call
    sorted_stack(s);

    arrange(s,num);
}



int main(){

    stack<int> s;
    s.push(8);
    s.push(5);
    s.push(88);
    s.push(75);
    s.push(3);
    s.push(46);
    s.push(1);

    sorted_stack(s);

    cout<<"Sort stack in ascending order\n";
    while(!s.empty()){
        cout<<s.top()<< " ";
        s.pop();
    }
    return 0;
}