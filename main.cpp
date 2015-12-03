#include <list>
#include <iostream>

using namespace std;

int main()
{
    list <int> xlist; // x[i].
    list <int> ylist; // y[i].
    list <int>::iterator nexti; //next[i].

    // Numeros de prueba.
    xlist.push_back(1);
    xlist.push_back(2);
    xlist.push_back(3);
    xlist.push_back(4);
    xlist.push_back(5);
	
    // Inicialización listas.
    nexti=xlist.begin();
    for(int i=0;i<xlist.size();i++)
    {
        ylist.push_back(*nexti);
        nexti++;
    }

    list <int>::iterator temp; // Puntero auxiliar.
    temp=ylist.begin();
    temp++; // Puntero auxiliar apunta a "y[next[i]], i=1,-> y[2]".
    nexti=ylist.begin(); //next[1]=y[1].
    for(int i=0;i<xlist.size();i++)
    {
       *temp=(*nexti)*(*temp); // y[next[i]]=y[i]*y[next[i]].
        nexti=(temp++); // nexti=next[next[i]].
    }

    // Rutina para imprimir en pantalla los resultados.
    nexti=ylist.begin();
    for(int i=0;i<xlist.size();i++)
    {
        cout << i << "\t" << *nexti <<endl;
        nexti++;
    }
	
	return 0;
}
