class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        elif len(prices) ==1:
            return 0
        elif len(prices) == 2:
            if prices[1]>prices[0]:
                diff = prices[1] - prices[0]
                return max(diff, 0)
            return 0
        
        buy_pt = 0
        sell_pt = 0
        profit = 0
        for i, price in enumerate(prices):
            if i>=1:
                if prices[i] > prices[i-1]:
                    buy_pt = prices[i-1]
                    sell_pt = prices[i]
                    profit += prices[i] - prices[i-1]
                elif prices[i] < prices[i-1]:
                    buy_pt = prices[i]
                
        return profit
