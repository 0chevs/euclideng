#include "loadImage.h"
#include "time.h"
#include "stdbool.h"

int width = 64;
int height = 64;
int window2;
unsigned char * data = NULL;

static GLfloat g_rotate = 0;

void load_image(const char * image_path)
{
    FILE * imageFile = fopen(image_path, "rb");
    unsigned char info[54];

    if (imageFile == NULL)
    {
        printf("Could not open file\n", image_path);
        exit(1);
    }

    fread(info, sizeof(unsigned char), 54, imageFile);

    width = *(int *) &info[18];
    height = *(int *) &info[22];

    data = calloc(width * height * 3, sizeof(unsigned char));

    fread(data, sizeof(unsigned char), width * height * 3, imageFile);
    fclose(imageFile);
}

void renderBMP(float x, float y, void *font, char *string)
{
    char *c;
    glRasterPos2f(x,y);
    for(c=string; *c != '\0'; c++){
        glutBitmapCharacter(font, *c);
    }
}
void Controls(unsigned char key,int x,int y)
{
    switch(key)
    {
    case 27:
        delay(2000);
        exit(0);
        break;
    }
}

void ControlsUp(unsigned char key,int x,int y)
{
    switch(key)
    {
    case 27:;
        delay(2000);
        exit(0);
        break;
    }
}

void displayEnd(void)
{
    drawImage();
    drawText();
    glutPostRedisplay();
}

void drawImage()
{
    glPushMatrix();
    glColor3f(1,1,1);
    GLuint texture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_BGR, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    glMatrixMode(GL_MODELVIEW);
    glOrtho(0, width, 0, height, -1, 0);

    glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, texture);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2i(0, 0);
    glVertex2i(0, 0);
    glTexCoord2i(0, 1);
    glVertex2i(0, height);
    glTexCoord2i(1, 1);
    glVertex2i(width, height);
    glTexCoord2i(1, 0);
    glVertex2i(width, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    glFlush();
    glPopMatrix();
}

void drawText()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GLUT_SINGLE | GLUT_RGB);
    glLoadIdentity();
    glOrtho(-90.0, 100.0, -15.0, 100.0, 0.0, 1.0);
    glColor3f(1.f, 0.f, 0.f);
    char buf[100] = {0};
    sprintf(buf, "GROUP 13: NAZIER, CLINT");
    renderBMP(0, 0,GLUT_BITMAP_TIMES_ROMAN_24, buf);
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void quit_main()
{

    load_image("Data/Group.bmp");

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Picture");

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glClearColor(0, 0, 0, 0);
    glutKeyboardFunc(Controls);
    glutKeyboardUpFunc(ControlsUp);

    glutDisplayFunc(displayEnd);

    glutMainLoop();

    free(data);
    return 0;
}





