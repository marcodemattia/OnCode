#include <iostream>
#include <vector>

/**
 * What we need to do is keep track of how many are ramping up and how many are ramping down.
 * Each time we ramp up we add one more candy than before. Each time we ramp down we add one
 * more candy to those before the current one in the ramp-down sequence. The only tricky part
 * is when a local maximum is found. In this formulation of the problem a maximum is any kid
 * who is between two kids with lower rating. As we go through the vector we do not know yet
 * the number of candies we will assign to the kid after him. This will only be known once the
 * ramp down ends. At that point we can compare how many candies we give to the kid on before
 * the local maximum and how many we give to the one after it. We can correct the number of
 * candies given to the local maximum accordingly.
 * If a plateau is found all the elements of the plateau adiacent only to elements with the
 * same rating will receive one candy. Only the borders of the plateau can receive a number
 * greater than 1.
 */

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
    int lastBeforeRampDown = 1;
    for (int i=1; i<ratings.size(); ++i) {
      // Ramp up
      if (ratings[i-1] < ratings[i]) {
	candies += countUp;
        lastBeforeRampDown = countUp;
	countDown = 1;
	++countUp;
      }
      // Plateau
      else if (ratings[i-1] == ratings[i]) {
	candies += 1;
	countUp = 2;
	lastBeforeRampDown = 1;
      }
      // Ramp down
      else {
	if (countDown > lastBeforeRampDown) {
	  // We reached the count, include the previous local maximum
	  ++countDown;
	  lastBeforeRampDown = 1000000;
	}
	candies += countDown;
	// Only if there was a ramp up (countUp is set to 2 by default and increased in case of a rampUp at the
	// end of the rampUp as well)
	// Starts from 2 because it will be for the ramp up, it will happen after a 1.
	countUp = 2;
	++countDown;
      }
      std::cout << "countUp = " << countUp << ", countDown = " << countDown << ", lastBeforeRampDown = " << lastBeforeRampDown << std::endl;
      std::cout << "rating["<<i<<"] = " << ratings[i] << ", candies = " << candies << std::endl;
    }

    // Final check after reaching the end of the vector
    std::cout << "countDown = " << countDown << ", lastBeforeRampDown = " << lastBeforeRampDown << std::endl;
    if (countDown > lastBeforeRampDown) {
      // It should be countDown-1 + previousCountUp +1, simplified to this
      // candies += countDown-previousCountUp;
      candies += 1;
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
  // // ratings.push_back(3);
  // // ratings.push_back(3);
  // // ratings.push_back(3);
  // // // Total is 21

  // ratings.push_back(1);
  // ratings.push_back(2);
  // ratings.push_back(2);
  // ratings.push_back(1);

  // ratings.push_back(1);
  // ratings.push_back(2);
  // ratings.push_back(4);
  // ratings.push_back(4);
  // ratings.push_back(3);

  // ratings.push_back(1);
  // ratings.push_back(3);
  // ratings.push_back(4);
  // ratings.push_back(3);
  // ratings.push_back(2);
  // ratings.push_back(1);

  // ratings.push_back(5);
  // ratings.push_back(1);
  // ratings.push_back(1);
  // ratings.push_back(1);
  // ratings.push_back(10);
  // ratings.push_back(2);
  // ratings.push_back(1);
  // ratings.push_back(1);
  // ratings.push_back(1);
  // ratings.push_back(3);


  ratings.push_back(-3);
  ratings.push_back(-2);
  ratings.push_back(3);
  ratings.push_back(6);
  ratings.push_back(1);
  ratings.push_back(-10);
  ratings.push_back(-9);
  ratings.push_back(-8);
  ratings.push_back(-7);
  ratings.push_back(-6);
  ratings.push_back(4);
  ratings.push_back(3);
  ratings.push_back(3);
  // // Total is 35

  Solution a;

  std::cout << "candies = " << a.candy(ratings) << std::endl;

  return 0;
}
