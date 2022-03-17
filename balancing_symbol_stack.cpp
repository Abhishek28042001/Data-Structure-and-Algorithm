#include<iostream>
#include<unordered_map>
using namespace std;

class stack{
    public:
    char *arr;
    int top;
    int size;

    stack(int size){
        this->size = size;
        top = -1;
        arr = new char[size];
    }

    void push(char element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow\n";
        }
    }

    void check(){
        unordered_map <char,int> m;
        char c;
        for(int i=0;i<size;i++){
            c = arr[i];
            if(c == '('){
                m[c]++;
            }
            else if(c == '{'){
                m[c]++;
            }
            else if(c == '['){
                m[c]++;
            }
            if(c == ')'){
                c = '(';
                m[c]--;
                if(m[c]<0){
                    cout<<"Unbalanced\n";
                    break;
                }
            }
            else if(c == '}'){
                c = '{';
                m[c]--;
                if(m[c]<0){
                    cout<<"Unbalanced\n";
                    break;
                }
            }
            else if(c == ']'){
                c = '[';
                m[c]--;
                if(m[c]<0){
                    cout<<"Unbalanced\n";
                    break;
                }
            }
        }
        int flag = 0;
        for(int i=0;i<size;i++){
            if(m[arr[i]] != 0){
                flag++;
                //cout<<"Unbalanced\n";
                break;
            }
        }
        if(flag == 0){
            cout<<"Balanced\n";
        }
    }
};

int main(){
    string str;
    cout<<"Enter string\n";
    cin>>str;
    int size = str.length();
    stack s(size);
    for(int i=0;i<size;i++){
        s.push(str[i]);
    }
    s.check();

    return 0;
}