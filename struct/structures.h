#ifndef STRUCTURES_H
#define STRUCTURES_H

// Strukturani e'lon qilish
struct User
{
    int Id;
    char user_name[30];
    char Password[50];  
    char FirstName[20];
    char LastName[20];
    char PhoneNumber[13];  
};

struct UserInfo
{
    char user_name[30];
    char FirstName[20];
    char LastName[20];
    char PhoneNumber[13];
    
};



struct LoginUser
{
    char user_name[30];
    char Password[50];  
};

struct LoginConfirmation
{
    struct User user;
    int match;
};



struct Message
{
    char sender_username [30];
    char recipient_username [30];
    char datetime[20];
    char length_message[500];
};



#endif