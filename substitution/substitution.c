#include <cs50.h>
#include <stdio.h>
#include <strings.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>




int main(int argc, string argv[])
{
    //check command line argument lenght
    if (argc != 2)
    {
        printf("Incomplete Command Line arguement\n");
        return 1;
    }

    //check character Lenght
    if (strlen(argv[1]) != 26)
    {
        printf("Key Must Contain 26 Characters\n");
        return 1;
    }

    char s[26];
    strcpy(s, argv[1]);

    // check for number
    for (int i = 0 ; i < 26; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            printf("Only Alphabets Accepted\n");
            return 1;
        }

    }


    //check for character repetition
    for (int i =  0 ; i < 26; i++)
    {
        int count = 0;
        for (int j = 0 ; j < 26; j++)
        {
            if (s[i] == s[j] || s[i] == s[j] + 32 || s[i] == s[j] - 32)
            {
                count++;
                if (count > 1)
                {
                    return 1;
                    printf("Character Repetition Not Allowed");
                }
            }
        }
    }

    //GET USER INPUT
    string plaintext = get_string("Plaintext:");
    int z = strlen(plaintext) + 1;

    //COPY USER INPUT TO CHAR ARRAY
    char ciphertext [z];
    for (int i = 0; i < z; i++)
    {
        ciphertext[i] = plaintext[i];

    }

    //DECLARE ARRAY TO GET INDEX VALUES
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                      'u', 'v', 'w', 'x', 'y', 'z'

                     };

    //ITERATE OVER PLAINTEXT
    for (int i = 0, n = strlen(plaintext) ; i < n; i++)
    {
        //ITERATE OVER CHAR ALPHA
        int count = 0;
        for (int j = 0; j < 26 ; j++)
        {
            count++;

            //CONDITION FOR LOWERCASE
            if (plaintext[i] == alpha[j])
            {
                ciphertext[i] = tolower(s[count - 1]);
            }

            //CONDITION FOR UPPERCASE
            if (plaintext[i] == toupper(alpha[j]))
            {
                ciphertext[i] = toupper(s[count - 1]);
            }
        }

    }





    printf("ciphertext: %s\n", ciphertext);

}


