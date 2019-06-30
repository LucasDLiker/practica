#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED


typedef struct
{
int id;
char nombre[50];
char origen[50];
int isEmpty;
}eActor;


int generates_Next_Id_Actor();
int initActores(eActor *actores, int ACTORESMAX);



#endif

