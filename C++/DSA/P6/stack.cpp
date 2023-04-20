/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

//###INSERT CODE HERE -
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

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}




