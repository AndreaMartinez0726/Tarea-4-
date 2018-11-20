Resultados_hw4.pdf: Resultados_Hw4.tex
	pdflatex Resultados_Hw4.tex


Resultados_Hw4.tex: Plots_hw4.py 1).txt 2).txt 3).txt data_10.txt data_20.txt data_30.txt data_40.txt data_50.txt data_60.txt data_70.txt 45.txt
	python Plots_hw4.py


1).txt 2).txt 3).txt : PDE.cpp
	g++ PDE.cpp -w
	./a.out


data_10.txt data_20.txt data_30.txt data_40.txt data_50.txt data_60.txt data_70.txt 45.txt: ODE.cpp
	g++ ODE.cpp -w
	./a.out	


