
#include <iostream>
#include <memory>
#include <list>
#include <vector>
using namespace std;

void solution(int piecesLeft, vector<int> &machines, size_t index, list<list<int>> &output, list<int> &current);

int main() {
	int n, pieces;
	cin >> n;

	vector<int> machines(n);
	for (int i = 0; i < n; ++i) {
		cin >> machines[i];
	}
	cin >> pieces;

	list<list<int>> output;
	list<int> current;
	solution(pieces, machines, 0, output, current);

	cout << output.size() << endl;
	for (auto &it1 : output) {
		for (auto &it2 : it1) {
			cout << it2 << " ";
		}
		cout << endl;
	}
	return 0;
}

void solution(int piecesLeft, vector<int> &machines, size_t index,
		list<list<int>> &output, list<int> &current) {
	for (;index < machines.size(); ++index) {
		if (piecesLeft > machines.at(index)) {
			list<int> toForward(current);
			toForward.push_back(machines.at(index));
			solution(piecesLeft - machines.at(index), machines, index + 1, output, toForward);
		}
		else if (piecesLeft == machines.at(index)) {
			list<int> toForward(current);
			toForward.push_back(machines.at(index));
			output.push_back(move(toForward));
		}
	}
}
