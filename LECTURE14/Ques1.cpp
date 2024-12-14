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

int main()
{
    int arr[5] = {8, 10, 17, 1, 3};

    cout << "Pivot is " << getPivot(arr, 0, 4) << endl;

    return 0;
}