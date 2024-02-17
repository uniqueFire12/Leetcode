class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {    
        int i = 0, diff = 0;
        priority_queue<int> pq;
        for(i = 0; i < h.size()-1; i++) {
            diff = h[i+1] - h[i];
            if(diff <= 0) {
                continue;                
            }
            
            bricks -= diff;
            pq.push(diff);
            
            if(bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            
            if(ladders < 0) break;
        }
        return i;
    }
};