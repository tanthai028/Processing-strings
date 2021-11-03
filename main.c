#include <stdio.h>
#include <string.h>
#define PHONE_LENGTH 15
#define PHRASE_LENGTH 1000

void read_input(char *str, int N);
void changeLetter(char *c);
void phone(char *str);
void phrase(char *str, char letter);

int main(int argc, char *argv[]) {

  // Task 1
  if (strcmp(argv[1], "phone") == 0) {
    // Create string variable and scan string input to string varaible
    char str[PHONE_LENGTH + 1];
    read_input(str, PHONE_LENGTH);

    // Complete task 1
    phone(str);
  }

  // Task 2
  else {
    // Create string variable and scan string input to string varaible
    char str[PHRASE_LENGTH + 1];
    read_input(str, PHRASE_LENGTH);
    char letter = *argv[2];
    
    // Complete task 2
    phrase(str, letter);
  }

  return 0;
}

// Read input file
void read_input(char *str, int N){
  int ch, i = 0; 
  while ((ch = getchar()) != '\n'){  

    if (i < N){  
      *str++= ch;
      i++;
    }
  }

  *str = '\0';   /* terminates string */
}

// Phone helper function ( Changes phoneletter to phonenumber))
void changeLetter(char *c){

  if (*c >= 'A' && *c <= 'C') *c = '2';
  if (*c >= 'D' && *c <= 'F') *c = '3';
  if (*c >= 'G' && *c <= 'I') *c = '4';
  if (*c >= 'J' && *c <= 'L') *c = '5';
  if (*c >= 'M' && *c <= 'O') *c = '6';
  if (*c >= 'P' && *c <= 'S') *c = '7';
  if (*c >= 'T' && *c <= 'V') *c = '8';
  if (*c >= 'W' && *c <= 'Z') *c = '9';

}

// Task 1
void phone(char *str){
  char *p = str;

  // Iterate entire string until reached null
  while (*p != '\0'){

    // Checks for only letters (ignore dashes and numbers)
    if (*p >= 'A' && *p <= 'Z') 

      // Change phoneletter to phonenumber
      changeLetter(p);

    p++;
  }

  // Print updated string
  printf("%s\n", str);
}


// Task 2
void phrase(char *str, char letter){

  // Counter: number of words that contains the specified letter
  int counter = 0, words = 0;
  char *p = str;

  // Iterate entire string until reached null
  while (*p != '\0'){

    // Checks if letter contained in word
    if (*p == letter) {
      counter++;

      // Skip to next word
      do {
        p++;
      } while (*p != ' ' && *p != '\0');
    }

    // If found a empty space, finished iterating over a word
    if (*p == ' ') 
      words++;
    
    p++;
  }
  // Add the last word
  words++;

  // Calculate and print percentage of words that contain the specified letter
  float percentage = ((float)counter / (float)words) * 100;
  printf("%.1f\n", percentage);
}