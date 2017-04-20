#include<iostream>
#include<string>
using namespace std;
//题目：实现两个带有符号的大数相加问题
//输入：a，b;
//输出：sum

char *&  Bn_unsigned_ADD(char*first, char* second);
char *&  Bn_unsigned_Sub(char*first, char* second);//da-xiao
char sign = '+';
char* bigNumberAdd()
{
	
	string number;
	getline(cin,number);
	char *numchar = (char *)number.c_str();
	int length = strlen(numchar);
	int signcount=0;
	for (int i = 0; i < length; i++)
	{
		if (numchar[i] == '-')
			signcount++;
	}
	char *first = strtok(numchar, ",-");
	char *second = strtok(NULL, ",-");
	char * result=nullptr;
	if (signcount>2 || signcount<0)
		return NULL;
	else if (signcount == 2)//2负数相加
	{
	    sign = '-';
		result = Bn_unsigned_ADD(first, second);
	}
	else if (signcount == 0)
	{
		result = Bn_unsigned_ADD(first, second);
	}
	else if (signcount == 1 && numchar[0] == '-')
	{
		if (strlen(first) < strlen(second) || (strlen(first) == strlen(second) && strcmp(first, second) <= 0))//
		{
			result = Bn_unsigned_Sub(second, first);
		}
		else
		{
			sign = '-';
			result = Bn_unsigned_Sub(first,second);
		}
	}
	else
	{
		if (strlen(first) > strlen(second) || (strlen(first) == strlen(second) && strcmp(first, second) >= 0))//
		{
			result = Bn_unsigned_Sub(first, second);
		}
		else
		{
			sign = '-';
			result = Bn_unsigned_Sub(second, first);			
		}
	}
	return result;
}
char *&  Bn_unsigned_ADD(char*first, char* second)
{
	
	int firstLen = strlen(first);
	int secondLen = strlen(second);
	int resultLen = (firstLen >= secondLen) ? firstLen + 1 : secondLen + 1;
	char *result=new char[resultLen+1];
	memset(result, '0', resultLen);
	result[resultLen] = '\0';
	int takeOver = 0;
	int k = resultLen - 1;
	int i = firstLen - 1;
	int j = secondLen - 1;
	while( i >= 0 && j >= 0)
	{
		result[k] = first[i] + second[j] - '0' + takeOver;
		if (result[k] > '9')
		{
			result[k] -= 10;
			takeOver = 1;
		}
		else
			takeOver = 0;
		k--;i--; j--;
	}
	while (i >= 0)
	{
		result[k] = first[i] + takeOver;
		if (result[k] > '9')
		{
			result[k] -= 10;
			takeOver = 1;
		}
		else
			takeOver = 0;
		k--; i--;
	}
	while (j >= 0)
	{
		result[k] = second[j] + takeOver;
		if (result[k] > '9')
		{
			result[k] -= 10;
			takeOver = 1;
		}
		else
			takeOver = 0;
		k--; j--;
	}
	if (k == 0)
		result[k] = takeOver + '0';
	return result;
}

char *&  Bn_unsigned_Sub(char*first, char* second)//da-xiao
{

	int firstLen = strlen(first);
	int secondLen = strlen(second);
	int resultLen = firstLen;
	char *result = new char[resultLen+1];
	memset(result, '0', resultLen);
	result[resultLen] = '\0';
	int takeOver = 0;
	int k = resultLen - 1,i = firstLen - 1,j = secondLen - 1;
	
	while (i >= 0 && j >= 0)
	{
		result[k] = first[i] - second[j] + '0' + takeOver;
		if (result[k] < '0')
		{
			result[k] += 10;
			takeOver = -1;
		}
		else
			takeOver = 0;
		k--; i--; j--;
	}
	while (i >= 0)
	{
		result[k] = first[i]  + takeOver;
		if (result[k] < '0')
		{
			result[k] += 10;
			takeOver = -1;
		}
		else
			takeOver = 0;
		k--; i--;
	}
	while (j >= 0)
	{
		result[k] = second[j]  + takeOver;
		if (result[k] < '0')
		{
			result[k] += 10;
			takeOver = -1;
		}
		else
			takeOver = 0;
		k--; j--;
	}
	/*if (k == 0)
		result[k] = takeOver + '0';*/
	return result;
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
int main()
{
	char *sum = bigNumberAdd();
	if (sign == '-')
		cout << sign;
	 PrintNumber(sum);
	 delete[] sum;
	return 0;
}