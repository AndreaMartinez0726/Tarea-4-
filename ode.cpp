#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

//funciones creadas para calcular a_x y a_y:
float a_x(float v_x, float v_y){
	float a_x=-sqrt(v_x*v_x+v_y*v_y)*v_x;
	return a_x;
}
float a_y (float v_x, float v_y){
	float a_y=-10-sqrt(v_x*v_x+v_y*v_y)*v_y;
	return a_y;
}

int main (){
	//datos del problema:
	ofstream proyectil("45°.txt");
	float x=0;
	float y=0;
	float tetha=3.141592654/4;
	float v_x=300*cos(tetha);
	float v_y=300*sin(tetha);
	float dt=0.001;
	float i=0;
	while(y>=0){
		//calculamos los ks de vx y vy:
		float k1x, k1y, k2x, k2y, k3x, k3y, k4x, k4y, k1vx, k1vy, k2vx, k2vy, k3vx, k3vy, k4vx, k4vy;
		
		k1vx=a_x(v_x,v_y);
		k1vy=a_y(v_x,v_y);
		k2vx=a_x((v_x+dt*k1vx/2),(v_y+dt*k1vy/2));
		k2vy=a_y((v_x+dt*k1vx/2),(v_y+dt*k1vy/2));
		k3vx=a_x((v_x+dt*k2vx/2),(v_y+dt*k2vy/2));
		k3vy=a_y((v_x+dt*k2vx/2),(v_y+dt*k2vy/2));
		k4vx=a_x((v_x+dt*k3vx),(v_y+dt*k3vy));
		k4vy=a_y((v_x+dt*k3vx),(v_y+dt*k3vy));
		
	
	
	
	
	return 0;
}
