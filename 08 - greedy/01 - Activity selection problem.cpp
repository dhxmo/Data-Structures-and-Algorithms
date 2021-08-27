/* There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) 
where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one 
meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting. */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// data structure to store meeting details
struct Meeting
{
    int start;
    int end;
    int position;
};

// Function to sort meeting times in ascending end time
bool comparisonOperator(struct Meeting m1, Meeting m2)
{
    return (m1.end < m2.end);
}

/* 
    1. Sort all pairs(Meetings) in increasing order of second 
        number(Finish time) of each pair.
    2. Select first meeting of sorted pair as the first Meeting 
        in the room and push it into result vector and set a variable 
        time_limet(say) with the second value(Finishing time) of the 
        first selected meeting.
    3. Iterate from the second pair to last pair of the array and if 
        the value of the first element(Starting time of meeting) of the 
        current pair is greater then previously selected pair finish time 
        (time_limit) then select the current pair and update the result 
        vector (push selected meeting number into vector) and variable 
        time_limit.
    4. Print the Order of meeting from vector.

    Time Complexity: O(NlogN)
    Space Complexity: O(N)
 */

void maxMeetings(int start[], int end[], int n)
{
    // declare a structure to hold meeting start and end times, and position
    struct Meeting meet[n];

    // populate the structure
    for (int i = 0; i < n; i++)
    {
        // start time of meeting
        meet[i].start = start[i];

        // end time of meeting
        meet[i].end = end[i];

        // position of meeting in the array
        meet[i].position = i + 1;
    }

    // sort the structure
    sort(meet, meet + n, comparisonOperator);

    // store the selected meetings
    vector<int> meetingsAllowed;
    // select the first meeting
    meetingsAllowed.push_back(meet[0].position);
    // declare how long the current longest meeting lasts
    int meeting_lasts_till = meet[0].end;

    for (int i = 1; i < n; i++)
    {
        // if the start time is past the last meeting
        if (meet[i].start >= meeting_lasts_till)
        {
            // hold that meeting
            meetingsAllowed.push_back(meet[i].position);

            // update how long this meeting will last
            meeting_lasts_till = meet[i].end;
        }
    }

    for (int i = 0; i < meetingsAllowed.size(); i++)
    {
        cout << meetingsAllowed[i] << " ";
    }
}

int main()
{
    // Starting time
    int start[] = {1, 3, 0, 5, 8, 5};

    // Finish time
    int finish[] = {2, 4, 6, 7, 9, 9};

    // Number of meetings.
    int n = sizeof(start) / sizeof(start[0]);

    maxMeetings(start, finish, n);
    cout << endl;

    return 0;
}