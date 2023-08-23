#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    //prompt user for  input
    float dollar;
    do 
     {
         dollar=get_float("Change owed:");
     }
    while (dollar<=0);
    
    int cents =round(dollar*100);
    
int count=0;

while(cents>=25)
{
    count++;
    cents-=25;
    
}

while (cents>=10)
{
    count++;
    cents-=10;
}

while (cents>=5)
{
    count++;
    cents-=5;
}
while (cents>=1)
{
    count++;
    cents-=1;
}




printf("%i\n",count);

}

  
     

   



     

