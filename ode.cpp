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
	
	
	
	
	
	return 0;
}
