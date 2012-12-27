class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        int size = intervals.size();
        int i = 0;
        while (i < size && intervals[i].end < newInterval.start) {
            result.push_back(intervals[i]);
            i++;
        }

        if (i == size) {
            result.push_back(newInterval);
            return result;
        }

        Interval news;
        news.start = newInterval.start <= intervals[i].start?  newInterval.start : intervals[i].start;
        while ( i < size && newInterval.end > intervals[i].end) {
            i++;
        }

        if (i == size) {
            news.end = newInterval.end;
            result.push_back(news);
            return result;
        }

        if (newInterval.end < intervals[i].start) {
            news.end = newInterval.end;
        } else {
            news.end = intervals[i].end;
            i++;
        }

        result.push_back(news);

        while (i < size) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
