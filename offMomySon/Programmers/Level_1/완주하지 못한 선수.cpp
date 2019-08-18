#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

//map ������, n���� element�� insert �ϸ�, nlog(n) time complexity �ҿ�ȴ�.
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	int ansIndex = 1;
	map<string,int> participantSet;

	for (string str : participant) {
		++participantSet[str];
	}

	for (string str : completion) {
		--participantSet[str];
	}

	for (pair<string, int> p : participantSet) {
		if (p.second > 0) {
			return p.first;
		}
	}
}

//Test main
int main() {
	cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" });
}