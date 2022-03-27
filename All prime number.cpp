// ye abhi correct nhi hai
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number : ";
    cin>>n;
    for(int i=2;i<=n;i++){
        int m = i/2;
        int flag = 0;
        for(int j=2;j<=m;j++){
            if(m%j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<i<<" ";
        }
    }
    return 0;
}