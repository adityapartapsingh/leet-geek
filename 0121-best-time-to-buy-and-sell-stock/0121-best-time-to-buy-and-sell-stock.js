/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
   let lowest=prices[0];
   let profit=0;
   let i=0;
   while(i<prices.length){
    if(prices[i]<lowest){
        lowest=prices[i];
    }
    else if(prices[i]-lowest>profit){
        profit= prices[i]-lowest;

    }
    i++;
   }
   return profit;
};