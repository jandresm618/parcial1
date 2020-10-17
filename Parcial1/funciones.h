#ifndef FUNCIONES_H
#define FUNCIONES_H

bool movParabolico(float xf, float yf, float xi, float yi, float alpha, float t, float dt, bool ofensiveDefensive,float d);
bool detectColision(float xo,float yo,float xd,float yd,bool ofensiveDefensive,float d);
void simulacion1(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d);
void simulacion2(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d);
void simulacion3(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d);
void simulacion4(float xo,float yo,float xd,float yd,float alphao,float alphad ,float d);

#endif // FUNCIONES_H
