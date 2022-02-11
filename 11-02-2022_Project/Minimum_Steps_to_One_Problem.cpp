/*


*/

//#define FORREF
#ifndef FORREF

using namespace std;
#include<iostream>


struct Count {

	int minStep(int n) {
		if (n == 1) {
			// this is your base condition
			return 0;
		}

		int step_one_cnt = INT_MAX, step_two_cnt = INT_MAX, step_three_cnt = INT_MAX;
	
		step_one_cnt = 1 + minStep(n - 1);
		
		if (n % 2 == 0) {
			step_two_cnt = 1 + minStep(n / 2);
		}

		if (n % 3 == 0) {
			step_three_cnt = 1 + minStep(n / 3);
		}
		
		return min(step_one_cnt, min(step_two_cnt, step_three_cnt));
	}
};






int main() {

	int n = 10;
	Count ct;
	cout << ct.minStep(n);

}


#endif // FORR