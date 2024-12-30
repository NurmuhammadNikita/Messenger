#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "struct/structures.h"
#include "func/functions.h"






int main()
{
    struct User user;


    int amal;
    do
    {
        printf("Royhatdan o'tish: 1  ");
        printf("Akkauntga kirish: 2  ");
        printf("dasturdan chiqish 0: ");
        
        scanf("%d",&amal);

        switch (amal)
        { 
        case 1:
        {
            SignUp();

            do
            {
                printf("Habar yozish: 3 ");
                printf("orqaga: 4 ");

                switch (amal)
                {
                case 3:
                    
                    // habar yozadigan funksiya

                    break;
                
                default:
                    break;
                }
            } while (amal != 4);
            



            break;

           
        }
        
        case 2:
        {
           LoginUser();
           break; 
           
            
        }

        case 3:
        {
          
           break; 
           
            
        }

        default:
            break;
        }




    } while (amal != 0);
    return 0;
}

//         cd "d:\Coding\ForJob-NT\Messenger\" ; if ($?) { gcc Messenger-User.c -o Messenger-User func/functions.c} ; if ($?) { .\Messenger-User }  