
import numpy 
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D




#graficas de las trayectorias del proyectil:
#la trayectoria de 45 grados:
punto_1=numpy.loadtxt('45.txt',float,delimiter=',')
plt.plot(punto_1[:,1],punto_1[:,2])
plt.hold(True)
#el resto de trayectorias:
for k in range(7):
    punto_1=numpy.loadtxt('data_'+str(10+10*k),float,delimiter=',')
    plt.plot(punto_1[:,1],punto_1[:,2])
    plt.hold(True)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Trayectorias a diferentes angulos, considerando fuerzas de arrastre')
plt.legend(('$\epsilon$'+'=10','$\epsilon$'+'=20','$\epsilon$'+'=30','$\epsilon$'+'=40','$\epsilon$'+'=50','$\epsilon$'+'=60','$\epsilon$'+'=70','$\epsilon$'+'=45'),loc='upper right')
plt.savefig('trayectorias.png')




#graficas para el problema de diferencias finitas:
#leemos las coordenadas de los puntos usados para discretizar el dominio:
mesh=numpy.loadtxt('dominio.txt',float,delimiter=',')
x=mesh[:,0]
y=mesh[:,1]
plt.hold(False)


# realizamos las graficas:
dt=(3,3,10)
steps=(10000,100000,100000)
figura = plt.figure()

for i in range(3):
    T=numpy.loadtxt(str(i+1)+').txt',float,delimiter=',',usecols=range(38))#se cargan los datos;
    #ahora ejecutamos otro ciclo, de 4 pasos para graficar
    for j in range(4):
        intervalo=int(steps[i]/3)
        T_graficar=T[intervalo*j,:]
        proyeccion = figura.gca(projection='3d')
        proyeccion.plot_trisurf(x, y, T_graficar, cmap=plt.cm.autumn)
        figura.savefig('caso'+str(i+1)+'_t'+str(intervalo*j*dt[i])+'.png')
        figura.clear()
        
   




