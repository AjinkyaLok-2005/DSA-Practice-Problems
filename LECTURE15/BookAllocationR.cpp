#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0; i < n; i++)
    {
        if(pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int s, int e, int n, int m, int ans)
{
    
    
    int mid = s + (e-s)/2;

    //base case
    if(s > e)
    {
        return ans;
    }

    if(isPossible(arr, n, m, mid))
    {
        ans = mid;
        return allocateBooks(arr, s, mid-1, n, m, ans);
    }
    else
    {
        return allocateBooks(arr, mid+1, e, n, m, ans);
    }
}


int ans(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;

    int result = allocateBooks(arr, s, e, n, m, ans);

    return result;
}

int main()
{
    vector<int> arr = {5, 17, 100, 11}; // Array of book pages
    int n = arr.size();                 // Number of books
    int m = 4;  

    int final_ans = ans(arr, n, m);

    cout << "The minimum number of pages a student has to read is: " << final_ans << endl;

    return 0;
}