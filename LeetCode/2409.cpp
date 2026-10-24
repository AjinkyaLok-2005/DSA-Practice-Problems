#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDayOfYear(string date, vector<int>& cumMonthDays)
    {
        int month = stoi(date.substr(0, 2));
        int days = stoi(date.substr(3));

        return cumMonthDays[month - 1] + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob)
    {
        vector<int> monthDays = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        vector<int> cumMonthDays(13, 0);

        cumMonthDays[1] = 31;

        for (int i = 2; i <= 12; i++)
        {
            cumMonthDays[i] = cumMonthDays[i - 1] + monthDays[i - 1];
        }

        int arriveAliceDay = findDayOfYear(arriveAlice, cumMonthDays);
        int leaveAliceDay  = findDayOfYear(leaveAlice, cumMonthDays);
        int arriveBobDay   = findDayOfYear(arriveBob, cumMonthDays);
        int leaveBobDay    = findDayOfYear(leaveBob, cumMonthDays);

        int overlapDays = min(leaveAliceDay, leaveBobDay)
                        - max(arriveAliceDay, arriveBobDay) + 1;

        return overlapDays < 0 ? 0 : overlapDays;
    }
};

int main()
{
    Solution sol;

    string arriveAlice = "08-15";
    string leaveAlice = "08-18";
    string arriveBob = "08-16";
    string leaveBob = "08-19";

    int result = sol.countDaysTogether(
        arriveAlice, leaveAlice, arriveBob, leaveBob
    );

    cout << "Days together: " << result << endl;

    return 0;
}