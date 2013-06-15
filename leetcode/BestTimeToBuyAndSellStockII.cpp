#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) return 0;
    int pro = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i-1]) {
            pro += (prices[i] - prices[i-1]);
        }
    }
    return pro;
}

int maxProfit(vector<int> &a) {
    int size = a.size();
    if (size == 0 || size == 1) {
        return 0;
    }

    int profict = 0;
    int i = 0;
    while (i < size) {
        while((i + 1) < size && a[i] >= a[i+1]) {
            i++;
        }

        int max = a[i];
        int min = a[i];
        while ((i + 1) < size && a[i] <= a[i + 1]) {
            max = a[i+1];
            i++;
        }
        i++;
        profict += (max - min);
    }
    return profict;
}

int main() {
  vector<int> a;
  a.push_back(1);
  a.push_back(2);

  int c = maxProfit(a);

  return 0;
}
