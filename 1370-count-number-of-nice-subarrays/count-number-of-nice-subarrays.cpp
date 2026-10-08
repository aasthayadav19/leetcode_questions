class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int odd = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){

            int num = nums[i];

            if(num % 2 != 0){
                odd++;
            }

            if (mp.find(odd - k) != mp.end()){
                ans += mp[odd - k];
            }

            mp[odd]++;
        }
        return ans;
    }
};