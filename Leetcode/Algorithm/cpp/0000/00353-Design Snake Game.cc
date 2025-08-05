#include <deque>

const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food_) {
        snake.push_back({0, 0});
        snakest.insert({0, 0});
        w = width;
        h = height;
        f = 0;
        food = food_;
        
        dirmp["U"] = 0;
        dirmp["R"] = 1;
        dirmp["D"] = 2;
        dirmp["L"] = 3;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int dir = dirmp[direction];
        
        int y = snake.begin()->first;
        int x = snake.begin()->second;
        
        int ny = y + my[dir];
        int nx = x + mx[dir];
                
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
            return -1;
        }
        
        if (f < food.size() && food[f].first == ny && food[f].second == nx) {
            f++;
            snake.push_front({ny, nx});
            snakest.insert({ny, nx});
            return f;
        }

        auto tail = *snake.rbegin();
        snake.pop_back();
        snakest.erase(snakest.find(tail));
        
        pair<int, int> next = {ny, nx};
        if (snakest.count(next) != 0) {
            return -1;
        }
        
        snake.push_front(next);
        snakest.insert(next);
        
        return f;
    }
private:
    deque<pair<int, int> > snake;
    int w, h;
    int f;
    vector<pair<int, int> > food;
    map<string, int> dirmp;
    set<pair<int, int> > snakest;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
