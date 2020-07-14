class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
      ans = (0.5* abs(60*hour -11*minutes));
        ans = min(360.00-ans ,ans);
        return ans;
    }
};
