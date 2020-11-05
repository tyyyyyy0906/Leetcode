/******************************************************************************
* leetcode��Ŀ(������)��
*	leetcode:#1550(����������������������). -> threeConsecutiveOdds():
*   leetcode:#219 (����һ����������arr��һ������k,�ж��������Ƿ����������ͬ������i��j��ʹ��arr[i] = arr[j],����i��j�Ĳ�ľ���ֵ����Ϊk). -> containsNearbyDuplicate()



******************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>

/// <summary>
/// ����std::set key��Ψһ�Խ�������ȥ��
/// </summary>
/// <param name="arr"></param>
void vectorUniqueMethodA(std::vector<int>* arr) {
	if (arr->size() <= 1) return;

	std::set<int> set_(arr->begin(), arr->end());
	arr->assign(set_.begin(), set_.end());

	for (const auto &it : *arr) {
		std::cout << "vectorUnique ȥ�ؽ�� = " << it << std::endl;
	}
}

/// <summary>
/// ����std::vector�Ľӿ�erase��std::uniqueʵ��ȥ��
/// </summary>
/// <param name="arr"></param>
void vectorUniqueMethodB(std::vector<int>* arr) {
	if (arr->size() <= 1) return;

	std::sort (arr->begin(), arr->end());
	arr->erase(std::unique(arr->begin(), arr->end()), arr->end());

	for (const auto &it : *arr) {
		std::cout << "vectorUniqueAnother ȥ�ؽ�� = " << it << std::endl;
	}
}

namespace AlgorithmVector {

	///leetcode 1550(https://leetcode-cn.com/problems/three-consecutive-odds/)
	///����һ���������� arr�������ж��������Ƿ������������Ԫ�ض��������������������ڣ��뷵�� true �����򣬷��� false
	bool threeConsecutiveOdds(std::vector<int>* arr) {
		if (arr->size() < 3) return false;
		int cout = 0;
		for (int i = 0; i < arr->size(); i++) {
			if (cout >= 3) return true;
			(arr->at(i) % 2 == 0) ? (cout = 0) : cout++;
		}
		return cout == 3;
	}

	/// leetcode 219(https://leetcode-cn.com/problems/contains-duplicate-ii/)
	/// ����һ����������arr��һ������k,�ж��������Ƿ����������ͬ������i��j��ʹ��arr[i] = arr[j],����i��j�Ĳ�ľ���ֵ����Ϊk;
	bool containsNearbyDuplicate(std::vector<int>* arr, int k) {
		if (arr->size() < 2) return false;

		//����һ������С���������������ڴ���������ʱ�Ƚ�����
		/*for (int i = 0; i < arr->size(); i++) {
			for (int j = i + 1; j < arr->size(); j++) {
				if (arr->at(i) == arr->at(j)) {
					if (abs(i - j) <= k) return true;
					else continue;
				}
			}
		}
		return false;*/

		//������
		std::unordered_map<int, int> map;

		for (int i = 0; i < arr->size(); i++) {
			if (map.find(arr->at(i)) != map.end()) {  // �ҵ���
				if (i - map[arr->at(i)] <= k) return true;
				else map[arr->at(i)] = i;
			} else map[arr->at(i)] = i;
		}
		return false;
	}
	
}

int main() {
	std::vector<int> test_ = { 1, 2, 4, 2, 3, 2, 2 };
	vectorUniqueMethodA(&test_);
	vectorUniqueMethodB(&test_);

	using namespace AlgorithmVector;
	{
		///leetcode 1550��������
		std::vector<int> leetcode1550_A = { 1, 2, 3, 5, 7 };
		std::vector<int> leetcode1550_B = { 1, 2, 3, 4, 7 };
		std::vector<int> leetcode1550_C = { 1, 2, 2 };
		std::vector<int> leetcode1550_D = { 1 };
		std::vector<int> leetcode1550_E = { 1, 3, 5, 7, 9 };
		std::vector<int> leetcode1550_F = { 1, 2, 34, 3, 4, 5, 7, 23, 12 };
		std::cout << "leetcode 1550�������� 1 = " << threeConsecutiveOdds(&leetcode1550_A) << std::endl;
		std::cout << "leetcode 1550�������� 2 = " << threeConsecutiveOdds(&leetcode1550_B) << std::endl;
		std::cout << "leetcode 1550�������� 3 = " << threeConsecutiveOdds(&leetcode1550_C) << std::endl;
		std::cout << "leetcode 1550�������� 4 = " << threeConsecutiveOdds(&leetcode1550_D) << std::endl;
		std::cout << "leetcode 1550�������� 5 = " << threeConsecutiveOdds(&leetcode1550_E) << std::endl;
		std::cout << "leetcode 1550�������� 6 = " << threeConsecutiveOdds(&leetcode1550_F) << std::endl;

		///leetcode 219��������
		std::vector<int> leetcode219_A = { 1, 2, 3, 1 };
		std::vector<int> leetcode219_B = { 1, 0, 1, 1 };
		std::vector<int> leetcode219_C = { 1, 2, 3, 1, 2, 3 };
		std::cout << "leetcode 219�������� 1 = " << containsNearbyDuplicate(&leetcode219_A, 3) << std::endl;
		std::cout << "leetcode 219�������� 2 = " << containsNearbyDuplicate(&leetcode219_B, 1) << std::endl;
		std::cout << "leetcode 219�������� 3 = " << containsNearbyDuplicate(&leetcode219_C, 2) << std::endl;
	}

	return 0;
}