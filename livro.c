#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "livro.h"


void cabecalho()
{
    printf("========================================\n");
    printf("GERENCIAMENTO DE LIVROS\n");
    printf("========================================\n\n");

}



// Função para adicionar livros
void inputLivro() {
    FILE *arquivo;
    Livro l;
    char continuar;

    do {
        system("cls");
        int idDuplicado = 0;

        printf("\nDigite o Codigo: ");
        scanf("%d", &l.id);

                // Verificação de duplicidade de ID
                arquivo = fopen("Livros.txt", "r");
                if (arquivo != NULL) {
                    char linha[200];
                    Livro temp;

                    while (fgets(linha, sizeof(linha), arquivo)) {
                        if (sscanf(linha, "%d;%*d;%*[^;];%*[^;];%*[^;];%*d;%*d;%*[^;\n]", &temp.id) == 1) {
                            if (temp.id == l.id) {
                                idDuplicado = 1;
                                break;
                            }
                        }
                    }
                    fclose(arquivo);
                }

                if (idDuplicado) {
                    printf("\nERRO: Ja existe um livro com o Codigo %d.\n", l.id);
                    printf("\nDeseja tentar novamente? (s/n): ");
                    continuar = getche();
                    continue;
                }

        
        arquivo = fopen("Livros.txt", "a");
        if (arquivo == NULL) {
            printf("Erro na abertura do arquivo!");
            getch();
            return;
        }

        fflush(stdin);
        printf("\nDigite o ISBN: ");
        scanf("%d", &l.isbn);

        fflush(stdin);
        printf("\nDigite o Titulo: ");
        fgets(l.titulo, sizeof(l.titulo), stdin);
        l.titulo[strcspn(l.titulo, "\n")] = '\0';

        fflush(stdin);
        printf("\nDigite o nome do Autor: ");
        fgets(l.autor, sizeof(l.autor), stdin);
        l.autor[strcspn(l.autor, "\n")] = '\0';

        fflush(stdin);
        printf("\nDigite a editora: ");
        fgets(l.editora, sizeof(l.editora), stdin);
        l.editora[strcspn(l.editora, "\n")] = '\0';

        fflush(stdin);
        printf("\nDigite o ano de lancamento: ");
        scanf("%d", &l.ano);

        fflush(stdin);
        printf("\nDigite a localizacao do livro: ");
        scanf("%d", &l.loc);

        strcpy(l.disponivel, "Sim");

        fprintf(arquivo, "%d;%d;%s;%s;%s;%d;%d;%s\n",
                l.id, l.isbn, l.titulo, l.autor, l.editora, l.ano, l.loc, l.disponivel);

        fclose(arquivo);

        printf("\nLivro cadastrado com sucesso.");
        printf("\nDeseja continuar (s/n): ");
        continuar = getche();

    } while (continuar == 's');
}


    // ---------------------------------------------------------------------------


    // Função para exibir todos os livro
    void listarLivros(){

        FILE *arquivo;
        arquivo = fopen("Livros.txt", "r"); 

        Livro l;
        char linha[200];

       

        if(arquivo == NULL)
        {
            printf("Erro na abertura do arquivo!");
            getch();
            return;
        }

        else
        {
            while (fgets(linha, sizeof(linha), arquivo)) {
                if (sscanf(linha, "%d;%d;%49[^;];%49[^;];%49[^;];%d;%d;%49[^\n]",
                        &l.id, &l.isbn, l.titulo, l.autor, l.editora, &l.ano, &l.loc, l.disponivel) == 8) {
                
                    printf("----------------------------");
                    printf("\nCodigo: %d", l.id);
                    printf("\nISBN: %d", l.isbn);
                    printf("\nTitulo: %s", l.titulo);
                    printf("\nAutor: %s", l.autor);
                    printf("\nEditora: %s", l.editora);
                    printf("\nAno: %d", l.ano);
                    printf("\nLocalizacao: %d", l.loc);
                    printf("\nDisponvel: %s", l.disponivel);
                    printf("\n----------------------------\n");
                }
            }           
        }

        printf("\nPrecione qualquer tecla para sair");
        fclose(arquivo);
        getch();
    }


// -----------------------------------------------------------------------

