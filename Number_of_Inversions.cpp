/*
 * Problem: Count the number of inversions in an array.
 * An inversion is a pair (i, j) such that i < j and a[i] > a[j].
 * 
 * Approach:
 * - Modified Merge Sort (Divide and Conquer)
 * - During merge, count how many elements from the left array are greater than current right element.
 * 
 * Time Complexity: O(n log n)
 * - Each merge_sort call divides the array → log n
 * - Each merge step takes linear time → O(n)
 * 
 * Space Complexity: O(n)
 * - Temporary array used during merging
 */

int merge(int low, int mid, int high, vector<int>& a, int n) {
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    int cnt = 0;

    // Merge the two halves while counting inversions
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            // All elements from a[i] to a[mid] are greater than a[j]
            cnt += (mid - i + 1);
            temp.push_back(a[j]);
            j++;
        }
    }

    // Append remaining elements
    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(a[j]);
        j++;
    }

    // Copy the sorted subarray back to original array
    for (int k = 0; k < temp.size(); k++) {
        a[low + k] = temp[k];
    }

    return cnt;
}

int merge_sort(int low, int high, vector<int>& a, int n) {
    int cnt = 0;
    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    // Count inversions in left, right, and during merge
    cnt += merge_sort(low, mid, a, n);
    cnt += merge_sort(mid + 1, high, a, n);
    cnt += merge(low, mid, high, a, n);

    return cnt;
}

// Main function to count number of inversions
int numberOfInversions(vector<int>& a, int n) {
    return merge_sort(0, n - 1, a, n);
}
