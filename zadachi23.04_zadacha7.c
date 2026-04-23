#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    float hourly_rate;
    float hours_worked;
    float weekly_salary;
} Employee;

void clear_buffer() {
    while(getchar() != '\n');
}

int main() {
    while(1) {
        int choice;
        
        printf("1. Добавяне на нов запис\n");
        printf("2. Извеждане на данните и заплатите\n");
        printf("3. Изход\n");
        printf("Въведете вашия избор: ");
        
        scanf("%d", &choice);
        clear_buffer();

        if(choice == 3) {
            break;
        }

        if(choice == 1) {
            FILE *file = fopen("employees.bin", "ab+");
            
            if(file == NULL) {
                printf("Грешка при отваряне на файла!\n");
                continue;
            }

            fseek(file, 0, SEEK_END);
            long file_size = ftell(file);
            int current_count = file_size / sizeof(Employee);

            if(current_count >= 30) {
                printf("Достигнат е максималният брой от 30 сътрудници!\n\n");
                fclose(file);
                continue;
            }

            Employee emp;
            
            printf("Въведете ID на сътрудника: ");
            scanf("%d", &emp.id);
            
            printf("Въведете почасово плащане: ");
            scanf("%f", &emp.hourly_rate);
            
            printf("Въведете брой отработени часове за седмицата: ");
            scanf("%f", &emp.hours_worked);
            clear_buffer();

            float gross_salary;
            
            if(emp.hours_worked > 40.0) {
                float overtime = emp.hours_worked - 40.0;
                gross_salary = (40.0 * emp.hourly_rate) + (overtime * emp.hourly_rate * 1.5);
            } else {
                gross_salary = emp.hours_worked * emp.hourly_rate;
            }

            float taxes = gross_salary * 0.0365;
            emp.weekly_salary = gross_salary - taxes;

            fwrite(&emp, sizeof(Employee), 1, file);
            fclose(file);
            
            printf("\n");
        }
        else if(choice == 2) {
            FILE *file = fopen("employees.bin", "rb");
            
            if(file == NULL) {
                printf("Няма записани данни!\n\n");
                continue;
            }

            Employee emp;
            
            printf("\nСписък на сътрудниците:\n");
            
            while(fread(&emp, sizeof(Employee), 1, file) == 1) {
                printf("ID: %d | Ставка: %.2f | Часове: %.2f | Заплата: %.2f\n", 
                       emp.id, emp.hourly_rate, emp.hours_worked, emp.weekly_salary);
            }
            
            printf("\n");
            fclose(file);
        }
    }

    return 0;
}