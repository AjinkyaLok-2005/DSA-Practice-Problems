#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx, int newy, vector < vector < bool >> & vis, vector < vector < int >> & arr, int n)
{
    if((newx >= 0 && newx <n) && (newy >=0 && newy < n) && 
    vis[newx][newy] != 1 && arr[newx][newy] ==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector < vector < int >> & arr, int n, vector<string> &ans, 
    vector < vector < bool >> & vis, string path)
{
    //base case
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }

    //4movements
    //D=south, L=west, R=east, U=north

    vis[x][y] = 1;
    //Down
    if(isSafe(x+1, y, vis, arr, n))
    {
        solve(x+1, y, arr, n, ans, vis, path + 'D');
    }

    //Left
    if(isSafe(x, y-1, vis, arr, n))
    {
        solve(x, y-1, arr, n, ans, vis, path + 'L');
    }

    //Right
    if(isSafe(x, y+1, vis, arr, n))
    {
        solve(x, y+1, arr, n, ans, vis, path + 'R');
    }

    //Up
    if(isSafe(x-1, y, vis, arr, n))
    {
        solve(x-1, y, arr, n, ans, vis, path + 'U');
    }

    vis[x][y] = 0;
}

vector<string>searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> visited (n, vector<bool> (n, 0));

    string path = "";

    if(arr[0][0] == 0)
    {
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main() {
    int n;
    cin >> n;  // size of maze

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];   // maze input (0 = blocked, 1 = open)
        }
    }

    vector<string> result = searchMaze(arr, n);

    if (result.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << "Paths found: " << result.size() << endl;
        for (string &path : result) {
            cout << path << endl;
        }
    }

    return 0;
}