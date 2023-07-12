// do something with restriction of only include <iostream>
#include <iostream>
using namespace std;


// template <typename T>
// class Array {
//     private:
//         T* a;
//         int n;
//     public:
//         Array(int n) {
//             this->n = n;
//             a = new T[n];
//         }
//         Array(int n, T init) {
//             this->n = n;
//             a = new T[n];
//             for (int i = 0; i < n; i++) {
//                 a[i] = init;
//             }
//         }
//         Array(int n, T (*f)(int)) {
//             this->n = n;
//             a = new T[n];
//             for (int i = 0; i < n; i++) {
//                 a[i] = f(i);
//             }
//         }
//         T& operator[](int i) {
//             return a[i];
//         }
//         T* begin() {
//             return a;
//         }
//         T* end() {
//             return a + n;
//         }
//         Array<T>& shuffle() {
//             srand(time(NULL));
//             for (int i = 0; i < n; i++) {
//                 swap(a[i], a[rand()%n]);
//             }
//             return *this;
//         }
//         Array<T>& sort() {
//             for (int i = 0; i < n; i++) {
//                 for (int j = i; j > 0 && a[j] < a[j-1]; j--) {
//                     swap(a[j], a[j-1]);
//                 }
//             }
//             return *this;
//         }
//         Array<T>& qsort() {
//             quicksort(0, n-1);
//             return *this;
//         }
//         void quicksort(int left, int right) {
//             int pivot = (left+right)/2;
//             int mid = a[pivot];
//             int i = left, j = right;
//             while (i <= j) {
//                 while (a[i] < mid) {
//                     i++;
//                 }
//                 while (a[j] > mid) {
//                     j--;
//                 }
//                 if (i <= j) {
//                     swap(a[i], a[j]);
//                     i++;
//                     j--;
//                 }
//             }
//             if (left < j) quicksort(left, j);
//             if (right > i) quicksort(i, right);
//         }
//         friend ostream& operator<<(ostream& os, Array<T>& a) {
//             for (int i = 0; i < a.n; i++) {
//                 os << a[i] << ' ';
//             }
//             return os;
//         }
// };

// void quicksort(int a[], int left, int right) {
//     int mid = a[(left+right)/2];
//     int i = left, j = right;
//     while (i <= j) {
//         while (a[i] < mid) i++;
//         while (a[j] > mid) j--;
//         if (i <= j) {
//             swap(a[i],a[j]);
//             i++;
//             j--;
//         }
//     }
//     if (left < j) quicksort(a, left, j);
//     if (i < right) quicksort(a, i, right);
// }


// int binarysearch(int a[], int x, int left, int right) {
//     if (right < left) return left;
//     int pivot = (left+right)/2;
//     if (x == a[pivot]) return pivot;
//     else {
//         if (x < a[pivot]) 
//             return binarysearch(a, x, left, pivot-1);
//         else
//             return binarysearch(a, x, pivot+1, right);
//     }
// }

// void binaryinsertionsort(int a[], int n) {
//     for (int i = 1; i < n; i++) {
//         int pos = binarysearch(a, a[i], 0, i-1);
//         for (int j = i; j > pos; j--)
//             swap(a[j], a[j-1]);
//     }
// }

// void insertionsort(int a[], int n) {
//     for (int i = 1; i < n; i++)
//         for (int j = i; j > 0; j--) {
//             if (a[j] < a[j-1])
//                 swap(a[j],a[j-1]);
//             else
//                 break;
//         }
// }



// void selectionsort(int a[], int n) {
//     for (int i = 0; i < n -1; i++) {
//         int min = a[i];
//         for (int j = i+1; j < n; j++) {
//             if (a[j] < a[min])
//                 min = j;
//         }
//         swap(a[i], a[min]);
//     }
// }

// void bubblesort_optimize(int a[], int n) {
//     for (int i = 0; i < n; i++) {
//         bool swapped = false;
//         for (int j = 0; j < n-i; j++) {
//             if (a[j] > a[j+1]) {
//                 swap(a[j], a[j+1]);
//                 swapped = true;
//             }
//         }
//         if (!swapped) break;
//     }
// }

