int contarEstudantes(int* estudantes, int tamanhoEstudantes, int* sanduiches, int tamanhoSanduiches){
    int contagemPreferencia[2] = {0}; // Contagem das preferências de sanduíches circular (0) e quadrado (1)
    for (int i = 0; i < tamanhoEstudantes; i++) {
        contagemPreferencia[estudantes[i]]++;
    }

    int estudanteInicio = 0; // Ponteiro para o início da fila
    int estudanteFim = tamanhoEstudantes - 1; // Ponteiro para o final da fila

    for (int i = 0; i < tamanhoSanduiches; i++) {
        if (contagemPreferencia[sanduiches[i]] == 0) {
            // Não há mais estudantes que desejam esse tipo de sanduíche
            return tamanhoSanduiches - i;
        }

        // Verifica se o estudante atual na frente da fila deseja esse tipo de sanduíche
        while (estudantes[estudanteInicio] != sanduiches[i]) {
            // O estudante não deseja o sanduíche atual, move-o para o final da fila
            int temp = estudantes[estudanteInicio];
            estudanteInicio = (estudanteInicio + 1) % tamanhoEstudantes;
            estudanteFim = (estudanteFim + 1) % tamanhoEstudantes;
            estudantes[estudanteFim] = temp;
        }

        // O estudante atual obteve seu sanduíche preferido, atualize a contagem
        contagemPreferencia[sanduiches[i]]--;
        // Remova o estudante da fila
        estudanteInicio = (estudanteInicio + 1) % tamanhoEstudantes;
    }

    // Neste ponto, a distância entre os ponteiros estudanteInicio e estudanteFim é o número de estudantes incapazes de comer
    int estudantesIncapazesDeComer = (estudanteFim - estudanteInicio + 1) % tamanhoEstudantes;
    return estudantesIncapazesDeComer;
}
