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
void init(DList &l) {
    l.pHead = l.pTail = NULL;
} 
DNode* getDNode(int x) {
    DNode* new_node = new DNode;
    new_node->info = x;
    new_node->pNext = NULL;
    new_node->pPrev = NULL;
    return new_node;
}

void addHead(DList &l, int x) {
    DNode* new_node = getDNode(x);
    if (l.pHead == NULL) {
        l.pHead = l.pTail = new_node;
    } else {
        new_node->pNext = l.pHead;
        l.pHead->pPrev = new_node;
        l.pHead = new_node;
    }
}
void addTail(DList &l, int x) {
    DNode* new_node = getDNode(x);
    if (l.pHead == NULL) {
        l.pHead = l.pTail = new_node;
    } else {
        new_node->pPrev = l.pTail;
        l.pTail->pNext = new_node;
        l.pTail = new_node;
    }
}

void createList(DList &l) {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        addTail(l, x);
    }
}

void printList(DList l) {
    if (l.pHead == NULL) {
        cout << "List is empty";
        return;
    }
    DNode* p = l.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void addAfter(DList &l, int x, int y) {
    DNode* new_node = getDNode(y);
    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            new_node->pNext = p->pNext;
            new_node->pPrev = p;
            p->pNext = new_node;
            if (new_node->pNext != NULL) {
                new_node->pNext->pPrev = new_node;
            }
            if (p == l.pTail) {
                l.pTail = new_node;
            }
            return;
        }
        p = p->pNext;
    }
    cout << "\nCan't find the value "<<x;
}

void addBefore(DList &l, int x, int y) {
    DNode* new_node = getDNode(y);
    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {

            new_node->pNext = p;
            new_node->pPrev = p->pPrev;
            p->pPrev = new_node;
            if (new_node->pPrev != NULL) {
                new_node->pPrev->pNext = new_node;
            }
            if (p == l.pHead) {
                l.pHead = new_node;
            }
            return;
        }
        p = p->pNext;
    }
    cout << "\nCan't find the value "<<x;

}

void addAfterMulti(DList &l, int x, int y) {
    
    DNode* p = l.pHead;
    bool check = false;
    while (p != NULL) {
        if (p->info == x) {
            check = true;
            DNode* new_node = getDNode(y);
            new_node->pNext = p->pNext;
            new_node->pPrev = p;
            p->pNext = new_node;
            if (new_node->pNext != NULL) {
                new_node->pNext->pPrev = new_node;
            }
            if (p == l.pTail) {
                l.pTail = new_node;
            }
        }
        p = p->pNext;
    }
    if (!check) {
        cout << "\nCan't find the value "<<x;
    }
   
}

void addBeforeMulti(DList &l, int x, int y) {
    DNode* p = l.pHead;
    bool check = false;
    while (p != NULL) {
        if (p->info == x) {
            check = true;
            DNode* new_node = getDNode(y);
            new_node->pNext = p;
            new_node->pPrev = p->pPrev;
            p->pPrev = new_node;
            if (new_node->pPrev != NULL) {
                new_node->pPrev->pNext = new_node;
            }
            if (p == l.pHead) {
                l.pHead = new_node;
            }
        }
        p = p->pNext;
    }
    if (!check) {
        cout << "\nCan't find the value "<<x;
    }
}

void removeHead(DList &l) {
    if (l.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }
    cout<<"\nDo you want to delete the first element?(y/n): ";
    char c;
    cin>>c;
    if (c != 'y' and c != 'Y') return;
    DNode* p = l.pHead;
    l.pHead = l.pHead->pNext;
    if (l.pHead != NULL) {
        l.pHead->pPrev = NULL;
    } else {
        l.pTail = NULL;
        cout<<"\nThe list becomes empty";
    }
    delete p;
}

void removeTail(DList &l) {
    if (l.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }
    cout<<"\nDo you want to delete the last element?(y/n): ";
    char c;
    cin>>c;
    if (c != 'y' and c != 'Y') return;
    DNode* p = l.pTail;
    l.pTail = l.pTail->pPrev;
    if (l.pTail != NULL) {
        l.pTail->pNext = NULL;
    } else {
        l.pHead = NULL;
        cout<<"\nThe list becomes empty";
    }
    delete p;
}

