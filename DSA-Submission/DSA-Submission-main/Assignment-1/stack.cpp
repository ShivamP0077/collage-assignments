#include<iostream>
using namespace std;

class Stack{
    

    int *arr;
    int sp;
    int size;

public:
    Stack(){
        size = 10;
        arr = new int[10];
        sp = -1;

    }
    Stack(int s){
        size = s;
        arr = new int[size];
        sp = -1;

    }

    void push(int n){
        sp++;
        if (sp != size)
        {
            arr[sp] = n;
        }
        else{
            cout<<"Stack is overloded \n exiting...";
        }

    }

    int pop()
    {
        if (sp != -1)
        {
            int deta = arr[sp];
            sp--;
            cout<<deta<<endl;
            return deta;
        }
        else{
            cout<< "stack is underflow \n exiting...";
            return 0;
        }
    }

    int top(){
        if (sp != -1){
            cout<<arr[sp]<<endl;
        return arr[sp];
        }
        else cout<<"Stack is underflow \n exiting...";
    }
};

int main(void){
  Stack s(5);
  s.push(9);
  s.pop();
}