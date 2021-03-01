#include <bits/stdc++.h>

using namespace std;

long long max(long long a, long long b) {
	return (a > b ? a : b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, k;
		cin >> n >> k;
		vector<long long> q(n);
		for (int i = 0; i < n; i++) {
			cin >> q[i];
		}
		// create a 'prev' variable to store the excess queries and add it to the current 'q[i]'
		// initialize it to 0 since there are no excess for the 1st day
		long long prev = 0;
		for (int i = 0; i < n; i++) {
			// add the 'prev' variable (which is the excess queries) to the current query of the day
			q[i] += prev;
			// update the 'prev' variable by storing the excess again
			prev = max(0, q[i] - k);
			// if the current query is greater than 'k', then set it to 'k' as its maximum
			if (q[i] > k) {
				q[i] = k;
			}
		}
		// create a 'checker' variable to check if the day where Chef does not fulfill
		// the maximum query, 'k', is not in the array itself
		bool checker = false;
		long long index = 0;
		for (int i = 0; i < n; i++) {
			// check the i-th day where Chef did not fulfill the maximum query, 'k'
			if (q[i] < k) {
				// store the day number in the 'index' variable
				index = i + 1;
				// set 'checker' variable to true
				checker = true;
				break;
			}
		}
		if (!checker) {
			// if the 'checker' variable is still equal to false, then the day that Chef
			// did not fulfill the maximum query, 'k', then it must be calculated separately
			// start from the day after that last day in the array
			index = n + 1;
			// divide the remaning queries which is in the 'prev' variable by 'k' 
			// before adding it to the 'index' variable in order to calculate what day
			// Chef will not be able to fulfill the maximum query, 'k'
			index += (prev / k);
		}
		cout << index << '\n';
	}
	return 0;
}