void removeNode(DList &l, int x) {
    // if (l.pHead == NULL) {
    //     cout<<"\nList is empty. Can't delete";
    //     return;
    // }

    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            cout<<"\nDo you want to delete "<<x<<" ?(y/n): ";
            char c;
            cin>>c;
            if (c != 'y' and c != 'Y') return;
            if (p == l.pHead) {
                DNode* q = l.pHead;
                l.pHead = l.pHead->pNext;
                if (l.pHead != NULL) {
                    l.pHead->pPrev = NULL;
                } else {
                    l.pTail = NULL;
                    cout<<"\nThe list becomes empty";
                }
                delete q;
                return;
            }
            if (p == l.pTail) {
                DNode* q = l.pTail;
                l.pTail = l.pTail->pPrev;
                if (l.pTail != NULL) {
                    l.pTail->pNext = NULL;
                } else {
                    l.pHead = NULL;
                    cout<<"\nThe list becomes empty";
                }
                delete q;
                return;
            }
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;
            delete p;
            if (l.pHead == NULL) {
                l.pTail = NULL;
                cout<<"\nThe list becomes empty";
            }
            return;
        }
        p = p->pNext;
    }
    cout<<"\nCan't find the value "<<x;
}

void removeMultiNodeS(DList &l, int x) {
    // if (l.pHead == NULL) {
    //     cout<<"\nList is empty. Can't delete";
    //     return;
    // }
    bool check = false;

    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            if (!check) {
                cout<<"\nDo you want to delete "<<x<<"s ?(y/n): ";
                char c;
                cin>>c;
                if (c != 'y' and c != 'Y') return;
            }
            check = true;
            if (p == l.pHead) {
                DNode* q = l.pHead;
                l.pHead = l.pHead->pNext;
                if (l.pHead != NULL) {
                    l.pHead->pPrev = NULL;
                } else {
                    l.pTail = NULL;
                    cout<<"\nThe list becomes empty";
                }
                delete q;
                p = l.pHead;
                continue;
            }
            if (p == l.pTail) {
                DNode* q = l.pTail;
                l.pTail = l.pTail->pPrev;
                if (l.pTail != NULL) {
                    l.pTail->pNext = NULL;
                } else {
                    l.pHead = NULL;
                    cout<<"\nThe list becomes empty";
                }
                delete q;
                p = l.pTail;
                continue;
            }
            p->pPrev->pNext = p->pNext;
            p->pNext->pPrev = p->pPrev;
            DNode* q = p;
            p = p->pNext;
            delete q;
            if (l.pHead == NULL) {
                l.pTail = NULL;
                cout<<"\nThe list becomes empty";
            }
            continue;
        }
        p = p->pNext;
    }
    if (!check) {
        cout<<"\nCan't find the value "<<x;
    }
}

void removeAfter(DList & l, int x) {
    // if (l.pHead == NULL) {
    //     cout<<"\nList is empty. Can't delete";
    //     return;
    // }
    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            if (p->pNext == NULL) {
                cout<<endl<<x<<" is the last element. Can't delete the element after it";
                return;
            }
            cout<<"\nDo you want to delete the element after "<<x<<" ?(y/n): ";
            char c;
            cin>>c;
            if (c != 'y' and c != 'Y') return;
            DNode* q = p->pNext;
            p->pNext = q->pNext;
            if (q->pNext != NULL) {
                q->pNext->pPrev = p;
            } else {
                l.pTail = p;
            }
            delete q;
            return;
        }
        p = p->pNext;
    }
    cout<<"\nCan't find the value "<<x;
}

