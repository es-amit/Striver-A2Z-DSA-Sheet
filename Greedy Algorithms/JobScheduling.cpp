#include <bits/stdc++.h>
using namespace std;

struct Job{
    public:
        int id;
        int profit;
        int dead;
};
static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);
    int maxTime = 0;

    for (int i = 0; i < n; i++)
    {
        maxTime = max(maxTime, arr[i].dead);
    }

    vector<int> jobDone(maxTime + 1, -1);

    int jobs = 0;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        int currId = arr[i].id;
        int currDead = arr[i].dead;
        int currProfit = arr[i].profit;

        for (int j = currDead; j >= 1; j--)
        {
            if (jobDone[j] == -1)
            {
                jobDone[j] = currId;
                jobs++;
                profit = profit + currProfit;
                break;
            }
        }
    }
    return {jobs, profit};
}