class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ans = rect_area(A, B, C, D) + rect_area(E, F, G, H);
        int delta = rect_intersect(A, B, C, D, E, F, G, H);
        return ans - delta;
    }
private:
    int rect_area(int a, int b, int c, int d) {
        return abs(a - c) * abs(b - d);
    }
    
    int rect_intersect(int a, int b, int c, int d, int e, int f, int g, int h) {
        int x = abs(a - c) + abs(e - g) - abs(min(a, e) - max(c ,g));
        int y = abs(b - d) + abs(f - h) - abs(min(b, f) - max(d, h));
        
        if (x < 0 || y < 0) {
            return 0;
        }
        return x * y;
    }
};
