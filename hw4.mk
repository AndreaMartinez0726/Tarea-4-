Resultados_hw4.pdf: Resultados_Hw4.tex
	pdflatex Resultados_Hw4.tex


Resultados_Hw4.tex: Plots_hw4.py 1).txt 2).txt 3).txt data_10.txt data_20.txt data_30.txt data_40.txt data_50.txt data_60.txt data_70.txt 45.txt
	python Plots_hw4.py


1).txt 2).txt 3).txt : PDE.cpp
	g++ PDE.cpp -w
	./a.out


data_10 data_20 data_30 data_40 data_50 data_60 data_70 45.txt: ODE.cpp
	g++ ODE.cpp -w
	./a.out	

caso1_t\=0.jpg caso1_t\=9999.jpg caso1_t\=19998.jpg caso2_t\=0.jpg caso2_t\=99999.jpg caso2_t\=199998.jpg caso2_t\=299997.jpg caso3_t\=0.jpg caso3_t\=333330.jpg caso3_t\=666660.jpg caso 3_t\=999990.jpg T_avarage_caso1.jpg T_avarage_caso2.jpg T_avarage_caso3.jpg trayectorias.jpg: 1).txt 2).txt 3).txt data_10 data_20 data_30 data_40 data_50 data_60 data_70 45.txt
	python Plots_hw4.py
