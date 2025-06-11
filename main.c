#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "sites.h"

#define COR_VERDE "\x1b[32m"
#define COR_AZUL "\x1b[34m"
#define COR_VERMELHO "\x1b[31m"
#define COR_AMARELO "\x1b[33m"
#define COR_MAGENTA "\x1b[35m"
#define COR_RESET "\x1b[0m"
#define FUNDO_AZUL "\x1b[44m"
#define FUNDO_VERDE "\x1b[42m"
#define NEGRITO "\x1b[1m"

int grafo[MAX_SITES][MAX_SITES] = {0};

void limparTela() {
    system("cls || clear");
}

void limparBuffer() {
    while (getchar() != '\n');
}

void exibirCabecalho(const char *titulo) {
    int largura = 60;
    int tituloLen = strlen(titulo);
    int paddingEsquerda = (largura - tituloLen) / 2;
    int paddingDireita = largura - tituloLen - paddingEsquerda;

    printf("\n%s%s", FUNDO_AZUL, COR_AMARELO);
    printf("+------------------------------------------------------------+\n");
    printf("|%*s%s%s%s%*s|\n", paddingEsquerda, "", NEGRITO, titulo, COR_AMARELO, paddingDireita, "");
    printf("+------------------------------------------------------------+%s\n\n", COR_RESET);
}

void exibirMensagem(const char *mensagem, const char *cor) {
    printf("\n%s%s%s%s%s\n\n", COR_AMARELO, FUNDO_AZUL, cor, mensagem, COR_RESET);
}

void exibirLinha() {
    printf("%s%s------------------------------------------------------------%s\n", COR_AZUL, NEGRITO, COR_RESET);
}

void inicializarGrafo() {
    // Conexões para computadores.com
    grafo[0][1] = grafo[0][4] = grafo[0][6] = 1;
    
    // Conexões para matematica.com
    grafo[1][2] = grafo[1][3] = 1;
    
    // Conexões para calculodiferencial.com
    grafo[2][3] = 1;
    
    // Conexões para fisica.com
    grafo[3][7] = 1;
    
    // Conexões para programacao.com
    grafo[4][0] = grafo[4][7] = 1;
    
    // Conexões para eletronica.com
    grafo[6][0] = grafo[6][3] = 1;
    
    // Conexões para ciencia.com
    grafo[7][3] = grafo[7][8] = grafo[7][9] = 1;
    
    // Conexões para filmes.com e musica.com
    grafo[8][5] = grafo[9][5] = 1;
}

int encontrarSite(const char *url) {
    for (int i = 0; i < totalSites; i++) {
        if (strcmp(sites[i].url, url) == 0) {
            return i;
        }
    }
    return -1;
}

void exibirSite(int indice) {
    int sair = 0;
    int historico[MAX_SITES];  // Pilha para armazenar o histórico de navegação
    int topo = 0;
    historico[topo] = indice;  // Inicializa com o primeiro site

    while (!sair) {
        int atual = historico[topo];  // Site atual é sempre o do topo
        
        limparTela();
        exibirCabecalho(sites[atual].titulo);
        
        printf("%sURL:%s %s%s%s\n\n", COR_VERDE, COR_RESET, COR_AZUL, sites[atual].url, COR_RESET);
        printf("%s%s%s\n\n", COR_MAGENTA, sites[atual].descricao, COR_RESET);
        
        exibirLinha();
        printf("%sLinks relacionados:%s\n", COR_VERDE, COR_RESET);
        
        int opcoes[MAX_SITES], count = 0;
        for (int i = 0; i < totalSites; i++) {
            if (grafo[atual][i]) {
                printf("%s%d%s - %s%s%s\n", COR_AMARELO, count+1, COR_RESET, COR_AZUL, sites[i].url, COR_RESET);
                opcoes[count++] = i;
            }
        }

        printf("\n%s%d%s - Voltar ao menu\n", COR_AMARELO, count+1, COR_RESET);
        printf("%s%d%s - %sDeletar este site%s\n", COR_AMARELO, count+2, COR_RESET, COR_VERMELHO, COR_RESET);

        exibirLinha();
        printf("\n%sEscolha uma opção:%s ", COR_VERDE, COR_RESET);

        int opcao;
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            opcao = 0;
        }

        if (opcao > 0 && opcao <= count) {
            if (topo < MAX_SITES - 1) {
                historico[++topo] = opcoes[opcao-1];
            }
        } 
        else if (opcao == count+1) {
            sair = 1;
        } 
        else if (opcao == count+2) {
            sair = 1;
        } 
        else {
            exibirMensagem(" Opção inválida! Pressione Enter... ", COR_VERMELHO);
            limparBuffer();
            getchar();
        }
    }
}


