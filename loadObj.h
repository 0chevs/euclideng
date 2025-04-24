#ifndef LOADOBJ_H
#define LOADOBJ_H

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "gobal_vars.h"
FILE* openFile;

/**< Reads off file data */
char* readOFFFile(char* fname, Objects *objectListing);

/**< renders a .off file object */
void drawOFFFile(Objects *objectListing);

/**< reads model data */
void readOFFModel(char* modelName, Objects *objectData);

#endif // LOADOBJ_H
