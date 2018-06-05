/*Given an array of N elements and L and R, count the number of subarrays
whose max. element is >= L, <= R. Examples:
Input : arr[] = {2, 0, 11, 3, 0}
          L = 1, R = 10
Output : 4. The sub-arrays {2}, {2, 0}, {3} 
and {3, 0} have maximum in range 1-10.

Input : arr[] = {3, 4, 1}
          L = 2, R = 4 
Output : 5. The sub-arrays are {3}, {4}, 
{3, 4}, {4, 1} and {3, 4, 1} 
Observations:
- Elements > R are never inc in any subarray.
- Elements < L can be inc in subarray as long as there is min. 1 element
between L and R inclusive.
- The number of all possible subarrays of an array of size N is N * (N + 1)/2. 
This is based on the sum of sequences 1 + 2 + 3 + ... + n = n x (n + 1) / 2
*/
#include <bits/stdc++.h>
using namespace std;

long count_subarrays(long n)
{
    // Helper function to count the number of subarrays formed by n elements.
    return n * (n + 1) / 2;
}
long subarrays_max_in_range(int array[], int n, int l, int r)
{
    /* We keep track of two counts for each subarray:
    - inc: count of all elements <= R
    - exc: count of all elements < L
    The count for a subarray is count_subarrays(inc) - count_subarrays(exc)
    */
    long inc = 0;
    long exc = 0;
    long result = 0;
    for (int i = 0; i < n; i++) {
        // If an element > r, we get the count for the previous subarray
        // and reset inc and exc
        if (array[i] > r) {
            result += count_subarrays(inc) - count_subarrays(exc);
            inc = 0;
            exc = 0;
        }
        // If an element is within the defined range, we increment inc
        else if (array[i] <= r and array[i] >= l) {
            result -= count_subarrays(exc)
            exc = 0
            inc += 1;
        }
        // If an element is < l, then we increment two counts
        else {
            inc += 1;
            exc += 1;
        }
    }
    result += count_subarrays(inc) - count_subarrays(exc);
    return result;
}


int main() {
    int a[] = {2, 0, 11, 3, 0};
    int n = sizeof(a) / sizeof(a[0]);
    int l = 1, r = 10;
    cout << subarrays_max_in_range(a, n, l, r);
    return 0;
}
