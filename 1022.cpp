#include<map>
#include<memory>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>

typedef std::map<std::string,std::set<std::string>> map_t;
map_t title_map;
map_t author_map;
map_t key_words_map;
map_t publisher_map;
map_t year_map;

int main(){
	std::string str;
	int n;
	std::cin >> n;
	std::getline(std::cin,str);
	std::string id;
	std::stringstream ss;
	for(int i=0;i<n;i++){
		std::getline(std::cin,id);
		
		std::getline(std::cin,str);
		title_map[str].emplace(id);
		
		std::getline(std::cin,str);
		author_map[str].emplace(id);
		
		std::getline(std::cin,str);
		ss.str(str);
		ss.clear();
		while(ss >> str){
			key_words_map[str].emplace(id);
		}
		
		std::getline(std::cin,str);
		publisher_map[str].emplace(id);
		
		std::getline(std::cin,str);
		year_map[str].emplace(id);
	}
	ss.str("");
	ss.clear();
	
	int m;
	std::cin >> m;
	std::getline(std::cin,str);
	for(int i=0;i<m;i++){
		std::getline(std::cin,str);
		id = str.substr(3);
//		std::cerr << id << std::endl;
		map_t *map;
		switch(str[0]){
			case '1':{
				map = &title_map;
				break;
			}
			case '2':{
				map = &author_map;
				break;
			}
			case '3':{
				map = &key_words_map;
				break;
			}
			case '4':{
				map = &publisher_map;
				break;
			}
			case '5':{
				map = &year_map;
				break;
			}
		}
		ss << str << std::endl;
		auto it = map->find(id);
		if(it == map->end()){
			ss << "Not Found" << std::endl;
		}else{
			for(auto &s:it->second){
				ss << s << std::endl;
			}
		}
		
	}
	std::cout << ss.str();
	
	return 0;
}
/*
1022. Digital Library (30)
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.

Sample Input:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
*/
