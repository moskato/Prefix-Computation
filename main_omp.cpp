#include <list>
#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 8

using namespace std;

int main()
{    
    list <int> xlist; // x[i].
    list <int> ylist; // y[i].
    list <int>::iterator nexti; //next[i].

    // Numeros de prueba.
    int n=8;
    for(int r=1; r <=n;r++)
    {
        xlist.push_back(r);
    }
    /*// Numeros de prueba.
    xlist.push_back(1);
    xlist.push_back(2);
    xlist.push_back(3);
    xlist.push_back(4);
    xlist.push_back(5);*/

    int tid;
    double TimeStart, TimeEnd ;

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

    omp_set_num_threads (NUM_THREADS) ;
    TimeStart= omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<xlist.size();i++)
    {
       *temp=(*nexti)*(*temp); // y[next[i]]=y[i]*y[next[i]].
        nexti=(temp++); // nexti=next[next[i]].
        tid=omp_get_num_threads();
        printf("El siguiente codigo se ejecutara con %d hilos\n",tid);

    }
    TimeEnd=omp_get_wtime();
    printf("Clock time = %.20f\n",(TimeEnd-TimeStart)) ;

    // Rutina para imprimir en pantalla los resultados.
    nexti=ylist.begin();
    for(int i=0;i<xlist.size();i++)
    {
        printf("y[%d]= %d\n",i,*nexti);
        nexti++;
    }
	
	return 0;
}