// void bubblesort(int a[], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n-i; j++) {
//             if (a[j] > a[j+1])
//                 swap(a[j], a[j+1]);
//         }
//     }
// }

// void shellsort(int a[], int n) {
//     for (int gap = n/2; gap > 0; gap /= 2) {
//         for (int i = gap; i < n; i++) {
//             int temp = a[i];
//             int j = i;
//             for (; j >= gap && a[j-gap] > temp; j -= gap) {
//                 a[j] = a[j-gap];
//             }
//             a[j] = temp;
//         }
//     }
// }

// void merge(int a[], int left, int pivot, int right) {
//     int* b = new int[right-left+1];
//     int i = left, j = pivot+1, k = 0;
//     while (i <= pivot and j <= right) {
//         if (a[i] < a[j])
//             b[k++] = a[i++];
//         else
//             b[k++] = a[j++];
//     }
//     while (i <= pivot) b[k++] = a[i++];
//     while (j <= right) b[k++] = a[j++];
//     for (int i = left; i <= right; i++)
//         a[i] = b[i-left];
//     delete[] b;
// }

// void mergesort(int a[], int left, int right) {
//     if (left < right) {
//         int pivot = (left+right)/2;
//         mergesort(a, left, pivot);
//         mergesort(a, pivot+1, right);
//         merge(a, left, pivot, right);
//     }
// }



void heapify(int a[], int n, int self) {
    int largest = self;
    int left = 2*self+1;
    int right = 2*self+2;
    if (left < n and a[left] > a[largest]) largest = left;
    if (right < n and a[right] > a[largest]) largest = right;
    if (largest != self) {
        swap(a[largest], a[self]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n-1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
}

// // linked list

struct Node {
    int info;
    Node* next;
    Node(int info, Node* next = NULL) : info(info), next(next) {}
};

struct List {
    Node* head;
    Node* tail;
    int n = 0;
    List() : head(NULL), tail(NULL) {}

    void push_back(int info) {
        if (head == NULL) {
            head = tail = new Node(info);
        } else {
            tail->next = new Node(info);
            tail = tail->next;
        }
        n++;
    }
    void push_front(int info) {
        if (head == NULL) {
            head = tail = new Node(info);
        } else {
            head = new Node(info, head);
        }
        n++;
    }
    void pop_front() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
    }
    void pop_back() {
        if (head == NULL) return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            n--;
            return;
        }
        Node* p = head;
        while (p->next != tail) p = p->next;
        delete tail;
        tail = p;
        tail->next = NULL;
        n--;
    }
    Node* find(int info) {
        for (Node* p = head; p != NULL; p = p->next) {
            if (p->info == info) return p;
        }
        return NULL;
    }
    void insert_after(Node* p, int info) {
        if (p == NULL) return;
        if (p == tail) {
            push_back(info);
            return;
        }
        p->next = new Node(info, p->next);
        n++;
    }
    void insert_before(Node* p, int info) {
        if (p == NULL) return;
        if (p == head) {
            push_front(info);
            return;
        }
        Node* q = head;
        while (q->next != p) q = q->next;
        q->next = new Node(info, p);
        n++;
    }
    void remove(Node* p) {
        if (p == NULL) return;
        if (p == head) {
            pop_front();
            return;
        }
        Node* q = head;
        while (q->next != p) q = q->next;
        q->next = p->next;
        delete p;
        n--;
    }
    void remove(int info) {
        remove(find(info));
    }
    bool empty() {
        return head == NULL;
    }
    void clear() {
        while (!empty()) pop_front();
    }
    void print() {
        for (Node* p = head; p != NULL; p = p->next)
            cout << p->info << ' ';
        cout << endl;
    }
    int size() {
        return n;
    }
};

// binary search tree
struct Node {
    int info;
    Node* left;
    Node* right;
    Node(int info, Node* left = NULL, Node* right = NULL) : info(info), left(left), right(right) {}
};

