#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
    int site = 0;
};
typedef struct Node *Tree;

Node *getNode(int x, int site)
{
    Node *T = new Node;
    T->info = x;
    T->site = site;
    T->pLeft = NULL;
    T->pRight = NULL;
    return T;
}

void insertTree(Tree &T, int x, int &site, int &MAX, int &MIN)
{
    if (T) // T!=NULL
    {
        // tim vitri phu hop
        //-> tim ben nhanh trai(nho hon goc) hoac phai(lon hon goc)
        if (x <= T->info) // x thuoc trai
        {
            site--;
            insertTree(T->pLeft, x, site, MAX, MIN);
        }
        else // x thuoc phai
        {
            site++;
            insertTree(T->pRight, x, site, MAX, MIN);
        }
    }
    else // T =NULL
    {
        if (site > MAX)
            MAX = site;
        if (site < MIN)
            MIN = site;
        T = getNode(x, site);
    }
}
// Node *Search(Tree T, int x)
// {
//     if (T)
//     {
//         if (T->info == x)
//             return T;
//         else if (T->info > x)
//             return Search(T->pLeft, x);
//         else if (T->info < x)
//             return Search(T->pRight, x);
//     }
//     return NULL;
// }

void inputTree(Tree &T, int &MAX, int &MIN)
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int site = 0;
        insertTree(T, x, site, MAX, MIN);
    }
}

void NLR(Tree T)
{
    if (T)
    {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

void xuly(vector<Node *> &place, Tree T, int MAX, int MIN) {
    if (!T) return; //base case
    // if T is the first node with the same site, put it to the place
    if (T->site - MIN >= 0 and T->site - MIN <= MAX) {
        if (place[T->site - MIN] == NULL) {
            place[T->site - (MIN)] = T;
        } 
        // if T is not the first node with the same site, 
        // compare the info of T and the first node with the same site
        else if (place[T->site - MIN] != NULL 
            and place[T->site - MIN]->info <= place[0 - MIN]->info 
            and T->site - MIN > -MIN) {

            place[T->site - (MIN)] = T;
        } else if (place[T->site - MIN] != NULL 
            and place[T->site - MIN]->info >= place[0 - MIN]->info 
            and T->site - MIN < -MIN) {

            place[T->site - (MIN)] = T;
        }
    }
    xuly(place, T->pLeft, MAX, MIN);
    xuly(place, T->pRight, MAX, MIN);
}
/// 0  1  2 3 4 5 6
///-3 -2 -1 0 1 2 3
void quicksort(vector<Node *> &a, int l, int r)
{
    srand(time(NULL));
    int mid = l + rand() % (r - l); // tim vitri giua: mid=(l+r)/2;
    int x = a[mid]->info;
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (a[i]->info < x)
        {
            i++;
        }
        while (a[j]->info > x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(a, l, j);
    if (r > i)
        quicksort(a, i, r);
}

void xuat(vector<Node *> place)
{
    quicksort(place, 0, place.size() - 1);
    for (int i = 0; i < place.size(); i++)
    {
        if (place[i] != NULL)
            cout << place[i]->info << " ";
    }
}
int main()
{
    Tree T = NULL;
    int MAX = 0, MIN = 2000000;
    inputTree(T, MAX, MIN);
    if (T)
    {
        vector<Node *> place(abs(MIN) + abs(MAX) + 1, NULL);
        xuly(place, T, MAX, MIN);
        xuat(place);
    }
}