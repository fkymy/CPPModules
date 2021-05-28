#include <cstdlib>

class Point {
public:
    double getX() const;
    double getY() const;

private:
    double x, y;
    static std::size_t count;
};

int main() {
    return sizeof(Point);
}
