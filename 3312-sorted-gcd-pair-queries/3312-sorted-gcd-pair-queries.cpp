class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size(),q=queries.size();
        int maxVal=*max_element(begin(nums),end(nums));
        vector<long long> gcdPairCount(maxVal+1,0);
        vector<int> answer;

        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=1;j*j<=num;j++){
                if(num%j==0){
                    gcdPairCount[j]++;
                    if(num/j!=j){
                        gcdPairCount[num/j]++;
                    }
                }
            }
        }

        

        //correction
        for(int i=maxVal;i>0;i--){
            gcdPairCount[i]=gcdPairCount[i]*(gcdPairCount[i]-1)/2;
            if(gcdPairCount[i]!=0){
                for(int j=2*i;j<=maxVal;j=j+i){
                    gcdPairCount[i]-=gcdPairCount[j];
                }
            }
        }
        //prefix gcd
        for(int i=1;i<=maxVal;i++){
            gcdPairCount[i]+=gcdPairCount[i-1];
        }

        for(int i=0;i<q;i++){
            long long target=queries[i];
            int temp=maxVal;
            int l=1,r=maxVal;
            while(l<r){
                int mid=l+(r-l)/2;
                if(gcdPairCount[mid]>target){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            answer.push_back(l);
        }

        return answer; 
    }
};