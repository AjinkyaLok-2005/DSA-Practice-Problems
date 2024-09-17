#include<iostream>
using namespace std;

int findUniq(int arr[], int size)
{
    int ans = 0;

    for(int i = 0; i < size; i++)
    {
        ans = ans ^ (arr[i]);
    }
    return ans;
}

int main()
{
    int size;
    int array[100];
    cout << "Enter the size of the array " << endl;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    } 

    cout << "THe unique element in the array is " << findUniq(array, size) << endl ;

    return 0;
}