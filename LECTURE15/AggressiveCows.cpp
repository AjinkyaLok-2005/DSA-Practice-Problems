#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>stalls, int n, int c, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i =0; i < stalls.size(); i++)
    {
        if(stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if(cowCount == c)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int s, int e, int n, int c, int ans)
{
    //base case
    if(s > e)
    {
        return ans;
    }

    int mid = s + (e-s)/2;

    //recursive call
    if(isPossible(stalls, n, c, mid))
    {
        ans = mid;
        return aggressiveCows(stalls, mid+1, e, n, c, ans);
    }
    else
    {
        return aggressiveCows(stalls, s, mid-1, n, c, ans);
    }
}

int ans(vector<int> stalls, int n, int c)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for(int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;

    int result = aggressiveCows(stalls, s, e, n, c, ans);

    return result;
}

int main()
{
    vector<int> stalls = {4, 2, 1, 3, 6};
    int n = stalls.size();
    int c = 2;

    int result = ans(stalls, n, c);

    cout << "The lalrgest minumum distance between the cows is " << result << endl;     

    return 0;
}