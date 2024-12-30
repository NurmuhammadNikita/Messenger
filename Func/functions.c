#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>



#include "functions.h"
#include "../struct/structures.h"



//###################################################################################################################################################
                                                //Sign Up

int VerificationUserName(char *userName)
{   char satr[50];
    int lamp = 0,sch = 0;
    FILE *veriUsername;
    veriUsername = fopen("Users.txt","r");


    while (fscanf(veriUsername,"%s",&satr)==1)
        {   
            sch++;
            if (sch == 2)
            {   
                if (strcmp(satr,userName) == 0)
                {
                    lamp = 1;
                    fseek(veriUsername, 0, SEEK_SET);
                    sch = 0;
                    break;
                }
                else lamp = 0;          
            }

            else if (sch == 6)
            {
                sch = 0;
            }            
        }

        if (lamp == 1)
        {
            printf("bunday foydalanuvchi nomi mavjud iltimos boshqa nomdan foydalaning\n");
        }

        fclose(veriUsername);

        return lamp;
}


struct User AddUser()
{   FILE *veriUsername;
    veriUsername = fopen("Users.txt","r");
    struct User User;
    {
        A:
         printf("First name: ");
        scanf("%s",User.FirstName);

        printf("Last name: ");
        scanf("%s",User.LastName);

    do
    {
        printf("User name: ");
        scanf("%s",User.user_name);       
    } while (VerificationUserName(User.user_name) == 1);

        printf("Password: ");
        scanf("%s",User.Password);

        printf("Phone Number(+998): ");
        scanf("%s",User.PhoneNumber);
    }

    printf("Sizning ma'lumotlaringiz\n Ism: %s Familiya: %s Foydalanuvchi nomi: %s Mahfiy kalit: %s Telefon raqam: %s \n",User.FirstName,User.LastName,User.user_name,User.Password,User.PhoneNumber);
    printf("\nMa'lumotlaringiz to'g'rimi?(Xa: 1  Yo'q: 0 ):");
    int aniqlash;
    scanf("%d",&aniqlash);
    if (aniqlash == 0)
    {
        goto A;
    }

    return User;
}


void SignUp()
{

                struct User user = AddUser();
            char userData[100];


            FILE *fileUsers, *fileForId;
            fileUsers = fopen("Users.txt","a");
            fileForId = fopen("FileForId.txt","r+");

            if (fileForId == NULL)
            {
                fileForId = fopen("FileForId.txt","w");
                user.Id = 1;
                 fprintf(fileForId,"%d",2);
                fclose(fileForId);
            }

            fscanf(fileForId,"%d",&user.Id);
            fclose(fileForId);

             fileForId = fopen("FileForId.txt","w");          
            fprintf(fileForId,"%d",user.Id+1);
            fclose(fileForId);
            
            sprintf(userData,"%d %s %s +998%s %s %s\n",user.Id,user.user_name,user.Password,user.PhoneNumber,user.FirstName,user.LastName);
            printf("Siz muvaffaqiyatli royhatdan o'tdingiz!!!");
            fprintf(fileUsers,"%s",userData);
}


//####################################################################################################################################################



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                                                //Log In




int VerificationUser( struct LoginUser loginUser)
{
    char satr[50];
    int lamp  = 0;
    int sch = 0;
    FILE *veriUser;
    veriUser = fopen("Users.txt","r");

    while (fscanf(veriUser,"%s",&satr)==1)
    {
        sch++;
        if(sch == 2)
        {
            if (strcmp(loginUser.user_name,satr) == 0)
            {
                lamp++;
            }
            
        }
        else if (sch == 3)
        {
            if (strcmp(loginUser.Password,satr) == 0)
            {
                lamp++;
            }
            
        }

        else if (sch == 6)
        {
            if (lamp == 2)
            {
                break;
            }
            else lamp = 0;
            sch = 0;
        }
    }

    if (lamp == 2)
    {
        printf("Hush kelibsiz!!!\n");
        return lamp;
    }
    else 
    {
        printf("Login yoki parol hato qayta urining\n");
        return lamp;
    }
    
    return lamp;

}

struct User LoginUser()
{
    struct LoginUser LoginUser;

    do
    {   
        printf("user name: ");
        scanf("%s",LoginUser.user_name);

        printf("Password: ");
        scanf("%s",LoginUser.Password);
    } while (VerificationUser(LoginUser) == 0);

    
}




//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                                            //Write Message


void WriteMessage()
{



}







//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$








