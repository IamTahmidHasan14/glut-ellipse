#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
float rx, ry;
void ellipse()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(-1.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(0.0,-1.0);
        glVertex2f(0.0,1.0);
    glEnd();
    glPointSize(2.5);
    glBegin(GL_POINTS);
    float x=0, y=ry, p;
    p=ry*ry-rx*rx*ry+rx*rx/4;
    while(x*ry*ry < y*rx*rx){
        glColor3f(1,0,0);
        glVertex2f(x/100,y/100);
        glVertex2f(x/100,-y/100);
        glVertex2f(-x/100,y/100);
        glVertex2f(-x/100,-y/100);

        if(p<0){
            p=p+2*ry*ry*(x+1)+ry*ry;
            x++;
        }
        else{
            p=p+2*ry*ry*(x+1)-2*rx*rx*(y-1)+ry*ry;
            x++; y--;
        }
    }

    p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
    while(y>=0){
        glColor3f(1,1,0);
        glVertex2f(x/100,y/100);
        glVertex2f(x/100,-y/100);
        glVertex2f(-x/100,y/100);
        glVertex2f(-x/100,-y/100);
        if(p<0){
            p=p+2*ry*ry*(x+1)-2*rx*rx*(y-1)+3*rx*rx;
            x++; y--;
        }
        else{
            p=p-2*rx*rx*(y-1)+rx*rx;
            y--;
        }
    };
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    cout<<"Enter radius (Rx, Ry): ";
    cin>>rx>>ry;
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("LAB 3");
    glutDisplayFunc(ellipse);
    glutMainLoop();
    return 0;
}
