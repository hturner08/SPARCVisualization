#ifndef RANDOMFUNCTIONS_H
#define RANDOMFUNCTIONS_H
#include <QColor>
#include <map>

class randomfunctions
{
public:
    static QColor calculate_color(float);
    static std::map<int,int[]> *colors;
};
#endif // RANDOMFUNCTIONS_H
