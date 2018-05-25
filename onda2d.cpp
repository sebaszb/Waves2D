#include"definiciones.h"
#include"condiniciales.h"
#include"forzamiento.h"
#include"obstaculos.h"
#include"resultados.h"
#include"transdiscretafourier.h"
//#include"automatas.h"

void copiaceldas()
{
     for(int j=0;j<M;j++)
     {
             for(int k=0;k<M;k++)
             {
             copiaintensidad[j][k]=intensidad[j][k];
             copiavelocidad[j][k]=velocidad[j][k];
             }
     }
     //cout<<"parece que copia"<<endl;
}

void copioold()
{
     for(int j=0;j<M;j++)
     {
             for(int k=0;k<M;k++)
             {
             oldint[j][k]=copiaintensidad[j][k];
             oldvel[j][k]=copiavelocidad[j][k];
             }
     }
     //cout<<"parece que copiaold"<<endl;
}

void automatanolineal()
{
     for(int i=1;i<M-1;i++)
     {
             for(int l=1;l<M-1;l++)
             {
             intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
             velocidad[i][l]=oldvel[i][l]+(k*sin(copiavelocidad[i][l]*3.1416/500)*dt)+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt);
             }      
     }
     if(RN>0)
     {aleatoriosfijos();}     
}//cierro la función automata

void automatafriccion()
{
     for(int i=1;i<M-1;i++)
     {
             for(int l=1;l<M-1;l++)
             {
             intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
             velocidad[i][l]=oldvel[i][l]-sqrt(copiavelocidad[i][l]*copiavelocidad[i][l])*copiavelocidad[i][l]*dt+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt);
             }      
     }
     if(RN>0)
     {aleatoriosfijos();}     
}//cierro la función automata

void automataKG()
{
     for(int i=1;i<M-1;i++)
     {
             for(int l=1;l<M-1;l++)
             {
             intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
             velocidad[i][l]=oldvel[i][l]+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt)+alfa*dt*copiaintensidad[i][l]+beta*dt*pow(copiaintensidad[i][l],3);
             }      
     }
     if(RN>0)
     {aleatoriosfijos();}     
}



void automatacircular()
{
     for(int i=1;i<M-1;i++)
     {
             for(int l=1;l<M-1;l++)
             {
                     if((i-M/2)*(i-M/2)+(l-M/2)*(l-M/2)>=(M/2)*(M/2))
                     {
                             intensidad[i][l]=0;
                             velocidad[i][l]=0;
                     }
                     else
                     {
                             intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
                             velocidad[i][l]=oldvel[i][l]+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt);
                     }
             }      
     }
     if(RN>0)
     {aleatoriosfijos();}     
}//cierro la función automata

void automataeliptico()
    {
	double a= M/2-5;
	double b= M/3;	
     for(int i=1;i<M-1;i++)
     {
             for(int l=1;l<M-1;l++)
             {
                     if(((i-M/2)*(i-M/2))/pow(a,2)+((l-M/2)*(l-M/2))/pow(b,2)>=1)
                     {
                             intensidad[i][l]=0;
                             velocidad[i][l]=0;
                     }
                     else
                     {
                             intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
                             velocidad[i][l]=oldvel[i][l]+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt);
                     }
             }      
     }
     if(RN>0)
     {aleatoriosfijos();}     
}//cierro la función automata


void automatatriangular()
{
     for(int i=1;i<M-1;i++)
     {
             for(int l=1;l<M-1;l++)
             {
                     
                     if(l<2*i && i<M/2)
                     {       
                     intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
                     velocidad[i][l]=oldvel[i][l]+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt);
                     }
                     if(l<((2*M)-2*i) && i>=M/2)
                     {                 
                      intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
                      velocidad[i][l]=oldvel[i][l]+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt);
                     }
                     if(l>=2*i && i<M/2)
                     {       
                     intensidad[i][l]=0;
                     velocidad[i][l]=0;
                     }
                     if(l>=((2*M)-2*i) && i>=M/2)
                     {                 
                      intensidad[i][l]=0;
                      velocidad[i][l]=0;
                     }
             }      
     }
     if(RN>0)
     {aleatoriosfijos();}     
}

void automata()
{
     for(int i=1;i<M-1;i++)                     //for(int i=1;i</*M-1*/*151;i++) //esto es para calcular los valores propios de shape 1 y dos (para que corra mas rapido)                                                                                                                                                                             
     {
             for(int l=1;l<M-1;l++)             //for(int l=/*1*/50;l<M-1;l++)
             {
             intensidad[i][l]=oldint[i][l]+dt*copiavelocidad[i][l];
             velocidad[i][l]=oldvel[i][l]+(copiaintensidad[i-1][l]-2*copiaintensidad[i][l]+copiaintensidad[i+1][l])/(4*dt)+(copiaintensidad[i][l-1]-2*copiaintensidad[i][l]+copiaintensidad[i][l+1])/(4*dt);
             }      
     }
     if(RN>0)
     {aleatoriosfijos();}     
}//cierro la función automata


int main()
{
    //disparadoraleatorios();
    //condinicialescero();
    //condpiramide();
    //             n1, n2                                                       los nomero para x y para y                                                                                                                                                                                                                                                                    
    //condsenosoidal(2 , 3);
    //condgolpe();
    //condtodos1();
    //rendija();
    //can1shape1();
    //can1shape2();
    copiaceldas();
    copioold();
    //cout<<1/dx<<endl;
    //DFT2desp();
    //resultados();
    for(int z=0;z<iteraciones;z++)
    { 
            contcadena=z;                                                      //para imprimir los datos en cadena       
            datosencadena();                                                   //para imprimir los datos en cadena
            //resultadosenergiacinetica();
            //resultadosenergiapotencial();
            //resultadosenergiatotal();
            /*if(z%40==0)    
            {                
            DFTcapturadatos();
            contentradasDFT=contentradasDFT+1;                                  //esto es para contar las veces que toma datos de un punto para calcular la DFT
            }*/
            automata();
            //automataeliptico();
            //automatacircular();
            //automatatriangular();
            //automataKG();
            //automatanolineal();
            //automatafriccion();
            //forzamiento();
            //nadador();
            //isla();
            forzamientofrontera();
            //rendija();
            rendija2();
            //can1shape1();
            //can1shape2();
            copioold();                               //esto no se puede borrar, es parte del automata                                                                                                                                                                                                                                                                                                              
            copiaceldas();                            //esto no se puede borrar, es parte del automata 
    }
    //DFT();
    //DFTesp();
    //resultados();
    //resultadosvelocidad();
    //cout<<T<<endl;
}
