#include <vector>
struct visited {
  unsigned char left;
  unsigned char right;
  unsigned char up;
  unsigned char down;

  visited() {
    left = false;
    right = false;
    up = false;
    down = false;
  }

  bool failure() {
    return (left == false &&
            right == false &&
            up == false &&
            down == false);
  }
};

typedef vector<vector<char> >::iterator outter_iterator;
typedef vector<char>::iterator inner_iterator;

class Solution {
 public:
  bool exist(vector<vector<char> >& board, string word) {
    int outer_size; = board.size();
    for (int i = 0; i)
  }
};


bool search(vector<vector<char>& board, int row, int column, string word, int begin, int length, visited temp) {
  if (begin == length) {
    return true;
  }

  if (row+1 < board.size()) {

  }


}
