const int N = 2;
const int M = 3;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        map<int, int> dp;
		const int start = hash(board);
		const int dest = hash({ {1, 2, 3}, {4, 5, 0} });
		
		dp[start] = 0;
		queue<int> q;
		q.push(start);
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			board = unhash(cur);
			
			int y = -1;
			int x = -1;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (board[i][j] == 0) {
						y = i;
						x = j;
					}
				}
			}
			
			for (int i = 0; i < 4; i++) {
				int ny = y + my[i];
				int nx = x + mx[i];
				
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
					continue;
				}
				
				swap(board[y][x], board[ny][nx]);
				
				int u = hash(board);
				if (dp.count(u) == 0 || dp[u] > dp[cur] + 1) {
					dp[u] = dp[cur] + 1;
					q.push(u);
				}
				
				swap(board[y][x], board[ny][nx]);
			}
		}
		return dp.count(dest) == 0? -1: dp[dest];		
    }
private:
	int hash(const vector<vector<int>>& board) {
		int cur = 1;
		int res = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				res += cur * board[i][j];
				cur *= 8;
			}
		}
		
		return res;
	}
	
	vector<vector<int> > unhash(int u) {
		vector<vector<int> > board(N, vector<int>(M, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board[i][j] = u & 7;
				u >>= 3;
			}
		}
		return board;
	}
};
