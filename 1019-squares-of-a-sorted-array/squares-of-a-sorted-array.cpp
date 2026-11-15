class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();

        vector<int> neg; // negative array
        vector<int> pos; // positive array

        for(int i=0; i<size; i++)
        {
            if(nums[i]<0)
             neg.push_back(nums[i]);
            else
             pos.push_back(nums[i]);
        }

        if(neg.size() == 0)//no negative element
         {
            for(int i=0; i<size; i++)
              pos[i]= pos[i]*pos[i];
              return pos;
         }
        if(pos.size() == 0)//no positive element
         {
            for(int i=0; i<size; i++)
             neg[i]= neg[i]*neg[i];
             reverse(neg.begin(),neg.end());
             return neg;
         } 

         int i=0 , j=0;
         int id =0;
         int n = neg.size();
         int m = pos.size();

         vector<int>res(n+m);

         for(int i=0; i<n; i++)
          neg[i] = neg[i]*neg[i];
          reverse(neg.begin(),neg.end());

         for(int j=0; j<m; j++)
          pos[j] = pos[j]*pos[j];

         while(i<n and j<m)
         {
            if(neg[i]<= pos[j])
            {
                res[id] = neg[i];
                id++;
                i++;
            }
            else
            {
                res[id] = pos[j];
                id++;
                j++;
            }
         }  
        while(i<n){
            res[id] = neg[i];
                id++;
                i++;
        } 
        while(j<m){
            res[id] = pos[j];
                id++;
                j++;
        }
    return res;

    }
};