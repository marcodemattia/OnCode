#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
 * Similar as CombiantionSum, but not identical. We can only use a number once and
 * numbers can appear multiple times in the list of candidates. This makes the structure
 * different from the CombinationSum solution, even though the general idea is similar.
 * 
 * We follow a different and simpler approach. Navigate the sequence down to smaller numbers.
 * The current sequence is stored in a stack. Everytime we enter the recursion we push the
 * candidate in the stack and when we get out we pop it back. If the difference between the
 * target and the number ever reaches zero the current stack is stored as a solution. In
 * practice, since we would have to convert the a stack<int> into a vector to store the
 * solution, we use directly the vector<int> with push_back and pop_back calls.
 */

using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
    sol_.clear();
    stack_.clear();
    // Remove elements bigger than the target
    candidates.erase(remove_if(candidates.begin(), candidates.end(), [target](int num) {return num > target;}), candidates.end());
    sort(candidates.begin(), candidates.end());

    buildCombinations(candidates, candidates.size()-1, target);

    // Cleanup possible duplicates. It can happen if there are duplicates of the same number
    // and the logic to avoid them is likely heavier (and more bug prone) than a final cleanup.
    sort(sol_.begin(), sol_.end());
    sol_.erase(unique(sol_.begin(), sol_.end()), sol_.end());

    return sol_;
  }

  void buildCombinations(const vector<int> & candidates, const int last, const int target)
  {
    std::cout << "checking last = " << last << std::endl;

    for (int i=last; i>=0; --i) {
      std::cout << "checking candidates["<<i<<"] = " << candidates[i] << std::endl;
      int candidate = candidates[i];
      int difference = target - candidate;
      stack_.push_back(candidate);

      if (difference == 0) {
	sol_.push_back(stack_);
	sort(sol_.back().begin(), sol_.back().end());
      }
      else {
	int newLast = distance(candidates.begin(), upper_bound(candidates.begin(), candidates.end(), difference)) - 1;
	buildCombinations(candidates, min(newLast, i-1), difference);
      }

      stack_.pop_back();
    }
  }

  vector<vector<int> > sol_;
  vector<int> stack_;
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
