

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letter(string a[]);
int main(void)

{

    //prompt user for input
    string text = get_string("Text:");

    //letter count
    int z = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isalpha(text[i]) != 0)
        {
            z++;
        }
    }
    printf("%i letters\n",z);


    //word count
    int a = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
      if (isalpha(text[i]) == 0  && isalpha(text[i + 1]))
        {
            a++;
        }
        
        if  (text[i]=='-')
        {
            a--;
        }
         if (isalpha(text[i]) && ispunct(text[i+1])  && isalpha(text[i+2]) )
         {
             a--;
         }
         if (isalpha(text[i]) && ispunct(text[i+1])  && isalpha(text[i+2]) && isalpha(text[i+3]))
         {
             a++;
         }

    }
     printf("%i words \n",a);

     //sentence
   int o=0;
   for (int i = 0, n = strlen(text); i < n; i++)
   {
       if((text[i]) == '.'  || (text[i]) == '?' || (text[i]) == '!')
       {
           o++;
       }

   }
   printf("%i sentences\n" ,o);

  //final compilation
  int L= (z*100)/a;
  int S=(o*100)/a;


int index = round(0.0588 * L - 0.296 * S - 15.8);

if(index<1)
{
    printf("Before Grade 1\n");
}

else if(index>=16)
{
    printf("Grade 16+\n");
}

else if (index==10)
{
    printf("Grade 10\n");
}

else
{
    printf("Grade %i\n",index);
}



}











