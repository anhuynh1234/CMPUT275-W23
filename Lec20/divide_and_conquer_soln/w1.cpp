// Divide-and-conquer worksheet
// Solution to problem #1
// Omid Ardakanian, 2022

#include <iostream>
#include <vector>

using namespace std;

// a greedy algorithm that finds the number of signposts 
// of size L that you can get by cutting the rods
int get_num_signposts(vector<int> & rods, int L) {
	int num = 0;
	for (int i=0;i<rods.size();++i) {
		num += rods[i]/L; // using integer division
	}
	return num;
}

// binary search method O(log2(high-low) * N)
int find_max_length(int low, int high, int q, vector<int> & rods) {
	while (low < high) {
		int mid = (high + low + 1)/2; // integer division

		// given a target length mid, find out how many rods
		// of length mid can be created using a greedy algorithm in O(N)
		if (get_num_signposts(rods, mid) >= q) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

int main() {
	int N, M, max_len = 0;
	cin >> N >> M;

	vector<int> rods(N);

	for (int i=0;i<N;++i) {
		cin >> rods[i];
		if (rods[i] > max_len)
			max_len = rods[i];
	}

	// binary search on the range of values L can take
	cout << find_max_length(0, max_len + 1, M, rods) << endl;
		
	return 0;
}