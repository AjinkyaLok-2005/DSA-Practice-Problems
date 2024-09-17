#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int arr[], int size)
{
    for(int i = 0; i < size; i+2)
    {
        if(i+1 < size)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main()
{
    int even[8] = {87, 454, 23, 32, 5, 8, 2, 0};
    int odd[5] = {9, 5, 1, 4, 54};

    swapAlternate(even, 8);
    printArray(even, 8);

    cout << endl;

    swapAlternate(odd, 5);
    printArray(odd, 5);

    cout << endl;
    
    return 0;
}