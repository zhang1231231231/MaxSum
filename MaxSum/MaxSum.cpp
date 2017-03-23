// ***********************************************************************
// Assembly         : 
// Author           : zhang
// Created          : 03-23-2017
//
// Last Modified By : zhang
// Last Modified On : 03-23-2017
// ***********************************************************************
// <copyright file="MaxSum.cpp" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary>
// 对于一个有正有负的整数数组，请找出总和最大的连续数列。
// 给定一个int数组A和数组大小n，请返回最大的连续数列的和。保证n的大小小于等于3000。
// 测试样例：
// [1, 2, 3, -6, 1]
// 返回：6
//</summary>
// ***********************************************************************

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MaxSum {
public:
	int getMaxSum(vector<int> A, int n) {
		// write code here
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return A[0];
		}
		int num = 0;
		vector<int> result;
		for (int i = 0; i < n; i++)
		{
			if (A[i] < 0)
			{
				if (num + A[i] <= 0)
				{
					result.push_back(num);
					num = 0;
				}
				else
				{
					result.push_back(num);
					cout << num << endl;
					num += A[i];
					cout << num << endl;
					result.push_back(num);
				}
			}
			else
			{
				num += A[i];
			}
		}
		if (num != 0)
		{
			cout << num << endl;
			result.push_back(num);
		}
		if (result.empty())
		{
			return 0;
		}
		sort(result.rbegin(), result.rend());
		return result[0];
	}
};

int main()
{
	int arr[] = { 1,2,3,-6,1 };
	int n = sizeof(arr) / sizeof(int);
	cout << "index:" << n << endl;
	vector<int> vct(arr, arr + n);
	MaxSum maxNum;
	int count = maxNum.getMaxSum(vct, vct.size());
	cout << count << endl;
	return 0;
}


