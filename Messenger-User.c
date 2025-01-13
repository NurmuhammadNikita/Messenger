#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "struct/structures.h"
#include "func/functions.h"






int main()
{   
    struct User user;
    system("cls");


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
                user = SignUp();
                system("cls"); 
                printf("Siz muvaffaqiyatli royhatdan o'tdingiz!!!\n");   
                break;
            }   
            case 2:
            {
                user = LoginUser();
                WriteController(user);  
                system("cls"); 
                break;
            }
            default:

                printf("Bunday raqamli amal mavjud emas!\n");
                break;
        }


    } while (amal != 0);
    return 0;
}

//         cd "d:\Coding\ForJob-NT\Messenger\" ; if ($?) { gcc Messenger-User.c -o Messenger-User func/functions.c} ; if ($?) { .\Messenger-User }  