#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
 
float * zNought(float h, float Erat){

    static float zNoughtValues[10];

    for (int i = 1; i < 11; i++) {
        zNoughtValues[i] = ( i*h*(Erat-1) )/(2*(i+2)*(Erat+1));
    }

    return zNoughtValues;
}

float calcDc(float h, float Ec, float pr) {

    float Dc;

    Dc = (Ec*h*h*h)/(12*(1-(pr*pr)));

    return Dc;
}

float * calcDeff (float h, float Erat, float Dc, float* zNoughtValues) {

    static float DeffValues[10];

    for (int i = 1; i < 11; i++) {
        DeffValues[i] = ( (12*Dc/Erat) * ( ( (3*Erat*(pow(i,2) + i + 2)) + (pow(i,3) + 3*pow(i,2) + 8*i) )/( 12*(i+1)*(pow(i,2) + 5*i + 6) ) - (zNoughtValues[i]* i * (Erat-1))/(h*(i+1)*(i+2)) + (pow(zNoughtValues[i],2)*(Erat+i))/(h * (i+1)) ) );
    }

    return DeffValues;
}

float * calcINought (float rhoc, float h, float rhorat) {

    static float iNoughtValues[10];

    for (int i = 1; i<11 ; i++) {
        iNoughtValues[i] = (rhoc*h/rhorat) * ( ( (rhorat - 1)/(i+1) ) + 1 );
    }

    return iNoughtValues;
} 


int main () {
    float l = 0.5;
    float b = 04;
    float h = 0.003;
    float Ec = 380.0;
    float Em = 70.0;
    float pr = 0.3;
    float rhoc = 3800;
    float rhom = 2700;
    float Erat;
    float rhorat;

    Erat = Ec/Em;
    rhorat = rhoc/rhom;

    float z0;
    float *zNoughtValues;
    zNoughtValues = zNought(h, Erat);

    float Dc;
    Dc=calcDc(h, Ec, pr);

    float *Deff;
    Deff = calcDeff(h, Erat, Dc, zNoughtValues);

    float *iNought;
    iNought = calcINought(rhoc, h, rhorat);

    for (int i = 1; i<11; i++){
        printf("for k = %d, z0 = %f, Deff = %.12lf, i0 = %f \n" , i, *(zNoughtValues + i), *(Deff + i), *(iNought + i));
    }

    return 0;
}

