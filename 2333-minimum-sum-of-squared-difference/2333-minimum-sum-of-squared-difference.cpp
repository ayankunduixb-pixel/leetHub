class Solution {
private:
    long long bruteForceApproach(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        priority_queue<int> pq;
        for(int i=0;i<n;i++){ // push all the diff into the priority queue
            pq.push(abs(nums1[i] - nums2[i]));
        }

        int k = k1 + k2;

        while(k>0 && pq.top() > 0){ // k1 and k2 values are utilized
            int largestDiff = pq.top();
            pq.pop();
            pq.push(largestDiff - 1);
            k--;
        }

        long long result = 0;
        while(!pq.empty()){
            long long diff = pq.top();
            pq.pop();
            result += (diff * diff);
        }

        return result;
    }
    long long optimalApproach(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for(int i = 0;i<n;i++){
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(),diff.end());

        // countDiff[d] = count of each diff
        vector<int> countDiff(maxDiff + 1,0);
        for(int d:diff){
            countDiff[d]++;
        }
        
        int k = k1+k2;

        for(int currDiff = maxDiff; currDiff > 0 && k>0; currDiff--){
            int countOps = min(countDiff[currDiff],k);
            countDiff[currDiff] -= countOps;
            countDiff[currDiff-1] += countOps;
            k -= countOps;
        }

        long long result = 0;
        for(long long d=1;d<=maxDiff; d++){
            result += countDiff[d] *(d*d);
        }

        return result;
    }
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // return bruteForceApproach(nums1,nums2,k1,k2);
        return optimalApproach(nums1,nums2,k1,k2);
    }
};