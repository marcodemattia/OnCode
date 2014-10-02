#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
* We use recursion. First we sort the list of numbers and remove those bigger than the target.
* We then loop on the numbers starting from the biggest. For each numbers we divide the target
* by it. If the remainder of the division is > 0 we call this function recursively on the subset
* of numbers from the smallest to the next-to largest and giving as target the remainder. If we
* arrive at a remainder of 0 we fill the numbers (starting from the innermost which is the smallest)
* and fill each number N times, where N = target/number. The input numbers and the target are
* guaranteed to be positive integers.
* This problem exhibits properties that make it suitable to a dynamic programming approach. It
* has substructure meaning that the solution can be built as a combination of solutions of
* subproblems. Memoization can help removing repetitions. Once a number in the list has been
* checked all the combinations of numbers smaller than it can be stored and reused in case this number
* appears again. Clearly, there are repetitions by using all combinations. For instance, 5 can be built
* as 2+2+1. Switching one of the 2s as two ones can be done only once.
* Extra care must be used to avoid double counting. We only take a memoized combination if the
* largest of its numbers is smaller than the current candidate number.
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
      // sort(sol_[target].begin(), sol_[target].end());
      // unique(sol_[target].begin(), sol_[target].end());
      return sol_[target];
    }
    else return vector<vector<int> >();
  }

  void buildCombination(const vector<int> & candidates, const unsigned int last, const int target)
  {
    std::cout << "----------------- checking target = " << target << ", last = " << last << std::endl;

    // If this target has already been evaluated skip the rest
    vector<vector<int> > combinations;
    for (int i=last; i>=0; --i) {
      int candidate = candidates[i];
      std::cout << "target = " << target << " trying with["<<i<<"]: " << candidate << std::endl;
      unsigned int remainder = target%candidate;
      unsigned int numDivs = target/candidate;
      if (remainder == 0) {
        std::cout << "perfect match" << std::endl;
        combinations.push_back(vector<int>(numDivs, candidate));
      }
      else numDivs++;
      for (int j=numDivs-1; j>0; --j) {
        int newTarget = target - j*candidate;
        std::cout << "attempting for newTarget["<<j<<"] = " << newTarget << std::endl;
        // If this subsolution is not there we build it
        if (sol_.find(newTarget) == sol_.end()) {
          // int newLast = distance(candidates.begin(), lower_bound(candidates.begin(), candidates.end(), min(candidate-1, newTarget)));
          int newLast = distance(candidates.begin(), lower_bound(candidates.begin(), candidates.end(), newTarget));
          if (newLast > last) newLast = last;
          // if (newLast > 0) {
          std::cout << "building combinations for target: " << newTarget << ", newLast["<<newLast<<"] = " << candidates[newLast] << std::endl;
          buildCombination(candidates, newLast, newTarget);
          // }
        }
        // Fill the combinations
        if (sol_.find(newTarget) != sol_.end()) {
          for (auto subSol = sol_[newTarget].begin(); subSol != sol_[newTarget].end(); ++subSol) {
            std::cout << "subSol->back() = " << subSol->back() << " >= " << candidate << std::endl;
            if (subSol->back() >= candidate) continue;
            vector<int> newCombination(j, candidate);
            newCombination.insert(newCombination.begin(), subSol->begin(), subSol->end());
            std::cout << "filling combination ";
            for (auto v : newCombination) std::cout << v << ", ";
            std::cout << endl;
            combinations.push_back(newCombination);
          }
        }
      }
      std::cout << "i = " << i << std::endl;
    }
    std::cout << "storing ------------------" << std::endl;
    sol_[target] = combinations;
  }

  unordered_map<int, vector<vector<int> > > sol_;
};

int main()
{
  Solution a;
  // vector<int> candidates = {2,3,6,7};
  // vector<vector<int> > sol(a.combinationSum(candidates, 10));
  // vector<int> candidates = {1,2};
  // vector<vector<int> > sol(a.combinationSum(candidates, 3));
  // vector<int> candidates = {5,4,2,3};
  // vector<vector<int> > sol(a.combinationSum(candidates, 14));
  vector<int> candidates = {2,3,5};
  vector<vector<int> > sol(a.combinationSum(candidates, 8));
  for (auto v : sol) {
    for (int n : v) {
      std::cout << n << ", ";
    }
    std::cout << std::endl;
  }
}