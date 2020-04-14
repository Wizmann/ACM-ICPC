// http://poj.org/problem?id=3449

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const double eps = 1e-6;
const double pi = acos(-1);
const double inf = 1e20;

//σêñσ«Üµ¡úΦ┤ƒΘ¢╢∩╝îµ╢êΘÖñΦ»»σ╖«τÜäσ╜▒σôì
inline int zero(double x)
{
    if(x<-eps) return -1;
    else if(fabs(x)<eps) return 0;
    else return 1;
}

inline double mul(double x)
{
    return x*x;
}

//τé╣τ▒╗
struct point
{
    double x,y;
    point(){}
    point(double i_x,double i_y)
    {
        x=i_x;y=i_y;
    }
    point operator - (const point &p) const
    {
        return point(x-p.x,y-p.y);
    }
    
    point operator * (double val) const
    {
        return point(x*val,y*val);
    }
    
    point operator + (const point &p) const
    {
        return point(x+p.x,y+p.y);
    }
    friend bool operator == (const point& pa,const point& pb)
    {
        return (zero(pa.x-pb.x)==0) && (zero(pa.y-pb.y)==0);
    }
};

double pntDis(const point& a, const point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

//Φ┐öσ¢₧vector(op->sp)Σ╕Ävector(op->ep)τÜäσÉæΘçÅτº»
//abs(xmult(sp,ep,op)) = 2* Σ╕ëΦºÆσ╜óΘ¥óτº»∩╝êsp,ep,op)
//xmult(sp,ep,op) = |op->sp| * |op->ep| * sin(sop) -> Φ╛╣op->spσê░Φ╛╣op->epτÜäσñ╣ΦºÆ
//µ¡úΦ┤ƒµÇºτö¿σÅ│µëïσ«ÜσêÖσêñσ«Ü∩╝îΣ╗ÄµëïµîçΣ╗Äop->spµÅíσê░op->epµû╣σÉæ
inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

//Φ┐öσ¢₧vector(op->sp)Σ╕Ävector(op->ep)τÜäµò░ΘçÅτº»
//dotmult(sp,ep,op) = |op->sp| * |op->ep| * cos(sop) -> Φ╛╣op->spσê░Φ╛╣op->epτÜäσñ╣ΦºÆ
double dotmult(point sp,point ep,point op)
{
    return (sp.x-op.x)*(ep.x-op.x)+(sp.y-op.y)*(ep.y-op.y);
}

//µ▒éσÉæΘçÅτÜäσñ╣ΦºÆ∩╝îΣ╗Ä(sp->op)σê░(ep->op)∩╝îΦ╛âτ▓╛τí«
double getangle(const point &sp,const point &ep,const point &op)
{
    double a=atan2(sp.y-op.y,sp.x-op.x);
    double b=atan2(ep.y-op.y,ep.x-op.x);
    if(b-a>pi) a+=2*pi;
    if(a-b>pi) b+=2*pi;
    return a-b;
}

//τ║┐µ«╡
struct segment
{
    point p1,p2;
    segment(){}
    segment(const point &ip1,const point &ip2)
    {
        p1=ip1;p2=ip2;
    }
    double distopoint(const point &c)//τé╣σê░τ║┐µ«╡τÜäµ£Çσ░ÅΦ╖¥τª╗
    {
        double x=mul(p1.x-c.x)+mul(p1.y-c.y);
        double y=mul(p2.x-c.x)+mul(p2.y-c.y);
        double z=mul(p1.x-p2.x)+mul(p1.y-p2.y);
        if(x+z-y<0 || y+z-x<0) return sqrt(min(x,y));
        return fabs(xmult(c,p1,p2)/sqrt(z));
    }
    double distoline(const point &c)//τé╣σê░τ║┐µ«╡µëÇσ£¿τ¢┤τ║┐τÜäµ£Çσ░ÅΦ╖¥τª╗
    {
        return fabs(xmult(c,p1,p2))/pntDis(p1,p2);
    }   
};


//τ¢┤τ║┐
struct line
{
    double a,b,c;
    line(){}
    line(double i_a,double i_b,double i_c)
    {
        a=i_a;b=i_b;c=i_c;
    }
    
    //σêñσ«Üτ¢┤τ║┐τ¢╕τ¡ë
    friend bool operator == (const line x,const line y)
    {
        double d;
        if(!zero(y.a)) d=x.a/y.a;
        else if(!zero(y.b)) d=x.b/y.b;
        else if(zero(y.c))
        {
            if(!zero(x.b)||!zero(x.a)) return true;
            else if(zero(x.c)) return true;
            else return false;
        }
        else return false;

        if(x.a==d*y.a&&x.b==d*y.b&&x.c==d*y.c) return true;
        else return false;
    }
    
    //µ▒éΦ┐çpτé╣τÜä∩╝îσ₧éτ¢┤Σ║ÄlτÜäτ¢┤τ║┐
    line make_vertical(const point &p)
    {
        line res=(*this);
        swap(res.a,res.b);
        res.b*=-1;
        res.c=-(res.a*p.x+res.b*p.y);

        return res;
    }
    
    //τé╣σê░τ¢┤τ║┐τÜäΦ╖¥τª╗,τ▓╛σ║ªΘù«Θóÿ∩╝ü∩╝ü∩╝ü
    //σÅ»Σ╗ÑΘççτö¿τé╣σê░τ║┐µ«╡µëÇσ£¿τ¢┤τ║┐τÜäΘò┐σ║ªΣ╗úµ¢┐∩╝îΦºüSegmentτ▒╗
    double distopoint(const point &p)
    {
        return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
    }
};

line makeLine(point p1,point p2)
{
    line res;
    int sig=1;
    res.a=p2.y-p1.y;
    if(zero(res.a)<0)
    {
        sig=-1;
        res.a=sig*res.a;
    }
    res.b=sig*(p1.x-p2.x);
    res.c=sig*(p1.y*p2.x-p2.y*p1.x);
    return res;
}

line makeLine(segment s)
{
    return makeLine(s.p1,s.p2);
}

bool lineIntersect(line l1,line l2,point &p)
{
    double d=l1.a*l2.b-l2.a*l1.b;
    if(fabs(d)<eps) return false;
    else
    {
        p.x = (l2.c*l1.b-l1.c*l2.b)/d;
        p.y = (l2.a*l1.c-l1.a*l2.c)/d;
        return true;
    }
}

bool segIntersect(segment l1,segment l2,point &p)//τ║┐µ«╡τ¢╕Σ║ñ∩╝îσîàµï¼τë╣µ«èτÜäµâàσå╡
{
    if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x))&&
       (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y))&&
       (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x))&&
       (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y))&&//σ┐½ΘÇƒµÄÆµûÑσ«₧Θ¬î
       (xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2)<=eps)&&
       (xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2)<=eps))//Φ╖¿τ½ïσ«₧Θ¬î
    {
        lineIntersect(makeLine(l1),makeLine(l2),p);
        return true;
    }
    else return false;
}

