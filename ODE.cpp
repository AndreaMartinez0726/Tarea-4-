#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

//funciones creadas para calcular a_x y a_y:
double a_x(float v_x, float v_y){
	double a_x=-sqrt(v_x*v_x+v_y*v_y)*v_x;
	return a_x;
}
double a_y (float v_x, float v_y){
	double a_y=-10-sqrt(v_x*v_x+v_y*v_y)*v_y;
	return a_y;
}

int main (){
	
	//datos del problema:
	ofstream proyectil("45.txt");
	double x=0;
	double y=0;
	double tetha=3.141592654/4;
	double v_x=300*cos(tetha);
	double v_y=300*sin(tetha);
	double dt=0.001;
	double i=0;
	while(y>=0){
		//calculamos los ks de vx y vy:
		double k1x, k1y, k2x, k2y, k3x, k3y, k4x, k4y, k1vx, k1vy, k2vx, k2vy, k3vx, k3vy, k4vx, k4vy;
		
		k1vx=a_x(v_x,v_y);
		k1vy=a_y(v_x,v_y);
		k2vx=a_x((v_x+dt*k1vx/2),(v_y+dt*k1vy/2));
		k2vy=a_y((v_x+dt*k1vx/2),(v_y+dt*k1vy/2));
		k3vx=a_x((v_x+dt*k2vx/2),(v_y+dt*k2vy/2));
		k3vy=a_y((v_x+dt*k2vx/2),(v_y+dt*k2vy/2));
		k4vx=a_x((v_x+dt*k3vx),(v_y+dt*k3vy));
		k4vy=a_y((v_x+dt*k3vx),(v_y+dt*k3vy));
		//ahora calculamos los ks de x y y:
		k1x=v_x;
		k1y=v_y;
		k2x=v_x+dt*k1vx/2;
		k2y=v_y+dt*k1vy/2;
		k3x=v_x+dt*k2vx/2;
		k3y=v_y+dt*k2vy/2;
		k4x=v_x+dt*k3vx;
		k4y=v_y+dt*k3vy;
		//calculamos el nuevo x y el nuevo y:
		y=y+dt*(k1y+2*k2y+2*k3y+k4y)/6;
		x=x+dt*(k1x+2*k2x+2*k3x+k4x)/6;
		//calculamos las velocidades:
		v_x=v_x+dt*(k1vx+2*k2vx+2*k3vx+k4vx)/6;
		if (v_x<0){
			v_x=0;
		}
		v_y=v_y+dt*(k1vy+2*k2vy+2*k3vy+k4vy)/6.0;
		i+=1;
		proyectil<<i*dt<<","<<x<<","<<y<<","<<v_x<<","<<v_y<<"\n";
		
		
		
	}
	
	
	return 0;
}