void criarNovoSite() {
    if (totalSites >= MAX_SITES) {
        exibirMensagem(" Limite máximo de sites atingido! Não é possível criar mais sites. ", COR_VERMELHO);
        limparBuffer();
        getchar();
        return;
    }
    
    limparTela();
    exibirCabecalho("CRIAR NOVO SITE");
    
    // Obter URL
    printf("%sDigite a URL do novo site (sem espaços):%s ", COR_VERDE, COR_RESET);
    char url[MAX_URL];
    scanf("%s", url);
    limparBuffer();
    
    if (encontrarSite(url) != -1) {
        exibirMensagem(" Já existe um site com esta URL! Pressione Enter... ", COR_VERMELHO);
        getchar();
        return;
    }
    
    // Obter título
    printf("%sDigite o título do site:%s ", COR_VERDE, COR_RESET);
    char titulo[MAX_TITULO];
    fgets(titulo, MAX_TITULO, stdin);
    titulo[strcspn(titulo, "\n")] = '\0';
    
    // Obter descrição
    printf("%sDigite a descrição do site:%s ", COR_VERDE, COR_RESET);
    char descricao[MAX_DESC];
    fgets(descricao, MAX_DESC, stdin);
    descricao[strcspn(descricao, "\n")] = '\0';
    
    // Adicionar o novo site
    strcpy(sites[totalSites].url, url);
    strcpy(sites[totalSites].titulo, titulo);
    strcpy(sites[totalSites].descricao, descricao);
    
    // Definir conexões de outros sites para este
    limparTela();
    exibirCabecalho("DEFINIR CONEXÕES PARA O NOVO SITE");
    printf("Selecione os sites que devem ter links para %s%s%s:\n\n", COR_AZUL, url, COR_RESET);
    
    for (int i = 0; i < totalSites; i++) {
        printf("%s%d%s - %s%s%s\n", COR_AMARELO, i+1, COR_RESET, COR_AZUL, sites[i].url, COR_RESET);
    }
    printf("\n%sDigite os números dos sites separados por espaço (0 para finalizar):%s ", COR_VERDE, COR_RESET);
    
    int opcao;
    do {
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            continue;
        }
        
        if (opcao > 0 && opcao <= totalSites) {
            grafo[opcao-1][totalSites] = 1;
        }
    } while (opcao != 0);
    limparBuffer();
    
    // Definir conexões deste site para outros
    limparTela();
    exibirCabecalho("DEFINIR CONEXÕES DO NOVO SITE");
    printf("Selecione os sites que %s%s%s deve linkar:\n\n", COR_AZUL, url, COR_RESET);
    
    for (int i = 0; i < totalSites; i++) {
        printf("%s%d%s - %s%s%s\n", COR_AMARELO, i+1, COR_RESET, COR_AZUL, sites[i].url, COR_RESET);
    }
    printf("\n%sDigite os números dos sites separados por espaço (0 para finalizar):%s ", COR_VERDE, COR_RESET);
    
    do {
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            continue;
        }
        
        if (opcao > 0 && opcao <= totalSites) {
            grafo[totalSites][opcao-1] = 1;
        }
    } while (opcao != 0);
    limparBuffer();
    
    totalSites++;
    exibirMensagem(" Site criado com sucesso! Pressione Enter... ", COR_VERDE);
    getchar();
}

void acessarSite() {
    limparTela();
    exibirCabecalho("ACESSAR SITE");
    
    printf("%sSites disponíveis:%s\n\n", COR_VERDE, COR_RESET);
    for (int i = 0; i < totalSites; i++) {
        printf("%s%d%s - %s%s%s\n", COR_AMARELO, i+1, COR_RESET, COR_AZUL, sites[i].url, COR_RESET);
    }
    
    printf("\n%sDigite o número do site ou 0 para voltar:%s ", COR_VERDE, COR_RESET);
    
    int opcao;
    if (scanf("%d", &opcao) != 1) {
        limparBuffer();
        return;
    }
    
    if (opcao > 0 && opcao <= totalSites) {
        exibirSite(opcao-1); 
    } else if (opcao != 0) {
        exibirMensagem(" Opção inválida! Pressione Enter... ", COR_VERMELHO);
        limparBuffer();
        getchar();
    }
}

