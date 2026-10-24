class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int alice = 0, bob = 0;
        int aliceArriveM = stoi(arriveAlice.substr(0, 2));
        int aliceLeaveM = stoi(leaveAlice.substr(0, 2));
        int aliceArriveD = stoi(arriveAlice.substr(3, 2));
        int aliceLeaveD = stoi(leaveAlice.substr(3, 2));
        int bobArriveM = stoi(arriveBob.substr(0, 2));
        int bobLeaveM = stoi(leaveBob.substr(0, 2));
        int bobArriveD = stoi(arriveBob.substr(3, 2));
        int bobLeaveD = stoi(leaveBob.substr(3, 2));

        int ans = 0;
        for (int M = 1; M <= 12; M++) {
            for (int D = 1; D <= days[M-1]; D++) {
                if (aliceArriveM <= M && aliceLeaveM >= M) {
                    if (aliceArriveM == M && aliceArriveD > D ||
                        aliceLeaveM == M && aliceLeaveD < D) {
                        alice = 0;
                    } else {
                        alice = 1;
                    }
                }
                if (bobArriveM <= M && bobLeaveM >= M) {
                    if (bobArriveM == M && bobArriveD > D ||
                        bobLeaveM == M && bobLeaveD < D) {
                        bob = 0;
                    } else {
                        bob = 1;
                    }
                }

                if (alice && bob) {
                    ans++;
                }
                alice = 0;
                bob = 0;
            }
        }
        return ans;
    }
};