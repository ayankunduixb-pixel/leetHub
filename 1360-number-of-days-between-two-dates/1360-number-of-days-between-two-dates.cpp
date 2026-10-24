class Solution {
public:
    int monthArr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int convert(string &s){
        string y,m,d;
        y += s[0];
        y += s[1];
        y += s[2];
        y += s[3];

        m += s[5];
        m += s[6];

        d += s[8];
        d += s[9];
        int cnt = 0,year,month,day;
        year = stoi(y);
        month = stoi(m);
        day = stoi(d);

        for(int i = 1971;i<year;i++){
            if((i % 4==0 && i % 100 !=0) || (i % 400 == 0)){
                cnt += 366;
            }
            else{
                cnt += 365;
            }
        }
        for(int i = 0;i < month;i++){
            cnt += monthArr[i];
        }

        // Add February 29 if the current year is a leap year
        if (month > 2 &&
            ((year % 4 == 0 && year % 100 != 0) ||
             year % 400 == 0)) {
            cnt++;
        }
        
        cnt += day;
        return cnt;
    }
    int daysBetweenDates(string date1, string date2) {
        int cnt1 = convert(date1);
        int cnt2 = convert(date2);
        return abs(cnt1-cnt2);
    }
};