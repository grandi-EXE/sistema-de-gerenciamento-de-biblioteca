📖 Sistema de Gerenciamento de Biblioteca 📖

![Status](https://img.shields.io/badge/status-Em%20Desenvolvimento-yellow)
![License](https://img.shields.io/badge/license-MIT-blue)

Este é um aplicativo de console em C para gerenciar livros de uma biblioteca. Ele permite cadastrar, consultar, emprestar e devolver livros usando arquivos `.txt` como banco de dados.

--------------------------------------------------------------------------------------------------------------------------
📑 Índice

- [ Objetivo do Projeto](#-objetivo-do-projeto)
- [ Funcionalidades Principais](#️-funcionalidades-principais)
- [ Como Compilar e Executar](#-como-compilar-e-executar)
- [ Estrutura do Projeto](#️-estrutura-do-projeto)
- [ Como São os Arquivos de Dados](#️-como-são-os-arquivos-de-dados)
- [ Explicação Técnica das Funções](#️-explicação-técnica-das-funções)

Objetivo do Projeto

Criar um sistema simples e funcional para gerenciar o catálogo e os empréstimos de livros de uma biblioteca publica que contenha.

 Controle de cadastro de livros  
 Gerenciamento de empréstimos para usuários  
 Consulta fácil do acervo  

Tudo isso salvo em arquivos `.txt`, sem necessidade de banco de dados.


Funcionalidades Principais

- ➕ Adicionar Livro: cadastra novos livros com ID, ISBN, título, autor, editora, ano e localização.
- ➖ Remover Livro: exclui um livro específico pelo ID.
- 🔎 Buscar Livro: busca por ID ou parte do título.
- 📓 Listar Todos os Livros: mostra o catálogo inteiro.
- 🧍 Associar Usuário ao Livro: marca um livro como emprestado para alguém.
- ✅ Desassociar Usuário: marca o livro como disponível novamente.

Como Compilar e Executar

✅ Compilar

Abra um terminal na pasta do projeto e rode:

```bash
gcc main.c livro.c -o biblioteca
```

Isso cria o executável chamado `biblioteca`.

▶️ Executar

```bash
./biblioteca
```


Estrutura do Projeto

```
📦 Projeto
 ┣ main.c         → Menu principal e fluxo de interação
 ┣ livro.c        → Todas as funções de gerenciamento
 ┣ livro.h        → Structs e protótipos de funções
 ┣ Livros.txt     → Arquivo com os dados dos livros
 ┣ user.txt       → Arquivo com os dados dos usuários
```

✅ main.c: implementa o menu interativo e chama as funções.  
✅ livro.c: contém toda a lógica de cadastro, busca e empréstimo.  
✅ livro.h: organiza as structs e declarações de função.

--------------------------------------------------------------------------------------------------------------------------

Como São os Arquivos de Dados

O sistema não usa banco de dados real. Ele salva os dados em arquivos `.txt`.

<details>
<summary>📖 Exemplo de Livros.txt</summary>
ID;ISBN;Titulo;Autor;Editora;Ano;Localizacao;Disponivel
1;9781234567890;A Arte da Programação;Donald Knuth;Addison Wesley;1968;1;Sim

✅ Campo **Disponivel**:
✅ `Sim` → disponível para empréstimo.
⛔ `Nao - Emprestado para: Nome do Usuário` → está emprestado.
</details>

<details>
<summary>👤 Exemplo de user.txt</summary>

```
ID;Nome;Documento
1;Joao Silva;123456789
2;Maria Souza;987654321
3;Carlos Lima;111222333
</details>

 Ambos são arquivos simples com dados separados por ponto e vírgula (`;`).


Explicação Técnica das Funções

<details>
<summary>📌 Adicionar Livro</summary>

- Verifica se já existe um livro com o mesmo ID para evitar duplicidade.
- Solicita dados como ISBN, título, autor, editora, ano e localização.
- Grava o registro no `Livros.txt` em modo de append (`a`).
</details>

<details>
<summary>📌 Remover Livro</summary>

- Abre `Livros.txt` para leitura e `temp.txt` para escrita.
- Copia todas as linhas exceto a que contém o ID a ser removido.
- Substitui `Livros.txt` pelo `temp.txt`.
</details>

<details>
<summary>📌 Listar Livros</summary>

- Abre `Livros.txt`.
- Lê linha por linha usando `fgets` e formata com `sscanf`.
- Exibe os dados no terminal.
</details>

<details>
<summary>📌 Buscar por ID ou Título</summary>

✅ ID:
- Usuário digita o código.
- Percorre o arquivo até encontrar.

✅ Título:
- Usuário digita parte do título.
- Usa `strstr` para achar correspondências parciais.
</details>

<details>
<summary>📌 Associar Usuário ao Livro (Empréstimo)</summary>

- Verifica se o usuário existe em `user.txt`.
- Marca o livro como emprestado com o nome do usuário.
- Atualiza `Livros.txt`.
</details>

<details>
<summary>📌 Desassociar Usuário (Devolução)</summary>

- Solicita o ID do livro.
- Marca o campo `Disponivel` como `Sim`.
- Atualiza `Livros.txt`.
</details>

<details>
<summary>👤 Exemplo de livros.txt</summary>

1;305447265;Dom Casmurro;Machado de Assis;Editora Ática;1899;1;sim
2;342559946;O Pequeno Príncipe;Antoine de Saint-Exupéry;Agir;1943;2;sim
3;364615694;1984;George Orwell;Companhia das Letras;1949;3;Nao - Emprestado para: Joao Silva
4;347803112;A Revolução dos Bichos;George Orwell;Companhia das Letras;1945;4;sim
5;312634559;Capitães da Areia;Jorge Amado;Companhia das Letras;1937;5;sim---
 Ambos são arquivos simples com dados separados por ponto e vírgula (`;`).
