#include "randomfunctions.h"
#include <bits/stdc++.h>
#include <map>
#include <QDebug>
/*Scale 1:
 * 7E00FF
 * 4E00FF
 * 1C00FF
 * 0029D5
 * 008974
 * 00EB12
 * 4EFF00
 * B0FF00
 * FFF500
 * FFC500
 * */
QColor randomfunctions::calculate_color(float value){
    std::map<float,int*> colorMap;
    int blue[] = {0,0,255};
    int two[] = {0,20,235};
    int three[] = {0,40,215};
    int four[] = {0,60,205};
    int five[] = {0,80,185};
    int six[] = {0,105,165};
    int seven[] = {0,130,145};
    int eight[] = {0,155,125};
    int nine[] = {0,180,105};
    int ten[] = {0,205,85};
    int eleven[] = {0,230,65};
    int yellow[] = {255,255,0};
    int thirteen[] = {255,240,0};
    int fourteen[] = {255,210,0};
    int fifteen[] = {255,180,0};
    int sixteen[] = {255,150,0};
    int seventeen[] = {255,120,0};
    int eighteen[] = {255,90,0};
    int nineteen[] ={255,60,0};
    colorMap[0.05] = blue;
    colorMap[0.1] = two;
    colorMap[0.2] = three;
    colorMap[0.3] = four;
    colorMap[0.5] = five;
    colorMap[0.7] = six;
    colorMap[1] = seven;
    colorMap[1.5] = eight;
    colorMap[2] = nine;
    colorMap[3] =ten;
    colorMap[5] =eleven;
    colorMap[7] = yellow;
    colorMap[10] = thirteen;
    colorMap[15] = fourteen;
    colorMap[20] =fifteen;
    colorMap[30] = sixteen;
    colorMap[50] = seventeen;
    colorMap[70] = eighteen;
    colorMap[100] =nineteen;
    std::map<float,int*>::iterator check = colorMap.begin();
    int color[3] = {0, 0, 0};
    int *current = color;
    while(check != colorMap.end()){
        qDebug()<<check->first;
        if(value < (check->first)/500){
            qDebug()<<"Color found!";
            return QColor(current[0],current[1],current[2],0);
        }
        current = check->second;
        check++;
    }
//    int min;
//    int max;
//    min = 0;
//    max = 1;
//    int r,g;
//    r = (value-min)/(max-min)*127 + 128;
//    g = 255 - (value-min)/(max-min)*255;
    qDebug("Error");
    return QColor(10,10,10,0);
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
