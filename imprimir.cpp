#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>//mas importantes
#include <string>//mas importantes
using namespace std;

int main()
{
    int a;
    cout<<"set zrange[-0.02:0.02]"<<endl;
    cout<<"set yrange[0.01:0.1]"<<endl;
    cout<<"set terminal png"<<endl;                                             //para que los escriba como imagenes
    for(a=0;a<500;a++)
    {
                      cout<<"set output"<<"'"<<a<<"int.png"<<"'"<<endl;          //para que lo escriba como imagenes
                      cout<<"splot "<<"'"<<a<<".dat"<<"'"<<" w pm3d"<<endl; 
    }
}