typedef Node* Tree;

void insert(Tree& root, int info) {
    if (root) {
        if (info < root->info)
            insert(root->left, info);
        else
            insert(root->right, info);
    } else {
        root = new Node(info);
    }
}

void input(Tree& root) {
    int info;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> info;
        insert(root, info);
    }
}

void LNR(Tree root) {
    if (root) {
        LNR(root->left);
        cout << root->info << ' ';
        LNR(root->right);
    }
}

Node* search(Tree root, int info) {
    if (root == NULL) return NULL;
    if (root->info == info) return root;
    if (info < root->info) return search(root->left, info);
    return search(root->right, info);
}

int depth(Tree root) {
    if (root == NULL) return -1;
    return 1 + max(depth(root->left), depth(root->right));
}

int count(Tree root) {
    if (root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

int count_leaf(Tree root) {
    if (root == NULL) return 0;
    if (root->left == NULL and root->right == NULL) return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}

void rotate_left(Tree& root) {
    if (root == NULL) return;
    if (root->right == NULL) return;
    Node* p = root->right;
    root->right = p->left;
    p->left = root;
}

void rotate_right(Tree& root) {
    if (root == NULL) return;
    if (root->left == NULL) return;
    Node* p = root->left;
    root->left = p->right;
    p->right = root;
}

void remove(Tree& root, int info) {
    if (root == NULL) return;
    if (info < root->info)
        remove(root->left, info);
    else if (info > root->info)
        remove(root->right, info);
    else {
        Node* p = root;
        if (root->left == NULL) {
            root = root->right;
        } else if (root->right == NULL) {
            root = root->left;
        } else {
            // leftmost of right subtree
            Node* q = root->right;
            while (q->left) q = q->left;
            root->info = q->info;
            remove(root->right, q->info);
        }
        delete p;
    }
}

bool is_full_bst(Tree root) {
    if (root == NULL) return true;
    if (root->left == NULL xor root->right == NULL) return false;
    return is_full_bst(root->left) and is_full_bst(root->right);
}

bool is_complete_bst(Tree root) {
    if (root == NULL) return true;
    if (root->left == NULL and root->right == NULL) return true;
    if (root->left == NULL xor root->right == NULL) return false;
    return is_complete_bst(root->left) and is_complete_bst(root->right);
}

bool is_perfect_bst(Tree root, int d, int level = 0) {
    if (root == NULL) return true;
    if (root->left == NULL and root->right == NULL) return d == level + 1;
    if (root->left == NULL xor root->right == NULL) return false;
    return is_perfect_bst(root->left, d, level + 1) and is_perfect_bst(root->right, d, level + 1);
}

bool check_perfect_bst(Tree root) {
    return is_perfect_bst(root, depth(root));
}

void print_node_rank_k(Tree root, int k) {
    if (root == NULL) return;
    if (k == 0) {
        cout << root->info << ' ';
        return;
    }
    print_node_rank_k(root->left, k - 1);
    print_node_rank_k(root->right, k - 1);
}

bool is_banlance_bst(Tree root) {
    if (root == NULL) return true;
    if (abs(depth(root->left) - depth(root->right)) > 1) return false;
    return is_banlance_bst(root->left) and is_banlance_bst(root->right);
}

Node* unbalanced_node(Tree root) {
    if (root == NULL) return NULL;
    if (abs(depth(root->left) - depth(root->right)) > 1) return root;
    Node* p = unbalanced_node(root->left);
    if (p) return p;
    return unbalanced_node(root->right);
}

struct unordered_map {
    static const int N = 100000;
    int n;
    int a[N];
    unordered_map() {
        n = 0;
        for (int i = 0; i < N; i++) a[i] = -1;
    }
    void insert(int info) {
        a[info % N] = info;
    }
    bool find(int info) {
        return a[info % N] == info;
    }
    void remove(int info) {
        a[info % N] = -1;
    }
};

int main() {

    return 0;
}



