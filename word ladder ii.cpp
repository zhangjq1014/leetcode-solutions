#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
/*
void find_word_ladder(vector<string> & wordList, vector< vector<int> > difference, int start, string & endWord)
{
}
*/
int main()
{
	string beginWord("hit");
	string endWord("cog");
	vector<string> wordList;
	wordList.push_back("hot");
	wordList.push_back("dot");
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");

	//wordList相互差异个数矩阵
	int length = beginWord.size();
	vector< vector<int> > difference (wordList.size(), vector<int>(wordList.size(), 0));
	for(int i = 0; i < wordList.size(); i ++)
	{
		for(int j = i + 1; j < wordList.size(); j ++ )
		{
			int difference_numbers = 0;
			for(int index = 0; index < length; index ++)
			{
				if(wordList[i][index] != wordList[j][index])
					difference_numbers += 1;
			}
			difference[i][j] = difference_numbers;
			difference[j][i] = difference_numbers;
		}
	}


	//wordList中与begin和end的差异个数
	vector< vector<int> > differences_to_beginWord(length + 1);
	vector<int> differences_to_endWord;
	for(int i = 0; i < wordList.size(); i++)
	{
		int difference_begin = 0, 
				difference_end = 0;

		for(int index = 0; index < length; index ++)
		{
			if(wordList[i][index] != endWord[index])
				difference_end += 1;
			if(wordList[i][index] != beginWord[index])
				difference_begin += 1;
		}
		differences_to_endWord.push_back(difference_end);
		differences_to_beginWord [difference_begin].push_back(i);
	}

	vector<string> result;
	result.push_back(beginWord);
		
	//构建
	for(int i = 0; i < differences_to_beginWord[1].size(); i++)
	{
		result.push_back(wordList[differences_to_beginWord[1][i]]);
		int temp_location = 2;
		int from = differences_to_beginWord[1][i];
		vector<int> location_start (length + 1);
		while(1)
		{
			if (temp_location == 2 && location_start[2] == differences_to_beginWord[2].size())
				break;
			int finded = 0;
			for(int j = location_start[temp_location]; j < differences_to_beginWord[temp_location].size(); j++)
			{
				int to = differences_to_beginWord[temp_location][j];
				if( difference[to][from] == 1)
				{
					result.push_back(wordList[to]);
					location_start[temp_location] = j + 1; 
					temp_location += 1;
					from  = to;
					if(differences_to_endWord[to] == 1)
					{
						//cout << result;
						break;
					}
					finded = 1;
					break;
				}
			}
				if(finded == 1 && temp_location < length + 1)
					continue;
				else
				{
					for(int ii = 0; ii < result.size(); ii++)
						cout << result[ii] << "," << location_start[ii] << " ";
					cout << endl;
					getchar();
					if(temp_location > length)
					{
						result.pop_back();
						temp_location -= 1;
						location_start[temp_location] = 0;
					}


					result.pop_back();
					location_start[temp_location] = 0;
					temp_location -= 1;	
					from = differences_to_beginWord[temp_location-1][location_start[temp_location-1]];
				}
		}
	}
	return 0;
}
