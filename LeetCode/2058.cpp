#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ---------- Approach 1: TC - O(n), O(1) extra space, single pass ----------
class SolutionOnePass {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;
        int prevCP = 0;
        int firstCP = 0;

        int minDist = INT_MAX;

        while (curr->next != NULL) {
            if (((curr->val > prev->val) && (curr->val > curr->next->val)) ||
                ((curr->val < prev->val) && (curr->val < curr->next->val))) {
                if (prevCP == 0) {
                    prevCP = i;
                    firstCP = i;
                } else {
                    minDist = min(minDist, i - prevCP);
                    prevCP = i;
                }
            }

            i++;
            prev = curr;
            curr = curr->next;
        }

        if (minDist == INT_MAX) {
            return {-1, -1};
        } else {
            return {minDist, prevCP - firstCP};
        }
    }
};

// ---------- Approach 2: TC - O(n), O(n) extra space, two pass ----------
class SolutionTwoPass {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;

        ListNode* temp = head;
        while (temp != NULL) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> idx;
        for (int i = 1; i < (int)nums.size() - 1; i++) {
            if (((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1])) ||
                ((nums[i] < nums[i - 1]) && (nums[i] < nums[i + 1]))) {
                idx.push_back(i);
            }
        }

        int n = idx.size();
        if (n < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;
        int maxDist = idx[n - 1] - idx[0];

        for (int i = 1; i < n; i++) {
            minDist = min(minDist, idx[i] - idx[i - 1]);
        }

        return {minDist, maxDist};
    }
};

// ---------- Helpers ----------
ListNode* buildList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void printResult(const string& label, const vector<int>& res) {
    cout << label << ": [" << res[0] << ", " << res[1] << "]" << endl;
}

// ---------- main ----------
int main() {
    vector<vector<int>> testCases = {
        {3, 1},
        {5, 3, 1, 2, 5, 1, 2},
        {1, 3, 2, 2, 3, 2, 2, 2, 7}
    };

    SolutionOnePass sol1;
    SolutionTwoPass sol2;

    for (int t = 0; t < (int)testCases.size(); t++) {
        ListNode* head1 = buildList(testCases[t]);
        ListNode* head2 = buildList(testCases[t]);

        cout << "Test case " << t + 1 << ": [";
        for (int v : testCases[t]) cout << v << " ";
        cout << "]" << endl;

        auto res1 = sol1.nodesBetweenCriticalPoints(head1);
        printResult("  OnePass ", res1);

        auto res2 = sol2.nodesBetweenCriticalPoints(head2);
        printResult("  TwoPass ", res2);

        cout << endl;

        freeList(head1);
        freeList(head2);
    }

    return 0;
}