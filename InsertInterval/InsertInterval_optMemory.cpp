#include <iostream>
#include <vector>

using namespace std;

/**
 * The intervals are non-overlapping and they are provided sorted according to their start times.
 * We consider all different cases and act accordingly. The initial interval is modified in different
 * ways depending on the way it overlaps.
 * This version is optimized for memory, it does all the changes in place in the input vector.
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
    bool startFound = false;
    if (intervals.size() == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    else if (intervals.size() == 1) {
      if (newInterval.end < intervals[0].start) {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
      }
      if (newInterval.start < intervals[0].start) {
        intervals[0].start = newInterval.start;
      }
      if (newInterval.end > intervals[0].end) {
        intervals[0].end = newInterval.end;
      }
      if (newInterval.start > intervals[0].end) {
        intervals.push_back(newInterval);
      }
      return intervals;
    }
    
    for (int i=0; i<intervals.size()-1; ++i) {
      if (newInterval.start < intervals[i].end) {
        if (!startFound) {
          if (newInterval.start <= intervals[i].start) {
            startFound = true;
            if (newInterval.end < intervals[i].start) {
              intervals.insert(intervals.begin()+i, newInterval);
              break;
            }
            else intervals[i].start = newInterval.start;
          }
        }
        if (newInterval.end < intervals[i].end) break;
        else if (newInterval.end < intervals[i+1].start) intervals[i].end = newInterval.end;
        else if (newInterval.end < intervals[i+1].end) {
          intervals[i].end = intervals[i+1].end;
          intervals.erase(intervals.begin()+i+1);
          --i;
          break;
        }
        else {
          intervals.erase(intervals.begin()+i+1);
          --i;
        }
      }
    }
    if (!startFound) {
      intervals.push_back(newInterval);
    }
    return intervals;
  }
};

int main()
{

  std::vector<Interval> intervals;
  // intervals.push_back(Interval(1,2));
  intervals.push_back(Interval(3,5));
  // intervals.push_back(Interval(6,7));
  intervals.push_back(Interval(8,10));
  intervals.push_back(Interval(12,16));
  
  for (auto interval : intervals) std::cout << interval.start << "," << interval.end << std::endl;

  Interval newInterval(2,6);
  // Interval newInterval(4,9);
  // Interval newInterval(6,7);

  Solution a;
  a.insert(intervals, newInterval);

  std::cout << "Result:" << std::endl;
  for (auto interval : intervals) std::cout << interval.start << "," << interval.end << std::endl;
}