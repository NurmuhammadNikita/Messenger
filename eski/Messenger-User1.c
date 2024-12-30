#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//#include "func/functions.h" 
//##################################################################################################################################

                                                            // Sturkturalar
struct User
{
    int Id;
    char user_name[30];
    char Password[50];  
    char FirstName[20];
    char LastName[20];
    char PhoneNumber[13];  
};

struct Message
{
    char sender_username [30];
    char recipient_username [30];
    char datetime[15];
    char length_message[500];
};


//###################################################################################################################################

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

                                                        // Funksiyalar


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
{   char satr[50];
    int lamp = 0,sch = 0;
    FILE *veriUsername;
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

int Login(char *userName, char *password, char *phoneNumber)
{
    bool Login = false;




}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
{

    int amal;
    do
    {
        printf("royhatdan o'tish: 1  Akkauntga kirish: 2  dasturdan chiqish 0: ");
        scanf("%d",&amal);

        switch (amal)
        {
        case 1:
        {
            SignUp();
            break;
        }
        
        case 2:
        {

            printf("\n\n%d",multiply(5,6));
        }

        default:
            break;
        }




    } while (amal != 0);

    printf("\n\nreturngacha keldi\n\n");
    return 0;
}