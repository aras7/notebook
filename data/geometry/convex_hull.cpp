struct Point
{
	double x, y;

	Point() {}
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};

double ccw(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

Point pivot;

bool cmp(Point a, Point b) {
	return ccw(pivot, a, b) > ccw(pivot, b, a);
}

vector<Point> convex_hull_grahan_scan(vector<Point> points) {
	vector<Point> hull;

	if(points.size() >= 3)
	{
		int low_right_idx = 0;
		for(int i = 1;i < points.size();i++)
			if(points[i].x < points[low_right_idx].x)
				low_right_idx = i;
			else if(points[i].x == points[low_right_idx].x && points[i].y < points[low_right_idx].y)
				low_right_idx = i;

		swap(points[0], points[low_right_idx]);
		pivot = points[0];

		sort(points.begin()+1, points.end(), cmp);
	
		for(int i = 0; i < 2; i++)
			hull.push_back(points[i]);

		for(int i = 2; i < points.size(); i++) {
			while(hull.size() >= 2 && ccw(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0)
				hull.pop_back();

			hull.push_back(points[i]);
		}

	}

	return hull;
}
