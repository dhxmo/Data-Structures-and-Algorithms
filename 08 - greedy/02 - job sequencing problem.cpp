/* Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. */

#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    int id, deadline, profit;
};

bool comparator(Job a, Job b)
{
    return (a.profit > b.profit);
}

/* 
    Time Complexity: O(N^2)
    Space Complexity: O(N) 
*/

pair<int, int> jobScheduling(Job jobs[], int n)
{
    // sort the jobs in decreasing order of profits
    sort(jobs, jobs + n, comparator);

    int result[n];

    // find max deadline and populate empty slots
    int maxDeadline = jobs[0].deadline;
    for (int i = 1; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    int slots[maxDeadline + 1];
    for (int i = 0; i < maxDeadline; i++)
        slots[i] = false;

    int jobCount = 0, jobProfit = 0;

    // look through the sorted list of jobs
    for (int i = 0; i < n; i++)
    {
        // start at the job's deadline
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            //whenever there's an empty slot
            if (slots[j] == false)
            {
                // update job to that slot
                slots[j] = true;
                result[j] = i;
                //update count and profit
                jobCount++;
                jobProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the result
    cout << "Sequence of the jobs to be performed (Job id #): ";
    for (int i = 0; i < n; i++)
    {
        if (slots[i])
            cout << jobs[result[i]].id << " ";
    }

    cout << endl;

    return make_pair(jobCount, jobProfit);
}

int main()
{
    Job jobs[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    pair<int, int> result = jobScheduling(jobs, n);

    cout << "Total profits that can be generated = " << result.second << endl;

    return 0;
}