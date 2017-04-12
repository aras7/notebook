pair<pair<Point, Point>, double > closest_pair_point_distance(vector<Point>points) {
    /*
    Use Sweep Line
    points must have at least 2 points
    */
    if(points.size() <= 1)
        return make_pair(make_pair(Point(), Point()), static_cast<double>(INF));

    sort(points.begin(), points.end(), cmp);

    pair<Point, Point> closest_points = make_pair(points[0], points[1]);
    double dist, min_distance = points[0].distance(points[1]);

    int left = 0;
    set<Point> tree;
    set<Point>::iterator start_box, end_box;

    tree.insert(points[0]);
    tree.insert(points[1]);

    for(int right = 2; right < points.size(); right++) {
        while(points[right].x - points[left].x > min_distance)
           tree.erase(points[left++]);

        start_box = tree.lower_bound(Point(points[right].x - min_distance, points[right].y - min_distance));
        end_box = tree.lower_bound(Point(points[right].x, points[right].y + min_distance));

        while(start_box != end_box) {
           dist = points[right].distance(*start_box);

           if(dist < min_distance) {

              min_distance = dist;
              closest_points = make_pair(points[right], *start_box);
           }
           start_box++;
        }

        tree.insert(points[right]);
    }

    return make_pair(closest_points, min_distance);
}
