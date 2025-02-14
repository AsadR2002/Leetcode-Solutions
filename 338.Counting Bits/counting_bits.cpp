class Solution {
    public:
        vector<int> countBits(int n) {
            std::vector<int> vec; 
            vec.push_back(0);
            for(int i = 1; i < n + 1; i++) {
                //insert 
                int count = 0;
                int temp = i;
                while (temp) {
                    count += (temp & 1); // Add 1 if the last bit is 1
                    temp >>= 1; // Right shift n to check next bit
                }
                vec.push_back(count);
            }
            return vec;
        }
    };