class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--) {
            
            // Agar digit 9 se choti hai to simply +1 kardo
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            // Agar 9 hai to 0 bana do aur carry aage jayega
            digits[i] = 0;
        }
        
       
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};