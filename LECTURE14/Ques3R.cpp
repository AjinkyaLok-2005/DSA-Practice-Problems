//USING RECURSION

#include<iostream>
using namespace std;

long long int binarySearch(int s, int e, int n, long long int ans)
{
    //base case
    if(s > e)
    {
        return ans;
    }

    long long int mid = s + (e-s)/2;
    long long int square = mid * mid;

    if(square == n)
    {
        return mid;
    } 

    if(square < n)
    {
        return binarySearch(mid+1, e, n, mid);
    }
    else
    {
        return binarySearch(s, mid-1, n, ans);
    }
}

int mySqrt(int x)
{
    return binarySearch(0, x, x, 0);
}

int main()
{
    int x;
    cout << "Enter a number :- ";
    cin >> x;

    int result = mySqrt(x);
    cout << "Square root is " << result;
    return 0;
}