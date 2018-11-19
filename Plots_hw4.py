
import numpy 
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D




#graficas de las trayectorias del proyectil:
#la trayectoria de 45°:
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
plt.savefig('trayectorias.pdf')








