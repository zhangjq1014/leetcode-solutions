#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
/*
void find_word_ladder(vector<string> & wordList, vector< vector<int> > difference, int start, string & endWord)
{
}
*/


void read_path ( vector< vector<int> > & pred, 
					int target,
						int srv,
							vector <int> & result) {

	if (srv == target) {

		for (int j = 0; j < result.size(); j++){
			cout << result [j] << ",";
		}
		cout << endl;
		return;
	}
	
	for ( int i = 0; i < pred[target].size(); i++) {
		result.push_back(target);
		read_path(pred, pred[target][i], srv, result);
		result.pop_back();
	}

}
int main()
{
	string beginWord("hot");
	string endWord("dog");
	vector<string> wordlist;
	wordlist.push_back(beginWord);
	wordlist.push_back("cog");
	wordlist.push_back("tot");
	wordlist.push_back("hog");
	wordlist.push_back("hop");
	wordlist.push_back("pot");
	wordlist.push_back("dot");
	wordlist.push_back(endWord);

	//wordlist加上beginWord构建图形
	vector < vector <int> > graph (wordlist.size());
	
	for(int i = 0; i < wordlist.size(); i ++)
	{
		for(int j = i + 1; j < wordlist.size(); j ++ )
		{
			int difference_numbers = 0;
			for(int index = 0; index < beginWord.size(); index ++)
			{
				if(wordlist[i][index] != wordlist[j][index])
					difference_numbers += 1;
			}
			if(difference_numbers == 1){
				graph[j].push_back(i);
				graph[i].push_back(j);
			}
		}
	}

	for(int i = 0; i < graph.size(); i++){
		cout << i << ":" ;

		for (int j = 0; j < graph[i].size(); j++){
			cout << graph[i][j] << ",";
		}
		cout << endl;
	}
	
	//bfs_algorithm	
	vector < vector<int> > pred (wordlist.size());
	vector <int> dist (wordlist.size(), -1);
	dist[0] = 0;

	queue <int> visitQueue;
	visitQueue.push(0);

	while(!visitQueue.empty()) {
		int v = visitQueue.front();
		visitQueue.pop(); 

		for (int i = 0; i < graph[v].size(); i++) {
			int w = graph[v][i];

			if (dist[w] == -1) {
				visitQueue.push(w);
				dist[w] = dist[v] + 1;
			}

				if (dist[w] == dist[v] + 1) {
					pred[w].push_back(v);
			}
		}

	}

	for(int i = 0; i < pred.size(); i++){
		cout << i << ":" ;

		for (int j = 0; j < pred[i].size(); j++){
			cout << pred[i][j] << ",";
		}
		cout << endl;
	}
	
	cout << endl;
	vector <int> result;
	read_path(pred, graph.size() - 1, 0, result);

	return 0;
}





		
