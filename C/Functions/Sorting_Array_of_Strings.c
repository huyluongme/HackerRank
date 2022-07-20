#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a =  0, count_b = 0;
    int arr_a[26] = {0}, arr_b[26] = {0};

    for(int i = 0; i < strlen(a); ++i)
        arr_a[a[i] - 'a'] = 1;

    for(int i = 0; i < strlen(b); ++i)
        arr_b[b[i] - 'a'] = 1;

    for(int i = 0; i < 26; ++i){
        if(arr_a[i]) ++count_a;
        if(arr_b[i]) ++count_b;
    }

    if(count_a != count_b) return count_a > count_b;
    else return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) != strlen(b)) return strlen(a) > strlen(b);
    else return strcmp(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 0; i < len - 1; ++i)
        for(int j = len - 1; j > i; --j){
            if((*cmp_func)(arr[j - 1], arr[j]) > 0){
                char *tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}