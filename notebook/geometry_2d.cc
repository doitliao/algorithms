#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

namespace geometry{
	template < typename T>
	class Point{
	public:
		T x,y;
		Point():x(0), y(0){}
		Point(T x, T y):x(x), y(y){}

		Point operator+(const Point& rhs){
			return Point(x + rhs.x, y + rhs.y);
		}

		Point operator-(const Point& rhs){
			return Point(x - rhs.x, y - rhs.y);
		}

		T operator*(const Point& rhs){
			return x * rhs.x + y * rhs.y;
		}
		
		T operator^(const Point& rhs){
			return x * rhs.y - y * rhs.x;
		}
	};
	
	//Compute the dot product AB * BC
	template<typename T>
	T dot(Point<T>& A, Point<T>& B, Point<T>& C){
		return (B - A) * (C - B);
	}

	//Compute the cross product AB x AC
	template<typename T>
	T cross(Point<T>& A, Point<T>& B, Point<T>& C){
		return (B - A) ^ (C - A);
	}

	//Compute the distance from A to B
	template<typename T>
	double distance(Point<T>& A, Point<T>& B){
		int dx = B.x - A.x;
		int dy = B.y - A.y;
		return sqrt(dx * dx + dy * dy);
	}

	//Compute the distance from C to AB
	//if isSegment is true, AB is a segment, not a line.
	template<typename T>
	double linePointDistance(Point<T>& A, Point<T>& B, Point<T>& C, bool isSegment = false){
		double dist = cross(A, B, C) / distance(A, B);
		if(!isSegment)return dist;

		//isSegment is true.
		if(0 < dot(A, B, C)) return distance(B, C);
		if(0 < dot(B, A, C)) return distance(A, C);
		return dist;
	}

	//Compute the area of th ploygon.
	template<typename T>
	double polygon(std::vector<Point<T> >& p){
		int area = 0;
		const int N = p.size();

		//We will triangulate the polygon
		//into triangles with points p[0], p[i], p[i+1]

		for(int i = 1; i + 1 < N; i++){
			area += cross(p[0], p[i], p[i + 1]);
		}
		return std::abs(area / 2.0);
	}

	template <typename T>
	class Line{
	public:
		Line(T A, T B, T C):A(A), B(B), C(C){}
		Line(const Point<T> & X, const Point<T> & Y){
			A = Y.y - X.y;
			B = X.x - Y.x;
			C = A * X.x + B * X.y;
		}

		//Find the prependicular bisector of XY
		static Line perpendicularBisector(const Point<T> & X, const Point<T> & Y){
			T a = Y.y - X.y;
			T b = X.x - Y.x;
			T c = -1 * b * X.x + a * X.y;
			return Line(-1 * b, a, c);
		}

	public:
		T A, B, C;
	};

	//Compute the intersection point of line X and Y
	template <typename T>
	bool lineIntersection(const Line<T> & X, const Line<T> & Y, Point<double>& P){
		double det = X.A * Y.B - Y.A * X.B;
		if(det == 0)return false; // Lines are parallel

		P.x = (Y.B * X.C - X.B * Y.C) / det;
		P.y = (X.A * Y.C - Y.A * X.C) / det;
		return true;
	}
	
	//Compute intersection of line AB and CD
	template <typename T>
	bool lineIntersection(const Point<T>& A, const Point<T>& B,
												const Point<T>& C, const Point<T>& D, 
												Point<double>& P, bool isSegment){
		Line<T> X(A, B);
		Line<T> Y(C, D);
		if(false == lineIntersection(X, Y, P))return false;

		if(!isSegment) return true;
		if(isSegment){
			if( P.x < min(A.x, B.x) || P.x > max(A.x, B.x))return false;
			if( P.x < min(C.x, D.x) || P.x > max(C.x, D.x))return false;
			if( P.y < min(A.y, B.y) || P.y > max(A.y, B.y))return false;
			if( P.y < min(C.y, D.y) || P.y > max(C.y, D.y))return false;
		}
		return true;	
	}
	
	
	template <typename T>
	class Circle{
	public:
		Circle(){}
		Circle(const Point<T>& C, T r){
			center.x = C.x;
			center.y = C.y;
			radius = r;
		}
	public:
		Point<T> center;
		T radius;
	};

	//Finding a Circle From 3 Points
	template <typename T>
	bool findCircle(const Point<T> & X, const Point<T>& Y, const Point<T> & Z,
									Circle<T>& C){
		Line<T> a = Line<T>::perpendicularBisector(X, Y);		
		Line<T> b = Line<T>::perpendicularBisector(Y, Z);		
		
		Point<T> center;
		if(false == lineIntersection(a, b, center))return false;
		double radius = distance(center, X);
	}
};

using namespace geometry;
int main(){
	std::vector<geometry::Point<int> > p;
	p.push_back(geometry::Point<int> (0, 0));
	p.push_back(geometry::Point<int> (2, 0));
	p.push_back(geometry::Point<int> (2, 3));
	//p.push_back(geometry::Point(0, 3));
	
	std::cout<<geometry::polygon(p)<<std::endl;

	Point<int> A(0, 0);
	Point<int> B(3, 3);
	Point<int> C(6, 2);
	Point<int> D(5, 0);

	Point<double> P;
	cout<<lineIntersection(A, B, C, D, P, true)<<endl;
	cout<<"P: "<<P.x<<" "<<P.y<<endl;

	cout<<linePointDistance(A, C, B)<<endl;
	cout<<linePointDistance(A, C, D)<<endl;
}
