#include<iostream>
#include<vector>
#include<cmath>

// ���α׷��ӽ� Ư���� �޸� üũ���Ͽ�,
// �Ʒ� �Լ�ȭ�� �ڵ带 �����ϸ�, �����ʰ���.
using namespace std;

long long solution(int N);
void deletNonePrimeNum(int N, vector<bool>& isPrimeNum);
int sumAllPrimeNum(int N, vector<bool>& isPrimeNum);

int main(void) {
	cout << solution(7) << endl;
}

long long solution(int N){
	long long primeNumSum = 0;
	vector<bool> isPrimeNum(N + 1, true);

	deletNonePrimeNum(N, isPrimeNum);
	//for (int i = 2; i <= square; i++) {
	//	if (isPrimeNum[i] == true) {
	//		for (int j = 2; j * i <= N; j++) {
	//			isPrimeNum[i*j] = false;
	//		}
	//	}
	//}
	primeNumSum = sumAllPrimeNum(N, isPrimeNum);
	//for (int i = 2; i < isPrimeNum.size(); i++) {
	//	if (isPrimeNum[i] == true) {
	//		primeNumSum += i;
	//	}
	//}
	return primeNumSum;
}

//�ִ�� N ������ �Ҽ��� ���Ѵ�.
// �Ҽ��� 1�� �ڱ��ڽ��� ���ڸ� �����ϴ� �����̴�.
// �Ҽ��� �����ϸ� ���̻� �Ҽ��� �ƴϴ�.
// ��, 2,4,6,8 .. �� �Ҽ��� �ƴϴ�.
// �̷��� ������ �԰��Ͽ�, ���������� �Ҽ����� �ִ�� N/2 �� ���ڰ� �Ҽ����� �˻��ϰ� �Ҽ��̸� �����Ͽ�
// �Ҽ��� �ƴ� ���ڸ� ���Ѵ�.
void deletNonePrimeNum(int N, vector<bool>& isPrimeNum) {
	int sqrtNum = sqrt(N);
	for (int i = 2; i <= sqrtNum; i++) {
		if ( isPrimeNum[i] == true ) {
			for (int j = 2; j*i <= N ; j++) {
				int num = i * j;
				isPrimeNum[num] = false;
			}
		}
	}
}

int sumAllPrimeNum(int N, vector<bool>& isPrimeNum) {
	int sum = 0;
	for (int i = 2; i < isPrimeNum.size() ; i++) {
		if (isPrimeNum[i] == true) {
			sum += i;
		}
	}
	return sum;
}