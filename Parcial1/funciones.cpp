#include "funciones.h"
#include <math.h>
#include <iostream>

#define G 9.81

using namespace std;

void movParabolico(float xf,float yf,float xi,float yi,float alpha,float t,float dt){
    int vox,voy,vx,vy;
    vox=(xf-xi)/t;
    voy=(yf-yi+0.5*G*pow(t,2))/(t);
    cout<<"Velocidad en x: "<<vox<<endl;
    cout<<"Velocidad en y: "<<voy<<endl;
    while(yi>yf && xi>xf){
        vx=vox*cos(alpha);
        vy=voy*sin(alpha)-G*dt;
        xi=xi+vx*dt;
        yi=yi+(vy*dt)+(0.5*G*pow(dt,2));
        cout<<"Posicion x: "<<xi<<" > "<<xf<<endl;
        cout<<"Posicion y: "<<yi<<" > "<<yf<<endl;
    }
}
