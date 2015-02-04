#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate
{
    Coordinate()
    {}
    Coordinate(int x, int y)
        :x(x),
        y(y)
    {}

    int x, y;
};

#endif