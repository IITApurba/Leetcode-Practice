class Solution {
public:
    int reverse(int x) {

        long reversed = 0;
        int remainder;
        //reverse the number
        while(x != 0)
        {
            remainder = x % 10;
            reversed = reversed * 10 + remainder;
            x = x / 10;
        }

        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }
        
        return reversed;

    }
};