#include <stdio.h>
#include <string.h>


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
                user = SignUp();
                
                break;

            
            }
            
            case 2:
            {
                user = LoginUser();   
            }

            case 3:
            {
                printf("%s %s",user.FirstName,user.user_name);  
                WriteController(user);
  
                break;   
            }

            default:
                break;
        }




    } while (amal != 0);
    return 0;
}

//         cd "d:\Coding\ForJob-NT\Messenger\" ; if ($?) { gcc Messenger-User.c -o Messenger-User func/functions.c} ; if ($?) { .\Messenger-User }  