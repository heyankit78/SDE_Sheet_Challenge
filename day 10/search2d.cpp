#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
       int start = 0, end = m * n - 1;

    // Binary search.
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int val = mat[mid / n][mid % n];

        if (target < val) {
            end = mid - 1;
        } else if (target > val) {
            start = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}
