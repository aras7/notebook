struct Point{
    int idx;
    double x, y;

    Point(): idx(-1), x(0), y(0) {}
    Point(double _x, double _y): idx(-1) {
       x = _x, y = _y;
    }

    Point(int _id, double _x, double _y) {
       idx = _id, x = _x, y = _y;
    }

    // sort increasing per 'y' first
    bool operator<(const Point& p) const {
        return (y != p.y) ? y < p.y : x < p.x;
    }

    bool operator==(const Point& p) const {
        return x == p.x &&  y == p.y;
    }

    double distance(Point p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    void const print(bool salt=true) const {
      printf("[%d](%lf, %lf)", idx, x, y);
      if(salt) puts("");
    }
};
// sort increasing per 'x' first
bool cmp(Point a, Point b) {
    return (a.x != b.x) ? a.x < b.x : a.y < b.y;
}
