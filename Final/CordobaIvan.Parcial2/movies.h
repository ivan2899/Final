#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct
{
    int id;
    char titulo[50];
    char genero[50];
    float rating;
}eMovie;

eMovie* movie_new();

#endif // MOVIES_H_INCLUDED


