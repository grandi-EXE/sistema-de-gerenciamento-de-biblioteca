#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "livro.h"




int main(){


    int opcao;

    do{
        system("cls");

        cabecalho();
        printf("\n============ MENU PRINCIPAL ============\n");
        printf("1 - Inserir livro\n");
        printf("2 - Remover livro\n");
        printf("3 - Associar ou desassociar usuario ao livro\n");
        printf("4 - Exibir livros\n");
        printf("5 - Sair\n");
        printf("=========================================\n");
        printf("\nDigite a opcao desejada:");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            inputLivro();
        break;
        
        case 2:
            removerLivro();
        break;

        case 3:{
           
            int opcaoAssociacao;

            do
            {
                system("cls");
                cabecalho();
                printf("\n====== MENU DE ASSSOCIACAO ======\n");
                printf("1 - Associar usuario ao livro\n");
                printf("2 - Desassociar usuario do livro\n");
                printf("3 - Voltar ao menu principal\n");
                printf("==================================\n");

                printf("\nSelecione o modo desejado:");
                scanf("%d", &opcaoAssociacao);

                    switch (opcaoAssociacao)
                    {
                    case 1:
                        associarLivro();
                    break;

                    case 2:
                        desassociarLivro();
                    break;

                    case 3:
                        printf("\nVoltando para o MENU...");
                    break;
                    
                    default:
                        printf("\nOpcao invalida");
                        getch();
                    break;
                    }
                

            } while (opcaoAssociacao != 3);
        }break;


        case 4:{
           
            int opcaoExibicao;

            do
            {
                system("cls");
                cabecalho();
                printf("\n===== MENU DE EXIBICAO =====\n");
                printf("1 - Todos os livros\n");
                printf("2 - Busca livro por ID\n");
                printf("3 - Busca livro por Titulo\n");
                printf("4 - Voltar ao menu principal\n");
                printf("=============================\n");

                printf("\nSelecione o modo desejado:");
                scanf("%d", &opcaoExibicao);

                switch (opcaoExibicao)
                {
                case 1:
                    listarLivros();
                break;

                case 2:
                    buscarPorID();
                break;

                case 3:
                    buscarPorTitulo();
                break;

                case 4:
                    printf("\nVoltando para o MENU...");
                break;
                
                default:
                    printf("\nOpcao invalida");
                    getch();
                break;
                }
                

            } while (opcaoExibicao != 4);
            

        }break;

        case 5:
        
            printf("\nPrograma encerrado.");
            getch();

        break;

        default:

            printf("\nOpcao invalida");
            getch();

        break;
        }

    }while(opcao != 5);    

   

}



 