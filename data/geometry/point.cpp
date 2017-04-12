template <class T>
struct PointBase{
    int idx;
    T x, y;

    PointBase(): idx(-1), x(0), y(0) {}
    PointBase(T _x, T _y): idx(-1) {
       x = _x, y = _y;
    }

    PointBase(int _id, T _x, T _y) {
       idx = _id, x = _x, y = _y;
    }

    // sort increasing per 'y' first
    bool operator<(const PointBase& p) const {
        return (y != p.y) ? y < p.y : x < p.x;
    }

    bool operator==(const PointBase& p) const {
        return x == p.x &&  y == p.y;
    }

    T distance(PointBase p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    void const print(bool salt=true) const {
      printf("[%d](%lf, %lf)", idx, x, y);
      if(salt) puts("");
    }
};
typedef PointBase<double> Point;

// sort increasing per 'x' first
bool cmp(Point a, Point b) {
    return (a.x != b.x) ? a.x < b.x : a.y < b.y;
}

