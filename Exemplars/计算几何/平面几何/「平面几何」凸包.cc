bool isConvex(point poly[])
{
	for(int i=0;i<n;i++)
	{
		int j=(i+1)%n;
		int k=(i+2)%n;
		if(xmult(poly[j],poly[k],poly[i])<0)//当点是逆时针给出时，取小于0，当顺时针给出时，取大于
		{
			return false;
		}
	}
	return true;
}


typedef long long llint;

const double eps=1e-8;

inline int zero(double x)
{
    if(x>eps) return 1;
    else if(x<-eps) return -1;
    else return 0;
}

struct CPoint {
    llint x, y;
};

class ConvexHull {
public:
    template <typename T>
    T mul(const T& value) {
        return value * value;
    }

    double xmult(const CPoint& sp, const CPoint& ep, const CPoint& op) {
        return ((sp.x - op.x) * (ep.y - op.y) - (sp.y - op.y) * (ep.x - op.x));
    }

    double pntDis(const CPoint& p1, const CPoint& p2) {
        return sqrt(mul(p1.x - p2.x) + mul(p1.y - p2.y));
    }

    void add_point(int x, int y) {
        points.push_back({x, y});
    }

    int findtop() {
        int res = 0;
        for(int i = 1; i < points.size(); i++) {
            if (points[i].y < points[res].y) {
                res = i;
            } else if(points[i].y == points[res].y && points[i].x < points[res].x) {
                res=i;
            }
        }
        return res;
    }

    const vector<CPoint> graham() {
        int top = findtop();
        pstack.push_back(points[top]);
        swap(points[0], points[top]);

        sort(points.begin() + 1, points.end(), [&](const CPoint& p1, const CPoint& p2) -> bool {
            if (xmult(p1, p2, points[0]) > 0) {
                return true;
            } else if (xmult(p1, p2, points[0]) == 0 && pntDis(p1, points[0]) < pntDis(p2, points[0])) {
                return true;
            } else {
                return false;
            }
        });

        pstack.push_back(points[1]);
        pstack.push_back(points[2]);
        for(int i = 3; i < points.size(); i++) {
            while (zero(xmult(points[i], pstack[pstack.size() - 1], pstack[pstack.size() - 2])) > 0) {
                pstack.pop_back();//有等号时，不包括点都在一条直线的情况
            }
            pstack.push_back(points[i]);
        }
        return pstack;
    }
private:
    vector<CPoint> points;
    vector<CPoint> pstack;
};

