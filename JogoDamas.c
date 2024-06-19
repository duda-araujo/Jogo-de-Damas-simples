#include<stdio.h>
int main()
{
    //ler tamanho do tabuleiro
    int tamanho;
    scanf("%d", &tamanho);

    char tabuleiro[15][15];
    setbuf(stdin, NULL);
    for(int linha=0; linha<tamanho; linha++)
    {
        //ler tabuleiro
        fgets(tabuleiro[linha], 15, stdin);
    }

    for(int coluna=0; coluna<tamanho; coluna++)
    {
        //verificar se inicialmente tem alguma dama preta
        if(tabuleiro[tamanho-1][coluna] == 'p')
        {
            tabuleiro[tamanho-1][coluna] = 'P';
        }
        //verificar se inicialmente tem alguma dama branca
         if(tabuleiro[0][coluna] == 'b')
        {
            tabuleiro[0][coluna] = 'B';
        }
    }

    int pontos_p=0;
    int pontos_b=0;
    int x_inicial, y_inicial, x_final, y_final;
    char movimento[10];

    do{
        //ler movimentos
        fgets(movimento, 10, stdin);
        sscanf(movimento, "%d %d %d %d", &x_inicial, &y_inicial, &x_final, &y_final);
    
        //se o ponto final para onde a peça vai se mexer está vazio
        if(tabuleiro[x_final][y_final]=='o')
        {
            //se a peça a ser movimentada é preta
            if(tabuleiro[x_inicial][y_inicial]=='p')
            {
                //condição de só movimentar para baixo
                if(x_final > x_inicial)
                {
                    //dar um passo esquerda ou direita
                    if((x_final == x_inicial+1))
                    {
                        tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                        tabuleiro[x_inicial][y_inicial] = 'o';
                    }
                    //dar dois passos e capturar esquerda
                    else if((x_final == x_inicial+2) && (y_final == y_inicial-2))
                    {
                        tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                        tabuleiro[x_inicial][y_inicial] = 'o';
                        tabuleiro[x_inicial+1][y_inicial-1] = 'o';
                        pontos_p++;
                    }
                    //dar dois passos e capturar direita
                    else{
                        tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                        tabuleiro[x_inicial][y_inicial] = 'o';
                        tabuleiro[x_inicial+1][y_inicial+1] = 'o';
                        pontos_p++;
                    }
                    //se virou dama ao final do movimento
                    if(tabuleiro[tamanho-1][y_final]=='p')
                    {
                        tabuleiro[tamanho-1][y_final]='P';
                        pontos_p++;
                    }
                }
            }
            //se a peça a ser movimentada é branca
            else if(tabuleiro[x_inicial][y_inicial]=='b')
            {
                //condição de só movimentar para cima
                if(x_final < x_inicial)
                {
                    //dar um passo esquerda ou direita
                    if((x_final == x_inicial-1))
                    {
                        tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                        tabuleiro[x_inicial][y_inicial] = 'o';
                    }
                    //dar dois passos e capturar esquerda
                    else if((x_final == x_inicial-2) && (y_final == y_inicial-2))
                    {
                        tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                        tabuleiro[x_inicial][y_inicial] = 'o';
                        tabuleiro[x_inicial-1][y_inicial-1] = 'o';
                        pontos_b++;
                    }
                    //dar dois passos e capturar direita
                    else{
                        tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                        tabuleiro[x_inicial][y_inicial] = 'o';
                        tabuleiro[x_inicial-1][y_inicial+1] = 'o';
                        pontos_b++;
                    }
                    //se virou dama ao final do movimento
                    if(tabuleiro[0][y_final]=='b')
                    {
                        tabuleiro[0][y_final]='B';
                        pontos_b++;
                    }
                }
            }
            //se a peça a ser movimentada é dama preta
            else if(tabuleiro[x_inicial][y_inicial]=='P')
            {
                //dar um passo para baixo esquerda ou direita
                if((x_final == x_inicial+1))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                }
                //dar um passo para cima esquerda ou direita
                else if((x_final == x_inicial-1))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                }
                //dar dois passos para baixo esquerda/capturar
                else if((x_final == x_inicial+2) && (y_final == y_inicial-2))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial+1][y_inicial-1] = 'o';
                    pontos_p++;
                }
                //dar dois passos para baixo direita/capturar
                else if((x_final == x_inicial+2) && (y_final == y_inicial+2))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial+1][y_inicial+1] = 'o';
                    pontos_p++;
                }
                //dar dois passos para cima esquerda/capturar
                else if((x_final == x_inicial-2) && (y_final == y_inicial-2))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial-1][y_inicial-1] = 'o';
                    pontos_p++;
                }
                //dar dois passos para cima direita/capturar
                else{
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial-1][y_inicial+1] = 'o';
                    pontos_p++;
                }
            }
            //se a peça a ser movimentada é dama branca
            else if(tabuleiro[x_inicial][y_inicial]=='B')
            {
                //dar um passo para baixo esquerda ou direita
                if((x_final == x_inicial+1))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                }
                //dar um passo para cima esquerda ou direita
                else if((x_final == x_inicial-1))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                }
                //dar dois passos para baixo esquerda/capturar
                else if((x_final == x_inicial+2) && (y_final == y_inicial-2))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial+1][y_inicial-1] = 'o';
                    pontos_b++;
                }
                //dar dois passos para baixo direita/capturar
                else if((x_final == x_inicial+2) && (y_final == y_inicial+2))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial+1][y_inicial+1] = 'o';
                    pontos_b++;
                }
                //dar dois passos para cima esquerda/capturar
                else if((x_final == x_inicial-2) && (y_final == y_inicial-2))
                {
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial-1][y_inicial-1] = 'o';
                    pontos_b++;
                }
                //dar dois passos para cima direita/capturar
                else{
                    tabuleiro[x_final][y_final] = tabuleiro[x_inicial][y_inicial];
                    tabuleiro[x_inicial][y_inicial] = 'o';
                    tabuleiro[x_inicial-1][y_inicial+1] = 'o';
                    pontos_b++;
                }
            }
        }
    }while(!(x_inicial==0 && y_inicial==0 && x_final==0 && y_final==0));

    printf("PRETAS %d\n", pontos_p);
    printf("BRANCAS %d\n", pontos_b);
    if(pontos_p>pontos_b)
       printf("PRETAS VENCERAM\n");
    else if(pontos_b>pontos_p)
       printf("BRANCAS VENCERAM\n");
    else
       printf("EMPATE\n");

    return 0;
}