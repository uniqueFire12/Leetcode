class DataStream {
public:
    int v=0, kmax=0, c=0;
    DataStream(int value, int k) {
      v = value;
      kmax = k;
    }
    
    bool consec(int num) {
      if(num == v) 
        c++;
      else
        c=0;
      return c >= kmax;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */