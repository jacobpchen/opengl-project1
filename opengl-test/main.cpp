#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void reshape(int, int);

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);    //set display window color to white
    //glMatrixMode(GL_PROJECTION);        // set projection parametes
    //gluOrtho2D(0.0,600,0.0,600);
}

void drawSky(){
    glColor3f(0.118, 0.565, 1.000);
    int sky_1[] = {-600, 600};
    int sky_2[] = {600, -400};
    glRectiv(sky_1, sky_2);
}

void drawRoad(){
   // draw black road
    glColor3f(0, 0, 0);
    int road_1[] = {-600, -450};
    int road_2[] = {600, -550};
    glRectiv(road_1, road_2);
    // yellow lines
    glColor3f(1.000, 1.000, 0.000);
    
}

void drawHouseOutline (int x1, int y1, int x2, int y2, float r, float g, float b){
    // outline of house
    glColor3f(r, g, b);
    int house_outline_1 [] = {x1, y1};
    int house_outline_2 [] = {x2, y2};
    glRectiv(house_outline_1, house_outline_2);
}

void drawRoof(int x1,int y1, int x2,int y2,int x3,int y3, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd( );
}

void drawDoor(int x1,int y1, int x2,int y2, float r, float g, float b){
    glColor3f(r, g, b);
    int door_outline_1 [] = {x1, y1};
    int door_outline_2 [] = {x2, y2};
    glRectiv(door_outline_1, door_outline_2);
}

void drawGrass(){
    glColor3f(0.0, 0.502, 0.0); // green
    int grass_outline_1 [] = {-600, -400};
    int grass_outline_2 [] = {600, -600};
    glRectiv(grass_outline_1, grass_outline_2);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);    // clear display window
    glLoadIdentity(); // reset coordinate system
    //glColor3f(1.0, 0.0, 0.0); // set line segment color to blue
    //glLineWidth(4.0);    // set line thickness
    
    /*
    int point1 [ ] = {300, 200};
    int point2 [ ] = {100, 100};
    int point3 [ ] = {200, 400};
    int point4 [ ] = {300, 100};
    int point5 [ ] = {100, 250};
    
    glBegin (GL_LINE_LOOP);
    glVertex2iv (point1);
    glVertex2iv (point2);
    glVertex2iv (point3);
    glVertex2iv (point4);
    glVertex2iv (point5);
    glEnd( );
    */
    
    
    /*
     glBegin(GL_TRIANGLES);
         glVertex2i(300, 0);
         glVertex2i(230, -80);
         glVertex2i(360, -80);
    
    glEnd();
    */
    
    /* Rectangle
    int vertex1 [ ] = {200, 100};
    int vertex2 [ ] = {50, 250};
    glRectiv (vertex1, vertex2);
    */
    
    drawSky();
    drawGrass();
    drawRoad();
    // Draw first house
    drawRoof(-550, -200, -450, -100, -350, -200, 0.878, 1.000, 1.000);
    drawHouseOutline(-550,-200,-350,-400, 0.282, 0.820, 0.800);
    drawDoor(-400, -330, -450, -400, 0.878, 1.000, 1.000);
    
    // Draw second house
    drawRoof(-300, -200, -200, -100, -100, -200, 0.741, 0.718, 0.420);
    drawHouseOutline(-300,-200,-100,-400, 1.000, 0.894, 0.710);
    drawDoor(-175, -330, -125, -400, 0.741, 0.718, 0.420);
    
    
    
    
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);    // initlaize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // set display mode
    glutInitWindowPosition(50, 100);    //set top left display window position
    glutInitWindowSize(1200, 1200);    //set display window width and height
    glutCreateWindow("An Example OpenGL Window");    // Create display window
    init();
    glutDisplayFunc(display); //send graphics to display window
    glutReshapeFunc(reshape);
    glutMainLoop();    // display everything and wait
    return 0;
}

void reshape(int width, int height){
    // view port
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);    // sets the screen to whole width
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // set a new projection window
    gluOrtho2D(-600, 600, -600, 600);
    
    // switch back to default model view
    glMatrixMode(GL_MODELVIEW);
    
}