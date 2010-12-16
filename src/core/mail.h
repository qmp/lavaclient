/* 
 */
#ifndef MAIL_H
#define MAIL_H

typedef enum
{
    DRAFT=2⁰;
    REPLIED=2²;
    SEEN=2³;
    TRASHED=2⁴;
    FUSER=2⁵;
}mail_status;

char* get_att(mail* mail, int index);
char* get_header(mail* mail, char* header);
char* get_body(mail* mail);
/* vim:set shiftwidth=4 cindent: */
