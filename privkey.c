/*
  Random code find on the internet
  The original author is Nick Farrow
  From his website: https://nickfarrow.com/Cryptography-in-Bitcoin-with-C/
 */

#include <secp256k1.h>
#include <stdio.h>
static secp256k1_context *ctx = NULL;

int main()
{
  ctx = secp256k1_context_create(
		SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
  /* Declare the private variable as a 32 byte unsigned char */
  unsigned char seckey[32];

  /* Load private key (seckey) from random bytes */
  FILE *frand = fopen("/dev/urandom", "r");

  /* Read 32 bytes from frand */
  fread(seckey, 32, 1, frand);

  /* Close the file */
  fclose(frand);

  /* Loop through and print each byte of the private key */
  printf("Private Key: ");
  for(int i = 0; i < 32; i++) printf("%02X", seckey[i]);
  printf("\n");
}

