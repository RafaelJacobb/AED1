//Representa a string de entrada, e retorna um ponteiro para um caractere, que será a substring mais longa.
char *longestNiceSubstring(char *s) {
    int n = strlen(s); // Obtém o comprimento da string de entrada
char *resultado = ""; // Inicializa a variável resultado como uma string vazia

// Loop principal para percorrer a string s
for (int i = 0; i < n; i++) {
    int *letrasMinusculas = (int *)calloc(26, sizeof(int));
    int *letrasMaiusculas = (int *)calloc(26, sizeof(int));
    
    // Loop aninhado para percorrer a string a partir da posição i e verifica se maiúscula ou minúscula
    for (int j = i; j < n; j++) {
        if (s[j] >= 'a' && s[j] <= 'z')
            letrasMinusculas[s[j] - 'a'] = 1;
        else if (s[j] >= 'A' && s[j] <= 'Z')
            letrasMaiusculas[s[j] - 'A'] = 1;
        
        int letrasMinusculasIguais = 1;
        int letrasMaiusculasIguais = 1;
        
         // Loop para comparar os arrays de letras minúsculas e maiúsculas
        for (int k = 0; k < 26; k++) {
            if (letrasMinusculas[k] != letrasMaiusculas[k]) {
                letrasMinusculasIguais = 0;
                letrasMaiusculasIguais = 0;
                break;
            }
        }
        
        // Se as letras minúsculas e maiúsculas são iguais, encontramos uma substring válida e calcula o comprimento da substring atual
        if (letrasMinusculasIguais && letrasMaiusculasIguais) {
            int comprimento = j - i + 1;

            // Se o comprimento atual é maior que o comprimento da substring armazenada em resultado e atualiza a substring
            if (comprimento > strlen(resultado))
                resultado = strndup(s + i, comprimento);
        }
    }
    
    // Libera a memória alocada para o array das letras.
    free(letrasMinusculas);
    free(letrasMaiusculas);
}

return resultado;
}