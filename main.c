#include <stdio.h>
#include <stdlib.h>
#define CROISEUR 4
#define PORTEAVIONS 5
#define TORPILLEUR 3
#define FREGATE 2
#define RATE 8
#define TOUCHE 1

void tableau (int map1 [24][18], int map2 [24][18])
{

    int ii;
    int jj;
    for(ii=0; ii <24; ii++)
        {
            for(jj=0; jj <18; jj++)
            {
                printf("%2d", map1[ii][jj]);
            }
            printf("\n");
        }
    printf("\n");
    for(ii=0; ii <24; ii++)
        {
            for(jj=0; jj <18; jj++)
            {
                printf("%2d", map2[ii][jj]);
            }
            printf("\n");
        }
} //fonction pour initialiser les terrains de jeu

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
} // fonction de pause

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}// fonction aléatoire

void placementfregate (int map1[24][18], int map2[24][18])
{
    int fregatexj1=0;
    int fregateyj1=0;
    int fregatexj2=0;
    int fregateyj2=0;
    do
    {
        do
        {
            fregatexj1= doRand(0,23);
            fregateyj1= doRand(0,17);

        } while(map1[fregatexj1][fregateyj1]!=0 );
        map1[fregatexj1][fregateyj1]=2;
        if (map1[fregatexj1+1][fregateyj1]==0 && fregatexj1+1<=23)
        {
            map1[fregatexj1+1][fregateyj1]=2;
        } else if (map1[fregatexj1-1][fregateyj1]==0 && fregatexj1-1>=0)
        {
            map1[fregatexj1-1][fregateyj1]=2;
        } else if (map1[fregatexj1][fregateyj1+1]==0 && fregateyj1+1<=17)
        {
            map1[fregatexj1][fregateyj1+1]=2;
        } else if (map1[fregatexj1][fregateyj1-1]==0 && fregateyj1-1>=0)
        {
            map1[fregatexj1][fregateyj1-1]=2;
        }
    } while (map1[fregatexj1][fregateyj1]==0);

    do
    {
        do
        {
            fregatexj2= doRand(0,23);
            fregateyj2= doRand(0,17);

        } while(map2[fregatexj2][fregateyj2]!=0);
        map2[fregatexj2][fregateyj2]=2;
        if (map2[fregatexj2+1][fregateyj2]==0 && fregatexj2+1<=23)
        {
            map2[fregatexj2+1][fregateyj2]=2;
        } else if (map2[fregatexj2-1][fregateyj2]==0 && fregatexj2-1>=0)
        {
            map2[fregatexj2-1][fregateyj2]=2;
        } else if (map2[fregatexj2][fregateyj2+1]==0 && fregateyj2-1<=17)
        {
            map2[fregatexj2][fregateyj2+1]=2;
        } else if (map2[fregatexj2][fregateyj2-1]==0 && fregateyj2-1>=0)
        {
            map2[fregatexj2][fregateyj2-1]=2;
        }
    } while (map2[fregatexj2][fregateyj2]==0);
}

void placementtorpilleur (int map1[24][18], int map2[24][18])
{
    int torpixj1= 0;
    int torpixj2=0;
    int torpiyj1=0;
    int torpiyj2=0;
    do
    {
        do
        {
            torpixj1= doRand(0,23);
            torpiyj1= doRand(0,17);

        } while(map1[torpixj1][torpiyj1]!=0);
        map1[torpixj1][torpiyj1]=3;
        if (map1[torpixj1+1][torpiyj1]==0 && map1[torpixj1+2][torpiyj1]==0 && torpixj1+2<=23)
        {
            map1[torpixj1+1][torpiyj1]=3;
            map1[torpixj1+2][torpiyj1]=3;
        } else if (map1[torpixj1-1][torpiyj1]==0 && map1[torpixj1-2][torpiyj1]==0 && torpixj1-2>=0)
        {
            map1[torpixj1-1][torpiyj1]=3;
            map1[torpixj1-2][torpiyj1]=3;
        } else if (map1[torpixj1][torpiyj1+1]==0 && map1[torpixj1][torpiyj1+2]==0 && torpiyj1+2<=17)
        {
            map1[torpixj1][torpiyj1+1]=3;
            map1[torpixj1][torpiyj1+2]=3;
        } else if (map1[torpixj1][torpiyj1-1]==0 && map1[torpixj1][torpiyj1-2]==0 && torpiyj1-2>=0)
        {
            map1[torpixj1][torpiyj1-1]=3;
            map1[torpixj1][torpiyj1-2]=3;
        }
    } while (map1[torpixj1][torpiyj1]==0);

    do
    {
        do
        {
            torpixj2= doRand(0,23);
            torpiyj2= doRand(0,17);

        } while(map2[torpixj2][torpiyj2]!=0);
        map2[torpixj2][torpiyj2]=3;
        if (map2[torpixj2+1][torpiyj2]==0 && map2[torpixj2+2][torpiyj2]==0 && torpixj2+2<=23)
        {
            map2[torpixj2+1][torpiyj2]=3;
            map2[torpixj2+2][torpiyj2]=3;
        } else if (map2[torpixj2-1][torpiyj2]==0 && map2[torpixj2-2][torpiyj2]==0 && torpixj2-2>=0)
        {
            map2[torpixj2-1][torpiyj2]=3;
            map2[torpixj2-2][torpiyj2]=3;
        } else if (map2[torpixj2][torpiyj2+1]==0 && map2[torpixj2][torpiyj2+2]==0 && torpiyj2+2<=17)
        {
            map2[torpixj2][torpiyj2+1]=3;
            map2[torpixj2][torpiyj2+2]=3;
        } else if (map2[torpixj2][torpiyj2-1]==0 && map2[torpixj2][torpiyj2-2]==0 && torpiyj2-2>=0)
        {
            map2[torpixj2][torpiyj2-1]=3;
            map2[torpixj2][torpiyj2-2]=3;
        }
    } while (map2[torpixj2][torpiyj2]==0);

}

