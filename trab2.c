int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    // Inicialização do array 'count' para contar as preferências dos estudantes por tipo de sanduíche (0 ou 1).
    int count[2] = {0};

    // Loop para contar as preferências dos estudantes.
    for(int i = 0; i < studentsSize; i++){
        count[students[i]]++;  // Incrementa o contador para o tipo de sanduíche que o estudante prefere.
    }

    // Loop para distribuir os sanduíches e verificar se todos os estudantes foram atendidos.
    for(int i = 0; i < sandwichesSize; i++){
        if(count[sandwiches[i]] == 0){
            // Se não houver estudantes que queiram esse tipo de sanduíche, retorna quantos estudantes ficarão sem.
            return sandwichesSize - i;
        }
        count[sandwiches[i]]--;  // Decrementa o contador para indicar que um sanduíche desse tipo foi distribuído.
    }

    // Se todos os estudantes receberam um sanduíche de acordo com suas preferências, retorna 0.
    return 0;
}