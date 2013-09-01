class Solution {
public:
    string simplifyPath(string path) {
        vector<string> path_vec;
        string now;
        path += '/';
        for (int i = 0; path[i]; /*PASS*/) {
            if (path[i] == '/') {
                if (now == "."  || now == "") {
                    // PASS
                } else if (now == "..") {
                    if (!path_vec.empty()) {
                        path_vec.pop_back();
                    }
                } else {
                   path_vec.push_back(now); 
                }
                now = "";
                while (path[i] == '/') {
                    i++;
                }
            } else {
                now += path[i];
                i++;
            }
        }
        string res;
        for(int i = 0; i < path_vec.size(); i++) {
            res += '/';
            res += path_vec[i];
        }
        return res == ""? "/" : res;
    }
};
