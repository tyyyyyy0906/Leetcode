/******************************************************************************
* leetcode题目(数组类)：
*	leetcode:#1550(存在连续三个奇数的数组). -> threeConsecutiveOdds():
*   leetcode:#219 (给定一个整数数组arr和一个整数k,判断数组中是否存在两个不同的索引i和j，使得arr[i] = arr[j],并且i和j的差的绝对值至多为k). -> containsNearbyDuplicate()



******************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>

/// <summary>
/// 利用std::set key的唯一性进行数组去重
/// </summary>
/// <param name="arr"></param>
void vectorUniqueMethodA(std::vector<int>* arr) {
	if (arr->size() <= 1) return;

	std::set<int> set_(arr->begin(), arr->end());
	arr->assign(set_.begin(), set_.end());

	for (const auto &it : *arr) {
		std::cout << "vectorUnique 去重结果 = " << it << std::endl;
	}
}

/// <summary>
/// 利用std::vector的接口erase和std::unique实现去重
/// </summary>
/// <param name="arr"></param>
void vectorUniqueMethodB(std::vector<int>* arr) {
	if (arr->size() <= 1) return;

	std::sort (arr->begin(), arr->end());
	arr->erase(std::unique(arr->begin(), arr->end()), arr->end());

	for (const auto &it : *arr) {
		std::cout << "vectorUniqueAnother 去重结果 = " << it << std::endl;
	}
}

namespace AlgorithmVector {

	///leetcode 1550(https://leetcode-cn.com/problems/three-consecutive-odds/)
	///给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false
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
	/// 给定一个整数数组arr和一个整数k,判断数组中是否存在两个不同的索引i和j，使得arr[i] = arr[j],并且i和j的差的绝对值至多为k;
	bool containsNearbyDuplicate(std::vector<int>* arr, int k) {
		if (arr->size() < 2) return false;

		//方法一适用于小数据量操作：对于大数据量耗时比较严重
		/*for (int i = 0; i < arr->size(); i++) {
			for (int j = i + 1; j < arr->size(); j++) {
				if (arr->at(i) == arr->at(j)) {
					if (abs(i - j) <= k) return true;
					else continue;
				}
			}
		}
		return false;*/

		//方法二
		std::unordered_map<int, int> map;

		for (int i = 0; i < arr->size(); i++) {
			if (map.find(arr->at(i)) != map.end()) {  // 找到啦
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
		///leetcode 1550测试用例
		std::vector<int> leetcode1550_A = { 1, 2, 3, 5, 7 };
		std::vector<int> leetcode1550_B = { 1, 2, 3, 4, 7 };
		std::vector<int> leetcode1550_C = { 1, 2, 2 };
		std::vector<int> leetcode1550_D = { 1 };
		std::vector<int> leetcode1550_E = { 1, 3, 5, 7, 9 };
		std::vector<int> leetcode1550_F = { 1, 2, 34, 3, 4, 5, 7, 23, 12 };
		std::cout << "leetcode 1550测试用例 1 = " << threeConsecutiveOdds(&leetcode1550_A) << std::endl;
		std::cout << "leetcode 1550测试用例 2 = " << threeConsecutiveOdds(&leetcode1550_B) << std::endl;
		std::cout << "leetcode 1550测试用例 3 = " << threeConsecutiveOdds(&leetcode1550_C) << std::endl;
		std::cout << "leetcode 1550测试用例 4 = " << threeConsecutiveOdds(&leetcode1550_D) << std::endl;
		std::cout << "leetcode 1550测试用例 5 = " << threeConsecutiveOdds(&leetcode1550_E) << std::endl;
		std::cout << "leetcode 1550测试用例 6 = " << threeConsecutiveOdds(&leetcode1550_F) << std::endl;

		///leetcode 219测试用例
		std::vector<int> leetcode219_A = { 1, 2, 3, 1 };
		std::vector<int> leetcode219_B = { 1, 0, 1, 1 };
		std::vector<int> leetcode219_C = { 1, 2, 3, 1, 2, 3 };
		std::cout << "leetcode 219测试用例 1 = " << containsNearbyDuplicate(&leetcode219_A, 3) << std::endl;
		std::cout << "leetcode 219测试用例 2 = " << containsNearbyDuplicate(&leetcode219_B, 1) << std::endl;
		std::cout << "leetcode 219测试用例 3 = " << containsNearbyDuplicate(&leetcode219_C, 2) << std::endl;
	}

	return 0;
}