void mostrarMenu() {
    limparTela();
    exibirCabecalho("SEARCH ENGINE");
    
    printf("%sMenu Principal:%s\n\n", COR_VERDE, COR_RESET);
    printf("%s1%s - Acessar um site\n", COR_AMARELO, COR_RESET);
    printf("%s2%s - Criar um novo site\n", COR_AMARELO, COR_RESET);
    printf("%s3%s - Buscar site por URL\n", COR_AMARELO, COR_RESET);
    printf("%s4%s - Mostrar matriz de adjacências\n", COR_AMARELO, COR_RESET);  // Nova opção
    printf("%s5%s - Sair\n", COR_AMARELO, COR_RESET);
    
    exibirLinha();
    printf("\n%sEscolha uma opção:%s ", COR_VERDE, COR_RESET);
}

void buscarSitePorURL() {
    limparTela();
    exibirCabecalho("Buscar site por URL");

    char url[256];
    printf("Digite a URL do site: ");
    limparBuffer();
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';  // Remove o \n

    int encontrado = -1;
    for (int i = 0; i < totalSites; i++) {
        if (strcmp(sites[i].url, url) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        exibirSite(encontrado);
    }

    // Novo: loop de navegação com controle de retorno
    int indiceAtual = encontrado;
    while (1) {
        exibirSite(indiceAtual);
        // Depois que exibirSite() retorna, significa que o usuário quis voltar ao menu
        break;
    }
}

void mostrarMatrizAdjacencia() {
    limparTela();
    exibirCabecalho("MATRIZ DE ADJACÊNCIAS");
    
    // Cabeçalho com os URLs (apenas os primeiros caracteres para caber na tela)
    printf("%5s", "");
    for (int j = 0; j < totalSites; j++) {
        printf("%3.3s ", sites[j].url);  // Mostra apenas os 3 primeiros caracteres da URL
    }
    printf("\n");
    
    // Linha separadora
    exibirLinha();
    
    // Matriz de adjacências
    for (int i = 0; i < totalSites; i++) {
        printf("%3.3s: ", sites[i].url);  // Mostra os 3 primeiros caracteres da URL como rótulo
        
        for (int j = 0; j < totalSites; j++) {
            if (grafo[i][j]) {
                printf("%s 1  %s", COR_VERDE, COR_RESET);  // Conexão existe (verde)
            } else {
                printf("%s 0  %s", COR_VERMELHO, COR_RESET); // Sem conexão (vermelho)
            }
        }
        printf("\n");
    }
    
    // Legenda
    exibirLinha();
    printf("\n%sLegenda:%s\n", COR_AMARELO, COR_RESET);
    printf("%s1%s - Conexão existente\n", COR_VERDE, COR_RESET);
    printf("%s0%s - Sem conexão\n", COR_VERMELHO, COR_RESET);
    printf("\nURLs completos:\n");
    for (int i = 0; i < totalSites; i++) {
        printf("%3.3s: %s\n", sites[i].url, sites[i].url);
    }
    
    printf("\n%sPressione Enter para voltar ao menu...%s", COR_VERDE, COR_RESET);
    limparBuffer();
    getchar();
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    inicializarGrafo();
    
    int opcao;
    do {
        mostrarMenu();
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            opcao = 0;
        }
        
        switch(opcao) {
            case 1:
                acessarSite();
                break;
            case 2:
                criarNovoSite();
                break;
            case 3:
                buscarSitePorURL();
                break;
            case 4:  
                mostrarMatrizAdjacencia();
                break;
            case 5:
                break;
            default:
                exibirMensagem(" Opção inválida! Pressione Enter... ", COR_VERMELHO);
                limparBuffer();
                getchar();
        }
    } while (opcao != 5);
    
    limparTela();
    exibirCabecalho("OBRIGADO!");
    printf("\n%sObrigado por usar nosso Search Engine!%s\n\n", COR_AZUL, COR_RESET);
    return 0;
}