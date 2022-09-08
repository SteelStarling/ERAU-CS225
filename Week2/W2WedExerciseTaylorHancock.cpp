/**
 * @file W2WedExerciseTaylorHancock.cpp
 * @author Taylor Hancock (hancoct6@my.erau.edu)
 * @brief 
 * @version 0.1
 * @date 09/07/2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double angle;
    cout<<"Enter the angle in degrees:";
    cin>>angle;
    angle *= (M_PI/180);
    cout<<"cos("<<angle<<")="<<cos(angle)<<endl;
    cout<<"sin("<<angle<<")="<<sin(angle)<<endl;
    cout<<"tan("<<angle<<")="<<tan(angle)<<endl;
    return 0;
}