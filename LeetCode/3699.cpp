#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int N;
    int M;

    typedef long long ll;
    int MOD = 1e9 + 7;

    //Memoization
    int solve(int i, int prevVal, bool increasing, vector<vector<vector<int>>>& dp)
    {
        //base case
        if(i == N)
        {
            return 1;
        }

        int result = 0;

        if(dp[i][prevVal][increasing] != -1)
        {
            return dp[i][prevVal][increasing];
        }

        if(increasing)
        {
            for(int nextVal = prevVal+1; nextVal <= M; nextVal++)
            {
                result = (result + solve(i+1, nextVal, false, dp)) % MOD;
            }
        }
        else
        {
            for(int nextVal = 1; nextVal < prevVal; nextVal++)
            {
                result = (result + solve(i+1, nextVal, true, dp)) % MOD;
            }
        }

        return dp[i][prevVal][increasing] = result;
    }

    //Tabulation
    vector<vector<vector<ll>>> solveTab(int N, int M)
    {
        //base case
        vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(M+1, vector<ll>(2, 0)));

        for(int prevVal = 1; prevVal <= M; prevVal++)
        {
            dp[N][prevVal][0] = 1;
            dp[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 1; i--)
        {
            for(int prevVal = 1; prevVal <= M; prevVal++)
            {
                for(int d = 0; d <= 1; d++)
                {

                    int result = 0;

                    if(d == 1)
                    {
                        for(int nextVal = prevVal+1; nextVal <= M; nextVal++)
                        {
                            result = (result + dp[i+1][nextVal][0]) % MOD;
                        }
                    }
                    else
                    {
                        for(int nextVal = 1; nextVal < prevVal; nextVal++)
                        {
                            result = (result + dp[i+1][nextVal][1]) % MOD;
                        }
                    }

                    dp[i][prevVal][d] = result;
                }
            }
        }

        return dp;
    }

    //TAbulation + Prefix Sum
    vector<vector<int>> solveTabOpt(int N, int M)
    {
        vector<vector<int>> curr(M+1, vector<int>(2, 0));
        vector<vector<int>> next(M+1, vector<int>(2, 0));

        // base case
        for(int prevVal = 1; prevVal <= M; prevVal++)
        {
            next[prevVal][0] = 1;
            next[prevVal][1] = 1;
        }

        // fill bottom up with prefix sum
        for(int i = N-1; i >= 1; i--)
        {
            vector<int> prefDir0(M+1, 0);  
            vector<int> prefDir1(M+1, 0);  

            for(int v = 1; v <= M; v++)
            {
                prefDir0[v] = (prefDir0[v-1] + next[v][0]) % MOD;
                prefDir1[v] = (prefDir1[v-1] + next[v][1]) % MOD;
            }

            for(int prevVal = 1; prevVal <= M; prevVal++)
            {
                
                curr[prevVal][1] = (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;

                curr[prevVal][0] = prefDir1[prevVal-1];
            }

            next = curr;
        }

        return next;
    }  
    
    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r - l + 1;

        // ll result = 0;

        // vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(2, -1)));

        // for(int startVal = 1; startVal <= M; startVal++)
        // {
        //     //increasing
        //     result = (result + solve(1, startVal, true, dp)) % MOD;

        //     //decreasing 
        //     result = (result + solve(1, startVal, false, dp)) % MOD;
        // }

        
        
        
        // vector<vector<vector<int>>> dp = solveTab(N, M);

        // ll result = 0;
        // for(int startVal = 0; startVal <= M; startVal++)
        // {
        //     //increasing
        //     result = (result + dp[1][startVal][1]) % MOD;
        //     result = (result + dp[1][startVal][0]) % MOD;
        // }



        // vector<vector<vector<int>>> dp = solveTabOpt(N, M);
        auto dp = solveTabOpt(N, M);

        ll result = 0;
        for(int startVal = 1; startVal <= M; startVal++)
        {
            result = (result + dp[startVal][0]) % MOD;
            result = (result + dp[startVal][1]) % MOD;
        }

        return result;
    }
};