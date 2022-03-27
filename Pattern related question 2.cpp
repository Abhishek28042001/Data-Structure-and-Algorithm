// ye correct hai

//MindTree CODING ROUND//


#include<iostream>
using namespace std;

int main(){
    int n,s;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"\nEnter s : " ;
    cin>>s;
    for(int i=1;i<=n;i++){
        int arr[i];
        for(int j=0;j<i;j++){
            arr[j] = s;
        }
        for(int j=0;j<i;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        s++;
    }
    s--;
    for(int i=0;i<n;i++){
        int arr[i];
        for(int j=0;j<n-i;j++){
            arr[j] = s;
            cout<<arr[j]<<" ";
            
        }
        s--;
        cout<<endl;
    }
    return 0;
}