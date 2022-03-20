//MindTree CODING ROUND//

//QUESTION- 4: Print Pattern
/*
for n=5
1
3*2
4*5*6
10*9*8*7
11*12*13*14*15
*/


//THIS CODE TIME COMPLEXITY IS O(n(log(n)))
//Auxiliary Space: O(N)

#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int size){
    int temp;
    int i,j;
    for(i=0,j=size-1;i<=j;i++,j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i];
        if(i!=size-1){
            cout<<"*";
        }
    }
    cout<<endl;
}


int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    int a=1;
    int i;
    for(i=1;i<=n;i++){
       int arr[i];
        for(int j=1;j<=i;j++){
            arr[j-1] = a;
            a++;
        }
        if(i%2==0){
            reverse(arr,i);
        }
        else{
            for(int j=0;j<i;j++){
                cout<<arr[j];
                if(j!=i-1){
                    cout<<"*";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}