#include<iostream>
using namespace std;

int check(int n){
    int a =n;
    //cout<<"ka n"<<n<<endl;
    int flag = 1;
    while(n != 1){
        if(n%5==0){
            n/=5;
        }
        if(n%3==0){
            n/=3;
        }
        if(n%2==0){
            n/=2;
        }
        if(n%2!=0 || n%3!=0 || n%5!=0){
            return 0;
        }
    }
    
    if(flag == 1){
    	cout<<"function ka a"<<a<<endl;
        return a;
    }
    
}


int main(){
    int n;
    cout<<"Enter Nth number to find Ugly Number\n";
    cin>>n;
    int a=2;
    int ans=1;
    int count =1;
    while(count != n){
    	a++;
        ans = check(a);
        
        count++;
    }
    cout<<"Answer : "<<ans<<"wwww"<<count<<"ss"<<a;
    return 0;
}