//Função para buscar livros por ID
void buscarPorID(){

     FILE *arquivo;
        arquivo = fopen("Livros.txt", "r"); 

        Livro l;
        int IDpesquisa;
        
        char continuar;
        char linha[200];

        if(arquivo == NULL)
        {
            printf("Erro na abertura do arquivo!");
            getch();
            return;
        }

    do{
            system("cls");
            int encontrado = 0;

            fflush(stdin);
            printf("\nDigite o codigo do livro a ser pesquisado:");
            scanf("%d", &IDpesquisa);

            rewind(arquivo);

            while (fgets(linha, sizeof(linha), arquivo)) 
            {
                if (sscanf(linha, "%d;%d;%49[^;];%49[^;];%49[^;];%d;%d;%49[^\n]",
                        &l.id, &l.isbn, l.titulo, l.autor, l.editora, &l.ano, &l.loc, l.disponivel) == 8) 
                {
                    if(l.id == IDpesquisa)
                    {

                    printf("----------------------------");
                    printf("\nCodigo: %d", l.id);
                    printf("\nISBN: %d", l.isbn);
                    printf("\nTitulo: %s", l.titulo);
                    printf("\nAutor: %s", l.autor);
                    printf("\nEditora: %s", l.editora);
                    printf("\nAno: %d", l.ano);
                    printf("\nLocalizacao: %d", l.loc);
                    printf("\nDisponvel: %s", l.disponivel);
                    printf("\n----------------------------\n");
                    
                    encontrado = 1;
              
                    }
                }
            }

            if(encontrado == 0){
                printf("\nLivro com Codigo %d nao encontrado\n", IDpesquisa);
            }

            printf("\nDeseja buscar outro livro (s/n):");
                continuar = getche();


    } while (continuar == 's');
            

        fclose(arquivo);
        getch();


}


// -------------------------------------------------------------------------------------

// Função para buscar livor por titulo
void buscarPorTitulo() {
    FILE *arquivo;
    arquivo = fopen("Livros.txt", "r");

    Livro l;
    char tituloBusca[30];
    char linha[200];
    char continuar;
    int encontrado;

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo!");
        getch();
        return;
    }

    do {
        system("cls");
        encontrado = 0;

        fflush(stdin);
        printf("\nDigite o titulo (ou parte) do livro a ser pesquisado: ");
        fgets(tituloBusca, sizeof(tituloBusca), stdin);
        tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

        rewind(arquivo);

       while (fgets(linha, sizeof(linha), arquivo)) 
            {
                if (sscanf(linha, "%d;%d;%49[^;];%49[^;];%49[^;];%d;%d;%49[^\n]",
                        &l.id, &l.isbn, l.titulo, l.autor, l.editora, &l.ano, &l.loc, l.disponivel) == 8) 
                {

                    if (strstr(l.titulo, tituloBusca) != NULL) 
                    {
                        printf("----------------------------");
                        printf("\nCodigo: %d", l.id);
                        printf("\nISBN: %d", l.isbn);
                        printf("\nTitulo: %s", l.titulo);
                        printf("\nAutor: %s", l.autor);
                        printf("\nEditora: %s", l.editora);
                        printf("\nAno: %d", l.ano);
                        printf("\nLocalizacao: %d", l.loc);
                        printf("\nDisponvel: %s", l.disponivel);
                        printf("\n----------------------------\n");
                        encontrado = 1;
                    }
                }
            }

        if (encontrado == 0) {
            printf("\nNenhum livro com o titulo \"%s\" foi encontrado.\n", tituloBusca);
        }

        printf("\nDeseja buscar outro titulo (s/n): ");
        continuar = getche();

    } while (continuar == 's');

    fclose(arquivo);
    getch();
}

// -----------------------------------------------------------------------------

// Função para remover livro

void removerLivro() {
    FILE *arquivo, *temp;
    Livro l;
    
    int idExcluir;
    int encontrado = 0;
    char continuar;
    char linha[200];

    do {
        arquivo = fopen("Livros.txt", "r");
        temp = fopen("temp.txt", "w");

        if (arquivo == NULL || temp == NULL) {
            printf("Erro ao abrir os arquivos.\n");
            return;
        }

        printf("Digite o Codigo do livro a ser removido: ");
        scanf("%d", &idExcluir);

        while (fgets(linha, sizeof(linha), arquivo)) {
            if (sscanf(linha, "%d;%d;%49[^;];%49[^;];%49[^;];%d;%d;%49[^\n]",
                       &l.id, &l.isbn, l.titulo, l.autor, l.editora, &l.ano, &l.loc, l.disponivel) == 8) {
                
                if (l.id != idExcluir) {
                    fprintf(temp, "%d;%d;%s;%s;%s;%d;%d;%s\n",
                            l.id, l.isbn, l.titulo, l.autor, l.editora, l.ano, l.loc, l.disponivel);
                } else {
                    encontrado = 1;
                }
            }
        }

        fclose(arquivo);
        fclose(temp);

        remove("Livros.txt");
        rename("temp.txt", "Livros.txt");

        if (encontrado == 1) {
            printf("Livro removido com sucesso!\n");
        } else {
            printf("Livro com Codigo %d nao encontrado.\n", idExcluir);
        }

        printf("\nDeseja excluir outro livro (s/n): ");
        continuar = getche();
        printf("\n");

    } while (continuar == 's');
}


