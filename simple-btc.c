#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct block
{
  time_t current_time;
  char *source;
  char *target;
  float amount;
  struct block *next;
} block_t;

typedef struct tm datetime; 

void print_blockchain(block_t *head);
void add_block(block_t *head, time_t current_time, char *source, char *target, float amount);
void new_blockchain();

int main()
{

  block_t *head = NULL;
  head = (block_t *) malloc(sizeof(block_t));
  if (head == NULL) return 1;

  head->source = "Satoshi Nakamoto";
  head->target = "Hal Finney";
  head->amount = 10;
  head->next = NULL;

  printf("STARTING BLOCKCHAIN:\n\n");
  print_blockchain(head);

  time_t current_time;
  char *source;
  char *target;
  float amount;
  int menu = 0;
  
  while (1)
  {
    printf("MENU:\n");
    printf("1) Add a block at end\n");
    printf("0) Quit\n");
    printf("Your choice: ");
    scanf("%d", &menu);

    if (menu == 1)
    {
      printf("Add a block at end,\n");
      current_time = time(NULL);
      char sender[20];
      printf("Sender: ");
      scanf("%s", sender);
      char receiver[20];
      printf("Receiver: ");
      scanf("%s", receiver);
      printf("Transaction amount: ");
      scanf("%f", &amount);
      add_block(head, current_time, sender, receiver, amount);
      new_blockchain();
      print_blockchain(head);
    }
    else if (menu == 0) break;
  }
  
  
  
  return 0;
}

void print_blockchain(block_t *head)
{
  block_t *current = head;
  time_t current_time;
  struct tm *today;
  time(&current_time);
  today = localtime(&current_time);
  
  int count_block = 0;
  
  while (current != NULL)
  {
    printf("\n=========================================================================\n");
    if (count_block == 0)
    {
      printf("||\n");
      printf("||\tGENESIS BLOCK!\n");
      time_t genesis_time;
      struct tm *genesisday;
      time(&genesis_time);
      genesisday = localtime(&genesis_time);
      genesisday->tm_mday = 12;
      genesisday->tm_mon = 1;
      genesisday->tm_year = 2009;
      printf("||\n");
      printf("-------------------------------------------------------------------------\n");
      printf("||\n");
      char *msg = "The Times Jan/03/2009 Chancellor on brink of second bailout for banks.";
      printf("||%s\n", msg);
      printf("||\n");
      printf("-------------------------------------------------------------------------\n");
    
      printf("||\tTimestamp:\t%d-%d-%d\n",
	     genesisday->tm_year,
	     genesisday->tm_mon,
	     genesisday->tm_mday
	     );
    }
    else
    {
      printf("||\tBLOCK N°%d\n", count_block);
      time(&current_time);
      today = localtime(&current_time);
      printf("-------------------------------------------------------------------------\n");
    
      printf("||\tTimestamp:\t%d-%d-%d\n",
	     (today->tm_year) + 1900,
	     (today->tm_mon) + 1,
	     today->tm_mday
	     );
    }
    
    printf("||\tSource:     \t%s\n", current->source);
    printf("||\tTarget:     \t%s\n", current->target);
    printf("||\tTransaction:\t%.2f BTC\n", current->amount);
    printf("=========================================================================\n");
    printf("\t\t\t\t||\n");
    printf("\t\t\t\t||\n");
    printf("\t\t\t\t\\/\n");
    current = current->next;
    count_block++;
  }
  printf("\t\t\t      ------\n");
  printf("\t\t\t      |NULL|\n");
  printf("\t\t\t      ------\n");
}

void add_block(block_t *head, time_t current_time, char *source, char *target, float amount)
{
  block_t *current = head;
  while (current->next != NULL) current = current->next;

  current->next = (block_t *) malloc(sizeof(block_t));
  current->next->current_time = current_time;
  current->next->source = source;
  current->next->target = target;
  current->next->amount = amount;
  current->next->next = NULL;
}


void new_blockchain()
{
  printf("===================\n");
  printf("BLOCKCHAIN UPDATED:\n");
  printf("===================\n");
}