//τ║┐µ«╡σ╗╢Θò┐
segment extendSegment(point p1,point p2,int flag,double ext)
{
    //flag==0µù╢∩╝îΣ╕ìσ╗╢Θò┐;
    //flag==1µù╢∩╝îΣ╗Äp1σÉæp2σ╗╢Θò┐
    //flag==2µù╢∩╝îΣ╗Äp2σÉæp1σ╗╢Θò┐
    //flag==3µù╢∩╝îσÅîσÉæσ╗╢Θò┐
    segment res;
    double d=0;
    res.p1=p1;
    res.p2=p2;
    if(fabs(p1.x-p2.x)>eps) d=ext/fabs(p1.x-p2.x);
    if(d==0||fabs(p1.y-p2.y)>eps) d=ext/fabs(p1.y-p2.y);
    if(flag & 1)
    {
        res.p2.x+= (p2.x-p1.x)*d;
        res.p2.y+= (p2.y-p1.y)*d;
    }
    if(flag & 2)
    {
        res.p1.x+= (p1.x-p2.x)*d;
        res.p1.y+= (p1.y-p2.y)*d;
    }
    return res;
}

bool onSegment(segment s,point p)
{
    return zero(xmult(s.p2,p,s.p1))==0 &&
            zero((p.x-s.p1.x)*(p.x-s.p2.x))<=0 &&
            zero((p.y-s.p1.y)*(p.y-s.p2.y))<=0;
}

vector<string> strsplit(const string& str, char delim = ' ') {
    vector<string> res;
    string buffer;

    int n = str.size();
    for (int i = 0; i < n; i++) {
        if (str[i] == delim) {
            if (!buffer.empty()) {
                res.push_back(buffer);
                buffer = "";
            }
        } else {
            buffer += str[i];
        }
    }
    if (!buffer.empty()) {
        res.push_back(buffer);
    }
    return res;
}

