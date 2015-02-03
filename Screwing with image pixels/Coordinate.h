#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate
{
    Coordinate(int x, int y)
        :x(x),
        y(y)
    {}

    const int x, y;

private:
    Coordinate& operator=(const Coordinate &tmp) = delete;
};

#endif