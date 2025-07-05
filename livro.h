#ifndef LIVRO_H
#define LIVRO_H


#include <stdio.h>

typedef struct livro {
    int id;
    int isbn;
    char titulo[50];
    char autor[50];
    char editora[50];
    int ano;
    int loc;
    char disponivel[50];
} Livro;


typedef struct user {
    int id;
    char nome[50];
    int doc;
} User;


void cabecalho();
void inputLivro();
void listarLivros();
void buscarPorID();
void buscarPorTitulo();
void removerLivro();
void associarLivro();
void desassociarLivro();

#endif