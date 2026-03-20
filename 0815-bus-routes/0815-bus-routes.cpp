class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }
        
        queue<int> q;
        q.push(source);
        
        unordered_set<int> visitedStops;
        visitedStops.insert(source);
        
        vector<bool> visitedRoutes(routes.size(), false);
        
        int buses = 0;
        
        while (!q.empty()) {
            int size = q.size();
            buses++;
            
            while (size--) {
                int curr = q.front();
                q.pop();
                
                for (int route : stopToRoutes[curr]) {
                    if (visitedRoutes[route]) continue;
                    visitedRoutes[route] = true;
                    
                    for (int nextStop : routes[route]) {
                        if (nextStop == target) {
                            return buses;
                        }
                        if (visitedStops.find(nextStop) == visitedStops.end()) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};