// time - O(n), space - O(1)

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
