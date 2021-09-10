///*
//	一个升序序列的中间位置的元素称为中位数，两个序列的中位数则是这两个序列升序排好序后的中间的数为中位数，现有两个等长的生序序列
//	A、B，找出它们的中位数。
//	分析：
//		我们可以先将这两个序列合并成一个升序序列，然后即可求出中位数，但是这样时间复杂度为O(n)，空间复杂度也为O(n);
//		我们也可以采用归并排序的想法，先求出两个序列的总元素的个数，因为他们等长，只需求出一个序列的长度，中间位置即为len，
//		之后我们开始依次比较，并进行计数count，当count=len时，该元素即为中位数，这样时间复杂度为O(n),空间复杂度为O(1)
//*/
//#include <stdio.h>
//int findMidNum1(int *l1, int *l2, int len) {
//	int count = 0, middle;
//	for (int i = 0, j = 0; *(l1 + i) && *(l2 + j);) {//依次比较，较小者出列
//		if (count++ == len) {//判断是否到达中位数的位置
//			middle = *(l1 + i) < *(l2 + j) ? *(l1 + i) : *(l2 + j);//取出中位数
//			break;
//		}
//		else {
//			*(l1 + i) < *(l2 + j) ? i++ : j++;//没有到，继续归并
//		}
//
//	}
//	return middle;
//}
//int findMidNum2(int *l1, int *l2, int len) {
//	int s1 = 0, d1 = len - 1, s2 = 0, d2 = len - 1, m1, m2;//两个表的开始结束位置及中间位置
//	while (s1 != d1 || s2 != d2) {
//		m1 = (s1 + d1) / 2;
//		m2 = (s2 + d2) / 2;
//		if (l1[m1] == l2[m2]) {//此时位置就是中位数的位置
//			return l1[m1];
//		}
//		if (l1[m1] < l2[m2]) {//此时舍弃m1左边元素，m2右边元素，但考虑到有奇偶情况，分开讨论
//			if ((s1 + d1) % 2 == 0) {//如果此时操作的序列为奇数，则要保留中间点
//				s1 = m1;//舍弃m1的左边部分
//				d2 = m2;//舍弃m2的右边部分
//			}
//			else {//而如果操作序列为偶数，则舍弃m1的左边及其中心点，舍弃m2的右边
//				s1 = m1 + 1;
//				d2 = m2;
//
//			}
//
//		}
//		else {//此时舍弃m2左边元素，m1右边元素，也需要分奇偶讨论
//			if ((s2 + d2) % 2 == 0) {//如果此时操作的序列为奇数，则要保留中间点
//				d1 = m1;//舍弃l1的左边部分
//				s2 = m2;//舍弃l2的右边部分
//			}
//			else {//而如果操作序列为偶数，则舍弃m1的左边及其中心点，舍弃m2的右边
//				d1 = m1;
//				s2 = m2 + 1;
//
//			}
//		}
//
//	}
//	return l1[s1] < l2[s2] ? l1[s1] : l2[s2];
//}
//int main() {
//	int l1[] = { 1,3,4,7,9 ,10,11};// 1 2 3 4 4 6 7 8 9 10 10 11
//	int l2[] = { 2,4,6,8,10 };
//	int len = sizeof(l1) / sizeof(int);
//	int middle;
//	middle = findMidNum2(l1, l2, len - 1);
//	printf("中位数是：%d ", middle);
//	return 0;
//}