void removeBefore(DList & l, int x) {
    // if (l.pHead == NULL) {
    //     cout<<"\nList is empty. Can't delete";
    //     return;
    // }
    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            if (p->pPrev == NULL) {
                cout<<endl<<x<<" is the first element. Can't delete the element before it";
                return;
            }
            cout<<"\nDo you want to delete the element before "<<x<<" ?(y/n): ";
            char c;
            cin>>c;
            if (c != 'y' and c != 'Y') return;
            DNode* q = p->pPrev;
            p->pPrev = q->pPrev;
            if (q->pPrev != NULL) {
                q->pPrev->pNext = p;
            } else {
                l.pHead = p;
            }
            delete q;
            return;
        }
        p = p->pNext;
    }
    cout<<"\nCan't find the value "<<x;
}
int numberOfX(DList l, int x) {
    int count = 0;
    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            count++;
        }
        p = p->pNext;
    }
    return count;
}
void removeMultiAfters(DList &l, int x) {
    int number_of_x = numberOfX(l, x);
    if (number_of_x == 1 and l.pTail->info == x) {
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the last element. Can't delete the element after it";
        return;
    }
    bool check = false;

    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            if (!check) {
                cout<<"\nDo you want to delete all elements after "<<x<<" ?(y/n): ";
                char c;
                cin>>c;
                if (c != 'y' and c != 'Y') return;
            }
            check = true;
            if (p->pNext == NULL) {
                // cout<<endl<<x<<" is the last element. Can't delete the element after it";
            } else {
                DNode* q = p->pNext;
                p->pNext = q->pNext;
                if (q->pNext != NULL) {
                    q->pNext->pPrev = p;
                } else {
                    l.pTail = p;
                }
                delete q;
            }
        }
        p = p->pNext;
    }
    if (!check) {
        cout<<"\nCan't find the value "<<x;
    }
}

void removeMultiBefores(DList &l, int x) {
    int number_of_x = numberOfX(l, x);
    if (number_of_x == 1 and l.pHead->info == x) {
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the first element. Can't delete the element before it";
        return;
    }
    bool check = false;

    DNode* p = l.pHead;
    while (p != NULL) {
        if (p->info == x) {
            if (!check) {
                cout<<"\nDo you want to delete all elements before "<<x<<" ?(y/n): ";
                char c;
                cin>>c;
                if (c != 'y' and c != 'Y') return;
            }
            check = true;
            if (p->pPrev == NULL) {
                // cout<<endl<<x<<" is the first element. Can't delete the element before it";
            } else {
                DNode* q = p->pPrev;
                p->pPrev = q->pPrev;
                if (q->pPrev != NULL) {
                    q->pPrev->pNext = p;
                } else {
                    l.pHead = p;
                }
                delete q;
            }
        }
        p = p->pNext;
    }
    if (!check) {
        cout<<"\nCan't find the value "<<x;
    }
}

void removeAll(DList &l) {
    // if (l.pHead == NULL) {
    //     cout<<"\nList is empty. Can't delete";
    //     return;
    // }
    cout<<"\nDo you want to delete all elements?(y/n): ";
    char c;
    cin>>c;
    if (c != 'y' and c != 'Y') return;
    DNode* p = l.pHead;
    while (p != NULL) {
        DNode* q = p;
        p = p->pNext;
        delete q;
    }
    l.pHead = NULL;
    l.pTail = NULL;
    cout<<"\nThe list becomes empty";
}
int main()
{
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
    cout<<"\n11. Delete the first element containing a specific value";
    cout<<"\n12. Delete all elements storing a particular value";
    cout<<"\n13. Delete the element after a specific value (only for the first one found)";
    cout<<"\n14. Delete the element before a specific value (only for the first one found)";
    cout<<"\n15. Delete all elements after a specific value";
    cout<<"\n16. Delete all elements before a specific value";
    cout<<"\n17. Delete all elements";
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
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeNode(L,x);
            break;
        case 12:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiNodeS(L,x);
            break;
        case 13:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeAfter(L,x);
            break;
        case 14:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeBefore(L,x);
            break;
        case 15:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiAfters(L,x);
            break;
        case 16:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiBefores(L,x);
            break;
        case 17:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            removeAll(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
