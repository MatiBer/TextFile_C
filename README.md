# TextFile

## Opis
Zadanie wykonane w ramach laboratorium z programowania strukturalnego

## Opis zadania

- Należy utworzyć 20-elementową tablicę struktur zawierających pola NR,Imię,Nazwisko,INDEX,L2,L3,L4,L5,K1,SUMA
- Wczytać do utworzonej struktury informacje z pliku.
- Napisać funkcję sprawdzającą czy wszystkie imiona i nazwiska są napisane prawidłowo: zaczynają się z dużej litery, a reszta liter jest mała. W razie problemów skorygować.
- Do liczb L1,L2,L3, L4 i K1 dodać jeden.
- Zapisać informacje do pliku – całą strukturę w formacie zgodnym z plikiem wejściowym, z poprawnie zapisanymi imionami i nazwiskami (ptk. 3), z poprawionymi liczbami L1,L2,L3, L4 i K1.

## W ramach tej procedury wyodrebniono nastepujace funkcje:

void load(struct Student *, char *);\
void get_word(FILE *, char *, int *);\
void check_firstname(struct Student *);\
void check_lastname(struct Student *);\
void plus(struct Student *);\
void save(struct Student *, char *);

## Zasada dzialania

- Program wczytuje do struktury informacie z pliku. Wczytuje tyle wierszy ile jest w pliku a SIZE definiuje ile jest maksymalnie wierszy.
- Sprawdza czy imie i nazwisko jest napisane prawidlowo i poprawia.
- dodaje 1 do liczb L1,L2,L3, L4 i K1 ,a do sumy dodaje 5.
- zapisuje zmienione dane do pliku.

## Kompilacja, uruchomienie i testowanie programu
Program kompilowany i uruchamiany był na platformie Ubuntu 20.04.3 LTS za pomocą programu visual studio code.

![image](https://github.com/MatiBer/TextFile_C/assets/106385056/5f2d062b-1ae8-42fb-9076-acdfc39f7fd0)
![image](https://github.com/MatiBer/TextFile_C/assets/106385056/cf01ad07-601c-44e7-b731-b7f6d6ed7bc1)