point parse_point(std::string str) {
    int n = str.size();
    assert(str[0] == '(');
    assert(str[n - 1] == ')');

    str = str.substr(1, n - 2);
    vector<string> tokens = strsplit(str, ',');

    return point(atoi(tokens[0].c_str()), atoi(tokens[1].c_str()));
}

struct Shape {
    char name;
    vector<segment> segs;

    bool operator < (const Shape& other) const {
        return name < other.name;
    }

    Shape() {}
    Shape(const vector<string>& tokens) {
        name = tokens[0][0];
        if (tokens[1] == "line") {
            segs.push_back(
                segment
                (
                    parse_point(tokens[2]),
                    parse_point(tokens[3])
                )
            );
        } else {
            vector<point> ps;
            if (tokens[1] == "square") {
                point p0 = parse_point(tokens[2]);
                point p2 = parse_point(tokens[3]);

                point p1;
                point p3;

                p1.x = ((p0.x + p2.x) + (p2.y - p0.y)) / 2.0;
                p1.y = ((p0.y + p2.y) + (p0.x - p2.x)) / 2.0;
                p3.x = ((p0.x + p2.x) - (p2.y - p0.y)) / 2.0;
                p3.y = ((p0.y + p2.y) - (p0.x - p2.x)) / 2.0;

                ps.push_back(p0);
                ps.push_back(p1);
                ps.push_back(p2);
                ps.push_back(p3);

            } else if (tokens[1] == "rectangle") {
                point p0 = parse_point(tokens[2]);
                point p1 = parse_point(tokens[3]);
                point p2 = parse_point(tokens[4]);
                ps.push_back(p0);
                ps.push_back(p1);
                ps.push_back(p2);

                double x = p2.x + (p0.x - p1.x);
                double y = p2.y + (p0.y - p1.y);

                ps.push_back(point(x, y));
            } else if (tokens[1] == "polygon") {
                int n = tokens.size();
                for (int i = 3; i < n; i++) {
                    ps.push_back(parse_point(tokens[i]));
                }
            } else if (tokens[1] == "triangle") {
                int n = tokens.size();
                for (int i = 2; i < n; i++) {
                    ps.push_back(parse_point(tokens[i]));
                }
            } else {
                assert(false);
            }

            int n = ps.size();
            for (int i = 0; i + 1 < n; i++) {
                segs.push_back(
                    segment(ps[i], ps[i + 1])
                );
            }
            segs.push_back(
                segment(ps[0], ps[n - 1])
            );

            /*
            printf("%c\n", name);
            for (int i = 0; i < ps.size(); i++) {
                printf("%f, %f\n", ps[i].x, ps[i].y);
            }
            puts("---");
            */
        }
    }

    bool intersect(const Shape& other) {
        int n = segs.size();
        int m = other.segs.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                point p;
                if (segIntersect(segs[i], other.segs[j], p)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    while (true) {
        vector<Shape> shapes;

        while (true) {
            string buffer;
            getline(cin, buffer);
            vector<string> tokens = strsplit(buffer);
            if (tokens.size() == 1) {
                break;
            }
            Shape s(tokens);
            shapes.push_back(s);
        }

        sort(shapes.begin(), shapes.end());

        if (shapes.size() == 0) {
            break;
        }

        int n = shapes.size();
        for (int i = 0; i < n; i++) {
            vector<char> intersect;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (shapes[i].intersect(shapes[j])) {
                    intersect.push_back(shapes[j].name);
                }
            }
            sort(intersect.begin(), intersect.end());

            if (intersect.size() == 0) {
                printf("%c has no intersections\n", shapes[i].name);
            } else if (intersect.size() == 1) {
                printf("%c intersects with %c\n",
                        shapes[i].name,
                        intersect[0]);
            } else if (intersect.size() == 2) {
                printf("%c intersects with %c and %c\n",
                        shapes[i].name,
                        intersect[0],
                        intersect[1]);
            } else {
                printf("%c intersects with ", shapes[i].name);
                int m = intersect.size();
                for (int i = 0; i < m; i++) {
                    if (i != m - 1) {
                        printf("%c, ", intersect[i]);
                    } else {
                        printf("and %c\n", intersect[i]);
                    }
                }
            }
        }
        puts("");
    }
    return 0;
}
