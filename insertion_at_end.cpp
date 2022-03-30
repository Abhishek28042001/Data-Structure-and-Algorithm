#include<bits/stdc++.h>
using namespace std;

void insertion(stack<int> &s, int n){
    //base case
    if(s.empty()){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();

    //recursive call
    insertion(s,n);

    s.push(num);
}



int main(){

    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    int n;
    cout<<"Enter number you want to insert.\n";
    cin>>n;

    insertion(s,n);

    cout<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}