#include <iostream>
using namespace std;

// Determine whether an integer is a palindrome.
// Do this without extra space.
//
bool Palindrome(int x) {
    if (x < 0) {
        return false;
    }
    int i = 1;
    int temp = x;
    while (temp / 10 != 0) {
        temp = temp / 10;
        i *= 10;
        
    }
    if (x < 10) {
        return true;
        
    }
    while (x >= 10) {
        int higher = x / i;
        x = x % i;
        int lower = x % 10;

        if (higher != lower) {
            return false;
            
        }
        x = x/10;
        i = i / 100;
    }
    return true;
}


int main() {
  if (Palindrome(2147447412) == true) {
    cout <<"true" << endl;
  } else {
    cout <<"false" << endl;
  }
  return 0;
}
