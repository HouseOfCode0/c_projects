#include "helpers.h"
#include<math.h>
#include<stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen);
            float average = round(sum / 3);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

         RGBTRIPLE new_arrange = image[i][j];
         image[i][j] = image[i][width - j - 1];
         image[i][width - j - 1] = new_arrange;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            copy[i][j]  = image[i][j];
        }
    }


    //iterate vertically
    for (int i = 0;i < height; i++)
    {
        //iterate horizontally
        for (int j = 0 ;j < width; j++)
        {


            //declare int sum of colours and number of pixels
            float red = 0;
            float blue = 0;
            float green = 0;
            float number = 0;

            //iterate to check if elements exist in 3 by 3 array in image[i][j]
            for (int column = i - 1; column <= i + 1; column++)
            {
                for( int row = j - 1; row <= j + 1; row++)
                {
                    if(0 <= column && column < height && 0 <= row && row < width)
                    {
                        red   +=  copy[column][row].rgbtRed;
                        blue  +=  copy[column][row].rgbtBlue;
                        green +=  copy[column][row].rgbtGreen;
                        number++ ;
                    }
                }
            }

    //average of individual colours from 3 by 3 grid and converting into int
    float red1  =   round(red / number);
    float blue1  = round(blue / number);
    float green1 = round(green / number);

     //value of pixel
            image[i][j].rgbtRed   = red1;
            image[i][j].rgbtBlue  = blue1;
            image[i][j].rgbtGreen = green1;
        }

    }

}



// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{


      //make copy
    RGBTRIPLE copy[height][width];
    for(int i = 0;i<height;i++)
    {
        for(int j = 0 ;j<width;j++)
        {
            copy[i][j]  = image[i][j];
        }
    }
         //declare gx
         float gx[3][3] ={ {-1,0,1}, {-2,0,2} , {-1,0,1} };
        //declare gy
        float gy[3][3] ={ {-1,-2,-1}, {0,0,0} , {1,2,1} };

     //iterate vertically
     for(int i = 0;i<height;i++)
    {
        //iterate horizontally
        for(int j = 0 ;j<width;j++)
        {

             //declare int sum of colours and number of pixels
             float redgy =0;
             float bluegy=0;
             float greengy= 0;
             float redgx =0;
             float bluegx =0;
             float greengx =0;

             //iterate to check if elements exist in 3 by 3 array in image[i][j]
            for(int column =i-1;column<=i+1;column++)
            {
                for(int row =j-1;row<=j+1;row++)
                {

                   //if pixels are not on edge
                   if(0<=column && column<height && 0<=row && row<width)
                    {

                        //sum of gx values
                        redgx   +=  (gx[i+1-column][j+1-row] * copy[column][row].rgbtRed);
                        bluegx  +=  (gx[i+1-column][j+1-row] * copy[column][row].rgbtBlue);
                        greengx +=  (gx[i+1-column][j+1-row] * copy[column][row].rgbtGreen);

                        //sum of gy values
                        redgy   +=  gy[i+1-column][j+1-row]*copy[column][row].rgbtRed;
                        bluegy  +=  gy[i+1-column][j+1-row]*copy[column][row].rgbtBlue;
                        greengy +=  gy[i+1-column][j+1-row]*copy[column][row].rgbtGreen;
                    }

                }
                  int fred1   = round(sqrt(pow(redgx,2)   + pow(redgy,2)));
                  int fblue1  = round(sqrt(pow(bluegx,2)  + pow(bluegy,2)));
                  int fgreen1 = round(sqrt(pow(greengx,2) + pow(greengy,2)));

                  int arr[3] = { fred1,fblue1,fgreen1} ;
                  for(int z = 0;z<3;z++)
                  {
                   if(arr[z]>255)
                   {
                       arr[z] = 255;
                   }
                   else if (arr[z]<0)
                   {
                        arr[z] = 0 ;
                   }
                  }
                image[i][j].rgbtRed   = arr[0];
                image[i][j].rgbtBlue  = arr[1];
                image[i][j].rgbtGreen = arr[2];
            }
          }

    }
}











