#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

int main() {
	string input;
	cin >> input;
	vector<list<int> > adjLists(256);
	vector<bool> visited(256, false);
	unordered_set<int> canBeARoot, canNotBeARoot;

	for (size_t i = 0; i < input.size(); i += 3) {
		adjLists.at(input[i]).push_back(input[i + 1]);
		//check if there is at most one parent
		if (canNotBeARoot.find(input[i+1]) == canNotBeARoot.end()) {
			canNotBeARoot.insert(input[i + 1]);
		}
		else {
			cout << "NO\n";
			return 0;
		}
		if (canNotBeARoot.find(input[i]) == canNotBeARoot.end()) {
			canBeARoot.insert(input[i]);
		}
	}

	//Check if there is only one root
	if (canBeARoot.size() != 1) {
		cout << "NO\n";
		return 0;
	}

	//check if any node has more then two kids
	for (auto &it : adjLists) {
		if (it.size() > 2) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