// ------------------------------------------------------------------------------------
// Funçao para associar usuario ao livro

void associarLivro() {
    FILE *arquivo, *temp, *user;
    Livro l;
    User u;

    int idLivroAssociar;
    int idUserAssociar;
    int livroEncontrado = 0;
    int userEncontrado = 0;
    char continuar;

    char linha[200];

    do {
        arquivo = fopen("Livros.txt", "r");
        user = fopen("user.txt", "r");
        temp = fopen("temp.txt", "w");

        if (arquivo == NULL || temp == NULL || user == NULL) {
            printf("Erro ao abrir os arquivos.\n");
            return;
        }

        printf("Digite o Codigo do livro a ser associado:\n");
        scanf("%d", &idLivroAssociar);

        printf("Digite o ID do usuario a ser associado:\n");
        scanf("%d", &idUserAssociar);

        
        while (fgets(linha, sizeof(linha), user)) {
            if (sscanf(linha, "%d;%49[^;];%d", &u.id, u.nome, &u.doc) == 3) {
                if (u.id == idUserAssociar) {
                    userEncontrado = 1;
                    break;
                }
            }
        }

        fclose(user);

        if (userEncontrado == 0) {
            printf("Usuario com ID %d nao encontrado.\n", idUserAssociar);
            fclose(arquivo);
            fclose(temp);
            return;
        }

        
        while (fgets(linha, sizeof(linha), arquivo)) {
            if (sscanf(linha, "%d;%d;%49[^;];%49[^;];%49[^;];%d;%d;%49[^\n]",
                       &l.id, &l.isbn, l.titulo, l.autor, l.editora, &l.ano, &l.loc, l.disponivel) == 8) {

                if (l.id == idLivroAssociar) {
                    snprintf(l.disponivel, sizeof(l.disponivel), "Nao - Emprestado para: %s", u.nome);
                    livroEncontrado = 1;
                }

                fprintf(temp, "%d;%d;%s;%s;%s;%d;%d;%s\n",
                        l.id, l.isbn, l.titulo, l.autor, l.editora, l.ano, l.loc, l.disponivel);
            }
        }

        fclose(arquivo);
        fclose(temp);

        remove("Livros.txt");
        rename("temp.txt", "Livros.txt");

        if (livroEncontrado == 0) {
            printf("Livro com Codigo %d não encontrado.\n", idLivroAssociar);
        } else {
            printf("Livro associado com sucesso ao usuario %s.\n", u.nome);
        }

        printf("\nDeseja associar outro livro? (s/n): ");
        continuar = getche();
        printf("\n");

    } while (continuar == 's');
}


// ----------------------------------------------------------------------------------

// Funçao para desassociar usuario ao livro
void desassociarLivro() {
    FILE *arquivo, *temp, *user;
    Livro l;
    User u;

    int idLivroDesassociar;
    int livroEncontrado = 0;
    char continuar;

    char linha[200];

    do {
        arquivo = fopen("Livros.txt", "r");
        temp = fopen("temp.txt", "w");

        if (arquivo == NULL || temp == NULL) {
            printf("Erro ao abrir os arquivos.\n");
            return;
        }

        fflush(stdin);
        printf("Digite o Codigo do livro a ser desassociado:\n");
        scanf("%d", &idLivroDesassociar);


        // Ler livros e copiar para temp.txt
        while (fgets(linha, sizeof(linha), arquivo)) {
            if (sscanf(linha, "%d;%d;%49[^;];%49[^;];%49[^;];%d;%d;%49[^\n]",
                       &l.id, &l.isbn, l.titulo, l.autor, l.editora, &l.ano, &l.loc, l.disponivel) == 8) {

                if (l.id == idLivroDesassociar) {
                    snprintf(l.disponivel, sizeof(l.disponivel), "sim");
                    livroEncontrado = 1;
                }

                fprintf(temp, "%d;%d;%s;%s;%s;%d;%d;%s\n",
                        l.id, l.isbn, l.titulo, l.autor, l.editora, l.ano, l.loc, l.disponivel);
            }
        }

        fclose(arquivo);
        fclose(temp);

        remove("Livros.txt");
        rename("temp.txt", "Livros.txt");

        if (livroEncontrado == 0) {
            printf("Livro com Codigo %d nao encontrado.\n", idLivroDesassociar);
        } else {
            printf("Livro desassociado com sucesso\n");
        }

        printf("\nDeseja desassociar outro livro? (s/n): ");
        continuar = getche();
        printf("\n");

    } while (continuar == 's');
}