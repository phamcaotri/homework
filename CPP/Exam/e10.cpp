#include <iostream>
using namespace std;

void inputMatrix(int a[][100], int &n)
{
    cin >> n;
    for (int hang = 0; hang < n; hang ++)
        for (int cot = 0; cot < n; cot ++)
        {
            cin >> a[hang][cot];
        }
}

void outputMatrix(int a[][100], int n)
{
    for (int hang = 0; hang < n; hang ++)
    {
        for (int cot = 0; cot < n; cot ++)
        {
            cout << a[hang][cot] << " ";
        }
        cout << '\n';
    }
}

void maxElementOfEachRow(int a[][100],int n)
{
    int indexr = 0, indexc = 0, maxV = 0;
    int hang = 0, cot = 0;
    for (hang = 0; hang < n; hang ++)
    {
        maxV = a[hang][0];
        indexr = hang;
        indexc = 0;
        for (cot = 1; cot < n; cot ++)
        {
            if (maxV < a[hang][cot])
            {
                maxV = a[hang][cot];
                indexr = hang;
                indexc = cot;
            }
        }
        cout<<"a["<<indexr<<"]["<<indexc<<"]="<<maxV<<endl;
    }
}


    
int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

    cout<<"Maximum element of each row in the matrix: "<<endl;
    maxElementOfEachRow(a,n); // Tim phan tu lon nhat cua moi dong, xuat vi tri cua phan tu do va gia tri lon nhat.VD: a[0][1]=12

    return 0;
}



