#include <list>
#include <stdio.h>
#include <omp.h>

using namespace std;

int main()
{    
    list <int> xlist; // x[i].
    list <int> ylist; // y[i].
    list <int>::iterator nexti; //next[i].

    int tid;
    tid=omp_get_num_procs();
    printf("\nEl siguiente codigo se ejecutara con %d hilos\n\n",tid);

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
    nexti=ylist.begin(); //next[1]=x[1].

    #pragma omp parallel for
    for(int i=0;i<xlist.size();i++)
    {
       *temp=(*nexti)*(*temp); // y[next[i]]=y[i]*y[next[i]].
        nexti=(temp++); // nexti=next[next[i]].
    }

    // Rutina para imprimir en pantalla los resultados.
    nexti=ylist.begin();
    for(int i=0;i<xlist.size();i++)
    {
        printf("\ny[%d]= %d\n\n",i,*nexti);
        nexti++;
    }
	
	return 0;
}
