// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<algorithm>
using namespace std;
int a[100] = { 0 };
class QkSort {
private:
public:
	QkSort() {};
	void QuickSort(int a[], int p, int r);
	int Partition(int a[], int p, int r);
	void print(int a[], int n);
};
void QkSort::QuickSort(int a[], int p, int r) {
	if (p < r) {
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}
int QkSort::Partition(int a[], int p, int r) {
	int i = p, j = r + 1;
	int x = a[p];
	while (true) {
		while (a[++i] < x&&i < r);
		while (a[--j] > x);
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}
void QkSort::print(int a[], int n) {
	cout << "排序成功：" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
int main()
{
	int n;
	cout << "请输入元素个数" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int p = 0, r = n - 1;
	QkSort s;
	s.QuickSort(a, p, r);
	s.print(a, n);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
