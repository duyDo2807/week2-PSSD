#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BlackAndRed {
 public:
  int cut(string deck) {
    int n = deck.size();

    for (int cut_pos = 0; cut_pos < n; cut_pos++) {
      string new_deck = deck.substr(cut_pos) + deck.substr(0, cut_pos);
      int red_count = 0;
      int black_count = 0;
      bool valid = true;

      for (char card : new_deck) {
        if (card == 'R') {
          red_count++;
        } else {
          black_count++;
        }

        if (red_count > black_count) {
          valid = false;
          break;
        }
      }

      if (valid) {
        return cut_pos;
      }
    }

    // If no valid cut is found, return -1
    return -1;
  }
};