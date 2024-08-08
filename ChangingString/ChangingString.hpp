#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ChangingString {
 public:
  int distance(string A, string B, int K) {
    int n = A.length();
    vector<int> diffs(n);

    // Calculate the initial differences
    for (int i = 0; i < n; i++) {
      diffs[i] = abs(A[i] - B[i]);
    }

    // Sort differences in descending order
    sort(diffs.rbegin(), diffs.rend());

    int total_difference = 0;
    for (int i = 0; i < n; i++) {
      total_difference += diffs[i];
    }

    for (int i = 0; i < K; i++) {
      if (diffs[i] == 0) {
        // If diff is 0, changing it will add a difference of at least 1
        total_difference += 1;
      } else {
        // Reduce this difference to 0
        total_difference -= diffs[i];
      }
    }

    return total_difference;
  }
};