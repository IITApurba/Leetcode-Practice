#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class StockPrice {
    unordered_map<int, int> timeToPrice;
    multiset<int> prices;
    int latestTime;

public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        latestTime = max(latestTime, timestamp);
        if (timeToPrice.count(timestamp)) {
            int oldPrice = timeToPrice[timestamp];
            prices.erase(prices.find(oldPrice));
        }
        timeToPrice[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return timeToPrice[latestTime];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};