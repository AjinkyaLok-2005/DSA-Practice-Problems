//TOTAL NUMBER OF OCCURENCES OF AN ELEMENT IN A SORTED ARRAY 

#include<iostream>
using namespace std;

int firstOcc(int * arr, int s, int e, int key)
{
    int ans = -1;

    //base case
    if(s > e)
    {
        return -1;
    }

    int mid = s + (e-s)/2;
    // cout << mid << endl;

    if(arr[mid] == key)
    {
        ans = mid;
        // e = mid - 1;
        // return firstOcc(arr, s, mid - 1, key); 
        int leftResult = firstOcc(arr, s, mid - 1, key); // Check the left half for earlier occurrences
        if (leftResult != -1) 
        {
            return leftResult;
        } 
        return ans;
    }

    if(arr[mid] < key)
    {
        return firstOcc(arr, mid+1, e, key);
    }
    else
    {
        return firstOcc(arr, s, mid-1, key);
    }

    return ans;
}

int lastOcc(int * arr, int s, int e, int key)
{
    int ans = -1;

    //base case
    if(s > e)
    {
        return -1;
    }

    int mid = s + (e-s)/2;

    if(arr[mid] == key)
    {
        ans = mid;
        int rightResult = lastOcc(arr, mid+1, e, key);
        if(rightResult != -1)
        {
            return rightResult;
        }
        return ans;
    }

    if(arr[mid] < key)
    {
        return lastOcc(arr, mid+1, e, key);
    }
    else
    {
        return lastOcc(arr, s, mid-1, key);
    }

    return ans;
}

int main()
{
    int arr[11] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5};

    int first_index = firstOcc(arr, 0, 10, 3);
    int last_index = lastOcc(arr, 0, 10, 3);

    int total_occ = (last_index - first_index)+1;
    cout << "Total number of occ: " << total_occ << endl;

    return 0;
}