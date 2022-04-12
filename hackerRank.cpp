#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<int> v;
    int ans = 0;
    if(n>3){
        v.push_back(3);
        v.push_back(2);
        v.push_back(1);
        ans = ans + 14 % 1000000007;
        for(int i=3;i<n;i++){
            v[i] = v[i-1] + v[i-2] + v[i-3];
            // int a = v[i] % (1000000007);
            ans = ans + (v[i] * v[i]) % 1000000007;
        }
        cout<<ans;
    }
    else{
        if(n==3){
            ans = ans + (14)% 1000000007;
        }
        if(n==2){
            ans = ans + (13)% 1000000007;
        }
        if(n==1){
            ans = ans + (9)% 1000000007;
        }
        cout<<ans;
    }
    return 0;
}