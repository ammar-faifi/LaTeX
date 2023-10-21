#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

void my_strncpy(char *dest, const char *src, int n) {
  for (int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}

void my_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

void exchange1(char my_str[], char from_str[], char to_str[]) {
  int my_len = my_strlen(my_str);
  int from_len = my_strlen(from_str);
  int to_len = my_strlen(to_str);

  for (int i = 0; i <= my_len - from_len; i++) {
    int match = 1;
    for (int j = 0; j < from_len; j++) {
      if (my_str[i + j] != from_str[j]) {
        match = 0;
        break;
      }
    }
    if (match) {
      my_strncpy(my_str + i, to_str, to_len);
      i += to_len - 1;
    }
  }
}

void exchange2(char *my_str, const char *from_str, const char *to_str) {
  int my_len = my_strlen(my_str);
  int from_len = my_strlen(from_str);
  int to_len = my_strlen(to_str);

  for (int i = 0; i <= my_len - from_len; i++) {
    int match = 1;
    for (int j = 0; j < from_len; j++) {
      if (my_str[i + j] != from_str[j]) {
        match = 0;
        break;
      }
    }
    if (match) {
      my_strncpy(my_str + i, to_str, to_len);
      i += to_len - 1;
    }
  }
}

char *exchange3(char *my_str, const char *from_str, const char *to_str) {
  int my_len = my_strlen(my_str);
  int from_len = my_strlen(from_str);
  int to_len = my_strlen(to_str);

  // Create a dynamic buffer for the modified string
  char *new_str = (char *)malloc(my_len * abs(to_len - from_len) + 1);
  if (new_str == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  int new_str_index = 0;

  for (int i = 0; i <= my_len - from_len+1; i++) {
    int match = 1;
    for (int j = 0; j < from_len; j++) {
      if (my_str[i + j] != from_str[j]) {
        match = 0;
        break;
      }
    }
    if (match) {
      my_strncpy(new_str + new_str_index, to_str, to_len);
      new_str_index += to_len;
      i += from_len - 1;
    } else {
      new_str[new_str_index] = my_str[i];
      new_str_index++;
    }
  }
  new_str[new_str_index] = '\0';

  return new_str;
}

int main() {
  char my_str1[] = "recieve";
  exchange1(my_str1, "ie", "ei");
  printf("exchange1: %s\n", my_str1);

  char my_str2[] = "recieve";
  exchange2(my_str2, "ie", "ei");
  printf("exchange2: %s\n", my_str2);

  char *my_str3 = "recieve";
  my_str3 = exchange3(my_str3, "ie", "eiiiiiiiiii");
  printf("exchange3: %s\n", my_str3);

  return 0;
}
