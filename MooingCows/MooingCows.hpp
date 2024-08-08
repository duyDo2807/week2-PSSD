#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class MooingCows {
 public:
  int dissatisfaction(vector<string> farmland) {
    int n = farmland.size();      // Rows
    int m = farmland[0].size();   // Columns
    vector<pair<int, int>> cows;  // Vector to save cows' locations

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (farmland[i][j] == 'C') {
          cows.emplace_back(i, j);  // Save cows' location
        }
      }
    }

    int minDisssatisfaction =
        numeric_limits<int>::max();  // Initialize minimum dissatisfaction to a
                                     // large value

    for (const auto& mooingCow : cows) {
      int totalDissatisfaction = 0;
      for (const auto& cow : cows) {
        if (mooingCow != cow) {
          int x = mooingCow.first - cow.first;
          int y = mooingCow.second - cow.second;
          totalDissatisfaction += x * x + y * y;
        }
      }
      minDisssatisfaction =
          min(minDisssatisfaction,
              totalDissatisfaction);  // Update minDissatisfaction
    }
    return minDisssatisfaction;
  }
};