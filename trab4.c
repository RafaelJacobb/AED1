#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Definindo a estrutura Element que contém o número e sua frequência
typedef struct {
    int num;
    int freq;
} Element;

// Definindo a estrutura Heap que contém um array de elementos e seu tamanho
typedef struct {
    Element* elements;
    int size;
} Heap;

// Função para criar um heap com um determinado tamanho
Heap* createHeap(int size) {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->elements = (Element*) malloc(sizeof(Element) * size);
    heap->size = 0;
    return heap;
}

// Função para trocar dois elementos
void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar o heap a partir de um determinado índice
void heapify(Heap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Encontrando o menor entre o nó atual, o filho esquerdo e o filho direito
    if (left < heap->size && heap->elements[left].freq < heap->elements[smallest].freq)
        smallest = left;

    if (right < heap->size && heap->elements[right].freq < heap->elements[smallest].freq)
        smallest = right;

    // Se o menor não é o nó atual, trocamos e continuamos o processo
    if (smallest != i) {
        swap(&heap->elements[i], &heap->elements[smallest]);
        heapify(heap, smallest);
    }
}

// Função para inserir um elemento no heap
void insert(Heap* heap, Element element) {
    ++heap->size;
    int i = heap->size - 1;
    heap->elements[i] = element;

    // Ajustando o heap após a inserção
    while (i != 0 && heap->elements[(i - 1) / 2].freq > heap->elements[i].freq) {
        swap(&heap->elements[i], &heap->elements[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Função para extrair (remover e retornar) o menor elemento do heap
Element extractMin(Heap* heap) {
    Element root = heap->elements[0];
    
    if (heap->size != 1) {
        // Substituindo a raiz pelo último elemento do heap e reduzindo o tamanho do heap
        heap->elements[0] = heap->elements[heap->size - 1];
        --heap->size;
        
        // Ajustando o novo root do heap
        heapify(heap, 0);
    }
    
    return root;
}

// Função principal que resolve o problema proposto
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    
    // Inicializando o array de frequências com zeros
    int freq[MAX] = {0};
    
    // Contando a frequência de cada número no array nums
    for (int i = 0; i < numsSize; ++i)
        ++freq[nums[i] + MAX/2];

    // Criando um min-heap para armazenar os k elementos mais frequentes
    Heap* heap = createHeap(k);
    
    // Inserindo os k elementos mais frequentes no min-heap
    for (int i = 0; i < MAX; ++i) {
        if (freq[i] != 0) {
            Element element;
            element.num = i - MAX/2;
            element.freq = freq[i];
            if (heap->size < k)
                insert(heap, element);
            else if (heap->elements[0].freq < freq[i]) {
                extractMin(heap);
                insert(heap, element);
            }
        }
    }

    // Definindo o tamanho do array de retorno como k
    *returnSize = k;
    
    // Alocando memória para o array de retorno
    int* result = malloc(k * sizeof(int));
    
     // Extraindo os k elementos mais frequentes do min-heap e armazenando-os no array de retorno
     for(int i=0; i<k; ++i){
         result[i] = extractMin(heap).num;
     }

     // Retornando o array de resultado
     return result;
}
