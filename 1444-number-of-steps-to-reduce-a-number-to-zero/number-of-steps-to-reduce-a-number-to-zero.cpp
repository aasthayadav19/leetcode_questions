class Solution {
public:
    int numberOfSteps(int num) {
        int resSteps = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                num = num / 2;
                resSteps++;
            } else {
                num = num - 1;
                resSteps++;
            }
        }
        return resSteps;
    }
};