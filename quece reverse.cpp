// ye correct hai
// Queue Reversal using recursion.

#include<bits/stdc++.h>
using namespace std;

void reverse_queue(queue<int> &q){
    //base case
    if(q.empty()){
        return;
    }
    int num = q.front();
    q.pop();

    //RECURSIVE CALL
    reverse_queue(q);

    q.push(num);

}

int main(){
    queue<int> q;
    int i=1;
    while(i<=5){
        q.push(i);
        i++;
    }
    reverse_queue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}