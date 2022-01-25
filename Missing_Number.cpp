/*
	Find the Missing Number (easy)

	Problem Statement
	We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. 
	Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.
	
	Example 1:
	Input: [4, 0, 3, 1]
	Output: 2
	
	Example 2:
	Input: [8, 3, 5, 2, 4, 6, 0, 1]
	Output: 7

	I am going to write two approach here for this problem.
	Approach 01 : findMissingNumber_1
	Approach 02 : findMissingNumber_2
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

class MissingNumber {
public:
	static int findMissingNumber_1(vector<int>& nums) {
		int sum = 0;
		int si = nums.size();
		for (int i = 0; i < si; ++i) {
			sum += nums[i];
		}

		int answer = ((si * (si + 1)) / 2) - sum;
		return answer;
	}

	static void swap(vector<int>& nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	static int findMissingNumber_2(vector<int>& nums) {
		nums.push_back(-1);

		int i = 0;
		while (i < nums.size())
		{
			if (nums[i] == -1 || nums[i] == i)
			{
				++i;
			}
			else
				swap(nums, i, nums[i]);
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (i != nums[i]) {
				return i;
			}
		}

		return -1;
	}
};

int main(int argc, char* argv[]) {
	vector<int> v1 = { 4, 0, 3, 1 };
	cout << MissingNumber::findMissingNumber_2(v1) << endl;
	v1 = { 8, 3, 5, 2, 4, 6, 0, 1 };
	cout << MissingNumber::findMissingNumber_2(v1) << endl;
}
#endif // FORREF
