#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
//declaramos una funcion que nos permita calcular las temperaturas en t +deltat;
float T_sig(float T,float T1, float T2,float T3,float T4,float c){
	float T_sig=T+c*(-4*T+T1+T2+T3+T4);
	return T_sig;
}
int main(){
	float k=1.62;
	float cp=820;
	float densidad=(2.71/1000)*pow(100,3);
	float dx=0.05;
	float dt=3;
	float c=(dt*k/(densidad*cp))/(dx*dx);
	float T1,T2,T3,T4,T0;
	float x[38];
	float y[38];
	float T[38];
	float Tsig[38];
	//generar los datos del dominio matematico:
	for (int i=0;i<6;i++){
		float pos=i*dx;
		x[i]=pos;
		x[6+i]=pos;
		x[12+i]=pos;
		x[18+i]=pos;
		x[24+i]=pos;
		y[i]=0;
		y[6+i]=dx;
		y[12+i]=2*dx;
		y[18+i]=3*dx;
		y[24+i]=4*dx;
	}
	for (int i=30;i<35;i++){
		y[i]=5*dx;
		x[i]=dx*(i-30);
	}
	x[36]=0.215;y[36]=0.215; x[35]=0.204; y[35]=0.25-0.019;x[37]=0.25-0.019;y[37]=0.204;
	ofstream dominio("dominio.txt");
	for (int i=0;i<38;i++){
		dominio<<x[i]<<","<<y[i]<<"\n";
	}
	//#1) Temperatura constante en las fronteras del dominio:
	//Se imponen las condicones de frontera:
	for(int i=0;i<35;i++){
		T[i]=0;
	}
	//las fronteras externas:
	for(int i=0;i<6;i++){
		T[i]=10;
		T[6*i]=10;
	}
	//las paredes del cilindro:
	for(int i=34;i<38;i++){
		T[i]=100;
	}
	ofstream guardar("1).txt");
	for (int time_step=0;time_step<10000;time_step++){
		//nodos internos:
		for(int j=0;j<4;j++){
			for (int i=7;i<11;i++){
				T0=T[i+6*j];T1=T[i+6*j+1];T2=T[i+6*j-1];T3=T[i+6*j+6];T4=T[i+6*j-6];
				Tsig[i+6*j]=T_sig(T0,T1,T2,T3,T4,c);
			}
			
		}
		//nodos de las fronteras simetricas:
		//simetria derecha
		for (int i=11;i<24;i=i+6){
			T0=T[i];T1=T[i-1];T2=T[i-1];T3=T[i+6];T4=T[i-6];
			Tsig[i]=T_sig(T0,T1,T2,T3,T4,c);
		}
		for (int i=31;i<35;i=i+1){
			T0=T[i];T1=T[i+1];T2=T[i-1];T3=T[i-6];T4=T[i-6];
			Tsig[i]=T_sig(T0,T1,T2,T3,T4,c);
		}
		//actualizar el vector T con los datos de T_sig:
		
		for(int i=0;i<34;i++){
			T[i]=Tsig[i];
			T[i]=Tsig[i];
		}
		for(int i=0;i<6;i++){
			T[i]=10;
			T[6*i]=10;
		}
		T[29]=100;
		
		//guardar datos de temperaturas nuevas:
		for(int i=0;i<38;i++){
			guardar<<T[i]<<",";
		}
		guardar<<"\n";
	}
	//#2) fronteras abiertas:
	//se imponen las condiciones de frontera:
	for(int i=0;i<35;i++){
		T[i]=0;
	}
	//las paredes del cilindro:
	for(int i=34;i<38;i++){
		T[i]=100;
	}
	ofstream guardar2("2).txt");
	
	for (int time_step=0;time_step<100000;time_step++){
		//nodos internos:
		for(int j=0;j<4;j++){
			for (int i=7;i<11;i++){
				T0=T[i+6*j];T1=T[i+6*j+1];T2=T[i+6*j-1];T3=T[i+6*j+6];T4=T[i+6*j-6];
				Tsig[i+6*j]=T_sig(T0,T1,T2,T3,T4,c);
			}
			
		}
		//nodos de las fronteras simetricas:
		//simetria derecha
		for (int i=11;i<24;i=i+6){
			T0=T[i];T1=T[i-1];T2=T[i-1];T3=T[i+6];T4=T[i-6];
			Tsig[i]=T_sig(T0,T1,T2,T3,T4,c);
		}
		for (int i=31;i<35;i=i+1){
			T0=T[i];T1=T[i+1];T2=T[i-1];T3=T[i-6];T4=T[i-6];
			Tsig[i]=T_sig(T0,T1,T2,T3,T4,c);
		}
		//nodos de las fronteras abiertas:
		for(int i=1;i<6;i++){
			Tsig[i]=Tsig[i+6];
			Tsig[6*i]=Tsig[6*i+1];
		}
		Tsig[0]=Tsig[1];
		//actualizar el vector T con los datos de T_sig:
		
		for(int i=0;i<34;i++){
			T[i]=Tsig[i];
			T[i]=Tsig[i];
		}
		
		T[29]=100;
		
		//guardar datos de temperaturas nuevas:
		for(int i=0;i<38;i++){
			guardar2<<T[i]<<",";
		}
		guardar2<<"\n";
	}
	
	
	return 0;
	
	
	
}
