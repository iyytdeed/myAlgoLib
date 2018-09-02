// sort algorithms exercise 
// 1\Insert Sort  2\Select Sort  3\Pop Sort  4\Merge Sort  5\Quick Sort  6\Heap Sort
// Author - Scott Ray

#include "stdafx.h"
#include<iostream>
#include<vector>

#include<stdio.h>

using namespace std;

class Solution {
public:
	void sort(vector<int> &ivec) {
		if (ivec.size() <= 1) return;
		insertSort(ivec);
		//selectSort(ivec);
		//popSort(ivec);
		//mergeSort(ivec, 0, ivec.size() - 1);
		//quickSort(ivec, 0, ivec.size() - 1);
		//heapSort(ivec);
		return;
	}

	void printVec(vector<int> &ivec) {
		for (int i : ivec) cout << i << ",";
		cout << endl;
		return;
	}
private:
	// insert sort
	// ave   good   bad   space  
	// o(n2) o(n)   o(n2) o(1)   stable
	void insertSort(vector<int> &vec) {
		if (vec.size() <= 1) return;
		int n = vec.size();
		for (int i = 1; i < n; i++) {
			for (int j = i; j > 0; j--) {
				if (vec[j - 1] > vec[j]) swap(vec, j - 1, j);
				else break;
			}
		}
		return;
	}

	// select sort
	// ave   good   bad   space  
	// o(n2) o(n2)  o(n2) o(1)   unstable
	void selectSort(vector<int> &vec) {
		if (vec.size() <= 1) return;
		int n = vec.size();
		for (int floor = 0; floor < n - 1; floor++) {
			for (int j = floor; j < n; j++) {
				if (vec[j] < vec[floor]) {
					swap(vec, floor, j);
				}
			}
		}
		return;
	}

	// pop sort
	// ave   good   bad   space  
	// o(n2) o(n)   o(n2) o(1)   stable
	void popSort(vector<int> &vec) {
		if (vec.size() <= 1) return;
		int n = vec.size();
		for (int ceil = n; ceil > 0; ceil--) {
			for (int j = 1; j < ceil; j++) {
				if (vec[j - 1] > vec[j]) swap(vec, j - 1, j);
			}
		}
		return;
	}

	// heap sort
	// ave      good      bad      space  
	// o(nlogn) o(nlogn)  o(nlogn) o(1)   unstable
	void heapSort(vector<int> &ivec) {
		if (ivec.size() <= 1) return;
		// step_1 - construct max heap
		int len = ivec.size();
		toMaxheap(ivec, 1, len);
		//  step_2 - select sort loop
		for (int tail = len - 1; tail >= 1; tail--) {
			swap(ivec, tail, 0);
			toMaxheap(ivec, 1, tail);
		}
		return;
	}

	void toMaxheap(vector<int> &ivec, int i, int len) { // i-数组index+1(这样才方便寻址两个儿子), len-数组长度
		// bound
		if (i > len / 2) return;
		// step_0 init
		int lchild = 2 * i;
		int rchild = 2 * i + 1;
		int max = i;
		// step_1 保证两个儿子都正常了
		toMaxheap(ivec, lchild, len);
		toMaxheap(ivec, rchild, len);
		// 调整参数
		max -= 1;
		lchild -= 1;
		rchild -= 1;
		// 功能模块开始
		if (lchild < len && ivec[lchild] > ivec[max]) max = lchild;
		if (rchild < len && ivec[rchild] > ivec[max]) max = rchild;
		if (max != i - 1) swap(ivec, max, i - 1); // 注意 i - 1, 因为max是调整过后的值
		return;
	}
	// quick sort
	// ave      good      bad      space  
	// o(nlogn) o(nlogn)  o(n2)    o(logn)~o(n)   unstable
	void quickSort(vector<int> &ivec, int lo, int hi) {
		if (lo >= hi) return;
		printVec(ivec);
		int i = partition(ivec, lo, hi);
		quickSort(ivec, lo, i - 1);
		quickSort(ivec, i + 1, hi);
		return;
	}

	int partition(vector<int> &ivec, int lo, int hi) {
		int i = lo, j = hi, base = ivec[lo];
		while (i < j) {
			while (i < j && ivec[j] >= base) j--;
			ivec[i] = ivec[j];
			while (i < j && ivec[i] <= base) i++;
			ivec[j] = ivec[i];
		}
		ivec[i] = base;
		return i;
	}

	// merge sort
	// ave      good      bad      space  
	// o(nlogn) o(nlogn)  o(nlogn) o(n)   stable
	void mergeSort(vector<int> &ivec, size_t lo, size_t hi) {
		if (hi - lo <= 0) return;
		if (hi - lo == 1) {
			if (ivec[lo] > ivec[hi]) swap(ivec, lo, hi);
			else return;
		}
		size_t mid = lo + (hi - lo) / 2;
		mergeSort(ivec, lo, mid);
		mergeSort(ivec, mid + 1, hi);
		mergeVec(ivec, lo, hi, mid);
		return;
	}

	void mergeVec(vector<int> &ivec, int lo, int hi, int mid) {
		vector<int> extraVec(hi - lo + 1, 0);
		for (size_t cur = 0, curLo = lo, curMid = mid + 1; cur < extraVec.size();) {
			// step_1
			while (curLo == mid + 1 && cur < extraVec.size()) extraVec[cur++] = ivec[curMid++];
			while (curMid == hi + 1 && cur < extraVec.size()) extraVec[cur++] = ivec[curLo++];
			if (cur == extraVec.size()) break;
			// step_2
			if (ivec[curLo] < ivec[curMid]) extraVec[cur++] = ivec[curLo++];
			else extraVec[cur++] = ivec[curMid++];
		}
		// step_3
		for (size_t cur = 0, curLo = lo; cur < extraVec.size();) ivec[curLo++] = extraVec[cur++];
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
	vector<int> ivec = { 6, 2, 3, 5 ,7 ,9, 11, 2, 2 };//{ 3, 7, 3, 4, 4 ,2 };
	Solution s;
	s.sort(ivec);

	s.printVec(ivec);

	int in;
	cin >> in;
	return 0;
}
