class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            vector<string> array;
            for(int num : nums){
                array.push_back(to_string(num));
            }
    
            sort(array.begin(), array.end(), [](const string &a, const string &b){
                return (b + a) < (a + b);
            });
    
            string largest = ""; 
            if(array[0] == "0") return "0";
            for(string num: array) largest += num; 
            return largest;        
        }
};