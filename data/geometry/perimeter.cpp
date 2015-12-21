double distance(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double perimeter_of_figure_lines(vector<Point> points) {
	double perimeter = distance(points[0], points[points.size()-1]);

	for(int i = 1; i < points.size(); i++)
		perimeter += distance(points[i-1], points[i]);

	return perimeter;
}