void placementcroiseur (int map1[24][18], int map2[24][18])
{
    int croiseurxj1=0;
    int croiseuryj1=0;
    int croiseurxj2=0;
    int croiseuryj2=0;
    do
    {
        do
        {
            croiseurxj1= doRand(0,23);
            croiseuryj1= doRand(0,17);

        } while(map1[croiseurxj1][croiseuryj1]!=0);
        map1[croiseurxj1][croiseuryj1]=4;
        if (map1[croiseurxj1+1][croiseuryj1]==0 && map1[croiseurxj1+2][croiseuryj1]==0 && map1[croiseurxj1+3][croiseuryj1]==0 && croiseurxj1+3<=23)
        {
            map1[croiseurxj1+1][croiseuryj1]=4;
            map1[croiseurxj1+2][croiseuryj1]=4;
            map1[croiseurxj1+3][croiseuryj1]=4;
        } else if (map1[croiseurxj1-1][croiseuryj1]==0 && map1[croiseurxj1-2][croiseuryj1]==0 && map1[croiseurxj1-3][croiseuryj1]==0 && croiseurxj1-3>=0)
        {
            map1[croiseurxj1-1][croiseuryj1]=4;
            map1[croiseurxj1-2][croiseuryj1]=4;
            map1[croiseurxj1-3][croiseuryj1]=4;
        } else if (map1[croiseurxj1][croiseuryj1+1]==0 && map1[croiseurxj1][croiseuryj1+2]==0 && map1[croiseurxj1][croiseuryj1+3]==0 && croiseuryj1+3<=17)
        {
            map1[croiseurxj1][croiseuryj1+1]=4;
            map1[croiseurxj1][croiseuryj1+2]=4;
            map1[croiseurxj1][croiseuryj1+3]=4;
        } else if (map1[croiseurxj1][croiseuryj1-1]==0 && map1[croiseurxj1][croiseuryj1-2]==0 && map1[croiseurxj1][croiseuryj1-3]==0 && croiseuryj1-3>=0)
        {
            map1[croiseurxj1][croiseuryj1-1]=4;
            map1[croiseurxj1][croiseuryj1-2]=4;
            map1[croiseurxj1][croiseuryj1-3]=4;
        }
    } while (map1[croiseurxj1][croiseuryj1]==0);

    do
    {
        do
        {
            croiseurxj2= doRand(0,23);
            croiseuryj2= doRand(0,17);

        } while(map2[croiseurxj2][croiseuryj2]!=0);
        map2[croiseurxj2][croiseuryj2]=4;
        if (map2[croiseurxj2+1][croiseuryj2]==0 && map2[croiseurxj2+2][croiseuryj2]==0 && map2[croiseurxj2+3][croiseuryj2]==0 && croiseurxj2+3<=23)
        {
            map2[croiseurxj2+1][croiseuryj2]=4;
            map2[croiseurxj2+2][croiseuryj2]=4;
            map2[croiseurxj2+3][croiseuryj2]=4;
        } else if (map2[croiseurxj2-1][croiseuryj2]==0 && map2[croiseurxj2-2][croiseuryj2]==0 && map2[croiseurxj2-3][croiseuryj2]==0 && croiseurxj2-3>=0)
        {
            map2[croiseurxj2-1][croiseuryj2]=4;
            map2[croiseurxj2-2][croiseuryj2]=4;
            map2[croiseurxj2-3][croiseuryj2]=4;
        } else if (map2[croiseurxj2][croiseuryj2+1]==0 && map2[croiseurxj2][croiseuryj2+2]==0 && map2[croiseurxj2][croiseuryj2+3]==0 && croiseuryj2+3<=17)
        {
            map2[croiseurxj2][croiseuryj2+1]=4;
            map2[croiseurxj2][croiseuryj2+2]=4;
            map2[croiseurxj2][croiseuryj2+3]=4;
        } else if (map2[croiseurxj2][croiseuryj2-1]==0 && map2[croiseurxj2][croiseuryj2-2]==0 && map2[croiseurxj2][croiseuryj2-3]==0 && croiseuryj2-3>=0)
        {
            map2[croiseurxj2][croiseuryj2-1]=4;
            map2[croiseurxj2][croiseuryj2-2]=4;
            map2[croiseurxj2][croiseuryj2-3]=4;
        }
    } while (map2[croiseurxj2][croiseuryj2]==0);
}

