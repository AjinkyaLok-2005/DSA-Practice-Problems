#include<iostream>
using namespace std;

int UniquElement(int arr[], int size)
{
    int uniqarr[100];
    bool isunique = true;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] == arr[i])
            {
                isunique = false;
            }
        }

        if(isunique == true)
        {
            uniqarr[100] = arr[i];
        }
        else
        {
            break;
        }

        
    }

    return uniqarr[100];

}

int main()
{
    int array[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    int size = sizeof(array)/sizeof(array[0]);

    cout << "Array of unique elements is " << UniquElement(array, size) << endl;

    return 0;
}
