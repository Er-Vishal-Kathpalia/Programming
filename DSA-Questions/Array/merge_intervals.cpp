#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    int len = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for (int i = 0; i < len; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Skip if interval is already covered
        if (!ans.empty() && ans.back()[1] >= end) {
            continue;
        }

        for (int j = i + 1; j < len; j++) {
            if (end >= intervals[j][0]) {
                end = max(end, intervals[j][1]);  // fix: take max to merge correctly
            } else {
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}

int main() {
    int m;
    cin >> m;
    vector<vector<int>> intervals;

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, end});  // fix: corrected input logic
    }

    vector<vector<int>> ans = mergeIntervals(intervals);

    for (auto &interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
