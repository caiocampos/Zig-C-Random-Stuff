#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

using namespace std;

struct point {
    double x;
    double y;
    point() {
        x = y = 0;
    }
    point(double px,double py) {
        x = px;
        y = py;
    }
};

GLfloat xf, yf, win;
GLint view_w, view_h;
vector<double> vetor[2];
vector<point> points;


double fatorial(int a)
{
   int i;
   double produto;

   produto = 1;
   for (i = a; i >0 ; i--)
      produto *= (double) i;
   return produto;
}

double combinacao(int a, int b)
{
   return fatorial(b)/(fatorial(a)*fatorial(b-a));
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     int i;
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glClear(GL_COLOR_BUFFER_BIT);
     // Desenha um retângulo preenchido com a cor corrente

     if (points.size() == 1)
     {
         glBegin(GL_POINTS);
            glVertex2d(points[0].x, points[0].y);
         glEnd();
     } else if (points.size() > 1) {
                            glBegin(GL_LINE_STRIP);
                                 for (double t = 0; t <= 1; t += 0.01)
                                 {
                                      double x = 0;
                                      double y = 0;
                                      for (i = 0; i < points.size(); i++)
                                      {
                                            double res = combinacao(i,points.size()-1)*pow(t,i)*pow(1-t,points.size()-i-1);
                                            x += res*points[i].x;
                                            y += res*points[i].y;
                                      }
                                      glVertex2d(x,y);
                                 }
                                 glVertex2d((points.end()-1)->x,(points.end()-1)->y);
                            glEnd();
     }
     glFlush();
}


// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    xf=50.0f;
    yf=50.0f;
    win=250.0f;
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'R':
            case 'r':// muda a cor corrente para vermelho
                     glColor3f(1.0f, 0.0f, 0.0f);
                     break;
            case 'G':
            case 'g':// muda a cor corrente para verde
                     glColor3f(0.0f, 1.0f, 0.0f);
                     break;
            case 'B':
            case 'b':// muda a cor corrente para azul
                     glColor3f(0.0f, 0.0f, 1.0f);
                     break;
    }
    glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
         if (state == GLUT_DOWN) {
                  point p;
                  p.x = ( (2 * win * x) / view_w) - win;
                  p.y = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
                  points.push_back(p);
                  if(points.size() > 30)
                          points.erase(points.begin());
         }
    }
    glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do teclado
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) {
           win -= 20;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           gluOrtho2D (-win, win, -win, win);
    }
    if(key == GLUT_KEY_DOWN) {
           win += 20;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           gluOrtho2D (-win, win, -win, win);
    }
    glutPostRedisplay();
}

// Programa Principal
int main(void)
{

     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(350,300);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Exemplo de Interacao");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutKeyboardFunc(GerenciaTeclado);
     glutMouseFunc(GerenciaMouse);
     glutSpecialFunc(TeclasEspeciais);
     Inicializa();
     glutMainLoop();
}
