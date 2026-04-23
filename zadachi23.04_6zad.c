#include <stdio.h>
#include <string.h>

int anagram_check(char* first, char* second) {

    int first_size = strlen(first);
    int second_size = strlen(second);
    int check;

    if(first_size != second_size) {
        return 0;
    }

    char temp_second[51];
    strcpy(temp_second, second);

    for(int i = 0; i < first_size; i++) {
        check = -1;
        char temp = first[i];

        for(int j = 0; j < first_size; j++) {
            if(temp == temp_second[j]) {
                check = 0;
                temp_second[j] = '*';
                break;
            }
        }

        if(check != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {

    char first[51];
    fgets(first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0';
    first[strcspn(first, "\r")] = '\0';

    char second[51];
    fgets(second, sizeof(second), stdin);
    second[strcspn(second, "\n")] = '\0';
    second[strcspn(second, "\r")] = '\0';

    int result = anagram_check(first, second);

    printf("\n");

    if(result == 1) {
        printf("%s = %s", first, second);
    }
    else {
        printf("%s != %s", first, second);
    }

    return 0;
}