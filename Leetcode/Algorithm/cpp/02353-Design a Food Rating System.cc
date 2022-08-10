const int INF = 0x3f3f3f3f;

struct Food {
    string food;
    string cuisine;
    int rating;
    
    bool operator < (const Food& other) const {
        if (cuisine != other.cuisine) {
            return cuisine < other.cuisine;
        }
        
        if (rating != other.rating) {
            return rating > other.rating;
        }
        
        if (food != other.food) {
            return food < other.food;
        }
        
        return false;
    }
};

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for (int i = 0; i < n; i++) {
            mp[foods[i]] = { cuisines[i], ratings[i] };
            
            st.insert({foods[i], cuisines[i], ratings[i]});
        }        
    }
    
    void changeRating(string food, int newRating) {
        Food f = { food, mp[food].first, mp[food].second };
        auto iter = st.find(f);
        assert(iter != st.end());
        st.erase(iter);
        f.rating = newRating;
        st.insert(f);
        mp[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        auto iter = st.lower_bound({"", cuisine, INF});
        assert(iter != st.end());
        assert(iter->cuisine == cuisine);
        return iter->food;
    }
private:
    int n;
    map<string, pair<string, int> > mp;
    set<Food> st;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