void placementpa (int map1[24][18], int map2[24][18])
{
    int paxj1= 0;
    int payj1= 0;
    int paxj2= 0;
    int payj2= 0;
    do
    {
        do
        {
            paxj1= doRand(0,23);
            payj1= doRand(0,17);

        } while(map1[paxj1][payj1]!=0);
        map1[paxj1][payj1]=5;
        if (map1[paxj1+1][payj1]==0 && map1[paxj1+2][payj1]==0 && map1[paxj1+3][payj1]==0 && map1[paxj1+4][payj1]==0 && paxj1+4<=23)
        {
            map1[paxj1+1][payj1]=5;
            map1[paxj1+2][payj1]=5;
            map1[paxj1+3][payj1]=5;
            map1[paxj1+4][payj1]=5;
        } else if (map1[paxj1-1][payj1]==0 && map1[paxj1-2][payj1]==0 && map1[paxj1-3][payj1]==0 && map1[paxj1-4][payj1]==0 && paxj1-4>=0)
        {
            map1[paxj1-1][payj1]=5;
            map1[paxj1-2][payj1]=5;
            map1[paxj1-3][payj1]=5;
            map1[paxj1-4][payj1]=5;
        } else if (map1[paxj1][payj1+1]==0 && map1[paxj1][payj1+2]==0 && map1[paxj1][payj1+3]==0 && map1[paxj1][payj1+4]==0 && payj1+4<=17)
        {
            map1[paxj1][payj1+1]=5;
            map1[paxj1][payj1+2]=5;
            map1[paxj1][payj1+3]=5;
            map1[paxj1][payj1+4]=5;
        } else if (map1[paxj1][payj1-1]==0 && map1[paxj1][payj1-2]==0 && map1[paxj1][payj1-3]==0 && map1[paxj1][payj1-4]==0 && payj1-4>=0)
        {
            map1[paxj1][payj1-1]=5;
            map1[paxj1][payj1-2]=5;
            map1[paxj1][payj1-3]=5;
            map1[paxj1][payj1-4]=5;
        }
    } while (map1[paxj1][payj1]==0);

    do
    {
        do
        {
            paxj2= doRand(0,23);
            payj2= doRand(0,17);

        } while(map2[paxj2][payj2]!=0);
        map2[paxj2][payj2]=5;
        if (map2[paxj2+1][payj2]==0 && map2[paxj2+2][payj2]==0 && map2[paxj2+3][payj2]==0 && map2[paxj2+4][payj2]==0 && paxj2+4<=23)
        {
            map2[paxj2+1][payj2]=5;
            map2[paxj2+2][payj2]=5;
            map2[paxj2+3][payj2]=5;
            map2[paxj2+4][payj2]=5;
        } else if (map2[paxj2-1][payj2]==0 && map2[paxj2-2][payj2]==0 && map2[paxj2-3][payj2]==0 && map2[paxj2-4][payj2]==0 && paxj2-4>=0)
        {
            map2[paxj2-1][payj2]=5;
            map2[paxj2-2][payj2]=5;
            map2[paxj2-3][payj2]=5;
            map2[paxj2-4][payj2]=5;
        } else if (map2[paxj2][payj2+1]==0 && map2[paxj2][payj2+2]==0 && map2[paxj2][payj2+3]==0 && map2[paxj2][payj2+4]==0 && payj2+4<=17)
        {
            map2[paxj2][payj2+1]=5;
            map2[paxj2][payj2+2]=5;
            map2[paxj2][payj2+3]=5;
            map2[paxj2][payj2+4]=5;
        } else if (map2[paxj2][payj2-1]==0 && map2[paxj2][payj2-2]==0 && map2[paxj2][payj2-3]==0 && map2[paxj2][payj2-4]==0 && payj2-4>=0)
        {
            map2[paxj2][payj2-1]=5;
            map2[paxj2][payj2-2]=5;
            map2[paxj2][payj2-3]=5;
            map2[paxj2][payj2-4]=5;
        }
    } while (map2[paxj2][payj2]==0);
}
void tir (int map1[24][18], int map2[24][18])
{
    int attaquexj1=0;
    int attaquexj2=0;
    int attaqueyj1=0;
    int attaqueyj2=0;
    int fregatej1= 2;
    int fregatej2= 2;
    int torpilleurj1= 3;
    int torpilleurj2= 3;
    int croiseurj1= 4;
    int croiseurj2= 4;
    int pavj1= 5;
    int pavj2= 5;
    do
    {
        printf("ATTAQUE DU JOUEUR 1\n");
        attaquexj1= doRand(0,25);
        attaqueyj1= doRand(0,19);
        if (map2[attaquexj1][attaqueyj1]!=0 && map2[attaquexj1][attaqueyj1]!=1 && map2[attaquexj1][attaqueyj1]!=8)
        {
            if(map2[attaquexj1][attaqueyj1]==2)
            {
                fregatej2= fregatej2-1;
            } else if (map2[attaquexj1][attaqueyj1]==3)
            {
                torpilleurj2= torpilleurj2-1;
            } else if (map2[attaquexj1][attaqueyj1]==4)
            {
                croiseurj2= croiseurj2-1;
            }else if (map2[attaquexj1][attaqueyj1]==5)
            {
                pavj2= pavj2-1;
            }
        map2[attaquexj1][attaqueyj1]= TOUCHE;
            printf("TOUCHE\n");
        } else if(map2[attaquexj1][attaqueyj1]==0)
        {
        map2[attaquexj1][attaqueyj1]= RATE;
        }

        printf("ATTAQUE DU JOUEUR 2\n");
        attaquexj2= doRand(0,25);
        attaqueyj2= doRand(0,19);
        if (map1[attaquexj2][attaqueyj2]!=0 && map1[attaquexj2][attaqueyj2]!=1 && map1[attaquexj2][attaqueyj2]!=8)
        {
            if(map1[attaquexj2][attaqueyj2]==2)
            {
                fregatej1= fregatej1-1;
            } else if (map1[attaquexj2][attaqueyj2]==3)
            {
                torpilleurj1= torpilleurj1-1;
            } else if (map1[attaquexj2][attaqueyj2]==4)
            {
                croiseurj1= croiseurj1-1;
            }else if (map1[attaquexj2][attaqueyj2]==5)
            {
                pavj1= pavj1-1;
            }
            map1[attaquexj2][attaqueyj2]= TOUCHE;
            printf("TOUCHE\n");

        } else if(map1[attaquexj2][attaqueyj2]==0)
        {
        map1[attaquexj2][attaqueyj2]= RATE;
        }
        printf(" JOUEUR 2: FREGATE: %d, TORPILLEUR: %d, CROISEUR: %d, PORTE-AVIONS: %d \n",fregatej2, torpilleurj2, croiseurj2, pavj2);
        printf(" JOUEUR 1: FREGATE: %d, TORPILLEUR: %d, CROISEUR: %d, PORTE-AVIONS: %d \n",fregatej1, torpilleurj1, croiseurj1, pavj1);
    }while ((fregatej1>0 || torpilleurj1>0 || croiseurj1>0 || pavj1>0) && (fregatej2>0 || torpilleurj2>0 || croiseurj2>0 || pavj2>0));
    printf("\n");
    if (fregatej1>0 || torpilleurj1>0 || croiseurj1>0 || pavj1>0)
    {
        printf("#######################\n#  JOUEUR 1 A GAGNER  #\n#######################\n");
    }else if (fregatej2>0 || torpilleurj2>0 || croiseurj2>0 || pavj2>0)
    {
        printf("#######################\n#\n#  JOUEUR 2 A GAGNER  #\n#\n#######################\n");
    }
}


int main()
{
    int map1[24][18]={0};
    int map2[24][18]={0};
    printf ("####################\n#  BIENVENUE A LA  #\n# BATAILLE NAVALE  #\n#################### \n");
    printf("\n");
    placementfregate(map1,map2);
    placementtorpilleur(map1,map2);
    placementcroiseur(map1,map2);
    placementpa(map1,map2);
    printf ("PLACEMENT DES BATEAUX \n");
    printf("\n");
    tableau(map1,map2);
    printf("\n DEBUT DE LA PARTIE!!! \n");
    tir(map1,map2);
    tableau(map1,map2);
    return 0;
}
