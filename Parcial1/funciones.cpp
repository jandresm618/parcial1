#include "funciones.h"
#include <math.h>
#include <iostream>

#define G 9.81

using namespace std;

void movParabolico(float xf,float yf,float xi,float yi,float alpha,float t,float dt){
    int vox,voy;
    vox=(xf-xi)/(cos(alpha)*t);
    voy=(yf-yi+1.5*G*pow(t,2));
    cout<<"Velocidad en x: "<<vox<<endl;
    cout<<"Velocidad en y: "<<voy<<endl;
    while(yi>yf && xi>xf){
        xi=xi+vox*dt;
        yi=yi+(voy*dt)+(0.5*G*pow(dt,2));
        cout<<"Posicion x: "<<xi<<" > "<<xf<<endl;
        cout<<"Posicion y: "<<yi<<" > "<<yf<<endl;
    }
}
