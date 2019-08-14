#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct {
	int weight;
	int time;
}TruckInfo;

// �ٸ��� ���� �ø�.
bool pushBridge(int limitBridgeWeight, int& nowBridgeWeight, queue<TruckInfo>& q, TruckInfo truck) {
	if (nowBridgeWeight + truck.weight > limitBridgeWeight) {
		return false;
	}
	q.push(truck);
	nowBridgeWeight += truck.weight;
	return true;
}
// �ٸ��� ���� ��.
void popBridge(int nowTime, int bridge_length, int& nowBridgeWeight, queue<TruckInfo>& q) {
	if (q.empty())
		return;

	TruckInfo frontTruckInfo = q.front();
	int spendTime = nowTime - frontTruckInfo.time;
	int truckWeight = frontTruckInfo.weight;

	if (spendTime >= bridge_length) {
		nowBridgeWeight -= truckWeight;
		q.pop();
	}
}
// ������ �������� üũ.
bool checkTransportFinished(queue<TruckInfo>& q, int& nextTruckIndex, int truckWeightsLength) {
	if (q.empty() && nextTruckIndex >= truckWeightsLength) {
		return true;
	}
	return false;
}
// Ǯ��.
// �ٸ��� ���̿� ���� ������ �ٸ��� �ִ� �ð��� �����ȴ�.
// ex) bridge_length = 2 �� ���
// 1,2 �� �ٸ��� �ӹ��� �ִ�. -> 3�ʰ� �Ǿ�����, �ٸ����� ���� ������. ��� ������ �ص� ������.
// Logic
// 1) ���� �ð���, �ٸ��� �ӹ��� ������ �ȵǴ� ���� ����.
// 2) ��� ���� ������ �������� üũ.
// 3) ���� �ð���, ������ �ٸ��� �ö󰥼� ������ í�� �ø�.
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int nowTime = 1;
	int nowBridgeWeight =0;
	int nextTruckIndex =0 ;
	queue<TruckInfo> q;
	
	while (true) {
		popBridge(nowTime, bridge_length, nowBridgeWeight, q);
		
		if (checkTransportFinished(q, nextTruckIndex, truck_weights.size())) {
			break;
		}

		if (nextTruckIndex < truck_weights.size()) {
			if (pushBridge(weight, nowBridgeWeight, q, { truck_weights[nextTruckIndex], nowTime })) {
				nextTruckIndex++;
			}
		}
		nowTime++;
	}
	return nowTime;
}

//Test main
int main() {
	int ans = solution(2, 10, { 7,4,5,6 });
	cout << ans << "\n";
	return ans;
}