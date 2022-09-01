#include <stdio.h>

//回调函数作业

//1.回调函数就是一个通过函数指针调用的函数，一般通过函数指针实现
//一般不是函数的实现方调用，而是在特定的场景下，由另外一方调用
//调用函数指针指向的函数

//2.
//char* arr[5]={"hello","bit"};
//test(arr)
//求test函数中形参形式  -- 指针 或 数组
// void test(char**arr)
// void test(char arr[5])

//3.
//int arr[3][5]={1,2,3,4,5,6,7,8,9,10}
// print_arr(arr,3,5)
// 求print_arr函数中形参形式 
// void print_arr(int (*arr)[5],int row,int col);
//arr是首元素地址，这里指第一行，而第一行也是一个数组，有5个元素，数组的地址用数组指针来接收


////4.
//
//
//int main()
//{
//	int a[5] = { 5,4,3,2,1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	//结果 - 4,1
//	return 0;
//}

//指针进阶作业

////1.
//
//
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	//结果 - 1,6
//	//aa是二维数组首元素读地址，这里就是第一行的地址，+1就指向了第二行的开头,又是指第二行的首元素地址，
//	// 所以-1就是在5的位置，向前移动一个整形,到6的起始位置，解引用就是6
//	//*（aa+1）= aa[1]
//	return 0;
//}
//
////2.实现一个函数，可以左旋字符串中的k个字符
////如：ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符就是CDAB
//
//
//////暴力求解法
////#include <string.h>
////#include <assert.h>
////
////void left_move(char* arr, int k)
////{
////	assert(arr != NULL);  //指针的断言
////	int i = 0;
////	int len = strlen(arr);
////	for (i = 0; i < k; i++)
////	{
////		//左旋转一个字符
////		//1.
////		char tmp = *(arr);
////		//2.
////		int j = 0;
////		for (j = 0; j < len-1; j++)
////		{
////			*(arr + j) = *(arr + j + 1);
////		}
////		//3.
////		*(arr + len - 1) = tmp;
////	}
////}
//
////三步翻转法
////abcdef
////bafedc
////cdefab
//
//#include <string.h>
//#include <assert.h>
//
//void reverse(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int len = strlen(arr);
//	reverse(arr,arr+k-1);  //逆序左边
//	reverse(arr+k,arr+len-1);  //逆序右边
//	reverse(arr,arr+len-1);  //逆序整体
//}
//
//int main()
//{
//	char arr[] = "ABCDEFG";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//3.写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串

#include <string.h>
#include <assert.h>

void reverse(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	reverse(arr,arr+k-1);  //逆序左边
	reverse(arr+k,arr+len-1);  //逆序右边
	reverse(arr,arr+len-1);  //逆序整体
}

int is_left_move(char* s1, char* s2)
{
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(s1, 1);
		int ret = strcmp(s1, s2);
		if (ret == 0)
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	char arr1[] = "ABCDEFG";
	char arr2[] = "CDEFGAB";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
