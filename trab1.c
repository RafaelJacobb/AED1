#include <stdio.h>
#include <string.h>

// Função para verificar se um caractere é maiúsculo
int ehMaiusculo(char c) {
    return c >= 'A' && c <= 'Z';
}

// Função para verificar se um caractere é minúsculo
int ehMinusculo(char c) {
    return c >= 'a' && c <= 'z';
}

// Função para verificar se uma string é "nice"
int ehNice(char *s, int inicio, int fim) {
    int maiusculos[26] = {0}; // Array para rastrear letras maiúsculas
    int minusculos[26] = {0}; // Array para rastrear letras minúsculas

    // Percorre a substring de s e marca as letras encontradas nos arrays
    for (int i = inicio; i <= fim; i++) {
        if (ehMaiusculo(s[i])) {
            maiusculos[s[i] - 'A'] = 1;
        } else if (ehMinusculo(s[i])) {
            minusculos[s[i] - 'a'] = 1;
        }
    }

    // Verifica se todas as letras do alfabeto estão presentes em pares (maiúscula e minúscula)
    for (int i = 0; i < 26; i++) {
        if ((maiusculos[i] == 1 && minusculos[i] == 0) ||
            (maiusculos[i] == 0 && minusculos[i] == 1)) {
            return 0;
        }
    }

    return 1;
}

// Função para encontrar a maior substring "nice" em s
char* maiorSubstringNice(char *s) {
    int tamanho = strlen(s);
    int inicio = 0, fim = 0;
    int tamMaximo = 0;

    // Percorre todas as substrings possíveis de s
    for (int i = 0; i < tamanho; i++) {
        for (int j = i; j < tamanho; j++) {
            // Verifica se a substring é "nice" e atualiza o tamanho máximo encontrado
            if (ehNice(s, i, j) && (j - i + 1) > tamMaximo) {
                tamMaximo = j - i + 1;
                inicio = i;
                fim = j;
            }
        }
    }

    // Cria a substring "nice" encontrada
    char *resultado = malloc(sizeof(char) * (tamMaximo + 1));
    strncpy(resultado, s + inicio, tamMaximo);
    resultado[tamMaximo] = '\0';

    return resultado;
}

int main() {
    char s[] = "c";
    char *resultado = maiorSubstringNice(s);

    printf("Maior substring nice: %s\n", resultado);

    free(resultado); // Libera a memória alocada para a substring

    return 0;
}
