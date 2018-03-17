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
    double totalLength = D; //����ܵ�·�̳���  
    station.resize(N);  
    for(int i=0;i<N;i++){  
        std::cin>> station[i].second >> station[i].first;  
    }  
    std::sort(station.begin(),station.end());  
    if(station[0].first!=0){     //����㣬���վû�м���վ���ǾͲ���ǰ��  
        std::cout << "The maximum travel distance = 0.00";  
        return 0;  
    }  
    int loc = 0;    //��ǵ�ǰ�ڵڼ�������վ  
    double currentOil = 0;      //��ǵ�ǰ������ʣ�¶�����  
    while(D>0){     //��ʾ���յ�ľ���  
        double maxLength = station[loc].first+C*A;       //��ǰվ�����ܵ����Χ  
        if(station[loc+1].first>maxLength || (loc==N-1 && maxLength<totalLength)){       //���δ�����յ�Ͳ���ǰ���͵�����ǰһվ�㲻��ǰ����2�����  
            std::cout << "The maximum travel distance = " 
			          << std::fixed << std::setprecision(2) << maxLength;  
            return 0;  
        }  
        double minPrice = station[loc].second;  
        int minLoc = loc;  
        int findIt = 0;     //������ܵ���ķ�Χ���Ƿ��ҵ��ȵ�ǰ����վ�����˵ļ���վ  
        for(int i=loc+1;station[i].first<=maxLength && i<N;i++){ //�ҵ���Χ�ڵĵ�һ��С�ڵ��ڿ�ʼλ��ֵ  
            if(station[i].second<minPrice){  
                minPrice = station[i].second;  
                minLoc = i;  
                findIt = 1;  
                break;  
            }  
        }  
        if(D<A*C && (station[minLoc].first>=totalLength || findIt==0)){  //���������վ�����ܵ����յ��Ҹü���վ���յ�֮��û�и����˵ļ���վ  
            minTotalprice += ((double)((totalLength-station[loc].first)/A)-currentOil)*station[loc].second;  
            std::cout << std::fixed << std::setprecision(2)<< minTotalprice;  
            return 0;  
        }  
        if(findIt==1){  
            minTotalprice += (double)((station[minLoc].first-station[loc].first-currentOil*A)/A)*station[loc].second;  
            D = totalLength-station[minLoc].first;  
            loc = minLoc;  
            currentOil = 0;  
        }else{      //��Χ�ڵĶ���ʼ��վ�����ҷ�Χ�ڵ���Сվ����ʼ��վ�����Ϳ�����վ  
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
̰�Ĳ���
��distance=0�ĵط������м���վ
��distance=D�ĵط����յ㣩���������͵�ʣ��������Ϊ0
����ĳһվΪA���������A�����ͣ�����ʻ����Զ����ΪmaxDis=Cmax*Davg
ʹ��leftGas��������¼ʣ������
��A.distance~A.distance+maxDis֮��Ѱ�ҵ�һ����A���˵�վ������ҵ�����ΪB������A�Ӹպ���ʻ��B������
��û�з������1��վ���������յ㣬����A�Ӹպÿ�����ʻ���յ������
��û�з������1�����2��վ������һ��վC��C.price����Ӧ��Χ����С����A�����ͣ���ʻ��C
�������1��2��3���κ�һ�����������ʻ��������ΪA.distance+maxDis
*/ 

/*
1033. To Fill or Not to Fill (25)
ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
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
  2 ������
  3       �����ԣ�������˼·��̰�ģ�Ҳ����Ҫ�þ������ٵ�Ǯ��Ҫȥ������Զ�ĵط���
  4       ��ô��������̰�ĵ���Ŀ����ôȥ˼���أ�
  5       ���ȣ�����������������ZJU��ţ���ᵽ��һ�㣬����̰�ĵ���Ŀ�����������������Լ�ȥ���һ�飬���������п��ܻ�����Ǵ�������������
  6       ��ô�����Ǿ�һ������һ����������ɣ�
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
 22 �Ȼ���ͼ�ٿ�
 23 1����㣬�϶���Ҫ���͵ģ���Ȼ�ܶ��ܲ���������ô���������ˡ����Ӷ��٣�
 24 �����������۲�һ�£��������֮����Զ����600��Ҳ����˵�������������������������Ļ���[0,600]�����ҿ��Դﵽ��·�̷�Χ��
 25 ���ˣ���ô������ֻ��Ҫ�������Χ�ڵ��������̰�Ĳ��ԣ�
 26 ��㴦���ͼ���7.1�����֮�������ĵ�һ������վA�ͼ�С��7.1����ô����A֮�󲻹���ʲô��������Ƕ�Ӧ�ü��ͣ�����Ҫ�Ӷ��٣�������ȷ������
 27 ��Ϊ�����ڵ�ǰ״̬�£����������̰�����ġ�
 28 2��ͨ��1�ķ���������ѡ���˼���վB������ֵ��ǿ�����ǣ����������A�ӵ����ܵ�Bʱ�����������״̬��
 29 ��ʱ������վ����B�㣬B����Զ�ܵ�750(150+600������������θ���̰���㷨������̰���ľ����أ�
 30 B�����ͼ���7����Ȼ��750֮ǰ�ļ���վ�кܶ࣬�ͼ��б�7С�ģ���7��ģ�Ҳ�е���7�ġ���ô��̰�����㣬һ������ɵ��ȥѡ��һ���ͼ۹�ģ���C��E��
 31 ��Ϊ����ȫ���Ե����7С�ļ���վ�ټ��ͣ�ΪʲôҪȥ��7��ļ���վ�����أ�
 32 so������ѡ����D���ͼ�6.85�������ң�D���ͼ۱ȵ�ǰ�ı��ˣ��������Ǽ���ֻҪ����B����>D�ͺã��Ӷ��˾Ͳ�������̰���ı����ˣ�
 33 3������D֮�󣬿���˵�ǱȽϿ��ĵģ���Ϊ����[300,300+600]�ķ�Χ�����������˵ģ���ʱ���Ӹ�����ʱ������Ϊ������˵ģ����ԣ�Ϊ��̰�����������
 34 ������֮����Զ���Ե�900��300+600������ô����900֮ǰ�����ǻ�����E��F����F�ͼ۽�EҪ����һЩ����ˣ�Ϊ�˵���Ŀ�ĵأ����ǲ��ò���F���͡�
 35 4����֮ǰ�����������ͬ���ǣ���Σ����ǵ�Ŀ�ĵص�ʱ�򣬻�������ʣ��ģ�600-300<600��������ʣ����͹���300���������ܵ�900����
 36 ��ô��������F�Ӷ��ٵ����أ�
 37 վ��F��λ�ã����ǿ�ʼ˼��������400��һ������վG�������ͼ�Ҫ7.3���ӵ��أ���ô��
 38 ���ǣ�����F�����ˣ�����Ҳֻ���ܵ�1200��600+600�������ԣ�û�취��Ϊ�˵���Ŀ�ĵأ����ǲ��ò���G�ӣ����ǣ�����Ҫע�⣬��ΪG��F���ͼ�Ҫ��
 39 ���ԣ�Ϊ��̰�����ǻ���F���ͼ����������ܹ��ﵽĿ�ĵص�ǰ���£��������ڹ�ĵط��ټӵ��ͣ��ڱ��˵ĵط���ӵ��͡���̰����
 40 5������G֮�󣬼����˴�ʱ���仹ʣ�µ��͹���200��Ҳ����˵�������ڹ�ĵĵط�Gֻ��Ҫ��50��1250-1000-200�����ܵ�H���ɣ���ΪH���ͼ�������ˣ�û��֮һ����
 41 ��[1000,1000+600]�ķ�Χ�ڣ�������˵ģ�so���������ߵ���H
 42 6���ߵ���H֮�󣬾Ͳ��ö����ˣ�H֮��Ҳû�м���վ�ˣ����Ҽ����ܹ���Ŀ�ĵ�I�������͹��ˡ�
 43 
 44 ���������Ϸ���֮��Ҫ��ʼ�����ϵĸ���������г��󣬼���������������ࣨҪ�������е�����������ң�����̰�ĵ�˼��ȥ���ǲ�ͬ������£��������־���
 45 ���ڵ�ǰ����վ��������վ���������
 46 ���1��600�׷�Χ�ڣ���Ŀ�ĵء�������ǡ���ܵ�Ŀ�ĵص�����                                                                  ��6��
 47 ���2��600�׷�Χ��û�м���վ�������ͼ۶�󡪡������������ܶ�Զ���Զ                                                
 48 ���3��600�׷�Χ���м���վ��                                                                         
 49                             a:�бȵ�ǰ����վ���ͼ۸����˵ļ���վ�����ӵ�ǡ���ܵ��Ǹ��������վ������              ��1����2����5��
 50                             ��ע��1������ж�����˵ģ�����Ҫ��ѡȡ������Ǹ�������������˵��Ǹ���2�����ܻ�����ʣ�ࣩ
 51                             b:û�бȵ�ǰ����վ���ͼ۸����˵ļ���վ����������Ȼ����600��Χ���ҵ�����˵ļ���վ����             ��3����4��
 52 
 53 �������ڶ������ݣ�
 54 Sample Input 2:
 55 50 1300 12 2
 56 7.10 0
 57 7.00 600
 58 
 59 Sample Output 2:
 60 The maximum travel distance = 1200.00
 61 
 62 �������̣�
 63 1��600�ķ�Χ�ڣ�����600�����м���վ�����ұȵ�ǰ���ͼ�Ҫ���ˣ���ˣ��������3��a���ʣ����Ǽӵ�ǡ���ܵ�������Ƚ�������ǣ�ֻ�м�����ǡ���ܵ���
 64 ע�⣬���ﲻ�ܹ�Ϊ���2����Ϊ���2�Ľ����Ӧ��һ���޷�����Ŀ�ĵأ����ԣ���ǰ��״̬���޷��жϳ��ܲ��ܵ���Ŀ�ĵأ�
 65 2��600��Χ�ڣ�û�м���վ�������������2�����ܶ�Զ�ܶ�Զ����Ϊ�Ѿ��޷�����Ŀ�ĵ��ˣ�ֻ�ܾ����ܵ��ܸ�Զ
 66 
 67 �������ϵķ������Ϳ��Կ�ʼ���Ե�д������
 68 ���������Ż���
 69     1�����û�м���վ
 70     2����㼴�յ�
 71 
 72 ��Ҫ�ļ����ؼ��㣬����˵����ʻ�Ĺ�������Ҫ��¼Щʲô��Ϣ��
 73     1�����ﵱǰ����վ������������Ϊ����Ҫ���㻹��Ҫ�Ӷ����ͣ����ԣ��ܹ���Ҫ�����������е�����=�ڵ�ǰ����վҪ�ӵ�����
 74  
 */