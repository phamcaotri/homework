/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

void Init(Stack &S)
{
    S.n=0;
}

void Push(Stack &S, int x)
{
    S.arr[S.n]=x;
    S.n++;
}

void Pop(Stack &S)
{
    S.n--;
}

bool isEmpty(Stack S)
{
    if (S.n==0) 
        return true;
    return false;
}

bool isFull(Stack S)
{
    if (S.n==MAX) 
        return true;
    return false;
}

int Top(Stack S)
{   if (isEmpty(S)) 
        return NULLDATA;
    return S.arr[S.n-1];
}

void printStack(Stack S)
{   
    if (isEmpty(S)) 
        cout<<"Stack is empty" << '\n';
    else
        for (int i=0; i<S.n; i++)
            cout<<S.arr[i]<<" ";
}

bool isValid(string s) {
    Stack a;
    Init(a);
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '(')
            Push(a,1);
        else {
            if (isEmpty(a))
                return false;
            Pop(a);
        }
    }
    if (isEmpty(a))
        return true;
    return false;
}


int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



