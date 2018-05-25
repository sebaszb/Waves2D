void forzamiento()                                          //cada 565 iteraciones hace un periodo el modo normal 1 del cuadrado
{
     //if(f<=100)
     //{                                                                    
     //intensidad[87][M/2]=0.1*sin(2*3.141592*f/100);                
     //if(f<=100){intensidad[M/2][M/2]=0.1*sin(2*M_PI*f/200);}
     intensidad[24][198]=0.1*sin(2*M_PI*f/206.33);
     intensidad[26][198]=0.1*sin(2*M_PI*f/206.33);
     //intensidad[M-2][M/2]=0.1*sin(2*3.141592*f/228);
     //intensidad[60][40]=0.005*sin(3.141592*f/20);                  
     //}
     f=f+1;
}

void nadador()                                                    //deveria poner a oscilar el punto minimo
{
     intensidad[50][nadreal+30]=0.01*sin(3.141592*f/5);
     nad=nad+1;
     if(nad==6)
     {
               nadreal=nadreal+1;
               nad=0;
     }
     f=f+1;
}

void forzamientofrontera()
{
     for(int q=1;q<M-1;q++)
     {
             intensidad[q][0]=0.005*sin(3.141592*f/20);
     }
     f++;
}
