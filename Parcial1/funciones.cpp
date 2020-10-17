#include "funciones.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>

#define G 9.81

using namespace std;

bool movParabolico(float xf,float yf,float xi,float yi,float alpha,float t,float dt,bool ofensiveDefensive,float d){
    int vox,voy,vx,vy;
    bool colision=false;
    vox=(xf-xi)/t;
    voy=(yf-yi+0.5*G*pow(t,2))/(t);
    cout<<"Velocidad en x: "<<vox<<endl;
    cout<<"Velocidad en y: "<<voy<<endl;
    while(yi>yf && xi>xf && colision==false){
        vx=vox*cos(alpha);
        vy=voy*sin(alpha)-G*dt;
        xi=xi+vx*dt;
        yi=yi+(vy*dt)+(0.5*G*pow(dt,2));
        cout<<"Posicion x: "<<xi<<" > "<<xf<<endl;
        cout<<"Posicion y: "<<yi<<" > "<<yf<<endl;
        //Ataque ofensivo
        colision=detectColision(xf,yf,xi,yi,ofensiveDefensive,d);
    }
    return colision;
}

bool detectColision(float xo,float yo,float xd,float yd,bool ofensiveDefensive,float d){
    int x,y,r;
    x=abs(xo-xd);
    y=abs(yo-yd);
    r=sqrt(pow(x,2)+pow(y,2));
    if(ofensiveDefensive){
        //Si el ataque es ofensivo --> r = 0.05d
        if(r>0.05*d)return false;
        else return true;
    }
    else{
        //Si el ataque es defensivo --> r = 0.025d
        if(r>0.025*d)return false;
        else return true;
    }
}
