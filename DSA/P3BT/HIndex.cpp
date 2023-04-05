/*
Chương trình dưới đây thực hiện công việc sau:
1. nhập số n
2. nhập mảng a chứa n số nguyên
3. sắp xếp mảng a theo thứ tự giảm dần
4. chạy i từ 0 đến n-1, nếu a[i] < i+1 thì in ra i và dừng chương trình
*/

#include <iostream>
using namespace std;

int calculateHIndex(int *citation, int n);

void Sort(int *c, int left, int right) {
    int i = left, j = right;
    int pivot = c[(left + right) / 2];
    while (i <= j) {
        while (c[i] > pivot) i++;
        while (c[j] < pivot) j--;
        if (i <= j) {
            swap(c[i], c[j]);
            i++;
            j--;
        }
    }
    if (left < j) Sort(c, left, j);
    if (i < right) Sort(c, i, right);
}

int calculateHIndex(int *citation, int n)
{
    Sort(citation, 0, n - 1);
    int i;
    int hIndex = 0;
    for (i = 0; i < n; i++)
    {
        if (citation[i] >= i + 1)
            hIndex = i + 1;
        else
            break;
    }
    return hIndex;
}

int main()
{
	int* citation;
	int n;
	int i;
	cin >> n;
	//cout << n << endl;
	citation = new int[n];

	for (i = 0; i < n; i++)
		cin >> citation[i];

	cout << calculateHIndex(citation, n);
	return 0;


}