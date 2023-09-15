#include <stdio.h>
#include <stdlib.h>

// Definir uma estrutura para armazenar um par (frequência, número)
typedef struct pair {
    int freq;
    int num;
} pair;

// Comparar dois pares pelo campo frequência
int compare(const void* a, const void* b) {
    pair* pa = (pair*) a;
    pair* pb = (pair*) b;
    return pb->freq - pa->freq;
}

// Criar uma função que retorna os k elementos mais frequentes de um vetor de números
int* topKFrequent(int* nums, int numsSize, int k) {
    // Criar um vetor para armazenar as frequências de cada número
    // Usar o intervalo [-104, 104] como índices do vetor
    int* freq = (int*) calloc(20001, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    // Criar um vetor de pares (frequência, número)
    // Usar um cast explícito para o tipo pair*
    pair* pairs = static_cast<pair*>(malloc(numsSize * sizeof(pair)));
    int count = 0;
    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            pairs[count].freq = freq[i];
            pairs[count].num = i - 10000;
            count++;
        }
    }

    // Ordenar o vetor em ordem decrescente de frequência
    qsort(pairs, count, sizeof(pair), compare);

    // Pegar os k primeiros elementos do vetor e colocar em um novo vetor
    int* ans = (int*) malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        ans[i] = pairs[i].num;
    }

    // Liberar a memória alocada
    free(freq);
    free(pairs);

    // Retornar o vetor com os k elementos mais frequentes
    return ans;
}
