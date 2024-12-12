#include<iostream>
using namespace std;

int findMinIndex(int * arr, int start, int n)
{
    int minIndex = start;
    for(int i = start+1; i < n; i++)
    {
        if(arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSort(int * arr, int n, int start = 0)
{
    //base case
    if(start >= n-1)
    {
        return;
    }

    int minIndex = findMinIndex(arr, start, n);

    if(minIndex != start)
    {
        swap(arr[start], arr[minIndex]);
    }

    //recursive call
    selectionSort(arr, n, start+1);
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}