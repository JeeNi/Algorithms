#include <string>
#include <vector>
#include <stack>
#include<iostream>

using namespace std;

typedef struct {
	int height;
	int index;
}TopInfo;

// 1) ���� ž�� ���̸� ���� stack ���� ������ ������ ū ���� ������ ���� pop �Ѵ�.
// 2) ���� �ڽź��� ���� ���� ���ٸ� ��� ����, ��ȣ�� �����ϴ� ž �迭�� 0�� �ִ´�.
// 3) ���� �ִٸ� �ش� index�� ���� , ��ȣ�� �����ϴ� ž �迭�� �ִ´�.
// 4) ���� ž�� ���̸� stack �� �ִ´�.
// ��� �ݺ��Ѵ�.
vector<int> solution(vector<int> heights) {
	vector<int> answer;
	answer.push_back(0);

	stack<TopInfo> topStack;
	topStack.push({heights[0], 1});

	for (int i = 1; i < heights.size(); i++) {
		while (!topStack.empty()) {
			TopInfo nowTopInfo = topStack.top();
			
			if (nowTopInfo.height > heights[i]) {
				answer.push_back(nowTopInfo.index);
				break;
			}
			else {
				topStack.pop();
			}

			if (nowTopInfo.height <= heights[i] &&
				topStack.empty() ) {
				answer.push_back(0);
				break;
			}
		}
		topStack.push({ heights[i], i + 1 });
	}

	return answer;
}

//Test main
int main() {
	vector<int> res = solution({});
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
}



