void DFTcapturadatos()
{
     //entrada[contentradasDFT]=intensidad[187][312];                           //esta fue la que utilice para DFTcanoneshape con 500 celdas
     entrada[contentradasDFT]=intensidad[125][100];
     //cout<<"ok"<<endl;
}

void DFT()
{
     
     //entrada[0]=1, entrada[1]=2, entrada[2]=3, entrada[3]=4, entrada[4]=5;
     transformadapreal=0;
     transformadapimaginaria=0;
     /*for(int l=0;l<NUMERO;l++)
     {
             entrada[l]=sin(l*3.141592*2*(0.01)*30)+sin(l*3.141592*2*(0.01)*40);                           //me parece que el 1/delta de t debe ser igual al numero de celdas, si es asi tendria un problema ya que el delta t en el automata es del orden de 10 a la menos 6, por lo tanto necesitaria del orden de un millon de datos para la transformada!!!
     }*/
     for(int a=0;a<NUMERO;a++)
     {
             for(int b=0;b<NUMERO;b++)
             {
                     transformadapreal+=entrada[b]*cos(3.141592*2*a*b/NUMERO);
                     transformadapimaginaria+=entrada[b]*(-1)*sin(3.141592*2*a*b/NUMERO);
             }
             transformada[a]=sqrt(pow(transformadapreal,2)+pow(transformadapimaginaria,2));
             transformadapreal=0;
             transformadapimaginaria=0;
     }     
     for(int q=0;q<NUMERO;q++)
     {
             cout<<q<<"  "<<transformada[q]<<endl;
             //cout<<entrada[q]<<endl;
     }
}


void DFT2desp()
{
     double Treal=0;                                                            //la parte real de la transformada
     double Timaginaria=0;                                                      //la parte imaginaria de la transformada
     int k1top=int (1/dx);                                                      //el numero total de puntos que tendra la transformada (ojo es esto al cuadrado)
     int k2top=k1top;                                                           //el dx es siempre igual al dy
     //double **transespacial=new double[k1top][k2top];                         //depronto esto pone problema
     //long double transespacial[500][500];
     int Conta, Contb;
     
     for(int k1=0;k1<k1top;k1++)
     {
             for(int k2=0;k2<k2top;k2++)
             {
                     for(int a=0;a<k1top;a++)                                   //el for para la primera suma (recordemos que k1top=k2top)
                     {
                             for(int b=0;b<k1top;b++)                           //el for para la segunda suma
                             {
                                     Conta=a;
                                     Contb=b;
                                     while(Conta>M){Conta=Conta-M;}
                                     while(Contb>M){Contb=Contb-M;}
                                     Treal+=cos((2*M_PI/k1top)*(k1*a+k2*b))*intensidad[Conta][Contb];
                                     Timaginaria+=(-1)*sin((2*M_PI/k1top)*(k1*a+k2*b))*intensidad[Conta][Contb];
                             }
                     }
                     transespacial[k1][k2]=sqrt(pow(Treal,2)+pow(Timaginaria,2));
                     Treal=0;
                     Timaginaria=0;
             }
     }
     for(int k1=0;k1<k1top;k1++)                                                //aca lo imprimo
     {
             for(int k2=0;k2<k2top;k2++)
             {
                     cout<<k1<<"   "<<k2<<"  "<<transespacial[k1][k2]<<endl;
             }
     }
}
