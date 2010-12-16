/* 
 */
#ifndef WRITEMAIL_H
#define WRITEMAIL_H

#include "email.h"
bool add_header(char* header, char* value);
bool set_body(char* body);
bool add_att( file);
void set_status(mail* mail, mail_status status);
void unset_status(mail* email, mail_status status);
bool write(mail* mail);
/* vim:set shiftwidth=4 cindent: */
