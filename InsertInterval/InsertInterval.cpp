#include <iostream>
#include <vector>

using namespace std;

/**
 * The intervals are non-overlapping and they are provided sorted according to their start times.
 * If the new interval overlaps with any of the existing ones we extend this overlap and remove
 * all other overlapping intervals.
 * All changes are done in place in the input vector.
 */

/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    // Check if the start is before or inside. If it is, check if the end is smaller than the
    // new interval. If it is, set it to the end of the new interval and set a bool. From now on
    // every other interval that has a start before this new end will be removed (flagged for
    // removal, for efficiency we do all removals in one go).

    // Check the trivial case of an empty input vector
    if (intervals.size() == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }

    int startPosition = -1;
    int endPosition = -1;
    for (int i=0; i<intervals.size(); ++i) {
      if (startPosition == -1) {
        if (newInterval.start <= intervals[i].end) {
          // Start found, check if a new interval should be inserted or the
          // current one should be extended.
          if (newInterval.start < intervals[i].start) {
            if (newInterval.end < intervals[i].start) {
              intervals.insert(intervals.begin()+i, newInterval);
              return intervals;
            }
            intervals[i].start = newInterval.start;
          }
          // Extend the end of this interval to the end of the new interval.
          // All intervals that will found to be covered by the new end will be removed.
          startPosition = i;
          intervals[i].end = std::max(newInterval.end, intervals[i].end);
        }
      }
      else {
        // Find intervals to remove, if any. Extend the end if needed.
        if (newInterval.end >= intervals[i].start) {
          intervals[startPosition].end = std::max(newInterval.end, intervals[i].end);
          endPosition = i;
        }
      }
    }
    // Remove any interval that needs to be removed.
    if (endPosition != -1) {
      intervals.erase(intervals.begin()+startPosition+1, intervals.begin()+endPosition+1);
    }
    // If we did not find the beginning of the new interval it is beyond the last one, append it.
    if (startPosition == -1) {
      intervals.push_back(newInterval);
    }
    return intervals;
  }
};

int main()
{

  std::vector<Interval> intervals;
//  intervals.push_back(Interval(1,2));
//  intervals.push_back(Interval(3,5));
//  intervals.push_back(Interval(6,7));
//  intervals.push_back(Interval(8,10));
//  intervals.push_back(Interval(12,16));

  intervals.push_back(Interval(1,5));
  intervals.push_back(Interval(6,8));
  
  for (auto interval : intervals) std::cout << interval.start << "," << interval.end << std::endl;

  // Interval newInterval(2,12);
  // Interval newInterval(4,9);
  // Interval newInterval(13,15);
  Interval newInterval(3,7);

  Solution a;
  a.insert(intervals, newInterval);

  std::cout << "Result:" << std::endl;
  for (auto interval : intervals) std::cout << interval.start << "," << interval.end << std::endl;
}