#include "loadObj.h"

//Read .off file and save values to object struct (with pointer)
char* readOFFFile(char* fname, Objects *objectListing)
{
    char c[4];
    //Check if file exists in directory
    if ((openFile = fopen(fname, "r")) == NULL)
    {
        return ("File could not be opened\n");
    }
    else
    {
        //Check if file is .OFF format.
        if (fgets(c, 50, openFile) != NULL)
        {
            if (strcmp(c, "OFF") != 0)
            {
                // Get Vertex Lines and Face Lines
                fscanf(openFile, "%d", &(objectListing->vertexLines));
                fscanf(openFile, "%d", &(objectListing->faceLines));
                fscanf(openFile, "%d", &(objectListing->uVLines));

            }
            else
            {
                return ("File not in OFF format\n");
            }
        }
    }

    objectListing->coordinates = malloc(objectListing->vertexLines * sizeof(struct Vector3));
    objectListing->faces = malloc(objectListing->faceLines * sizeof(struct FaceVecor));

    for (int i = 0; i < objectListing->vertexLines; i++)
    {
        fscanf(openFile, "%lf", &(objectListing->coordinates)[i].x);
        fscanf(openFile, "%lf", &(objectListing->coordinates)[i].y);
        fscanf(openFile, "%lf", &(objectListing->coordinates)[i].z);
    }

    int vertexLine1, vertexLine2, vertexLine3;

    for (int i = 0; i < objectListing->faceLines; i++)
    {
        fscanf(openFile, "%d", &(objectListing->faces)[i].faceType);

        if ((objectListing->faces)[i].faceType == 3)
        {
            fscanf(openFile, "%d", &vertexLine1);
            (objectListing->faces)[i].coordinates1.x = (objectListing->coordinates)[vertexLine1].x;
            (objectListing->faces)[i].coordinates1.y = (objectListing->coordinates)[vertexLine1].y;
            (objectListing->faces)[i].coordinates1.z = (objectListing->coordinates)[vertexLine1].z;

            fscanf(openFile, "%d", &vertexLine2);
            (objectListing->faces)[i].coordinates2.x = (objectListing->coordinates)[vertexLine2].x;
            (objectListing->faces)[i].coordinates2.y = (objectListing->coordinates)[vertexLine2].y;
            (objectListing->faces)[i].coordinates2.z = (objectListing->coordinates)[vertexLine2].z;

            fscanf(openFile, "%d", &vertexLine3);
            (objectListing->faces)[i].coordinates3.x = (objectListing->coordinates)[vertexLine3].x;
            (objectListing->faces)[i].coordinates3.y = (objectListing->coordinates)[vertexLine3].y;
            (objectListing->faces)[i].coordinates3.z = (objectListing->coordinates)[vertexLine3].z;
        }

    }

    return (" .OFF File has been loaded successfully\n");
}

//Draw the model on the screen
void drawOFFFile(Objects *objectListing)
{
    //Generate the model
    for (int i = 0; i < objectListing->faceLines; i++)
    {
        switch ((objectListing->faces)[i].faceType)
        {
        case 3://Triangles
            glBegin(GL_TRIANGLES);
            glVertex3f((objectListing->faces)[i].coordinates1.x, (objectListing->faces)[i].coordinates1.y, (objectListing->faces)[i].coordinates1.z);
            glVertex3f((objectListing->faces)[i].coordinates2.x, (objectListing->faces)[i].coordinates2.y, (objectListing->faces)[i].coordinates2.z);
            glVertex3f((objectListing->faces)[i].coordinates3.x, (objectListing->faces)[i].coordinates3.y, (objectListing->faces)[i].coordinates3.z);
            glEnd();
            break;

        case 4://Quads
            break;
        }
    }
}

void readOFFModel(char* modelName, Objects *objectData)
{

    if (objectData->fileNotOpen)
    {
        char* status;

        printf("Loading .off file\n");
        status = readOFFFile(modelName, objectData);
        printf(status);

        objectData->fileNotOpen = false;
    }
}
