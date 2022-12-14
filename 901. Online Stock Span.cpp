class StockSpanner {
public:
    stack< pair<int,int> > st;
    int count = 0;
    StockSpanner() {  
    }
    
    int next(int price) {
        while(st.size() and st.top().first <= price)
            st.pop();
        if(st.size()){
            int res = count - st.top().second;
            st.push({price, count});
            count++;
            return res;
        }
        st.push({price, count}), count++;
        return count;
    }
};