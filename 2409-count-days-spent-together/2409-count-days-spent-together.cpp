class Solution {
public:
    int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int convert(string &s){
        string m,d;
        m += s[0];
        m += s[1];

        d += s[3];
        d += s[4];

        int cnt = 0,mm,dd;
        mm = stoi(m);
        dd = stoi(d);

        for(int i = 0;i < mm;i++){
            cnt += month[i];
        }
        cnt += dd;
        return cnt;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrivalA = convert(arriveAlice); // **Convert function will convert date to days**
        int arrivalB = convert(arriveBob);
        int leaveA = convert(leaveAlice);
        int leaveB = convert(leaveBob);
        
        int maxArrival = max(arrivalA,arrivalB);
        int minLeave = min(leaveA,leaveB);

        if(maxArrival >  minLeave){
            return 0;
        }
        return minLeave-maxArrival+1;
    }
};