class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
pair* pairs = (pair*) malloc(numsSize * sizeof(pair));
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
};
