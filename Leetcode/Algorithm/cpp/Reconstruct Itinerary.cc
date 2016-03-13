class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		map<string, int> mp;
		vector<string> nodelist;
		_n = tickets.size();
		
		for (auto& ticket: tickets) {
			mp[ticket.first] = -1;
			mp[ticket.second] = -1;
		}
		int idx = 0;
		for (auto& p: mp) {
			p.second = idx++;
			nodelist.push_back(p.first);
		}
		_g.resize(idx);
		idx = 0;
		for (const auto& ticket: tickets) {
			int a = mp[ticket.first];
			int b = mp[ticket.second];
			_g[a].push_back({b, idx++});
		}
		for (auto& line: _g) {
		    sort(line.begin(), line.end());
		}
		vector<int> _tmp;
		dfs(mp["JFK"], 0, _tmp);
		vector<string> res;
		for (auto node: _path) {
			res.push_back(nodelist[node]);
		}
		return res;
	}
private:
	void dfs(int cur, int step, vector<int>& tmp) {
	    if (!_path.empty()) {
	        return;
	    }
		tmp.push_back(cur);
		if (step == _n) {
			if (_path.empty() || tmp < _path) {
				_path = tmp;
			}
			goto END;
		}
		
		for (auto nextp: _g[cur]) {
			int next = nextp.first;
			int nr = nextp.second;
			
			if (_visit.find({cur, nr}) != _visit.end()) {
				continue;
			}

			_visit.insert({cur, nr});
			
			dfs(next, step + 1, tmp);
			
			_visit.erase(_visit.find({cur, nr}));
		}
END:
		tmp.pop_back();
	}
private:
	set<pair<int, int> > _visit;
	vector<int> _path;
	vector<vector<pair<int, int> > > _g;
	int _n;
};
