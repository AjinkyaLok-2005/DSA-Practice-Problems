#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using VB    = vector<bool>;
    using VVB   = vector<VB>;
    using VVVB  = vector<VVB>;
    using VVVVB = vector<VVVB>;

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    vector<vector<int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].length();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;

        int startR = 0;
        int startC = 0;

        // Find starting position and assign a bit to every litter cell
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                litterBit[r][c] = -1;

                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                }
                else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        // If there is no litter, nothing needs to be done
        if (litterCount == 0)
            return 0;

        // Mask where all litter bits are 1
        int allCollected = (1 << litterCount) - 1;

        // visited[row][col][energy][mask]
        VVVVB visited(
            m,
            VVVB(
                n,
                VVB(
                    maxEnergy + 1,
                    VB(1 << litterCount, false)
                )
            )
        );

        queue<State> que;

        que.push({
            startR,
            startC,
            maxEnergy,
            0
        });

        visited[startR][startC][maxEnergy][0] = true;

        int moves = 0;

        while (!que.empty()) {

            int size = que.size();

            while (size--) {

                State curr = que.front();
                que.pop();

                // Have we collected all litter?
                if (curr.collectedMask == allCollected) {
                    return moves;
                }

                // No energy left, so we cannot make another move
                if (curr.energyLeft == 0) {
                    continue;
                }

                // Try all four directions
                for (auto& dir : directions) {

                    int nextRow = curr.row + dir[0];
                    int nextCol = curr.col + dir[1];

                    // Outside the grid
                    if (nextRow < 0 || nextRow >= m ||
                        nextCol < 0 || nextCol >= n) {
                        continue;
                    }

                    // Wall
                    char cell = classroom[nextRow][nextCol];

                    if (cell == 'X')
                        continue;

                    int nextEnergy = curr.energyLeft - 1;
                    int nextCollectedMask = curr.collectedMask;

                    // Recharge cell
                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    }

                    // Litter cell
                    else if (cell == 'L') {
                        nextCollectedMask |=
                            (1 << litterBit[nextRow][nextCol]);
                    }

                    // If this state has not been visited
                    if (!visited[nextRow][nextCol]
                                  [nextEnergy]
                                  [nextCollectedMask]) {

                        visited[nextRow][nextCol]
                               [nextEnergy]
                               [nextCollectedMask] = true;

                        que.push({
                            nextRow,
                            nextCol,
                            nextEnergy,
                            nextCollectedMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};


int main() {

    Solution solution;

    // Example 1
    vector<string> classroom1 = {
        "S.L",
        ".X.",
        "..R"
    };

    int energy1 = 4;

    cout << "Example 1: "
         << solution.minMoves(classroom1, energy1)
         << endl;


    // Example 2
    vector<string> classroom2 = {
        "S.L",
        "..."
    };

    int energy2 = 3;

    cout << "Example 2: "
         << solution.minMoves(classroom2, energy2)
         << endl;


    // Example 3
    vector<string> classroom3 = {
        "S",
    };

    int energy3 = 5;

    cout << "Example 3: "
         << solution.minMoves(classroom3, energy3)
         << endl;


    return 0;
}