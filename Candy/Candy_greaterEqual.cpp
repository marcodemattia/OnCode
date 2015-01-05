#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int candies = 1;
    if (ratings.size() == 0) return 0;
    else if (ratings.size() == 1) return 1;
    int countDown = 2;
    int countUp = 2;
    int countPlateau = 0;
    int previousCountUp = 2;
    for (int i=1; i<ratings.size(); ++i) {
      // We use two counters. The first keeps track of the trend up and the second of the trend down.
      // We start from the second kid (the first always starts from one candy). If the previous
      // kid has a higher rating we give one candie to all the kids before him/her that have a higher
      // rating (tracked by countDown).
      // If the next kid had a higher rating we give him/her one candy for every kid before him that
      // has a lower rating (tracked by countUp).

      // The previous kid has a higher rating
      if (ratings[i-1] > ratings[i]) {
	// Decide if you need to increase also the previous plateau
	if (countDown >= previousCountUp) {
	  std::cout << "countDown = " << countDown << ", previousCountUp = " << previousCountUp << std::endl;
	  countDown+=countPlateau;
	  previousCountUp = 2;
	}
	std::cout << "countDown = " << countDown << std::endl;
	candies += countDown;
	if (countUp != 2) previousCountUp = countUp-1;
	countUp = 2;
	countPlateau = 1;
	++countDown;
      }
      // The previous kid has the same rating
      else if (ratings[i-1] == ratings[i]) {
	++countPlateau;
	if (countUp == 2) candies += 1;
	else candies += countUp-1;
      }
      // The previous kid has a lower rating
      else {
	candies += countUp;
	countDown = 1;
	countPlateau = 1;
	++countUp;
      }

      std::cout << "candies = " << candies << std::endl;
    }
    return candies;
  }
};

int main()
{
  vector<int> ratings;
  // ratings.push_back(1);
  // ratings.push_back(2);
  // ratings.push_back(3);
  // ratings.push_back(6);
  // ratings.push_back(1);
  // ratings.push_back(5);
  // ratings.push_back(4);
  // ratings.push_back(3);
  // ratings.push_back(3);
  // // Total is 18
  // ratings.push_back(3);
  // ratings.push_back(3);
  // ratings.push_back(3);
  // // Total is 21

  // ratings.push_back(1);
  // ratings.push_back(2);
  // ratings.push_back(2);

  // ratings.push_back(-3);
  // ratings.push_back(-2);
  // ratings.push_back(3);
  // ratings.push_back(6);
  // ratings.push_back(1);
  // ratings.push_back(-10);
  // ratings.push_back(-9);
  // ratings.push_back(-8);
  // ratings.push_back(-7);
  // ratings.push_back(-6);
  // ratings.push_back(4);
  // ratings.push_back(3);
  // ratings.push_back(3);
  // // Total is 35

  Solution a;

  std::cout << "candies = " << a.candy(ratings) << std::endl;

  return 0;
}
