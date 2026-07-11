class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int fleet = 0;
        double time = -1;
        double current_t = -1;
        for (int i = 0; i < speed.size(); i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend());

        for (int i = 0; i < speed.size(); i++){
            time = double(target - cars[i].first) / cars[i].second;
            if (current_t < time){
                fleet++;
                current_t = time;
            }
                
        }
        return fleet;
    }
};
