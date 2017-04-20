#include<iostream>
#include<cstring>
using namespace std;

//题目：输入数字n，打印1到n位十进制数的所有数字
//思路：这是一个大数问题：当n很大的时候，如果用int long long 来保存都有可能产生溢出。所以采用字符串来存储数字。
//利用全排列递归


///////////////////////
void PrintNumber(char *number)
{
	bool BeginFlag = true;
	int length = strlen(number);
	for (int i = 0; i < length; i++)
	{
		if (BeginFlag && (number[i] != '0'))
			BeginFlag = false;
		if (!BeginFlag)
			cout << number[i];
	}
	cout << '\t';
}
/////////////////
void Print1ToNdigitRecursively(char *number,int length,int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToNdigitRecursively(number, length, index + 1);
	}
}
//////////////
void Print1ToNdigit(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToNdigitRecursively(number, n, 0);
	}
	delete[] number;

}
int main()
{
	Print1ToNdigit(0);
	cout << "//////////////////////////////\n";
	Print1ToNdigit(-1);
	cout << "//////////////////////////////\n";
	Print1ToNdigit(1);
	cout << "//////////////////////////////\n";
	Print1ToNdigit(2);
	cout << "//////////////////////////////\n";
	Print1ToNdigit(3);
	return 0;
}