void resultados()
{
 for(int a=0;a<=M;a++)
 {
         for(int b=0;b<=M;b++)
         {
                 
                 cout<<xreal<<"    "<<yreal<<"    "<<intensidad[b][a]<<endl;
                 xreal=xreal+dx;
         }
         yreal=yreal+dy;
         xreal=0;                        //toca poner esto para que x vuelva a 0
         cout<<"  "<<endl;                                                      //para ver con pm3d gnuplot
 }   
}

void datosencadena()//toca mirar esto
{
     string Archivo;                           //declara una palabra (Archivo)
     ofstream myfile;                          //declara que quiero abrir un archivo
     stringstream s;                         //convierte de numero a palabra
     s<<contcadena<<".dat";
     s>>Archivo;
     myfile.open(Archivo.c_str());//aca pilas abajo
     ///////////////////////////////////////////////////////////////////////////
     for(int a=0;a<=M;a++)
 {
         for(int b=0;b<=M;b++)
         {
                 
                 //cout<<xreal<<"    "<<yreal<<"    "<<intensidad[b][a]<<endl;
                 myfile<<xreal<<"    "<<yreal<<"    "<<intensidad[b][a]<<endl;
                 xreal=xreal+dx;
         }
         myfile<<endl;
         yreal=yreal+dy;
         xreal=0;                        //toca poner esto para que x vuelva a 0
 }//////////////////////////////////////////////////////////////////////////////
  xreal=0;
  yreal=0;                               //los pongo en 0 para la proxima iteración   
     
     myfile.close();
}

void resultadosenergiacinetica()
{
     for(int w=0;w<M;w++)
     {
             for(int l=0;l<M;l++)
             energiak=energiak+(0.5*densidad*velocidad[w][l]*velocidad[w][l]);
     }
     if(energia_t_disp==0)
     {
                          cout<<energiak<<endl;
                          energiak=0;                       //toca ponerla en 0 despues de calcularla
                                            
     }
}

void resultadosenergiapotencial()
{
     for(int w=1;w<M;w++)
     {
             for(int l=1;l<M;l++)
             energiap=energiap+0.5*tension*(pow((intensidad[w-1][l]-intensidad[w][l])/dx,2)+pow((intensidad[w][l-1]-intensidad[w][l])/dy,2));
     }
     if(energia_t_disp==0)
     {
                          
                          cout<<energiap<<endl;
                          energiap=0;                       //toca ponerla en 0 despues de calcularla                    
     }
}

void resultadosenergiatotal()
{
     energia_t_disp=1;
     resultadosenergiacinetica();
     resultadosenergiapotencial();
     energiat=energiak+energiap;
     cout<<energiat<<endl;
     energiat=0;
     energiap=0;
     energiak=0;
     
}

void resultadosvelocidad()
{
 for(int a=0;a<M;a++)
 {
         for(int b=0;b<M;b++)
         {
                 
                 cout<<xreal<<"    "<<yreal<<"    "<<velocidad[b][a]<<endl;
                 xreal=xreal+dx;
         }
         yreal=yreal+dy;
         xreal=0;                        //toca poner esto para que x vuelva a 0
 }   
 //cout<<"que pasa"<<endl;
}
void interferencia()
{
     for(int l=0;l<M;l++)
     {
             cout<<l*dx<<"   "<<intensidad[l][50]<<endl;
     }
}
