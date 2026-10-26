class Solution {
public:
    bool checkPerfectNumber(int num) {
        int facSum = 0;

        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                facSum = facSum + i;
            }
        }

        if (num == facSum)
            return true;
        else
            return false;
    }
};