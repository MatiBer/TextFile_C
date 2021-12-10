#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20

typedef struct Student
{
    int id;
    char firstname[SIZE];
    char lastname[SIZE];
    int index;
    float L1;
    float L2;
    float L3;
    float L4;
    float K1;
    float SUM;
} Student;

void load(struct Student *, char *);
void get_word(FILE *, char *, int *);
void check_firstname(struct Student *);
void check_lastname(struct Student *);
int compareIndex(); // mod
void swapStudents(); // mod
void sortStudents(); // mod
void plus(struct Student *);
void save(struct Student *, char *);

int size;

int main()
{
    Student students[SIZE];
    load(students, "tablica");

    check_firstname(students);
    check_lastname(students);
    plus(students);

    sortStudents(students); // mod

    save(students, "tablica1"); // Tu podajemy gdzie mma byc zapisane

    return 0;
}

void load(struct Student *students, char *filename)
{
    int character;
    char word[100];
    FILE *file = fopen(filename, "r");

    int i = 0;

    int is_eof = 0;

    while (is_eof != 1)
    {
        get_word(file, word, &is_eof);
        students[i].id = atoi(word);

        get_word(file, word, &is_eof);
        strcpy(students[i].firstname, word);

        get_word(file, word, &is_eof);
        strcpy(students[i].lastname, word);

        get_word(file, word, &is_eof);
        students[i].index = atoi(word);

        get_word(file, word, &is_eof);
        students[i].L1 = atof(word);

        get_word(file, word, &is_eof);
        students[i].L2 = atof(word);

        get_word(file, word, &is_eof);
        students[i].L3 = atof(word);

        get_word(file, word, &is_eof);
        students[i].L4 = atof(word);

        get_word(file, word, &is_eof);
        students[i].K1 = atof(word);

        get_word(file, word, &is_eof);
        students[i].SUM = atof(word);
        i++;
    }

    size = i;

    fclose(file);
}

void get_word(FILE *file, char *result, int *is_eof)
{
    int i = 0;
    char character = getc(file);
    while (character != ',' && character != EOF && character != '\n')
    {
        result[i] = character;
        character = getc(file);
        i++;
    }

    if (character == EOF)
        *is_eof = 1;
    else
        *is_eof = 0;

    result[i] = '\0';
}

void check_firstname(struct Student *students)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < size; i++)
    {
        if (students[i].firstname[0] > 96)
            {
                students[i].firstname[0] = students[i].firstname[0] - 32;
            }
        int len = strlen(students[i].firstname);
        for (int j = 1; j < len; j++)
        {
      

            if (students[i].firstname[j] < 96)
            {
                students[i].firstname[j] = students[i].firstname[j] + 32;
            }
        }

        
    }
}

void check_lastname(struct Student *students)
{
    int i = 0;
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].lastname[0] > 96)
        {
            students[i].lastname[0] = students[i].lastname[0] - 32;
        }

        int len = strlen(students[i].lastname);
        for (int j = 1; j < len; j++)
        {

            if (students[i].lastname[j] < 96)
            {
                students[i].lastname[j] = students[i].lastname[j] + 32;
            }
        }

        
    }
}

// poczatek modyfikacji

int compareIndex(int indA, int indB)
{
    return indA > indB;

}
void swapStudents(struct Student *student, int A, int B)
{
    struct Student temp;
    temp= student[A];
    student[A]=student[B];
    student[B]=temp;
}

void sortStudents(struct Student *student)
{
    int i;
    int j;
    for(i=0;i<SIZE;i++)
    {
        for(j=i+1;j<SIZE;j++)
        {
            if(compareIndex(student[i].index,student[j].index))
            {
                swapStudents(student, i,j);
            }
        }
    }
}

// koniec modyfikacji

void plus(struct Student *students)
{
    int i = 0;

    for (int i = 0; i < size; i++)
    {
        students[i].L1 = students[i].L1 + 1;
        students[i].L2 = students[i].L2 + 1;
        students[i].L3 = students[i].L3 + 1;
        students[i].L4 = students[i].L4 + 1;
        students[i].K1 = students[i].K1 + 1;
        students[i].SUM = students[i].SUM + 5;
    }
}

void save(struct Student *students, char *filename)
{
    FILE *file = fopen(filename, "wb");

    for(int i = 0; i < size; i++)
    {
        fprintf(file, "%d,%s,%s,%d,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f", 
            students[i].id,
            students[i].firstname,
            students[i].lastname,
            students[i].index,
            students[i].L1,
            students[i].L2,
            students[i].L3,
            students[i].L4,
            students[i].K1,
            students[i].SUM
        );

        if (i != size - 1)
        {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}