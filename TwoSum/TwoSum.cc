#include <vector>
#include <algorithm>
#include <iostream>

/*
  If it was possible to sort the input vector and return the indeces to the sorted vector it would be simpler.
  This form of the solution can certainly be improved by reducing the number of copy operations.

  The basic idea is that if the input vector is sorted we do not need to look at all combinations.
 */

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target)
  {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.


    std::vector<int> numCopy(numbers);
    std::vector<int> sol(twoSumFind(numCopy, target));
    std::vector<int> actualSol;
    // std::cout << "sol[0] = " << sol[0] << std::endl;
    if( sol[0] == sol[1] ) {
      for( std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it ) {
	if(*it == sol[0]) {
	  actualSol.push_back(it - numbers.begin() + 1);
	}
      }
    }
    else {
      actualSol.push_back(std::find(numbers.begin(), numbers.end(), sol[0])-numbers.begin()+1);
      actualSol.push_back(std::find(numbers.begin(), numbers.end(), sol[1])-numbers.begin()+1);
    }
    std::sort(actualSol.begin(), actualSol.end());
    return actualSol;
  }

  std::vector<int> twoSumFind(std::vector<int> &numbers, int target)
  {
    std::sort(numbers.begin(), numbers.end());
    std::vector<int> sol;
    int i = 0;
    int j = 0;
    for( std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it, ++i ) {
      int d = target - *it;
      for( std::vector<int>::const_iterator jt = it+1; jt != numbers.end(); ++jt, ++j ) {
	if( d == *jt ) {
	  sol.push_back(*it);
	  sol.push_back(*jt);
	  return sol;
	}
	else if( *jt > d ) break;
      }
    }
    return sol;
  }
};

int main()
{
  Solution a;
  std::vector<int> v;
  v.push_back(2);
  v.push_back(4);
  v.push_back(7);
  v.push_back(11);
  v.push_back(15);
  v.push_back(4);

  std::vector<int> sol(a.twoSum(v, 8));

  for( std::vector<int>::const_iterator it = sol.begin(); it != sol.end(); ++it ) {
    std::cout << *it << std::endl;
  }

  std::cout << "target = " << 8 << " result = " << v[sol[0]-1]+v[sol[1]-1] << std::endl;
}
