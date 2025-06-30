class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0], profit=0;
        for(int i=1;i<prices.size();i++){
            int cost=prices[i]-mini;
            profit=max(cost, profit);
            mini=min(mini, prices[i]);
        }
        return profit;
    }
};

    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int Profit=0;
        for(int price:prices){
            if(price<minPrice){
                minPrice=price;
            }
            if(price-minPrice>Profit){
                Profit=price-minPrice;
            }
        }
        return Profit;
    }
