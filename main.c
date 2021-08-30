#include <stdio.h>
#include <string.h>

const size_t MAX_INPUT_SIZE = 512;

void changeMessage(char *message, unsigned msg_len, const char *key, unsigned key_len)
{
    for(unsigned i= 0; i<msg_len; i++)
        for(unsigned j=0; j<key_len; j++)
        {
            message[i] ^= key[j];
        }
}


int main()
{
  char message[MAX_INPUT_SIZE];
  puts("Enter the message \n");
  // fgets reads MAX_INPUT_SIZE bytes without breaking non-english chars
  // Wrning: non-english chars still tend to take up more than one byte of space
  fgets(message, sizeof(message), stdin);
  printf("Original message - %s \n", message);


  puts("Enter the key");
  char key[MAX_INPUT_SIZE];
  fgets(key, sizeof(key), stdin);

  unsigned msg_lenght = strlen(message);
  unsigned key_lenght = strlen(key);

  changeMessage(message, msg_lenght, key, key_lenght);
  printf("Encrypted message - %s \n", message);


  changeMessage(message, msg_lenght, key, key_lenght);
  printf("Decrypted message - %s \n", message);

  return 0;
}
