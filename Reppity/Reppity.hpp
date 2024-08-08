#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Reppity {
 public:
  int longestRep(string input) {
    int maxLength = 0;
    for (int length = input.length() / 2; length > 0; length--) {
      for (int start = 0; start <= input.length() - 2 * length; start++) {
        string substr = input.substr(start, length);
        size_t found = input.find(substr, start + length);
        if (found != string::npos) {
          maxLength = length;
        }
      }
      if (maxLength > 0) {
        break;
      }
    }
    return maxLength;
  }
};