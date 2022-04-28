//The main code file
#ifndef BONUS

#include "cipher.h"
#include <stdlib.h>




#define  WORD1  "encode"
#define  WORD2  "decode"
#define  USAGE_MESSAGE  "Usage: cipher <encode|decode> <k> <source path file> <output path file>\n"
#define INVALID_K  "The given shifts value is invalid\n"
#define INVALID_COMMAND "The given command is invalid\n"
#define INVALID_FILE "The given file is invalid\n"



#define READSIZE  15
#define NUM_OF_ARGS 5
#define MATCH 0
#define BASE 10
#define FIRSTARG 1
#define SECONDARG 2
#define THIRDARG 3
#define FOURTHARG 4








int input_check (int argc, const char *argv[])
{
  char *c = NULL;
  strtol (argv[SECONDARG], &c, BASE);
  if (argc != NUM_OF_ARGS)
    {
      fprintf (stderr, USAGE_MESSAGE);
      return EXIT_FAILURE;
    }
  if (*c != '\0')
    {
      fprintf (stderr, INVALID_K);
      return EXIT_FAILURE;
    }
  if ((strcmp (argv[FIRSTARG], WORD1) != MATCH) && (strcmp (argv[FIRSTARG], WORD2) != MATCH))
    {
      fprintf (stderr, INVALID_COMMAND);
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}

int main (int argc, const char *argv[])
{
  const char *input_file_path = argv[THIRDARG]; 
  const char *out_file_path = argv[FOURTHARG];
  if (input_check (argc, argv))
    {
      return EXIT_FAILURE;
    }

  FILE *in_file = fopen (input_file_path, "r"); 
  FILE *out_file = fopen (out_file_path, "w");
  if (in_file == NULL)
    {
      fprintf (stderr, INVALID_FILE);
      return EXIT_FAILURE;
    }
  if (out_file == NULL)
    {
      fprintf (stderr, INVALID_FILE);
      fclose (in_file);
      return EXIT_FAILURE;
    }
  else
    {
      char buffer[READSIZE] = {0};
      char *p;
      long conv = strtol (argv[2], &p, BASE);
      while (fgets (buffer, READSIZE, in_file) != NULL)
        {
          if (!strcmp (argv[FIRSTARG], WORD1))
            {
              encode (buffer, (int) conv);
              fprintf (out_file, "%s", buffer);
            }
          if (!(strcmp (argv[FIRSTARG], WORD2)))
            {
              decode (buffer, (int) conv);
              fprintf (out_file, "%s", buffer);
            }
        }
      fclose (in_file);
      fclose (out_file);
    }
}

#endif
