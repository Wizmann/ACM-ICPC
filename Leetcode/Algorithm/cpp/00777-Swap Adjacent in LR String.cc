class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
		assert (start.size() == end.size());
		
		if (!doMove(start, end, 'R')) {
            cout << start << ' ' << end << endl;
			return false;
		}
       
		reverse(start.begin(), start.end());
		reverse(end.begin(), end.end());
		if (!doMove(start, end, 'L')) {
            cout << start << ' ' << end << endl;
			return false;
		}
        
        cout << start << ' ' << end << endl;
		
		return start == end;
    }
	
private:
	bool doMove(string& start, string& end, const char c) {
        int n = start.size();
		int p = n - 1;
		int q = n - 1;
		
		while (p >= 0 && q >= 0) {
			while (p >= 0 && start[p] != c) {
				p--;
			}
			while (q >= 0 && end[q] != c) {
				q--;
			}
            
            if (p == q) {
                p--;
                q--;
                continue;
            }
			
			if ( (p < 0) ^ (q < 0) ) {
				return false;
			}
			
			if (p > q) {
				return false;
			}
			
            for (int i = p; i + 1 < n && i != q; i++) {
				if (start[i + 1] == 'X') {
					swap(start[i], start[i + 1]);
				} else {
                    break;
                }
			}

            p--;
            q--;
		}
		
		return true;
	}
};
