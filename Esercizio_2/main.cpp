#include <chrono>
#include <iostream>
#include <unistd.h>
#include <numeric>
#include <vector>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

//BobbleSort for vector ordinate:
void vettoreOrdinatoBobble(vector<int>& v1)
{
    double tempo_totale = 0;
    unsigned int num_ripetizioni = 200;
    for(unsigned int i = 0; i < num_ripetizioni; i++)
    {chrono::steady_clock::time_point t_inizio = chrono::steady_clock::now();
        BubbleSort(v1);
        chrono::steady_clock::time_point t_fine = chrono::steady_clock::now();
        tempo_totale += chrono::duration_cast<chrono::nanoseconds> (t_fine - t_inizio).count();
    }
    double tempo_medio = tempo_totale/200;
    cout << "Bubblesort v1: " << tempo_medio << endl;
}

//MergeSort for vector ordinate:
void vettoreOrdinatoMerge(vector<int>& v1)
{
    double tempo_totale = 0;
    unsigned int num_ripetizioni = 200;
    for(unsigned int i = 0; i < num_ripetizioni; i++)
    {chrono::steady_clock::time_point t_inizio = chrono::steady_clock::now();
        MergeSort(v1);
        chrono::steady_clock::time_point t_fine = chrono::steady_clock::now();
        tempo_totale += chrono::duration_cast<chrono::nanoseconds> (t_fine - t_inizio).count();
    }
    double tempo_medio = tempo_totale/200;
    cout << "Mergesort v1: " << tempo_medio << endl;
}

//BobbleSort for vector non ordinate:
void vettoreNonOrdinatoBobble(vector<int>& v2)
{
    double tempo_totale = 0;
    unsigned int num_ripetizioni = 200;
    for(unsigned int i = 0; i < num_ripetizioni; i++)
    {chrono::steady_clock::time_point t_inizio = chrono::steady_clock::now();
        BubbleSort(v2);
        chrono::steady_clock::time_point t_fine = chrono::steady_clock::now();
        tempo_totale += chrono::duration_cast<chrono::nanoseconds> (t_fine - t_inizio).count();
    }
    double tempo_medio = tempo_totale/200;
    cout << "Bubblesort v2: " << tempo_medio << endl;
}

//MergeSort for vector non ordinate:
void vettoreNonOrdinatoMerge(vector<int>& v2)
{
    double tempo_totale = 0;
    unsigned int num_ripetizioni = 200;
    for(unsigned int i = 0; i < num_ripetizioni; i++)
    {chrono::steady_clock::time_point t_inizio = chrono::steady_clock::now();
        MergeSort(v2);
        chrono::steady_clock::time_point t_fine = chrono::steady_clock::now();
        tempo_totale += chrono::duration_cast<chrono::nanoseconds> (t_fine - t_inizio).count();
    }
    double tempo_medio = tempo_totale/200;
    cout << "Mergsort v2: " << tempo_medio << endl;
}
int main(int argc, char ** argv)
{
    int n = 0;
    size_t dimv = stoll(argv[1]); // stol change character in a long long number
    vector<int> v1(dimv);
    vector<int> v2(dimv);

    // generate an ordinate vector
    generate(v1.begin(), v1.end(), [&n] () {return n++;});

    cout << "Vector v1 is an already ordinate vector:  " << endl;
    cout << "Time misured in nanoseconds:" << endl;
    vettoreOrdinatoBobble(v1);
    vettoreOrdinatoMerge(v1);

    cout << "Vector v2 is not an ordinate vector:  " << endl;
    cout << "Time misured in nanoseconds:" << endl;

    for(unsigned int i = 0; i < dimv; i++)
        v2[i] = rand()%1000;

    vector<int> v2copia = v2;

    vettoreNonOrdinatoBobble(v2);
    vettoreNonOrdinatoMerge(v2copia);

    return 0;
}
