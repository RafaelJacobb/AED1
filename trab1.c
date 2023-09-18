char *longestNiceSubstring(char *s) {
    int n = strlen(s);
char *resultado = "";

for (int i = 0; i < n; i++) {
    int *letrasMinusculas = (int *)calloc(26, sizeof(int));
    int *letrasMaiusculas = (int *)calloc(26, sizeof(int));
    
    for (int j = i; j < n; j++) {
        if (s[j] >= 'a' && s[j] <= 'z')
            letrasMinusculas[s[j] - 'a'] = 1;
        else if (s[j] >= 'A' && s[j] <= 'Z')
            letrasMaiusculas[s[j] - 'A'] = 1;
        
        int letrasMinusculasIguais = 1;
        int letrasMaiusculasIguais = 1;
        
        for (int k = 0; k < 26; k++) {
            if (letrasMinusculas[k] != letrasMaiusculas[k]) {
                letrasMinusculasIguais = 0;
                letrasMaiusculasIguais = 0;
                break;
            }
        }
        
        if (letrasMinusculasIguais && letrasMaiusculasIguais) {
            int comprimento = j - i + 1;
            if (comprimento > strlen(resultado))
                resultado = strndup(s + i, comprimento);
        }
    }
    
    free(letrasMinusculas);
    free(letrasMaiusculas);
}

return resultado;
}
