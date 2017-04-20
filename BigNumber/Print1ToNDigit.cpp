#include<iostream>
#include<cstring>
using namespace std;

//��Ŀ����������n����ӡ1��nλʮ����������������
//˼·������һ���������⣺��n�ܴ��ʱ�������int long long �����涼�п��ܲ�����������Բ����ַ������洢���֡�

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

	while (!Increment(number))//�ڱ�ʾ���ֵ��ַ����ϼ�1��ȷ��������nλ����ʹ��strcmp()��ʱ�临�Ӷ�Ϊo��n��,�ú������죬ʱ�临�Ӷ�ΪO��1��
		PrintNumber(number);//��ӡҪ���ϴ�ӡϰ�ߣ�089ҪΪ89��
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