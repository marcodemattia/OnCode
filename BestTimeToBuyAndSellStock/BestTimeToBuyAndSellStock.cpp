#include <iostream>
#include <vector>

/**
 * The maximum profit occurs for the biggest difference between consecutive min and max.
 * Obviously, the min must be after the max for the profit to happen. We store min, max
 * and a tentative tempMin that contains the new potential min. If there will be a new
 * raise such that price - tempMin is higher than the current max - min we swap the old
 * min and max with the new values. Whenever the price exceeds the current max we also
 * replace it since it is still after the min.
 */

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {

    if (prices.size() == 0) return 0;
    
    int min = prices[0];
    int max = prices[0];
    int tempMin = prices[0];
    
    for (int i=0; i<prices.size(); ++i) {
      int price = prices[i];
      if (price - tempMin > max - min) {
        max = price;
        min = tempMin;
      }
      else if (price < min && price < tempMin) {
        tempMin = price;
      }
      else if (price > max) {
        max = price;
      }
    }
    return (max-min);
  }
};

int main()
{
	std::cout << "test" << std::endl;
	
	vector<int> prices;
//  prices.push_back(1);
//  prices.push_back(2);
//  prices.push_back(3);
//  prices.push_back(4);
//  prices.push_back(2);
//  prices.push_back(10);
  prices.push_back(4);
  prices.push_back(7);
  prices.push_back(1);
  prices.push_back(1);
  prices.push_back(2);
  prices.push_back(11);
	Solution a;
  std::cout << "profit = " << a.maxProfit(prices) << std::endl;

	return 0;
}