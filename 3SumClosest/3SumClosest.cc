#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/**
 * Loop on the first two numbers. For the last one use a divide and conquer approach (binary-search like).
 */

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    target_ = target;

    std::sort(num.begin(), num.end());

    int length = num.size();

    distance_ = fabs(num[0]+num[1]+num[2]-target);
    result_ = num[0]+num[1]+num[2];

    // Loop on all the pairs. The vector is sorted so the
    // distance from 0 will reach a minimum.
    int lastFound = length-1;
    for( int i=0; i<length-2; ++i ) {
      for( int j=i+1; j<length-1; ++j ) {
	int previousDistance = 0;
	bool first = true;

	int partialSum = num[i]+num[j];

	findBest(num, partialSum, j+1, lastFound);
	if( distance_ == 0 ) return result_;
      }
    }
    return result_;
  }

  // This function could be simplified. It takes care of many different cases.
  void findBest(const std::vector<int> & num, const int partialSum, const int k1, const int k2)
  {
    int diff1 = partialSum+num[k1] - target_;
    if( k1 == k2 ) {
      if( fabs(diff1) < distance_ ) result_ = partialSum+num[k1];
    }
    else {
      int diff2 = partialSum+num[k2] - target_;
      if( diff1 == 0 ) {
	distance_ = 0;
	result_ = partialSum+num[k1];
      }
      else if( diff2 == 0 ) {
	distance_ = 0;
	result_ = partialSum+num[k2];
      }
      else if( k2-k1 == 1 ) {
	if( diff1*diff2 < 0 ) {
	  if( fabs(diff1) < fabs(diff2) && fabs(diff1) < distance_ ) {
	    distance_ = fabs(diff1);
	    result_ = partialSum+num[k1];
	  }
	  else if( fabs(diff2) < distance_ ) {
	    distance_ = fabs(diff2);
	    result_ = partialSum+num[k2]; 
	  }
	}
	else if( diff1 > 0 && fabs(diff1) < distance_ ) {
	  distance_ = fabs(diff1);
	  result_ = partialSum+num[k1];
	}
	else if( fabs(diff2) < distance_ ) {
	  distance_ = fabs(diff2);
	  result_ = partialSum+num[k2];
	}
      }
      else {
	if( diff1*diff2 > 0 ) {
	  if( diff1 > 0 && fabs(diff1) < distance_ ) {
	    result_ = partialSum+num[k1];
	    distance_ = fabs(diff1);
	  }
	  else if( fabs(diff2) < distance_ ) {
	    result_ = partialSum+num[k2];
	    distance_ = fabs(diff2);
	  }
	}
	else if( fabs(partialSum + num[(k1+k2)/2] - target_) > fabs(partialSum + num[(k1+k2)/2+1] - target_) ) {
	  findBest(num, partialSum, (k1+k2)/2, k2);
	}
	else {
	  findBest(num, partialSum, k1, (k1+k2)/2);
	}
      }
    }
  }

  int target_;
  int result_;
  int distance_;
};

int main()
{
  // std::vector<int> num{-1, 2, 1, -4};
  // std::vector<int> num{0, 0, 0};
  // std::vector<int> num{1,2,4,8,16,32,64,128};
  // std::vector<int> num{43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90};
  std::vector<int> num{0,1,2};

  Solution a;
  // std::cout << "result = " << a.threeSumClosest(num, 1) << std::endl;
  // std::cout << "result = " << a.threeSumClosest(num, 82) << std::endl;
  // std::cout << "result = " << a.threeSumClosest(num, 284) << std::endl;
  std::cout << "result = " << a.threeSumClosest(num, 3) << std::endl;

  return 0;
}
