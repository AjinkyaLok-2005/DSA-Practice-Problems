#include<iostream>
using namespace std;

void Sum(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout << "Sum of all the elements in the array is " << sum <<endl;
}


int main()
{
    int arr[5] = {2, 7, 1, -4, 11};

    Sum(arr, 5);

    return 0;
}