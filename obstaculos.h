void disparadoraleatorios()
{
    srand((unsigned)time(0));
    for(int r=0;r<numeroderandoms;r++)
    {
            aleatorio();
    }
}

void aleatorio()
{
     
     randomx[RN]=(rand()%99)+1;
     //cout<<randomx[RN]<<endl;
     randomy[RN]=(rand()%99)+1;
     //cout<<randomy[RN]<<endl;
     RN=RN+1;
}

void aleatoriosfijos()
{
     for(int q=0;q<=4;q++)
     {
             intensidad[randomx[q]][randomy[q]]=0;
             intensidad[randomx[q]+1][randomy[q]]=0;
             intensidad[randomx[q]][randomy[q]+1]=0;
             intensidad[randomx[q]+1][randomy[q]+1]=0;
             intensidad[randomx[q]-1][randomy[q]]=0;
             intensidad[randomx[q]-1][randomy[q]-1]=0;
             intensidad[randomx[q]-1][randomy[q]+1]=0;
             intensidad[randomx[q]][randomy[q]-1]=0;
             intensidad[randomx[q]+1][randomy[q]-1]=0;
     }
}

void isla()
{
     /*for(int q=40;q<M-40;q++)
     {
             for(int r=40;r<M-55;r++)
             {
                     intensidad[q][r]=0;
             }
     }*/
     intensidad[M/2][M/2]=0;
}

void rendija()
{
     for(int q=0;q<(M/2)-10;q++)
     {
             intensidad[67][q]=0;
     }
     for(int q=(M/2)+10;q<M;q++)
     {
             intensidad[67][q]=0;
     }
}

void rendija2()
{
     for(int q=0;q<40;q++)
     {
             intensidad[q][10]=0;
     }
     for(int q=45;q<55;q++)
     {
             intensidad[q][10]=0;
     }
     for(int q=60;q<M;q++)
     {
             intensidad[q][10]=0;
     }
}

void can1shape1()
{
     double a=0;
     for(int j=3*M/4;j<M;j++)
     {
             intensidad[M/4][j]=a;
             velocidad[M/4][j]=a;
     }
     for(int i=M/4;i<=M/2;i++)
     {
             intensidad[i][3*M/4]=a;
             velocidad[i][3*M/4]=a;
     }
     for(int i=M/2;i<=3*M/4;i++)
     {
             intensidad[i][(5*M/4)-i]=a;
             velocidad[i][(5*M/4)-i]=a;
     }
     for(int i=M/2;i<=3*M/4;i++)
     {
             intensidad[i][M/2]=a;
             velocidad[i][M/2]=a;
     }
     for(int j=M/4;j<=M/2;j++)
     {
             intensidad[M/2][j]=a;
             velocidad[M/2][j]=a;
     }
     for(int i=0;i<=M/2;i++)
     {
             intensidad[i][3*M/4-i]=a;
             velocidad[i][3*M/4-i]=a;
     }
}

void can1shape2()
{
     double a=0;
     for(int i=0;i<=M/4;i++)
     {
             intensidad[i][(3*M/4)+i]=a;
             velocidad[i][(3*M/4)+i]=a;
     }
     for(int j=3*M/4;j<M;j++)
     {
             intensidad[M/4][j]=a;
             velocidad[M/4][j]=a;
     }
     for(int i=M/4;i<=3*M/4;i++)
     {
             intensidad[i][3*M/4]=a;
             velocidad[i][3*M/4]=a;
     }
     for(int j=M/2;j<=3*M/4;j++)
     {
             intensidad[3*M/4][j]=a;
             velocidad[3*M/4][j]=a;
     }
     for(int i=M/2;i<=3*M/4;i++)
     {
             intensidad[i][i-(M/4)]=a;
             velocidad[i][i-(M/4)]=a;
     }
     for(int j=M/4;j<=M/2;j++)
     {
             intensidad[M/2][j]=a;
             velocidad[M/2][j]=a;
     }
     for(int i=M/4;i<=M/2;i++)
     {
             intensidad[i][2*M/4]=a;
             velocidad[i][2*M/4]=a;
     }
     for(int i=0;i<=M/4;i++)
     {
             intensidad[i][(3*M/4)-i]=a;
             velocidad[i][(3*M/4)-i]=a;
     }
}
