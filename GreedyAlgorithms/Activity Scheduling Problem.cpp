/*
	Activity Scheduling Problem
	Problem Statement:
	You are given n activities with their start and finish times.
	Select the maximum number of activities that can be performed by a single person,
	assuming that a person can only work on a single activity at a time.

	So, in problem asked to maximize the number of activities?
	How to maximise?
	The first intuitive though might be that pick the smallest activity so that it finished early
	and you are free to take next activity quickly. If you repeat such step 
	than it might be possible that your activity count will be maximum. 
	And, by the way you are greedy in your selection process, because
	your intention is to meet the maximum and so you are opting your choice 
	for that moment only. No recurse, no backtrack etc...
	
	But are you sure, it will give you maximum value at all the time?

	Let us take the following example: Consider the following 3 activities sorted by finish time:
	start[] = {10, 12, 20}
	finish[] = {20, 25, 30}

	So, my greedy thought here is pick the activity which is finished early, am i right?
	Ok, so how you do, because your activity is not sorted in this format.

	It means that you have to first sort the activity according to their finsish time.

	After the sorting of task just check the next task and does it's starting point is >= to current activity finish time?
	If your answer is YES than pict the activity otherwise ignore activity and move ahead....

	So, let's see the Implementation of this code quickly...

*/

#define FORREF
#ifndef FORREF
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> I, pair<int, int> r) {
	return I.second < r.second;
}

int main()
{
	// You are assuming thst at least one activity will be picked in all sircumstances
	int res = 1;
	vector<pair<int, int> > activity = { {10,20},{12,25},{20,30} };

	// include algorithm for sorting
	sort(activity.begin(), activity.end(), cmp);

	int fin = activity[0].second;
	
	// you started from second element in your sorted vector
	for (int i = 1; i < activity.size(); i++)
	{
		// you just comparing that if the start time of this activity is greater and equal to
		// finish time of last activity? If Yes, pick the current activity and also increase the 
		// activity count otherwise just move ahead
		if (activity[i].first >= fin)
		{
			fin = activity[i].second;
			res++;
		}
	}
	// print the result here
	cout << res;
	return 0; // Exit the mail loop
}

#endif // FORREF
