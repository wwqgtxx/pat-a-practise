#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <iomanip>  

int main()  
{  
	std::vector<std::pair<double,double>> station;  
	int C,D,A,N;  
	double minTotalprice = 0;  
    std::cin >> C >> D >> A >> N;  
    double totalLength = D; //标记总的路程长度  
    station.resize(N);  
    for(int i=0;i<N;i++){  
        std::cin>> station[i].second >> station[i].first;  
    }  
    std::sort(station.begin(),station.end());  
    if(station[0].first!=0){     //特殊点，起点站没有加油站，那就不能前进  
        std::cout << "The maximum travel distance = 0.00";  
        return 0;  
    }  
    int loc = 0;    //标记当前在第几个加油站  
    double currentOil = 0;      //标记当前油箱中剩下多少油  
    while(D>0){     //表示离终点的距离  
        double maxLength = station[loc].first+C*A;       //当前站点能跑的最大范围  
        if(station[loc+1].first>maxLength || (loc==N-1 && maxLength<totalLength)){       //如果未到达终点就不能前进和到达终前一站点不能前进的2种情况  
            std::cout << "The maximum travel distance = " 
			          << std::fixed << std::setprecision(2) << maxLength;  
            return 0;  
        }  
        double minPrice = station[loc].second;  
        int minLoc = loc;  
        int findIt = 0;     //标记在能到达的范围内是否找到比当前加油站更便宜的加油站  
        for(int i=loc+1;station[i].first<=maxLength && i<N;i++){ //找到范围内的第一个小于等于开始位的值  
            if(station[i].second<minPrice){  
                minPrice = station[i].second;  
                minLoc = i;  
                findIt = 1;  
                break;  
            }  
        }  
        if(D<A*C && (station[minLoc].first>=totalLength || findIt==0)){  //从这个加油站出发能到达终点且该加油站到终点之间没有更便宜的加油站  
            minTotalprice += ((double)((totalLength-station[loc].first)/A)-currentOil)*station[loc].second;  
            std::cout << std::fixed << std::setprecision(2)<< minTotalprice;  
            return 0;  
        }  
        if(findIt==1){  
            minTotalprice += (double)((station[minLoc].first-station[loc].first-currentOil*A)/A)*station[loc].second;  
            D = totalLength-station[minLoc].first;  
            loc = minLoc;  
            currentOil = 0;  
        }else{      //范围内的都比始发站大，则找范围内的最小站，从始发站灌满油开到该站  
            double tempPrice = station[loc+1].second,tempLoc = loc+1;  
            for(int i=loc+1;station[i].first<=maxLength && i<N;i++){  
                if(station[i].second<tempPrice){  
                    tempPrice = station[i].second;  
                    tempLoc = i;  
                }  
            }  
            D =totalLength - station[tempLoc].first;  
            minTotalprice += station[loc].second*(C-currentOil);  
            currentOil = C-(double)((station[tempLoc].first-station[loc].first)/A);  
            loc = tempLoc;  
        }  
    }  
    return 0;  
}  

/*
贪心策略
在distance=0的地方必须有加油站
在distance=D的地方（终点），油箱里油的剩余量必须为0
假设某一站为A，则如果在A加满油，能行驶的最远距离为maxDis=Cmax*Davg
使用leftGas变量来记录剩余油量
在A.distance~A.distance+maxDis之间寻找第一个比A便宜的站，如果找到，记为B，则在A加刚好行驶至B的油量
若没有符合情况1的站，但是有终点，则在A加刚好可以行驶至终点的油量
若没有符合情况1和情况2的站，则找一个站C，C.price在相应范围内最小，在A加满油，行驶至C
不是情况1、2、3的任何一种情况，则行驶的最大距离为A.distance+maxDis
*/ 

