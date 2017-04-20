#include<iostream>
#include<cstring>
using namespace std;

//题目：输入数字n，打印1到n位十进制数的所有数字
//思路：这是一个大数问题：当n很大的时候，如果用int long long 来保存都有可能产生溢出。所以采用字符串来存储数字。

bool Increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >=0 ; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;;
			}
				
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}
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
void Print1ToNdigit(int n)
{
	if (n <= 0)
		return ;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))//在表示数字的字符串上加1，确定到最大的n位数，使用strcmp()的时间复杂度为o（n）,该函数更快，时间复杂度为O（1）
		PrintNumber(number);//打印要符合打印习惯（089要为89）
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