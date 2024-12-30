#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../struct/structures.h"

//###############################################################################################
                                // Sign Up

int VerificationUserName(char *userName);

struct User AddUser();

void SignUp();
// ##############################################################################################

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

                            // Log In
int VerificationUser( struct LoginUser loginUser);

void LoginUser();


int Login();

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#endif