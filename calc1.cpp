#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
 
float * zNought(float h, float Ec, float Em){

    static float zNoughtValues[10];
    float Erat;

    Erat = Ec/Em;

    for (int i = 1; i < 11; i++) {
        zNoughtValues[i] = ( i*h*(Erat-1) )/(2*(i+2)*(Erat+1));
    }

    return zNoughtValues;
} 

int main () {
    float l = 0.5;
    float b = 04;
    float h = 0.003;
    float Ec = 380.0;
    float Em = 70.0;

    float z0;
    float *zNoughtValues;
    zNoughtValues = zNought(h, Ec, Em);

    for (int i = 1; i<11; i++){

        printf("z0 value for k = %d is %f \n", i, *(zNoughtValues + i));
    }
    return 0;
}

