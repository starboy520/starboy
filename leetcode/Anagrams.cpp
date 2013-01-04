#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int my_compare (const string& i, const string& j) {
	string temp1 = i;
	string temp2 = j;
	std::sort(temp1.begin(), temp1.end());
	std::sort(temp2.begin(), temp2.end());
	if (temp1 == temp2) return 0;
	return -1;
};

int split(vector<string>& strs, int begin, int high) {
	string& x = strs[begin];

	int i = begin;

	for (int j = begin+1; j <= high; j++) {
		if (my_compare(strs[j], x) == 0) {
			i++;
			std::swap(strs[i], strs[j])	;
		}
	}
	return i;
}

vector<string> anagrams(vector<string> &strs) {
	int low = 0;
	int high = strs.size() -1;
	while (low < high) {
		int idx = split(strs, low, high);
		if (idx == low) {
			std::swap(strs[idx], strs[high]);
			high--;
			low = idx;
		} else {
			low = idx + 1;
		}
	}
	vector<string> result;
	for (int j = 0; j < low; j++) {
		result.push_back(strs[j]);
	}
	return result;
}

int main() {
	vector<string> strs;
	strs.push_back("");
	strs.push_back("b");
	vector<string> a = anagrams(strs);
	cout << a.size() << endl;
	return 0;
}
