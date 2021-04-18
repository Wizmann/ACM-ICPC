typedef long long llint;

struct Task {
    int index;
    int startTime;
    int processTime;
};

class Comparator {
public:
    bool operator() (const Task& t1, const Task& t2) const {
        if (t1.processTime != t2.processTime) {
            return t1.processTime < t2.processTime;
        } else {
            return t1.index < t2.index;
        }
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks_) {
        vector<Task> tasks;
        int n = tasks_.size();
        for (int i = 0; i < n; i++) {
            tasks.push_back({i, tasks_[i][0], tasks_[i][1]});
        }
        sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
            return t1.startTime < t2.startTime;
        });
        
        multiset<Task, Comparator> st;
        llint cur = 0;
        vector<int> res;
        for (int i = 0; i < n; /* pass */) {
            if (st.empty() && cur < tasks[i].startTime) {
                cur = tasks[i].startTime;
            }
            while (i < n || !st.empty()) {
                while (i < n && tasks[i].startTime <= cur) {
                    st.insert(tasks[i]);
                    i++;
                }
                
                if (st.empty()) {
                    break;
                }
                
                res.push_back(st.begin()->index);
                cur += st.begin()->processTime;
                st.erase(st.begin());
            }
        }
        return res;
    }
};
