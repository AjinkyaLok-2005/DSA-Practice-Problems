#include<iostream>
using namespace std;

int getPivot(int * arr, int s, int e)
{
    //base case
    if(s == e)
    {
        return s;
    }

    int mid = s + (e-s)/2;

    //recursive call;
    if(arr[mid] >= arr[0])
    {
        return getPivot(arr, mid+1, e);
    }
    else
    {
        return getPivot(arr, s, mid);
    }

    // return s;
}

int binarySearch(int *arr, int s, int e, int k)
{
    //base case
    //element not found
    if(s>e)
    {
        return -1;
    }

    int mid = s + (e-s)/2;
    
    //base case
    //element found
    if(arr[mid] == k)
    {
        return mid;
    }

    if(arr[mid] < k)
    {
        return binarySearch(arr, mid+1, e, k);
    }
    else
    {
        return binarySearch(arr, s, mid-1, k);
    }
}

int findPosition(int * arr, int n, int k)
{
    int s = 0;
    int e = n-1;

    int pivot = getPivot(arr, s, e);
    if(arr[pivot] <= k && k <= arr[n-1])
    {
        //BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else
    {
        //BS on first line
        return binarySearch(arr, 0, pivot-1, k);
    }
}

int main()
{
    int arr[] = {3, 8, 10, 17, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k;

    cout << "Enter the Key to search in the array:- ";
    cin >> k;

    cout << "Index is " << findPosition(arr, n, k) << endl;

    return 0;
}