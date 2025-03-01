#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) \
  a ^= b;          \
  b ^= a;          \
  a ^= b

size_t key(char* string, size_t i) {
  return (size_t) (string[i] - 'a');
}

void lsd(char** array, size_t n, size_t m) {
  size_t count[26] = {0};
  char** new = (char**) malloc(n * sizeof(char*));

  for (size_t digit = m; digit > 0; digit--) {
    for (size_t i = 0; i < 26; i++)
      count[i] = 0;

    for (size_t str_i = 0; str_i < n; str_i++)
      count[key(array[str_i], digit - 1)]++;
    for (size_t i = 1; i < 26; i++)
      count[i] += count[i - 1];
    size_t i = n - 1;
    for (size_t _ = 0; _ < n; _++, i--) {
      size_t k = key(array[i], digit - 1);
      new[--count[k]] = array[i];
    }
    memcpy(array, new, n * sizeof(char*));
  }
  free(new);
}

int main(void) {
  size_t n, m;
  scanf("%zu%zu", &n, &m);
  m++;
  char** arr = (char**) malloc(n * sizeof(char*));
  for (size_t i = 0; i < n; i++) {
    char* str = (char*) malloc(m * sizeof(char));
    scanf("%s", str);
    arr[i] = str;
  }
  m--;
  lsd(arr, n, m);

  printf("%s", arr[0]);

  for (size_t i = 1; i < n; i++) {
    printf(" %s", arr[i]);
  }
  printf("\n");

  for (size_t i = 0; i < n; i++) {
    free(arr[i]);
  }
  // free(new);
  free(arr);
  return 0;
}