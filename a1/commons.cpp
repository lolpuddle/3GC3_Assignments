# include <vector>

// Brush Type 1 = Point
// Brush Type 2 = Line
// Brush Type 3 = Rectangle
// Brush Type 4 = Circle
// Brush Type 5 = Radial

struct Brush { 
    int brushType = 1;
    float r = 1.0;
    float g = 1.0;
    float b = 1.0;
} brush;

struct Point {
    int x;
    int y;
    float r;
    float g;
    float b;
};

std::vector<Point> points;
