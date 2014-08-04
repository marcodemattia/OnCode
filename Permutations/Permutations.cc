#include <iostream>
#include <vector>

/**
 * Recursively go into a smaller vector until size 2 is reached. For each recursion after the first
 * loop on the number of elements ( = number of permutations of the last element) switch the last
 * element of the subvector with the others. When size 2 is reached it will be the last switch.
 * Each recursion creates two temporary integers and the size of the shrinking subvector is passed
 * around. This is not terrible, but it might be possible to move something to data member and still
 * keep track of it (though the code would probably result more complicated).
 */

using namespace std;

class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    if( num.size() > 0 ) {
      sol.push_back(num);
      permute(num.size());
    }
    return sol;
  }

  void permute(int n)
  {
    int index = sol.size()-1;
    int i=0;
    while( i < n ) {
      if( i > 0 ) {
	sol.push_back(sol[index]);
	sol.back()[n-1] = sol[index][i-1];
	sol.back()[i-1] = sol[index][n-1];
      }
      if( n > 2 ) permute(n-1);
      ++i;
    }
  }

  vector<vector<int > > sol;
};

int main()
{
  vector<int> v = {1,2,3};
  Solution a;
  vector<vector<int> > sol(a.permute(v));
  for( const auto & i : sol ) {
    for( vector<int>::const_iterator it = i.begin(); it != i.end(); ++it ) {
      std::cout << *it;
    }
    std::cout << std::endl;
  }
  return 0;
}
