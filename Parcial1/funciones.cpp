#include "funciones.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>

#define G 9.81

using namespace std;

void simulacion1(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d){
    bool disp1,disp2,disp3;
    disp1=movParabolico(xd,yd,xo,yo,alphao,30,0.01,true,d);
    if(disp1) cout<<"DISPARO OFENSIVO 1 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 1 FALLIDO."<<endl;
    disp2=movParabolico(xd,yd,xo,yo,alphao,60,0.01,true,d);
    if(disp2) cout<<"DISPARO OFENSIVO 2 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 2 FALLIDO."<<endl;
    disp3=movParabolico(xd,yd,xo,yo,alphao,90,0.01,true,d);
    if(disp3) cout<<"DISPARO OFENSIVO 3 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 3 FALLIDO."<<endl;
}
void simulacion2(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d){
    bool disp1,disp2,disp3;
    disp1=movParabolico(xo,yo,xd,yd,alphad,30,0.01,false,d);
    if(disp1) cout<<"DISPARO DEFENSIVO 1 EN EL BLANC0."<<endl;
    else cout<<"DISPARO DEFENSIVO 1 FALLIDO."<<endl;
    disp2=movParabolico(xo,yo,xd,yd,alphad,60,0.01,false,d);
    if(disp2) cout<<"DISPARO OFENSIVO 2 EN EL BLANC0."<<endl;
    else cout<<"DISPARO DEFENSIVO 2 FALLIDO."<<endl;
    disp3=movParabolico(xo,yo,xd,yd,alphad,90,0.01,false,d);
    if(disp3) cout<<"DISPARO DEFENSIVO 3 EN EL BLANC0."<<endl;
    else cout<<"DISPARO DEFENSIVO 3 FALLIDO."<<endl;
}
void simulacion3(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d){
    bool disp1,disp2,disp3,disp4;
    disp4=movParabolico(xd,yd,xo,yo,alphao,30,0.01,true,d);
    if(disp4) cout<<"DISPARO OFENSIVO 1 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 1 FALLIDO."<<endl;
    disp1=movParabolico(xo,yo,xd,yd,alphad,30,0.01,false,d);
    if(disp1) cout<<"DISPARO OFENSIVO 1 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 1 FALLIDO."<<endl;
    disp2=movParabolico(xo,yo,xd,yd,alphad,60,0.01,false,d);
    if(disp2) cout<<"DISPARO OFENSIVO 2 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 2 FALLIDO."<<endl;
    disp3=movParabolico(xo,yo,xd,yd,alphad,90,0.01,false,d);
    if(disp3) cout<<"DISPARO OFENSIVO 3 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 3 FALLIDO."<<endl;
}
void simulacion4(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d){
    bool disp1,disp2,disp3,disp4;
    disp4=movParabolico(xd,yd,xo,yo,alphao,30,0.01,true,d);
    if(disp4) cout<<"DISPARO OFENSIVO 1 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 1 FALLIDO."<<endl;
    disp1=movParabolico(xo,yo,xd,yd,alphad,30,0.01,false,d);
    cout<<"TOMANDO PRECAUCIONES"<<endl;
    if(disp1) cout<<"DISPARO OFENSIVO 1 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 1 FALLIDO."<<endl;
    disp2=movParabolico(xo,yo,xd,yd,alphad,60,0.01,false,d);
    cout<<"TOMANDO PRECAUCIONES"<<endl;
    if(disp2) cout<<"DISPARO OFENSIVO 2 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 2 FALLIDO."<<endl;
    disp3=movParabolico(xo,yo,xd,yd,alphad,90,0.01,false,d);
    cout<<"TOMANDO PRECAUCIONES"<<endl;
    if(disp3) cout<<"DISPARO OFENSIVO 3 EN EL BLANC0."<<endl;
    else cout<<"DISPARO OFENSIVO 3 FALLIDO."<<endl;
}


bool movParabolico(float xf,float yf,float xi,float yi,float alpha,float t,float dt,bool ofensiveDefensive,float d){
    float vox,voy,vx,vy,time = 0.0;
    bool colision=false;
    vox=(xf-xi)/t;
    voy=(yf-yi+0.5*G*pow(t,2))/(t);
    cout<<"Velocidad en x: "<<vox<<endl;
    cout<<"Velocidad en y: "<<voy<<endl;
    while(yi>yf && xi>xf && colision==false){
        time+=dt;
        vx=vox*cos(alpha);
        vy=voy*sin(alpha)-G*dt;
        xi=xi+vx*dt;
        yi=yi+(vy*dt)+(0.5*G*pow(dt,2));
        cout<<"Time(sg): "<<time<<"Posicion x: "<<xi<<" > "<<xf<<" Posicion y: "<<yi<<" > "<<yf<<endl;
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
