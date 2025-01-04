#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>



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

        // if (lamp == 1)
        // {
        //     printf("bunday foydalanuvchi nomi mavjud iltimos boshqa nomdan foydalaning\n");
        // }

        fclose(veriUsername);

        return lamp;
}


struct User AddUser()
{   FILE *veriUsername;
    veriUsername = fopen("Users.txt","r");
    int lamp;
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
        lamp = VerificationUserName(User.user_name);  

        if (lamp == 1)
        {
            printf("bunday foydalanuvchi nomi mavjud iltimos boshqa nomdan foydalaning\n");
        }

    } while (lamp == 1);

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


struct User SignUp()
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

            return user;
}


//####################################################################################################################################################



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                                                //Log In




struct LoginConfirmation VerificationUser( struct LoginUser loginUser)
{
    char satr[50];
    int lamp  = 0;
    int sch = 0;
    FILE *veriUser;
    veriUser = fopen("Users.txt","r");


    struct LoginConfirmation loginConfirmation;

    while (fscanf(veriUser,"%s",&satr)==1)
    {
        sch++;
        if (sch == 1)
        {
            loginConfirmation.user.Id = atoi(satr);
        }
        
        else if(sch == 2)
        {
            if (strcmp(loginUser.user_name,satr) == 0)
            {
                lamp++;
            }

            strcpy(loginConfirmation.user.user_name,satr);
            
        }
        else if (sch == 3)
        {
            if (strcmp(loginUser.Password,satr) == 0)
            {
                lamp++;
            }

            strcpy(loginConfirmation.user.Password,satr);
            
        }

        else if (sch == 4)
        {
            strcpy(loginConfirmation.user.PhoneNumber,satr);
        }

        else if (sch == 5)
        {
            strcpy(loginConfirmation.user.FirstName,satr);
        }

        else if (sch == 6)
        {
            if (lamp == 2)
            {
                break;
            }
            else lamp = 0;
            sch = 0;
            strcpy(loginConfirmation.user.LastName,satr);
        }
    }



    if (lamp == 2)
    {
        printf("Hush kelibsiz!!!\n");
 //       return lamp;
    }
    else 
    {
        printf("Login yoki parol hato qayta urining\n");
 //       return lamp;
    }

    loginConfirmation.match = lamp;

    return loginConfirmation;

}

struct User LoginUser()
{
    struct LoginUser LoginUser;
    struct LoginConfirmation userVer;

    do
    {   
        printf("user name: ");
        scanf("%s",LoginUser.user_name);

        printf("Password: ");
        scanf("%s",LoginUser.Password);
        userVer = VerificationUser(LoginUser);
    } while (userVer.match == 0);

    return userVer.user;
}




//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                                            //Write Message


void WriteMessage(struct Message message)
{
    FILE *fileMessage;

    char messageData[600],fileName[65];
    int met = 0; 

   
    strcpy(fileName, message.sender_username);
    strcat(fileName,"-");
    strcat(fileName, message.recipient_username);

A:
    fileMessage = fopen(fileName,"a");

    if (fileMessage == NULL)
    {
        if (met == 0)
        {   met++;
            fileName[0] = '\0';
            strcat(fileName, message.recipient_username);
            strcat(fileName,"-");
            strcpy(fileName, message.sender_username);
            goto A;         
        }
        
        printf("Habar faylini yozish uchun ochishda hatolik!!!");
    }
    
   else
    {
       sprintf(messageData,"\nEga: %s\n\nXabar: %s\n\nVaqti: %s\n\n",message.sender_username,message.length_message,message.datetime);

        printf("%s ",messageData);
       fprintf(fileMessage,"%s",messageData);
       fclose(fileMessage);
    }
}


void WriteController(struct User user)
{

    struct Message message;
    int veriuser;

    strcpy(message.sender_username, user.user_name);
    do
    {   

        printf("Kimga habar yozasiz(user name): ");
        scanf("%s",message.recipient_username);

        veriuser = VerificationUserName(message.recipient_username);

        if (veriuser == 0)
        {
            printf("Bunday foydalanuvchi mavjud emas! ");
        }
        
    } while (veriuser == 0 );

    printf("habar yozishni to'xtatish 0!\n");

    char txt[500];

    do
    {   printf("\nHabar: ");
        scanf(" %499[^\n]", message.length_message);
        
        if(strcmp(message.length_message, "0") != 0)
        {
            strcpy(message.datetime, TimeReverser());
            WriteMessage(message);
        }
        else break;

    } while (1);
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$






//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                    //Time function

char* TimeReverser()
{


    time_t current_time;
    struct tm *time_info;
    static char time_str[20];  

    time(&current_time);


    time_info = localtime(&current_time);


    strftime(time_str, sizeof(time_str), "%H:%M:%S %d.%m.%Y", time_info);

    return time_str;
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%






