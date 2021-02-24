#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);    //set display window color to white
    //glMatrixMode(GL_PROJECTION);        // set projection parametes
    //gluOrtho2D(0.0,600,0.0,600);
}

void reshape(int, int);
void drawSky();
void drawRoad();
void drawWheatField();
void drawBridge();
void drawRiver();
void drawWindow(int x1, int y1, int x2, int y2,float r, float g, float b);              // take the house outline and draw windows relative
void drawTree();
void drawHouseOutline (int x1, int y1, int x2, int y2, float r, float g, float b);
void drawRoof(int x1,int y1, int x2,int y2,int x3,int y3, float r, float g, float b);
void drawDoor(int x1,int y1, int x2,int y2, float r, float g, float b);

void drawGrass();

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);    // clear display window
    glLoadIdentity(); // reset coordinate system
    
    drawSky();
    drawRiver();
    drawGrass();
    //drawWheatField();
    drawBridge();
    drawRoad();
    drawTree();
    
    // Draw first house
    drawRoof(-550, -200, -450, -100, -350, -200, 0.878, 1.000, 1.000);
    drawHouseOutline(-550,-200,-350,-400, 0.282, 0.820, 0.800);
    drawDoor(-400, -330, -450, -400, 0.878, 1.000, 1.000);
    drawWindow(-550,-200,-350,-400, 0.878, 1.000, 1.000);
    
    // Draw second house
    drawRoof(-300, -200, -200, -100, -100, -200, 0.741, 0.718, 0.420);
    drawHouseOutline(-300,-200,-100,-400, 1.000, 0.894, 0.710);
    drawWindow(-300,-200,-100,-400, 0.741, 0.718, 0.420);
    drawDoor(-200, -330, -150, -400, 0.741, 0.718, 0.420);
    
    // Draw third house
    drawRoof(-300, 300, -200, 450, -100, 300, 0.741, 0.718, 0.420);
    drawHouseOutline(-300, 300, -100, 100, 1.000, 0.894, 0.710);
    drawWindow(-300, 300, -100, 100, 0.741, 0.718, 0.420);
    drawDoor(-200, -330, -150, -400, 0.741, 0.718, 0.420);
    
    // Draw fourth house
    
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

void drawSky(){
    glColor3f(0.529, 0.808, 0.922);
    int sky_1[] = {-600, 600};
    int sky_2[] = {600, 300};
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
    glLineStipple(50, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2f(-599, -500);
        glVertex2f(599, -500);
    glDisable(GL_LINE_STIPPLE);
    glFlush();
    glEnd();
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
    // bottom grass
    glColor3f(0.0, 0.502, 0.0); // green
    int grass_outline_1 [] = {-600, -300};
    int grass_outline_2 [] = {600, -600};
    glRectiv(grass_outline_1, grass_outline_2);
    
    // top grass
    int grass_outline_3 [] = {-600, 300};
    int grass_outline_4 [] = {600, -100};
    glRectiv(grass_outline_3, grass_outline_4);
}

void drawWheatField(){
    glColor3f(0.933, 0.910, 0.667);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-75, -330);
    glVertex2f(-75, -400);
    glVertex2f(-75, -330);
    glVertex2f(-70, -310);
    glEnd();
}

void drawBridge(){
    glColor3f(0.824, 0.706, 0.549);
    int bridge_top[] = {200, -80};
    int bridge_bottom[] = {300, -320};
    glRectiv(bridge_top, bridge_bottom);
    
    
    // draw lines on the bridge
    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_LINES);
    for (int i = -300; i < -80; i+= 20){
        glVertex2f(200, i);
        glVertex2f(300, i);
    }
    glEnd();
    
}

void drawRiver(){
    glColor3f(0.255, 0.412, 0.882);
    int river_top[] = {-600, -300};
    int river_bot[] = {600, -100};
    glRectiv(river_top, river_bot);
}

void drawTree(){
    // draw trunk
    glColor3f(0.545, 0.271, 0.075);
    int trunk_top_left[] = {400, -325};
    int trunk_bot_right[] = {450, -400};
    glRectiv(trunk_top_left, trunk_bot_right);
    
    // draw tree
    glColor3f(0.000, 0.0, 0.000);
    glBegin(GL_LINE);
    glVertex2f(425, -200);
    glVertex2f(400, -210);
    glVertex2f(410, -210);
    glVertex2f(390, -220);
    
    glEnd();
}

void drawWindow(int x1, int y1, int x2, int y2,float r, float g, float b){
    glColor3f(r, g, b);
    int left_window_1 [] = {x1+25, y1-25};
    int left_window_2 [] = {x1+75, y1-75};
    int right_window_1 [] = {left_window_1[0] + 100, left_window_1[1]};
    int right_window_2 [] = {right_window_1[0] + 50, left_window_2[1]};
    glRectiv(left_window_1, left_window_2);
    glRectiv(right_window_1, right_window_2);
}
