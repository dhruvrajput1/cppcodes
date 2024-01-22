#include <iostream>
using namespace std;

// write a program to check if two strings are permutaions of each other or not;

bool isPermutaion(char *a, char *b)
{
	int freq1[26] = {0};
	for (int i = 0; a[i] != '\0'; i++)
	{
		char ch = a[i];
		int index = ch - 'a';
		freq1[index] = freq1[index] + 1;
	}
	int freq2[26] = {0};
	for (int i = 0; b[i] != '\0'; i++)
	{
		char ch = b[i];
		int index = ch - 'a';
		freq2[index] = freq2[index] + 1;
	}

	for (int i = 0; i <= 25; i++)
	{
		if (freq1[i] != freq2[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	char a[100];
	char b[100];
	cin.getline(a, 100);
	cin.getline(b, 100);

	

	if (isPermutaion(a, b))
	{
		cout << "Yes Permutaions" << endl;
	}
	else
	{
		cout << "Not Permutaions" << endl;
	}

	return 0;
}