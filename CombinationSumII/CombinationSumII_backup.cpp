#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
 * Similar as CombiantionSum, but not identical. We can only use a number once and
 * numbers can appear multiple times in the list of candidates. This makes the structure
 * difference from the CombinationSum solution, but the general idea is similar.
*/

using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sol_.clear();
    // Remove elements bigger than the target
    candidates.erase(remove_if(candidates.begin(), candidates.end(), [target](int num) {return num > target;}), candidates.end());
    sort(candidates.begin(), candidates.end());

    buildCombination(candidates, candidates.size()-1, target);

    if (sol_.find(target) != sol_.end()) {
      sort(sol_[target].begin(), sol_[target].end());
      sol_[target].erase( unique( sol_[target].begin(), sol_[target].end() ), sol_[target].end() );
      return sol_[target];
    }
    else return vector<vector<int> >();
  }

  void buildCombination(const vector<int> & candidates, const unsigned int last, const int target)
  {
    // std::cout << "----------------- checking target = " << target << ", last = " << last << std::endl;

    // If this target has already been evaluated skip the rest
    vector<vector<int> > combinations;
    for (int i=last; i>=0; --i) {
      int candidate = candidates[i];
      // std::cout << "target = " << target << " trying with["<<i<<"]: " << candidate << std::endl;
      int difference = target - candidate;
      if (difference == 0) {
	// std::cout << "perfect match" << std::endl;
	combinations.push_back(vector<int>(1, candidate));
      }
      else if (difference > 0) {
        if (sol_.find(difference) == sol_.end()) {
          // int newLast = distance(candidates.begin(), lower_bound(candidates.begin(), candidates.end(), difference));
	  // std::cout << "newLast = " << newLast << ", " << candidates[newLast] << std::endl;
          // int newLastUpper = distance(candidates.begin(), upper_bound(candidates.begin(), candidates.end(), difference))-1;
	  // std::cout << "newLastUpper = " << newLastUpper << ", " << candidates[newLastUpper] << std::endl;
	  std::cout << "dist = " << difference << std::endl;
          // if (newLast > last) newLast = last;
          // buildCombination(candidates, newLastUpper, difference);
          buildCombination(candidates, last-1, difference);
        }
        // Fill the combinations
        if (sol_.find(difference) != sol_.end()) {
          for (auto subSol = sol_[difference].begin(); subSol != sol_[difference].end(); ++subSol) {
            // std::cout << "subSol->back() = " << subSol->back() << " >= " << candidate << std::endl;
            if (subSol->back() > candidate) continue;
            vector<int> newCombination(1, candidate);
            newCombination.insert(newCombination.begin(), subSol->begin(), subSol->end());
            // std::cout << "filling combination ";
            // for (auto v : newCombination) std::cout << v << ", ";
            // std::cout << endl;
            combinations.push_back(newCombination);
          }
        }
      }
      // std::cout << "i = " << i << std::endl;
    }
    // std::cout << "storing ------------------ for target = " << target << std::endl;
    // std::cout << "combinations.size() = " << combinations.size() << std::endl;
    sol_[target] = combinations;
  }

  unordered_map<int, vector<vector<int> > > sol_;
};

int main()
{
  Solution a;
  vector<int> candidates = {10,1,2,7,6,1,5};
  vector<vector<int> > sol(a.combinationSum(candidates, 8));
  // vector<int> candidates = {1,1};
  // vector<vector<int> > sol(a.combinationSum(candidates, 2));
  for (auto v : sol) {
    for (int n : v) {
      std::cout << n << ", ";
    }
    std::cout << std::endl;
  }
}
