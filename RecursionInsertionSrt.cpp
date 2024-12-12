#include<iostream>
using namespace std;

void insertionSort(int * arr, int n)
{
    //base case
    if(n <= 1)
    {
        return;
    }

    //recursive call
    insertionSort(arr, n-1);

    int temp = arr[n-1];
    int j = n-2;

    while(j >= 0 && arr[j] > temp)
    {
        arr[j+1] = arr[j];
        j--; 
    }
    arr[j+1] = temp;
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}