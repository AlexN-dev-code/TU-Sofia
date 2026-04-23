
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int zad1();
int zad2();
int zad3();
int zad4();
int zad5();


int main(){
    int choice;

    do {
        printf("Vuvedete nomer na zadacha(0 za izhod): ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            printf("Nevaliden vhod! Molq vuvedete chislo ot 1-5.\n");
            continue;
        }

        printf("\n"); 

        switch(choice) {
            case 1: zad1(); break;
            case 2: zad2(); break;
            case 3: zad3(); break;
            case 4: zad4(); break;
            case 5: zad5(); break;
            case 0: printf("Krai na programata.\n"); break;
            default: printf("Nevaliden izbor! Opitaite otnovo.\n");
        }
    } while (choice != 0);

    return 0;
}

int zad1() {
    int guests;
    scanf("%d", &guests);

    char input[20];

    int chairs = 0, tables = 0, cups = 0, dishes = 0;
    double total = 0;

    while(1) {
        scanf("%s", input);

        if(strcmp(input, "PARTY!") == 0)
            break;

        if(strcmp(input, "Chair") == 0) {
            chairs++;
            total += 13.99;
        }
        else if(strcmp(input, "Table") == 0) {
            tables++;
            total += 42.00;
        }
        else if(strcmp(input, "Cups") == 0) {
            cups++; // 
            total += 5.98;
        }
        else if(strcmp(input, "Dishes") == 0) {
            dishes++; 
            total += 21.02;
        }
    }

    int neededTables = (guests + 7) / 8;   
    int neededChairs = guests;
    int neededSets = (guests + 5) / 6;     

    int moreTables = neededTables - tables;
    int moreChairs = neededChairs - chairs;
    int moreDishes = neededSets - dishes;

    printf("%.2f\n", total);

    if(moreTables > 0)
        printf("%d Table\n", moreTables);

    if(moreChairs > 0)
        printf("%d Chair\n", moreChairs);

    if(moreDishes > 0)
        printf("%d Dishes\n", moreDishes);

    return 0;
}
int zad2(){
    struct Product {
    char name[50];
    float price;
    int id;
};

struct Order {
    char address[50];
    int productId;
};


    struct Product products[100];
    struct Order orders[100];

    int pCount=0, oCount=0;
    char cmd[20];

    while(1) {
        scanf("%s", cmd);

        if(strcmp(cmd,"END")==0) break;

        if(strcmp(cmd,"Product")==0) {
            struct Product p;
            scanf("%s %f %d", p.name, &p.price, &p.id);

            products[pCount++] = p;

            for(int i=0;i<oCount;i++) {
                if(orders[i].productId == p.id) {
                    printf("Client %s ordered %s\n",
                           orders[i].address, p.name);

                  
                    for(int j=i;j<oCount-1;j++)
                        orders[j]=orders[j+1];
                    oCount--;
                    i--;
                }
            }
        }

        else if(strcmp(cmd,"Order")==0) {
            struct Order o;
            scanf("%s %d", o.address, &o.productId);

            int found=0;
            for(int i=0;i<pCount;i++) {
                if(products[i].id == o.productId) {
                    printf("Client %s ordered %s\n",
                           o.address, products[i].name);
                    found=1;
                    break;
                }
            }

            if(!found) {
                orders[oCount++] = o;
            }
        }
    }
    
    return 0;
}
                                    
int zad3(){
FILE *f = fopen("input.txt","r");
    FILE *fb = fopen("words.bin","wb");

    char words[100][50];
    int count=0;

    while(fscanf(f,"%s",words[count])==1) count++;

    char result[100][50];
    int r=0;

    strcpy(result[r++], words[0]);

    for(int i=1;i<count;i++){
        if(words[i][0]==words[i-1][strlen(words[i-1])-1]) {
            strcpy(result[r++], words[i]);
        }
    }

    for(int i=0;i<r;i++){
        fwrite(result[i], sizeof(char), strlen(result[i]), fb);
        fwrite(" ",1,1,fb);
    }

    fclose(f);
    fclose(fb);
    
    fb = fopen("words.bin","rb");
    char ch;
    while(fread(&ch,1,1,fb)==1) {
        printf("%c",ch);
    }
    fclose(fb);

    return 0;
}

int zad4(){
char fileName[50];
    int key;

    printf("File name: ");
    scanf("%s", fileName);

    printf("Key (2-10): ");
    scanf("%d", &key);

    FILE *in = fopen(fileName,"r");
    FILE *out = fopen("encoded.txt","w");

    char ch;
    while((ch=fgetc(in))!=EOF) {
        fputc(ch+key, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}

int zad5(){

    char word[] = "concatenation";
    int len = strlen(word);

    char guess[50];
    for(int i=0;i<len;i++) guess[i]='_';
    guess[len]='\0';

    int attempts=0;
    char ch;

    while(strcmp(word,guess)!=0) {
        printf("%s\n",guess);
        scanf(" %c",&ch);
        attempts++;

        for(int i=0;i<len;i++) {
            if(word[i]==ch) guess[i]=ch;
        }
    }

    printf("Poznata duma: %s\n",word);

    if(attempts <= len+2)
        printf("Pechelish!\n");
    else
        printf("Gubish!\n");

    return 0;
}
