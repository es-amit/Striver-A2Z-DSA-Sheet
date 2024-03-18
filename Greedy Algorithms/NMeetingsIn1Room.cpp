#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), cmp);
    int cnt = 1;
    int meetingEnd = meetings[0].second;
    for (int i = 0; i < n; i++)
    {
        if (meetings[i].first > meetingEnd)
        {
            cnt++;
            meetingEnd = meetings[i].second;
        }
    }
    return cnt;
}