class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if (start > end) {
            return 0;
        }

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int startMonth = stoi(start.substr(0, 2));
        int endMonth = stoi(end.substr(0, 2));
        int startDay = stoi(start.substr(3, 2));
        int endDay = stoi(end.substr(3, 2));

        int ans = 0;

        for (int m = startMonth; m <= endMonth; m++) {
            int firstDay = (m == startMonth) ? startDay : 1;
            int lastDay = (m == endMonth) ? endDay : days[m - 1];

            ans += lastDay - firstDay + 1;
        }

        return ans;
    }
};