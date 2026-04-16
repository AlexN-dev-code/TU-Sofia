#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int zad1();
int zad2();
int zad3();
int zad4();
int zad5();
int zad6();
int zad7();
int zad8();


int main(){
    int choice;

    do {
        printf("Vuvedete nomer na zadacha (0 za izhod): ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            printf("Nevaliden vhod! Molq, vuvedete chislo.\n");
            continue;
        }

        printf("\n"); 

        switch(choice) {
            case 1: zad1(); break;
            case 2: zad2(); break;
            case 3: zad3(); break;
            case 4: zad4(); break;
            case 5: zad5(); break;
            case 6: zad6(); break;
            case 7: zad7(); break;
            case 8: zad8(); break;
            case 0: printf("Krai na programata.\n"); break;
            default: printf("Nevaliden izbor! Opitaite otnovo.\n");
        }
    } while (choice != 0);

    return 0;
}


int zad1() {
int N, M,check = 1, temp = 0;

printf("Zadaite razmera na dvumerniq masiv:");
scanf("%d %d", &N, &M);

int** numbers= (int**)malloc(N * sizeof(int*));

if (numbers == NULL){
    printf("Neuspeshno zadelqne na pamet");
    return;
}
for(int i = 0; i < N; i++) {
        numbers[i] = (int*)malloc(M * sizeof(int));
        if (numbers[i] == NULL) {
            printf("Neuspeshno zadelqne na pamet!");
            for (int k = 0; k < i; k++) {
                free(numbers[k]);
            }
            free(numbers);
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("Vuvedete [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M - 1; j++) {
            if(numbers[i][j] > numbers[i][j + 1]) {
                check = 0;
                break;
            }
        }
    }

    for (int j = 0; j < M; j++) { 
        for (int i = 0; i < N - 1; i++) { 
            if (numbers[i][j] < numbers[i + 1][j]) { 
                check = 0;
                break;
            }
        }
        if (check == 0) break;
    }

    printf("Masivut e:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    if(check == 1) {
        printf("Uslovieto e izpulneno\n");
    }
    else {
        printf("Uslovieto ne e izpulneno.\n");
    }

    for(int i = 0; i < N; i++) {
        free(numbers[i]);
    }

    free(numbers);
}

int zad2(){
int N, M;

    printf("Zadaite razmera na dvumerniq masiv: ");
    scanf("%d %d", &N, &M);

    int** numbers = (int**)malloc(N * sizeof(int*));

    if(numbers == NULL) {
        printf("Neuspeshno zadavane na pamet!");
        return;
    }

    for(int i = 0; i < N; i++) {
        numbers[i] = (int*)malloc(M * sizeof(int));
        if(numbers[i] == NULL) {
            for(int k = 0; k < i; k++) {
            free(numbers[k]);
            }

            free(numbers);

            return;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("Vuvedete [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    int maxSum = -999999;
    int bestI = 0, bestJ = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int currentSum = 0;

            for (int r = i - 1; r <= i + 1; r++) {
                for (int c = j - 1; c <= j + 1; c++) {
                    if (r >= 0 && r < N && c >= 0 && c < M) {
                        if (r != i || c != j) {
                            currentSum += numbers[r][c];
                        }
                        
                    }
                }
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestI = i;
                bestJ = j;
            }
        }
    }

     printf("Masivut e:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    printf("Chisloto, na koeto sbora ot okolnite na nego e nai-golqm e: %d\n", numbers[bestI][bestJ]);

    for(int i = 0; i < N; i++) {
        free(numbers[i]);
    }

    free(numbers);
}

int zad3(){
int N, M, max_I = 0, min_I = 0;

    printf("Vuvedete razmera na masiva: ");
    scanf("%d %d", &N, &M);

    int** numbers = (int**)malloc(N * sizeof(int*));
    
    if(numbers == NULL) {
        printf("Neuspeshno zadelqne na pamet!");
        return;
    }

    for(int i = 0; i < N; i++) {
        numbers[i] = (int*)malloc(M * sizeof(int));

        if(numbers[i] == NULL) {
            for(int k = 0; k < i; k++) {
                free(numbers[k]);
            }

            free(numbers);

            return;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("Vuvedete [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    int max_element = numbers[0][0], min_element = numbers[0][0];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(numbers[i][j] > max_element) {
                max_element = numbers[i][j];
                max_I = i;
            }

            if(numbers[i][j] < min_element) {
                min_element = numbers[i][j];
                min_I = i;
            }
        }
    }

    printf("Minimalnoto chislo: [%d] ot red %d\n", min_element, min_I);
    printf("Maksimalnoto chislo: [%d] ot red %d\n", max_element, max_I);
    printf("\n");

    int* tempRow = numbers[max_I];
    numbers[max_I] = numbers[min_I];
    numbers[min_I] = tempRow;

    printf("Masivut e :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++) {
        free(numbers[i]);
    }

    free(numbers);
}

int zad4(){
int N, M;

    printf("Vuvedete broi hora (N) i broi priqtelstva(M): ");
    scanf("%d %d", &N, &M);

    int* friend_counts = (int*)calloc(N + 1, sizeof(int));

    if(friend_counts == NULL) {
        printf("Neuspeshno zadelqne na pamet!");
        return;
    }

    printf("Vuvedete %d dvoiki priqteli (naprimer 1 3):\n", M);
    for(int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        friend_counts[u]++; 
        friend_counts[v]++;
    }

    int query;
    printf("Vuvedete nomer na chovek za da vidite broq na priqtelite mu: ");
    scanf("%d", &query);

    if (query >= 1 && query <= N) {
        printf("Chovek nomer %d ima %d Priqteli.\n", query, friend_counts[query]);
    } else {
        printf("Nevaliden nomer na chovek.\n");
    }

    free(friend_counts);
}

int* add(int x, int* N, int* numbers) {
    int* temp_size = (int*)realloc(numbers, (*N + 1) * sizeof(int));

    if(temp_size == NULL) {
        printf("Neuspeshno zadelqne na pamet!\n");
        return numbers; 
    }

    numbers = temp_size;
    numbers[*N] = x; 
    (*N)++;          
    
    return numbers;
}

int* delete_element(int x, int* N, int* numbers) {
    if (*N == 0) return numbers; 

    int new_size = 0;
    int i;
    
    for(i = 0; i < *N; i++) {
        if(numbers[i] != x) {
            numbers[new_size] = numbers[i];
            new_size++;
        }
    }

    if (new_size == 0) {
        free(numbers);
        *N = 0;
        return NULL;
    }

    if (new_size < *N) {
        int* temp_size = (int*)realloc(numbers, new_size * sizeof(int));
        if(temp_size != NULL) {
            numbers = temp_size;
        }
        *N = new_size;
    }

    return numbers;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void smallest(int x, int N, int* numbers) {
    if (N == 0) {
        printf("Masivut e prazen!\n");
        return;
    }
    if (x <= 0 || x > N) {
        printf("Greshka: X trqbva da e mejdu 1 i %d\n", N);
        return;
    }

    int* copy = (int*)malloc(N * sizeof(int));
    int i;
    for(i = 0; i < N; i++) {
        copy[i] = numbers[i];
    }

    qsort(copy, N, sizeof(int), compare);

    printf("-> %d-toto nai-malko chislo e: %d\n", x, copy[x - 1]);
    
    free(copy);
}

int zad5(){
int N = 0;
    int* numbers = NULL;
    int i;

    printf("Vuvedete nachalna duljina na redicata ot chisla (0 za prazna): ");
    scanf("%d", &N);

    if(N > 0) {
        numbers = (int*)malloc(N * sizeof(int));
        if(numbers == NULL) {
            printf("Neuspeshno zadelqne na pamet!\n");
            return;
        }

        for(i = 0; i < N; i++) {
            printf("Vuvedete chislo %d: ", i + 1);
            scanf("%d", &numbers[i]);
        }
    }

    int command, x;
    while(1) {
        printf("\n--- menu ---\n");
        printf("1: add(x) - dobavi chislo\n");
        printf("2: delete(x) - Iztrii chislo\n");
        printf("3: smallest(x) - Nameri X-toto nai-malko chislo\n");
        printf("4: izhod\n");
        printf("Izberete komanda: ");
        scanf("%d", &command);

        if (command == 4) {
            printf("Izlizane ot programata...\n");
            break;
        }

        printf("Vuvedete stoinost za X: ");
        scanf("%d", &x);

        if (command == 1) {
            numbers = add(x, &N, numbers);
        } 
        else if (command == 2) {
            numbers = delete_element(x, &N, numbers);
        } 
        else if (command == 3) {
            smallest(x, N, numbers);
        } 
        else {
            printf("Nevalidna komanda!\n");
        }

        printf("Tekusht masiv: [");
        for(i = 0; i < N; i++) {
            printf("%d%s", numbers[i], (i < N - 1) ? ", " : "");
        }
        printf("]\n");
    }

    if(numbers != NULL) {
        free(numbers);
    }
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;

}

int zad6(){
 int N;

    printf("Vuvedete broq na elementite: ");
    scanf("%d", &N);

    int* arr1 = (int*)malloc(N * sizeof(int));

    if(arr1 == NULL) {
        printf("Neuspeshno zadelqne na pamet!");
        return;
    }

    int prime_count = 0;

    for(int i = 0; i < N; i++) {
        printf("Vuvedete element %d: ", i + 1);
        scanf("%d", &arr1[i]);
        if (is_prime(arr1[i])) {
            prime_count++;
        }
    }

    int* arr2 = (int*)malloc(prime_count * sizeof(int));
    if(arr2 == NULL && prime_count > 0) {
        printf("Neuspeshno zadelqne na pamet za vtoriq masiv!");
        free(arr1);
        return;
    }

    int new_size = 0;
    int p_idx = 0;

    for(int i = 0; i < N; i++) {
        if(is_prime(arr1[i])) {
            arr2[p_idx] = arr1[i];
            p_idx++;
        } else {
            arr1[new_size] = arr1[i];
            new_size++;
        }
    }

    if(new_size > 0) {
        arr1 = (int*)realloc(arr1, new_size * sizeof(int));
    }

    printf("\nMasiv bez prosti chisla: [");
    for (int i = 0; i < new_size; i++) {
        if(i != new_size - 1) {
            printf("%d, ", arr1[i]);
        }
        else {
            printf("%d]", arr1[i]);
        }
    }

    printf("\nMasiv samo s prosti chisla: [");
    for (int i = 0; i < prime_count; i++) {
        if(i != prime_count - 1) {    
            printf("%d, ", arr2[i]);
        }
        else {
            printf("%d]", arr2[i]);
        }
    }
    printf("\n");

    free(arr1);
    free(arr2);


}

int zad7(){
 int N, M;

    printf("Zadaite razmera na dvumerniq masiv(pone 3x3): ");
    scanf("%d %d", &N, &M);

    if (N < 3 || M < 3) {
        printf("Greshka: masiva trqbva da e pone 3х3!\n");
        return;
    }

    int** numbers = (int**)malloc(N * sizeof(int*));

    if(numbers == NULL) {
        printf("Neuspeshno zadelqne na pamet!");
        return;
    }

    for(int i = 0; i < N; i++) {
        numbers[i] = (int*)malloc(M * sizeof(int));
        if(numbers[i] == NULL) {
            for(int k = 0; k < i; k++) {
                free(numbers[k]);
            }
            free(numbers);
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("Vuvedete [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    int maxSum = -999999;
    int bestI = 0, bestJ = 0;

    for(int i = 0; i <= N - 3; i++) {
        for(int j = 0; j <= M - 3; j++) {
            int currentSum = 0;
            
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    currentSum += numbers[i + r][j + c];
                }
            }

            if(currentSum > maxSum) {
                maxSum = currentSum;
                bestI = i;
                bestJ = j;
            }
        }
    }

    printf("\nPodmatricata 3x3 s maksimalna suma (%d):\n", maxSum);
    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            printf("%d ", numbers[bestI + r][bestJ + c]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++) {
        free(numbers[i]);
    }

    free(numbers);


}

int zad8(){
int N = 10;
    int* numbers = (int*)malloc(N * sizeof(int));

    if(numbers == NULL) {
        printf("Neuspeshno zadelqne na pamet!");
        return;
    }

    printf("Vuvedete purvonachalnite 10 chisla:\n");
    for(int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Vuvejdate 'chislo poziciq' (za spirane vuvedete samo '0'):\n");
    while(1) {
        int input_num, pos;
        
        scanf("%d", &input_num);
        if(input_num == 0) {
            break;
        }
        
        scanf("%d", &pos);

        if(pos < 0 || pos > N) {
            printf("Greshka: Nevalidna poziciq! Trqbva da e mejdu 0 i %d\n", N);
            continue; 
        }

        int* temp = (int*)realloc(numbers, (N + 1) * sizeof(int));
        if(temp == NULL) {
            printf("Greshka pri zadelqne na pamet!");
            free(numbers);
            return;
        }
        numbers = temp;

        for(int i = N; i > pos; i--) {
            numbers[i] = numbers[i - 1];
        }

        numbers[pos] = input_num;
        N++;
    }

    printf("Izhod:\n");
    for(int i = 0; i < N; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
}