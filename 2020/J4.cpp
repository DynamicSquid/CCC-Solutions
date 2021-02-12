#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string T, S;
	cin >> T >> S;

	for (size_t a = 0; a < S.length(); ++a)
	{
		if (T.find(S) != string::npos) 
		{
			printf("yes");
			return 0;
		}

		S += S[0];
		S.erase(0, 1);
	}

	printf("no");
}