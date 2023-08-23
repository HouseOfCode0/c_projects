// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include<cs50.h>
#include<strings.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //convert to lower
    int s = strlen(word);
    char check_word[s]; 
    strcpy(check_word,word);
    
    for(int i =0 ;i<s; i++)
    {
       check_word[i] = tolower(word[i]); 
    }
   
    int z = hash(check_word);
    
    
    if(table[z] != NULL)
    {
    for (node *cursor = table[z];cursor != NULL;cursor= cursor->next)
    
    {
        if(strcasecmp(check_word,cursor->word) == 0)
        {
            return true;
        }
        
        cursor = cursor->next;
    }
    }
   
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *word++) != 0)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    }

    return (hash%N);

}

unsigned int count_words = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    //OPEN DICTIONARY
    FILE *ptr1 = fopen(dictionary, "r");
    if(ptr1 == NULL)
    {
        return false;
    }

    //LOOP READING DICTIONARY UNTIL EOF
    char buffer[LENGTH + 1];
    while(fscanf(ptr1,"%s",buffer) != EOF)

    {
        //ALLOCATE MEMORY TO NODE n
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }

        //COPY CHARACTER FROM BUFFER TO NODE
        strcpy(n->word,buffer);
        n->next = NULL;

        //RECEIVE INDEX VALUE FROM HASH
        unsigned int a =  hash(buffer);

        //ASSIGN FIRST NODE INTO AREAY
        if(table[a] == NULL)
        {
            table[a]= n;
        }

        //ASSIGN nth NODE INTO ARRAY
        else
        {
            n->next = table[a];
            table[a]= n;
        }
        
        //COUNT WORDS FOR SIZE FUNCTION
        count_words++;

    }

    fclose(ptr1);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    
   
    for(int a = 0;a<N;a++)
    {
        node *cursor = table[a];
        
        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor=cursor->next;
            free(temp);
            
        }
        table[a] = NULL;
    }
    
    return true;
}
