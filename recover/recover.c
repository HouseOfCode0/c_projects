#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

int main(int argc, char *argv[])
{
    //declare data type to assign to jpeg values
    typedef uint8_t BYTE;
    {
         BYTE data;
    }

    //CHECK FOR COMMAND LINE ARGUMENT
    if (argc != 2 )
    {
        printf("Incomplete Command Line Argument");
        return 1;
    }

    //OPEN MEMORY CARD
    FILE* ptr1 = fopen(argv[1],"r" );

    //CHECK IF POINTER IS NULL
    if(ptr1 == NULL)
    {
        printf("Memory not allocated");
        return 1;
    }

   //count how many times to allocate blocks of 512 bytes
    int jpeg_count = 0;
    BYTE buffer[512];
    FILE *img;


    // LOOP ITERATES THROUGH CHARACTERS IN BUFFER


    while(fread(buffer,512,1,ptr1) == 1)
    {
        
        //CHECK FOR JPEG
        if( buffer[0] == 0xff &&  buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
             jpeg_count++;
            //FOR FIRST JPEG
            if(jpeg_count == 1)
            {
                char temp_name[8];
                sprintf(temp_name, "%03i.jpg",jpeg_count-1);
                img = fopen(temp_name, "w");
                fwrite(buffer,512,1,img);
                fclose(img);
            }
            //FOR 2ND TO LAST JPEG
            if(jpeg_count>=1)
            {
                fclose(img);
                char temp_name[8];
                sprintf(temp_name, "%03i.jpg",jpeg_count-1);
                img = fopen(temp_name, "w");
                fwrite(buffer,512,1,img);
               
            }
            
        }

        //IF JPEG FILE ALREADY FOUND
        else
        {
            fwrite(buffer,512,1,img);
        }
        
    }
     fclose(ptr1);







}




