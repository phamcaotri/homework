/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -

DNode* getDNode(int x) {
    DNode* new_node = new DNode;
    new_node->info = x;
    new_node->pNext = NULL;
    new_node->pPrev = NULL;
    return new_node;
}

void addTail(DList &l, int x) {
    DNode* new_node = getDNode(x);
    // trường hợp danh sách rỗng
    if (l.pHead == NULL) {
        l.pHead = l.pTail = new_node;
    }
    else {
        new_node->pPrev = l.pTail;
        l.pTail->pNext = new_node;
        l.pTail = new_node;
    }
}

void addHead(DList &l, int x) {
    DNode* new_node = getDNode(x);
    // trường hợp danh sách rỗng
    if (l.pHead == NULL) {
        l.pHead = l.pTail = new_node;
    }
    else {
        new_node->pNext = l.pHead;
        l.pHead->pPrev = new_node;
        l.pHead = new_node;
    }
}

void createList(DList &l) {
    int n;
    while(cin >> n && n != -1) {
        addTail(l, n);
    }
}

void printList(DList l) {
    if (l.pHead == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    DNode* this_node = l.pHead;
    while (this_node != NULL) {
        cout << this_node->info << " ";
        this_node = this_node->pNext;
    }
    cout << endl;
}

void init(DList &L)
{
    L.pHead = L.pTail = NULL;
}


//###INSERT CODE HERE -
int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
