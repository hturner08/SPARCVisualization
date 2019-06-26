#include "randomfunctions.h"
#include <bits/stdc++.h>
#include <map>
//Green
//R:128
//G:255
//B:0
//Red
//R:255
//G:0
//B:0

QColor randomfunctions::calculate_color(float value){
    int niceValue = int(log10(value));
    int min;
    int max;
    min = 0;
    max = 1;
    int r,g;
    r = (value-min)/(max-min)*127 + 128;
    g = 255 - (value-min)/(max-min)*255;
    return QColor(r,g,0,0);
}
/*
LVL2
'Level Flags LColor LStyle LWidth FFGColor FBGColor FPattern FMode FScale FType
0.05 1 "Black" "Solid" 30 "Blue" "White" "Solid" 2 1 1
0.1 0 "Black" "Solid" 20 "R0 G20 B235" "White" "Solid" 2 1 1
0.2 0 "Black" "Solid" 30 "R0 G40 B215" "White" "Solid" 2 1 1
0.3 0 "Black" "Solid" 20 "R0 G60 B205" "White" "Solid" 2 1 1
0.5 0 "Black" "Solid" 30 "R0 G80 B185" "White" "Solid" 2 1 1
0.7 1 "Black" "Solid" 20 "R0 G105 B165" "White" "Solid" 2 1 1
1 0 "Black" "Solid" 30 "R0 G130 B145" "White" "Solid" 2 1 1
1.5 0 "Black" "Solid" 20 "R0 G155 B125" "White" "Solid" 2 1 1
2 0 "Black" "Solid" 30 "R0 G180 B105" "White" "Solid" 2 1 1
3 0 "Black" "Solid" 20 "R0 G205 B85" "White" "Solid" 2 1 1
5 1 "Black" "Solid" 30 "R0 G230 B65" "White" "Solid" 2 1 1
7 1 "Black" "Solid" 20 "Yellow" "White" "Solid" 2 1 1
10 1 "Red" "Solid" 30 "R255 G240 B0" "White" "Solid" 2 1 1
15 1 "Black" "Solid" 20 "R255 G210 B0" "White" "Solid" 2 1 1
20 1 "Black" "Solid" 30 "R255 G180 B0" "White" "Solid" 2 1 1
30 1 "Black" "Solid" 15 "R255 G150 B0" "White" "Solid" 2 1 1
50 1 "Black" "Solid" 30 "R255 G120 B0" "White" "Solid" 2 1 1
70 1 "Black" "Solid" 10 "R255 G90 B0" "White" "Solid" 2 1 1
100 1 "Black" "Solid" 30 "R255 G60 B0" "White" "Solid" 2 1 1
*/
