#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream fin;
	string input;
	
	fin.open(argv[1]);
	input = argv[2];
	
	int states[1001][1001] = {0};
	int finalSts[1001];
	int start;
	int accept[1001] = {0};
	int numOfAccept = 0;
	string type;
	int first;
	int from[1001] = {0};
	char tran[1001];
	int to[1001] = {0};
	int numOfTran = 0;
	string line;
	
	fin >> type;
	
	while (fin)
	{
		if (type == "state")
		{
			fin >> first;
			
			getline(fin, line);
			
			if (line == "\tstart")
			{
				start = first;
			}
			else if (line == "\taccept")
			{
				accept[first] = 1;
				numOfAccept++;
			}
			else if (line == "\tacceptstart" || line == "\tstart\taccept")
			{
				start = first;
				accept[first] = 1;
				numOfAccept++;
			}
		}
		else if (type == "transition")
		{
			fin >> from[numOfTran];
			fin >> tran[numOfTran];
			fin >> to[numOfTran];
			
			numOfTran++;
		}
		
		fin >> type;
	}
	
	int row;
	int i;
	
	states[0][start] = 1;
	
	int lgth = input.length();
	
	for (row = 0; input.length() > 0 && row < 1001; row++)
	{
		for (i = 0; i < numOfTran; i++)
		{
			if (states[row][from[i]] == 1 && tran[i] == input.at(0))
			{
				states[row+1][to[i]] = 1;
			}
			
		}
		
		input = input.substr(1);
	}
	
	int numOfFnlSts = 0;
	
	for (i = 0; i < 1001; i++)
	{
		if (states[lgth][i] == 1 && accept[i] == 1)
		{
			finalSts[numOfFnlSts] = i;
			
			numOfFnlSts++;
		}
	}
	
	if (numOfFnlSts == 0)
	{
		for (i = 0; i < 1001; i++)
		{
			if (states[lgth][i] == 1)
			{
				finalSts[numOfFnlSts] = i;
				
				numOfFnlSts++;
			}
		}
		
		cout << "reject";
		
		for (i = 0; i < numOfFnlSts; i++)
		{
			cout << " " << finalSts[i];
		}
	}
	else
	{
		cout << "accept";
		
		for (i = 0; i < numOfFnlSts; i++)
		{
			cout << " " << finalSts[i];
		}
	}
	
	cout << "\n";
	
	return 0;
}
