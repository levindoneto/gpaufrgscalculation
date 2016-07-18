#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAMNOME 40
#define TAMLISTA 150

typedef struct indice
{
    float ff, canctranc, d, c, b, a;
    char nome[TAMNOME];
    float i3;
} INDTRES;

void insere_indice(INDTRES indice3[], char resp, char resp_txt, char resp_sair)
{
    int j; //usado no for para mostrar os i3
    int i=0;

    printf("======================================\n");
    printf("*   Sistema de calculo do I3-UFRGS   *\n");
    printf("======================================\n\n");
    printf("Loading\n");
    Sleep(300);
    for(j=0 ; j<38 ; j++)
    {
        printf(".");
        Sleep(200);
    }
    do
    {
        fflush(stdin);
        printf("\n\nInsira o nome do aluno(a): ");
        gets(indice3[i].nome);

        printf("Insira quantos conceitos A's %s obteve: ", indice3[i].nome);
        scanf("%f", &indice3[i].a);

        printf("Insira quantos conceitos B's %s obteve: ", indice3[i].nome);
        scanf("%f", &indice3[i].b);

        printf("Insira quantos conceitos C's %s obteve: ", indice3[i].nome);
        scanf("%f", &indice3[i].c);

        printf("Insira quantos conceitos D's %s obteve: ", indice3[i].nome);
        scanf("%f", &indice3[i].d);

        printf("Insira quantos conceitos FF's %s obteve: ", indice3[i].nome);
        scanf("%f", &indice3[i].ff);

        printf("Insira quantas cadeiras %s trancou ou cancelou: ", indice3[i].nome);
        scanf("%f", &indice3[i].canctranc);

        i++;

        printf("Deseja inserir mais algum aluno(a)? (S) ou (N): ");
        scanf(" %c", &resp);

        resp = toupper(resp);

    }
    while(resp == 'S' && resp != 'N');


    for(j=0; j<i ; j++)
    {
        indice3[j].i3 = (indice3[j].ff + indice3[j].canctranc + indice3[j].d + indice3[j].c + indice3[j].b + indice3[j].a) / (indice3[j].ff + indice3[j].canctranc/2 + indice3[j].d/3 + indice3[j].c/6 + indice3[j].b/8 + indice3[j].a/10);
        printf("\nO indice 3 do aluno %s eh: %f\n", indice3[j].nome, indice3[j].i3);
    }
}

void grava_txt(INDTRES indice3[])
{
    FILE *fp;
    int j;
    char resp;
    char resp_sair;
    char resp_txt;

    fp=fopen("indices.txt", "a+w");

    fprintf(fp, "Indices dos alunos\n\n");

    for(j=0 ; j<5 ; j++)
    {
        if(indice3[j].i3 == 0.000000)
        {
            break;
        }
        else
            fprintf(fp, "%s: %f\n", indice3[j].nome, indice3[j].i3);
    }
    printf("\n*** Arquivo salvo com sucesso! ***\n\n\n");
    //---------------------------------------------------------
    printf("Deseja sair do programa? (S) ou (N)?\n");
    scanf(" %c", &resp_sair);
    resp_sair = toupper(resp_sair);
    if(resp_sair == 'S' && resp_sair != 'N')
    {
        printf("\n***Programa encerrado com sucesso***\n");
        Sleep(1500);
        exit("EXIT");
    }
    else if(resp_sair == 'N' && resp_sair != 'S')
    {
        main();
    }
    else
    {
        printf("\nResposta invalida!\n\n");
    }

    fclose(fp);
}

int main()
{
    char resp;
    char resp_txt;
    char resp_sair;

    INDTRES indice3[TAMLISTA];

    insere_indice(indice3, resp, resp_txt, resp_sair);

    printf("\n\n");

    printf("Deseja salvar esses indices em um arquivo texto? (S) ou (N)\n");
    scanf(" %c", &resp_txt);
    resp_txt = toupper(resp_txt);

    if(resp_txt == 'S' && resp_txt != 'N')
    {
        grava_txt(indice3);
    }
    else if(resp_txt == 'N' && resp_txt !='S')
    {
        printf("Deseja sair do programa? (S) ou (N)?\n");
        scanf(" %c", &resp_sair);
        resp_sair = toupper(resp_sair);
        if(resp_sair == 'S' && resp_sair != 'N')
        {
            printf("\n***Programa encerrado com sucesso***\n");
            Sleep(1500);
            exit("EXIT");
        }
        else if(resp_sair == 'N' && resp_sair != 'S')
        {
            main();
        }
        else
        {
            printf("\nResposta invalida!\n\n");
        }
    }

    system("PAUSE");

    return 0;
}
