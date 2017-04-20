#include<iostream>
#include<cstring>
using namespace std;

//��Ŀ����������n����ӡ1��nλʮ����������������
//˼·������һ���������⣺��n�ܴ��ʱ�������int long long �����涼�п��ܲ�����������Բ����ַ������洢���֡�
//����ȫ���еݹ�


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