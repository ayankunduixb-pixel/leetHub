class Solution {
public:
    int convert(string &s){
        string h,m;
        h += s[0];
        h += s[1];

        m += s[3];
        m += s[4];

        int totalMinute = 0,minute,hour;

        minute = stoi(m);
        hour = stoi(h);

        for(int i = 0;i<hour;i++){
            totalMinute += 60;
        }
        totalMinute += minute;
        return totalMinute;
    }
    int convertTime(string current, string correct) {
        int currentMin = convert(current);
        int correctMin = convert(correct);

        int cnt = 0;
        int timeDiff = correctMin - currentMin;

        while(timeDiff != 0){
            if(timeDiff % 60 == 0) {
                cnt++;
                timeDiff -= 60;
            }
            else if(timeDiff % 15 == 0) {
                cnt++;
                timeDiff -= 15;
            }
            else if(timeDiff % 5 == 0) {
                cnt++;
                timeDiff -= 5;
            }
            else if(timeDiff % 1 == 0) {
                cnt++;
                timeDiff -= 1;
            }
        }

        return cnt;
    }
};