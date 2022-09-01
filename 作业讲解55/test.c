#include <stdio.h>

//�ص�������ҵ

//1.�ص���������һ��ͨ������ָ����õĺ�����һ��ͨ������ָ��ʵ��
//һ�㲻�Ǻ�����ʵ�ַ����ã��������ض��ĳ����£�������һ������
//���ú���ָ��ָ��ĺ���

//2.
//char* arr[5]={"hello","bit"};
//test(arr)
//��test�������β���ʽ  -- ָ�� �� ����
// void test(char**arr)
// void test(char arr[5])

//3.
//int arr[3][5]={1,2,3,4,5,6,7,8,9,10}
// print_arr(arr,3,5)
// ��print_arr�������β���ʽ 
// void print_arr(int (*arr)[5],int row,int col);
//arr����Ԫ�ص�ַ������ָ��һ�У�����һ��Ҳ��һ�����飬��5��Ԫ�أ�����ĵ�ַ������ָ��������


////4.
//
//
//int main()
//{
//	int a[5] = { 5,4,3,2,1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	//��� - 4,1
//	return 0;
//}

//ָ�������ҵ

////1.
//
//
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	//��� - 1,6
//	//aa�Ƕ�ά������Ԫ�ض���ַ��������ǵ�һ�еĵ�ַ��+1��ָ���˵ڶ��еĿ�ͷ,����ָ�ڶ��е���Ԫ�ص�ַ��
//	// ����-1������5��λ�ã���ǰ�ƶ�һ������,��6����ʼλ�ã������þ���6
//	//*��aa+1��= aa[1]
//	return 0;
//}
//
////2.ʵ��һ�����������������ַ����е�k���ַ�
////�磺ABCD����һ���ַ��õ�BCDA
////ABCD���������ַ�����CDAB
//
//
//////������ⷨ
////#include <string.h>
////#include <assert.h>
////
////void left_move(char* arr, int k)
////{
////	assert(arr != NULL);  //ָ��Ķ���
////	int i = 0;
////	int len = strlen(arr);
////	for (i = 0; i < k; i++)
////	{
////		//����תһ���ַ�
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
////������ת��
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
//	reverse(arr,arr+k-1);  //�������
//	reverse(arr+k,arr+len-1);  //�����ұ�
//	reverse(arr,arr+len-1);  //��������
//}
//
//int main()
//{
//	char arr[] = "ABCDEFG";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//3.дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���

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
	reverse(arr,arr+k-1);  //�������
	reverse(arr+k,arr+len-1);  //�����ұ�
	reverse(arr,arr+len-1);  //��������
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