/*
1033. To Fill or Not to Fill (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
ZHANG, Guochuan
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/


/*
  2 分析：
  3       很明显，这道题的思路是贪心，也就是要用尽可能少的钱，要去尽可能远的地方。
  4       那么，像这种贪心的题目，怎么去思考呢？
  5       首先，今天听到戴龙翱（ZJU大牛）提到的一点，对于贪心的题目，测试样例，必须自己去体会一遍，这样，很有可能会给我们带来不少启发。
  6       那么，我们就一起来过一遍测试样例吧：
  7             
  8 Sample Input 1:
  9 50 1300 12 8
 10 6.00 1250
 11 7.00 600
 12 7.00 150
 13 7.10 0
 14 7.20 200
 15 7.50 400
 16 7.30 1000
 17 6.85 300
 18 
 19 Sample Output 1:
 20 749.17
 21 
 22 先画个图再看
 23 1：起点，肯定是要加油的，不然跑都跑不起来，那么，问题来了——加多少？
 24 让我们先来观察一下，油箱加满之后，最远能跑600；也就是说，如果我现在在起点把油箱加满的话，[0,600]都是我可以达到的路程范围；
 25 好了，那么，我们只需要看这个范围内的如何做出贪心策略；
 26 起点处的油价是7.1，如果之后遇到的第一个加油站A油价小于7.1，那么，在A之后不管是什么情况，我们都应该加油（至于要加多少，还不能确定），
 27 因为至少在当前状态下，这样做是最“贪婪”的。
 28 2：通过1的分析，我们选择了加油站B。而且值得强调的是，我们在起点A加的油跑到B时是正好用完的状态。
 29 这时，我们站在了B点，B点最远能到750(150+600），我们又如何根据贪心算法来做出贪婪的决策呢？
 30 B处的油价是7，显然，750之前的加油站有很多，油价有比7小的，比7大的，也有等于7的。那么，贪婪的你，一定不会傻到去选择一个油价贵的（如C、E）
 31 因为我完全可以到达比7小的加油站再加油，为什么要去比7大的加油站加油呢？
 32 so，我们选择了D（油价6.85），而且，D的油价比当前的便宜，所以我们加油只要够从B——>D就好，加多了就不符合我贪婪的本性了！
 33 3：到了D之后，可以说是比较开心的，因为在他[300,300+600]的范围内这价是最便宜的，此时不加更待何时！？因为是最便宜的，所以，为了贪，必须加满！
 34 加满了之后，最远可以到900（300+600），那么，在900之前，我们会遇到E、F，且F油价较E要便宜一些，因此，为了到达目的地，我们不得不到F加油。
 35 4：和之前的情况有所不同的是，这次，我们到目的地的时候，还是有油剩余的（600-300<600），而且剩余的油够跑300（即可以跑到900）。
 36 那么，我们在F加多少的油呢？
 37 站在F的位置，我们开始思考。距离400有一个加油站G，可是油价要7.3，坑爹呢！这么贵！
 38 可是，就算F加满了，我们也只能跑到1200（600+600），所以，没办法，为了到达目的地，我们不得不到G加，但是，这里要注意，因为G比F的油价要贵，
 39 所以，为了贪，我们会在F把油加满，（在能够达到目的地的前提下，尽可能在贵的地方少加点油，在便宜的地方多加点油——贪）；
 40 5：到了G之后，计算了此时邮箱还剩下的油狗刨200，也就是说，我们在贵的的地方G只需要加50（1250-1000-200），能到H即可，因为H的油价是最便宜（没有之一），
 41 在[1000,1000+600]的范围内，是最便宜的，so，就这样走到了H
 42 6：走到了H之后，就不用多想了，H之后也没有加油站了，而且加满能够到目的地I的油量就够了。
 43 
 44 经过了以上分析之后，要开始对以上的各个情况进行抽象，即把遇到的情况分类（要包括所有的情况），并且，基于贪心的思想去考虑不同的情况下，做出何种决策
 45 处在当前加油站（起点加油站）的情况下
 46 情况1：600米范围内，有目的地——计算恰好能到目的地的油量                                                                  【6】
 47 情况2：600米范围内没有加油站，无论油价多贵——加满——能跑多远算多远                                                
 48 情况3：600米范围内有加油站：                                                                         
 49                             a:有比当前加油站的油价更便宜的加油站——加到恰好能到那个最近的油站的油量              【1】【2】【5】
 50                             （注：1、如果有多个便宜的，还是要先选取最近的那个，而不是最便宜的那个；2、可能还有油剩余）
 51                             b:没有比当前加油站的油价更便宜的加油站——加满，然后在600范围内找到最便宜的加油站加油             【3】【4】
 52 
 53 再来看第二组数据：
 54 Sample Input 2:
 55 50 1300 12 2
 56 7.10 0
 57 7.00 600
 58 
 59 Sample Output 2:
 60 The maximum travel distance = 1200.00
 61 
 62 分析过程：
 63 1：600的范围内（包括600），有加油站，而且比当前的油价要便宜，因此，属于情况3—a，故，我们加到恰好能到，这里比较特殊的是，只有加满才恰好能到，
 64 注意，这里不能归为情况2，因为情况2的结果对应着一定无法到达目的地，所以，当前的状态还无法判断出能不能到达目的地；
 65 2：600范围内，没有加油站，这里属于情况2，能跑多远跑多远，因为已经无法到达目的地了，只能尽可能地跑更远
 66 
 67 经过以上的分析，就可以开始尝试地写代码了
 68 特殊的情况优化：
 69     1：起点没有加油站
 70     2：起点即终点
 71 
 72 主要的几个关键点，或者说是行驶的过程中需要记录些什么信息：
 73     1：到达当前加油站的油量——因为，你要计算还需要加多少油，所以，总共需要的油量—现有的油量=在当前加油站要加的油量
 74  
 */