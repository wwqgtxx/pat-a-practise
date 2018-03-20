#include<cstdio>
#include<bits/stdc++.h>

std::vector<std::vector<char>> g;
std::vector<std::vector<int>> g2;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int v,e;
	std::cin >> v >> e;
	g.resize(v+1,std::vector<char>(v+1));
	g2.resize(v+1);
	int a,b;
	for(int i=0;i<e;i++){
		std::cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
		g2[a].emplace_back(b);
		g2[b].emplace_back(a);
	}
	int m;
	std::cin >> m;
	std::vector<int> vec;
	std::vector<char> has(v+1);
	int k;
	std::stringstream ss;
	for(int i=0;i<m;i++){
		std::cin >> k;
		vec.clear();
		vec.resize(k);
		std::fill(has.begin(),has.end(),0);
		for(int j=0;j<k;j++){
			std::cin >> vec[j];
			has[vec[j]] = 1;
		}
		if(vec.size() == 1){
			if(g2[vec[0]].size() == 0){
				ss << "Yes" << std::endl;
			}else{
				ss << "Not Maximal" << std::endl;
			}
		}else{
			bool isClique = true;
			for(int j=0;j<k;j++){
				for(int jj=j+1;jj<k;jj++){
					if(g[vec[j]][vec[jj]] == 0){
						isClique = false;
						break;
					}
				}
			}
			if(isClique){
				bool isMaximal = true;
				for(auto &item: vec){
					for(auto &item2:g2[item]){
						if(has[item2] == 0){
							bool ok = true;
							for(auto &item3: vec){
								if(g[item2][item3] == 0){
									ok = false;
									break;
								}
							}
							if(ok){
								isMaximal = false;
								break;
							}
						}
					}
					if(!isMaximal){
						break;
					}
				}
				if(isMaximal){
					ss << "Yes" << std::endl;
				}else{
					ss << "Not Maximal" << std::endl;
				}
				
			}else{
				ss << "Not a Clique" << std::endl;
			}
		}
		
	}
	std::cout << ss.str();
}

/*
7-3 Maximal Clique£¨25 ·Ö£©
A clique is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))

Now it is your job to judge if a given subset of vertices can form a maximal clique.

Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers Nv (¡Ü 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.

After the graph, there is another positive integer M (¡Ü 100). Then M lines of query follow, each first gives a positive number K (¡Ü Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.

Output Specification:

For each of the M queries, print in a line Yes if the given subset of vertices can form a maximal clique; or if it is a clique but not a maximal clique, print Not Maximal; or if it is not a clique at all, print Not a Clique.

Sample Input:

8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
Sample Output:

Yes
Yes
Yes
Yes
Not Maximal
Not a Clique
*/
