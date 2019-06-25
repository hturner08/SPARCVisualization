#include "randomfunctions.h"
//Green
//R:128
//G:255
//B:0
//Red
//R:255
//G:0
//B:0
randomfunctions::randomfunctions()
{
}
QColor randomfunctions::calculate_color(float value){
    int min;
    int max;
    min = 0;
    max = 1;
    int r,g;
    r = (value-min)/(max-min)*127 + 128;
    g = 255 - (value-min)/(max-min)*255;
    return QColor(r,g,0,0);
}
