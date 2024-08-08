#include <algorithm>
#include <climits>
#include <iostream>

class EggCartons {
 public:
  int minCartons(int n) {
    // Initialize the minimum number of cartons to -1 as base
    int minCartons = -1;

    for (int eightEggs = 0; eightEggs * 8 <= n; ++eightEggs) {
      int remaining = n - eightEggs * 8;
      // Check if remaining eggs can be divided by 6
      if (remaining % 6 == 0) {
        // Calculate the number of 6-egg cartons
        int sixEggs = remaining / 6;
        // Calculate the total number of cartons
        int totalCartons = eightEggs + sixEggs;
        // Update the minimum number of cartons
        if (minCartons == -1 || totalCartons < minCartons) {
          minCartons = totalCartons;
        }
      }
    }

    return minCartons;
  }
};