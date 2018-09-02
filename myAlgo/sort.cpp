// sort algorithms practice 
// 1\Merge Sort  2\Quick Sort
// Author - Scott Ray
// Time - 2018/2/25

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	void sort(vector<int> &ivec) {
		if (ivec.size() <= 1) return;
		//mergeSort(ivec, 0, ivec.size() - 1);
		quickSort(ivec, 0, ivec.size() - 1);
		return;
	}
private:
	void quickSort(vector<int> &ivec, int lo, int hi) {
		if (hi - lo <= 0) return;
		if (hi - lo == 1)
			if (ivec[lo] > ivec[hi]) {
				swap(ivec, lo, hi);
				return;
			}
			else return;
		int base = lo, i = lo, j = hi;
		int baseVal = ivec[lo];
		while (i < j) {
			while (ivec[j] >= baseVal && i < j) j--;
			if (i == j) break;
			swap(ivec, base, j);
			base = j;
			baseVal = ivec[base];
			while (ivec[i] <= baseVal && i < j) i++;
			if (i == j) break;
			swap(ivec, base, i);
			base = i;
			baseVal = ivec[base];
		}
		ivec[i] = baseVal;
		base = i;
		quickSort(ivec, lo, base - 1);
		quickSort(ivec, base + 1, hi);
		return;
	}

	void mergeSort(vector<int> &ivec, size_t lo, size_t hi) {
		if (hi - lo <= 0) return;
		if (hi - lo == 1)
			if (ivec[lo] > ivec[hi]) {
				swap(ivec, lo, hi);
				return;
			}
			else return;
		size_t mid = lo + (hi - lo) / 2;
		mergeSort(ivec, lo, mid);
		mergeSort(ivec, mid + 1, hi);
		vector<int> extraVec(hi - lo + 1, 0);
		for (size_t cur = 0, curLo = lo, curMid = mid + 1; cur < extraVec.size();) {
			// step_1
			if (curLo == mid + 1) {
				while (cur < extraVec.size()) {
					extraVec[cur++] = ivec[curMid++];
				}
				continue;
			}
			else if (curMid == hi + 1) {
				while (cur < extraVec.size()) {
					extraVec[cur++] = ivec[curLo++];
				}
				continue;
			}
			// step_2
			if (ivec[curLo] < ivec[curMid]) {
				extraVec[cur++] = ivec[curLo++];
				continue;
			}
			else {
				extraVec[cur++] = ivec[curMid++];
				continue;
			}
		}
		// step_3
		for (size_t cur = 0, curLo = lo; cur < extraVec.size();) {
			ivec[curLo++] = extraVec[cur++];
		}
		return;
	}
	void swap(vector<int> &ivec, size_t loc1, size_t loc2) {
		int tp = ivec[loc1];
		ivec[loc1] = ivec[loc2];
		ivec[loc2] = tp;
		return;
	}
	
};

int main()
{
	vector<int> ivec = { 6, 2, 3, 5 ,7 ,9, 11, 2 };//{ 3, 7, 3, 4, 4 ,2 };
	Solution s;
	s.sort(ivec);

	for (auto it = ivec.begin(); it != ivec.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;

    return 0;
}

