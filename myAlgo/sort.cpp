// sort algorithms exercise 
// 1\Insert Sort  2\Select Sort  3\Pop Sort  4\Merge Sort  5\Quick Sort  6\Heap Sort
// Author - Scott Ray
// Time - 2018/2/25 version 1.0 ... 2018/4/20 version2.0 ...

#include "stdafx.h"
#include<iostream>
#include<vector>

#include<stdio.h>

using namespace std;

class Solution {
public:
    void sort(vector<int> &ivec) {
        if (ivec.size() <= 1) return;
        //insertSort(ivec);
        //selectSort(ivec);
        //popSort(ivec);
        mergeSort(ivec, 0, ivec.size() - 1);
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
                if (vec[j - 1] > vec[j]) swap(vec[j - 1], vec[j]);
                else break;
            }
        }
        return;
    }

    // select sort
    // ave   good   bad   space  
    // o(n2) o(n2)  o(n2) o(1)   stable
    void selectSort(vector<int> &vec) {
        if (vec.size() <= 1) return;
        int n = vec.size();
        for (int floor = 0; floor < n - 1; floor++) {
            for (int j = floor; j < n; j++) {
                if (vec[j] < vec[floor]) {
                    swap(vec[floor], vec[j]);
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
                if (vec[j - 1] > vec[j]) swap(vec[j - 1], vec[j]);
            }
        }
        return;
    }

    // heap sort
    // ave      good      bad      space  
    // o(nlogn) o(nlogn)  o(nlogn) o(1)   unstable
    void max_heapify(vector<int>& nums, int start, int end) {
        int dad = start;
        int son = 2 * dad + 1;
        while (son <= end) {
            if (son + 1 <= end && nums[son] < nums[son + 1]) son = son + 1;
            if (nums[dad] > nums[son]) return;
            else {
                swap(nums[dad], nums[son]);
                dad = son;
                son = 2 * dad + 1;
            }
        }
    }

    void heapSort(vector<int>& nums) {
        int len = nums.size();
        for (int i = len / 2 - 1; i >= 0; i--) {
            max_heapify(nums, i, len - 1);
        }
        for (int i = len - 1; i > 0; i--) {
            swap(nums[i], nums[0]);
            max_heapify(nums, 0, i - 1);
        }
    }
    // quick sort
    // ave      good      bad      space  
    // o(nlogn) o(nlogn)  o(n2)    o(logn)~o(n)   unstable
    void quickSort(vector<int> &ivec, int lo, int hi) {
        if (lo >= hi) return;
        int mid = partition(ivec, lo, hi);
        quickSort(ivec, lo, mid - 1);
        quickSort(ivec, mid + 1, hi);
    }

    int partition(vector<int> &ivec, int lo, int hi) {
        int pivot = ivec[lo];
        while (lo < hi) {
            while (lo < hi && ivec[lo] < pivot) lo++;
            ivec[hi] = ivec[lo];
            while (lo < hi && ivec[hi] >= pivot) hi--;
            ivec[lo] = ivec[hi];
        }
        ivec[lo] = pivot;
        return lo;
    }

    // merge sort
    // ave      good      bad      space  
    // o(nlogn) o(nlogn)  o(nlogn) o(n)   stable
    void mergeSort(vector<int> &ivec, int lo, int hi) {
        if (hi - lo <= 0) return;
        if (hi - lo == 1) {
            if (ivec[lo] > ivec[hi]) swap(ivec[lo], ivec[hi]);
            else return;
        }
        int mid = lo + (hi - lo) / 2;
        mergeSort(ivec, lo, mid);
        mergeSort(ivec, mid + 1, hi);
        merge(ivec, lo, hi, mid);
    }

    void merge(vector<int> &ivec, int lo, int hi, int mid) {
        vector<int> sup(hi - lo + 1, 0);
        int l = lo, r = mid + 1;
        for (int i = 0; i < hi - lo + 1; ) {
            while (l == mid + 1 && r <= hi) sup[i++] = ivec[r++];
            while (r == hi + 1 && l <= mid) sup[i++] = ivec[l++];
            if (i == hi - lo + 1) break;
            if (ivec[l] < ivec[r]) sup[i++] = ivec[l++];
            else sup[i++] = ivec[r++];
        }
        for (int i = 0; i < hi - lo + 1; i++) ivec[lo + i] = sup[i];
    }

};

int main()
{
    vector<int> ivec = { 6, 2, 3, 5 ,7 ,9, 11, 2, 2 };
    Solution s;
    s.sort(ivec);

    s.printVec(ivec);
    return 0;
}
