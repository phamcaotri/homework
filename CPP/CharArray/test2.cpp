#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
	string input;
	cout << "Input the string of characters: ";
	getline(cin, input);
	
	if (input.length() == 0) 
	{
		cout << "Chuoi rong." << endl;
	}
	else 
	{
		string output;
		int start = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
			{
				for (int j = i - 1; j >= start; j--)
				{
					output += input[j];
				}
				output += ' ';
				start = i + 1;
			}
			else if (i == input.length() - 1)
			{
				for (int j = i; j >= start; j--)
				{
					output += input[j];
				}
			}
		}
		cout << output << endl;
	}
	return 0;
}