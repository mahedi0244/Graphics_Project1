#  include <math.h>
#  include <stdlib.h>
#  include <ctime>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif




void convex_concave(float x_translation, float y_translation, bool convex){
    float color;
    if (convex == true)
        color = 0.0;
    else
        color = 1.0;
    
    float change = .0005;
    
    float r = 3.0;
    double theta1,theta2,p= 3.141593/180;
    glColor3f(color, color, color);
   
    
    float i = 270;
    float j = 270;
    
    while(i>90 && j<450){
        
        glColor3f(color, color, color);
        theta1 = i*p;
        theta2 = j*p;
        glVertex2f(r * cos(theta1) + x_translation, r * sin(theta1) + y_translation);
        glVertex2f(r * cos(theta2) + x_translation, r * sin(theta2) + y_translation);
        
        i = i-.1;
        j = j+.1;
        
        if (convex == true)
            color = color + change;
        else
            color = color - change;
        
    }
}

void display (void){
    float randx;
    float randy;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    
    srand(time(NULL));
    
    for (int i = 0; i<5; i++){
        //generating random numbers -21,-14,-7,0,7,14,21
        randx = (rand() % 7 + (-3))*7;
        randy = (rand() % 7 + (-3))*7;
        convex_concave(randx, randy, true);
        
        randx = (rand() % 7 + (-3))*7;
        randy = (rand() % 7 + (-3))*7;
        convex_concave(randx, randy, false);
    }
    
    glEnd();
    glFlush();
    
}


int main(int argc, char ** argv){
    
    glutInit(& argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Project1");
    glClearColor(0.5,0.5,0.5,0.0);
    gluOrtho2D(-25.0, 25.0,-25.0,25.0);
    glutDisplayFunc(display);
    glutMainLoop();
    
}