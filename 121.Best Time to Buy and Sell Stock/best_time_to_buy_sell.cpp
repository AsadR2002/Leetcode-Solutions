class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit = 0; 
            int cur_profit = prices[0];
    
            int sell_index = 1, buy_index = 0;
            
            while(sell_index < prices.size()){
                if(prices[sell_index] - prices[buy_index] > max_profit) {
                    max_profit = prices[sell_index] - prices[buy_index]; 
                }
    
                else if (prices[sell_index] - prices[buy_index] < 0) {
                    buy_index = sell_index; 
                }
    
                sell_index++; 
            }
            return max_profit; 
        }
    };