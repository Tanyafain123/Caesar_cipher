//the encode and decode function file
#ifndef CIPHER
#define CIPHER
#include <stdio.h>
#include <string.h>
#define MAGIC_NUMBER1 26
#define POSITIVE 1


void big_letters_enc(char * p,int k, int i, int* flag)
{
  p[i] = p[i] + (k % MAGIC_NUMBER1);
  *flag = POSITIVE;
  if (p[i] > 'Z')
    {
      p[i] = 'A' + (p[i] - 'Z') - 1;
    }
  if (p[i] < 'A')
    {
      p[i] = 'Z' - ('A' - p[i])+ 1;
    }

}
void  small_letters_enc(char * p,int k, int i, int* flag)
{
  p[i] = p[i] + (k % MAGIC_NUMBER1);
  *flag = POSITIVE;
  if (p[i] > 'z')
    {
      p[i] = 'a' + (p[i] - 'z') - 1;
    }
  if (p[i] < 'a')
    {
      p[i] = 'z' - ('a' - p[i]) + 1;
    }

}





void big_letters_dec(char * p,int k, int i, int* flag)
{
  p[i] = p[i] - (k % MAGIC_NUMBER1);
  *flag = POSITIVE;
  if (p[i] < 'A')
    {
      p[i] = 'Z' - ('A' - p[i]) + 1;
    }
  if (p[i] > 'Z')
    {
      p[i] = 'A' + (p[i] - 'Z') - 1;
    }

}
void  small_letters_dec(char * p,int k, int i, int* flag)
{
  p[i] = p[i] - (k % MAGIC_NUMBER1);
  *flag = POSITIVE;
  if (p[i] < 'a')
    {
      p[i] = 'z' - ('a' - p[i]) + 1;
    }
  if (p[i] > 'z')
    {
      p[i] = 'a' + (p[i] - 'z') - 1;
    }

}




void encode (char * p,int k)
{
  int flag;
  for (int i = 0; i < (int) strlen (p); i++)
    {
      if (p[i] >= 'A' && p[i] <= 'Z')
        {
          big_letters_enc(p, k, i, &flag);
        }

      if (p[i] >= 'a' && p[i] <= 'z')
        {
          small_letters_enc(p, k, i, &flag);
        }

      if (!flag)
        {
          p[i] = p[i];
        }
    }
}



void decode (char * p,int k)
{
  for (int i = 0; i < (int) strlen (p); i++)
    {
      int flag = 0;
      if (p[i] >= 'A' && p[i] <= 'Z')
        {
          big_letters_dec (p, k, i, &flag);
        }

      if (p[i] >= 'a' && p[i] <= 'z')
        {
          small_letters_dec (p, k, i, &flag);
        }
      if (!flag)
        {
          p[i] = p[i];
        }
    }
}

#endif
