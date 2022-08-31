#include <stdlib.h>
#include <stdio.h>

#include "movies.h"

eMovie* movie_new()
{
    eMovie* newMovie = (eMovie*) calloc(1, sizeof(eMovie));
    return newMovie;
}
