class Solution {
public:
    typedef long long ll;
    string freeSlotsFiller(ll required, int length) {
        string str;
        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                str.push_back(digit + '0');
                required /= digit;
            }
        }
        if (required != 1)
            return "";
        while (str.size() < length) {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string smallestNumber(string num, long long t) {
        int n = num.size();
        ll temp = t;
        string result;
        for (int primeFactor : {2, 3, 5, 7}) {
            while (temp % primeFactor == 0) {
                temp /= primeFactor;
            }
        }
        if (temp != 1)
            return "-1";

        vector<ll> remainingFactor(n + 1, t);
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            if (digit == 0)
                break;
            remainingFactor[i + 1] =
                remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }

        if (remainingFactor[n] == 1) {
            return num;
        }
        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if (zeroPos != -1) {
            zeroIdx = zeroPos;
        }

        for (int i = zeroIdx; i >= 0; i--) {
            ll required = remainingFactor[i];
            int freeSlots = n - 1 - i;
            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                ll nextRequired = required / gcd(required, digit);
                string requiredNumber =
                    freeSlotsFiller(nextRequired, freeSlots);
                if (requiredNumber.size() == freeSlots) {
                    return num.substr(0, i) + char(digit + '0') +
                           requiredNumber;
                }
            }
        }
        return freeSlotsFiller(t, n + 1);
    }
};