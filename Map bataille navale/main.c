#include <stdio.h>
#include <stdlib.h>

int main()
{
   int map1[20][20]={0};
   int map2[20][20]= {0};
   int ii;
   int jj;
   for(ii=0; ii <20; ii++)
    {
        for(jj=0; jj <20; jj++)
        {
            printf("%d", map1[ii][jj]);
            }
            printf("\n");
    }
    printf("\n");
    for(ii=0; ii <20; ii++)
    {
        for(jj=0; jj <20; jj++)
        {
            printf("%d", map2[ii][jj]);
            }
            printf("\n");
    }

    return ;

}
