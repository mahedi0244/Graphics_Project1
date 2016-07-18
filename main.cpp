#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif
#  include <math.h>



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
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_LINES);
    
    convex_concave(0.0, 6.0, true);
    convex_concave(0.0, -6.0, true);
    convex_concave(12.0, -6.0, true);
    
    convex_concave(6.0, -12.0, false);
    convex_concave(-12.0, 12.0, false);
    convex_concave(-6.0, -12.0, false);
    
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
    gluOrtho2D(-20.0, 20.0,-20.0,20.0);
    glutDisplayFunc(display);
    glutMainLoop();
}