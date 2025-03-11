#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "basicopengl.h"

#define PI 3.1415926536

//implemetação das funções
void renderizaOpenGL(void){
    //glFlush();
    glFinish();
}

void limpaJanela(void){
    glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
}

void selecionaEspessuraLinha(int espessura){
    if (espessura > 0 && espessura < 6)
        glLineWidth(espessura);
    else
        glLineWidth(1);
}

void selecionaCorFundo(int cor){
    switch(cor){
        case 0: glClearColor(0,0,0,1);break;
        case 1: glClearColor(1,1,1,1);break;
        case 2: glClearColor(0,0,0.5,1);break;
        case 3: glClearColor(0,0,1,1);break;
        case 4: glClearColor(0,0.5,0,1);break;
        case 5: glClearColor(0,0.5,0.5,1);break;
        case 6: glClearColor(0,0.5,1,1);break;
        case 7: glClearColor(0,1,0,1);break;
        case 8: glClearColor(0,1,0.5,1);break;
        case 9: glClearColor(0,1,1,1);break;
        case 10: glClearColor(0.5,0,0,1);break;
        case 11: glClearColor(0.5,0,0.5,1);break;
        case 12: glClearColor(0.5,0,1,1);break;
        case 13: glClearColor(0.5,0.5,0,1);break;
        case 14: glClearColor(0.5,0.5,0.5,1);break;
        case 15: glClearColor(0.5,0.5,1,1);break;
        case 16: glClearColor(0.5,1,0,1);break;
        case 17: glClearColor(0.5,1,0.5,1);break;
        case 18: glClearColor(0.5,1,1,1);break;
        case 19: glClearColor(1,0,0,1);break;
        case 20: glClearColor(1,0,0.5,1);break;
        case 21: glClearColor(1,0,1,1);break;
        case 22: glClearColor(1,0.5,0,1);break;
        case 23: glClearColor(1,0.5,0.5,1);break;
        case 24: glClearColor(1,0.5,1,1);break;
        case 25: glClearColor(1,1,0,1);break;
        case 26: glClearColor(1,1,0.5,1);break;
        default: glClearColor(0,0,0,1);break;
    }
}

void selecionaCor(int cor){
    switch(cor){
        case 0: glColor3f(0,0,0);break;
        case 1: glColor3f(1,1,1);break;
        case 2: glColor3f(0,0,0.25);break;
        case 3: glColor3f(0,0,0.5);break;
        case 4: glColor3f(0,0,0.75);break;
        case 5: glColor3f(0,0,1);break;
        case 6: glColor3f(0,0.25,0);break;
        case 7: glColor3f(0,0.25,0.25);break;
        case 8: glColor3f(0,0.25,0.5);break;
        case 9: glColor3f(0,0.25,0.75);break;
        case 10: glColor3f(0,0.25,1);break;
        case 11: glColor3f(0,0.5,0);break;
        case 12: glColor3f(0,0.5,0.25);break;
        case 13: glColor3f(0,0.5,0.5);break;
        case 14: glColor3f(0,0.5,0.75);break;
        case 15: glColor3f(0,0.5,1);break;
        case 16: glColor3f(0,0.75,0);break;
        case 17: glColor3f(0,0.75,0.25);break;
        case 18: glColor3f(0,0.75,0.5);break;
        case 19: glColor3f(0,0.75,0.75);break;
        case 20: glColor3f(0,0.75,1);break;
        case 21: glColor3f(0,1,0);break;
        case 22: glColor3f(0,1,0.25);break;
        case 23: glColor3f(0,1,0.5);break;
        case 24: glColor3f(0,1,0.75);break;
        case 25: glColor3f(0,1,1);break;
        case 26: glColor3f(0.25,0,0);break;
        case 27: glColor3f(0.25,0,0.25);break;
        case 28: glColor3f(0.25,0,0.5);break;
        case 29: glColor3f(0.25,0,0.75);break;
        case 30: glColor3f(0.25,0,1);break;
        case 31: glColor3f(0.25,0.25,0);break;
        case 32: glColor3f(0.25,0.25,0.25);break;
        case 33: glColor3f(0.25,0.25,0.5);break;
        case 34: glColor3f(0.25,0.25,0.75);break;
        case 35: glColor3f(0.25,0.25,1);break;
        case 36: glColor3f(0.25,0.5,0);break;
        case 37: glColor3f(0.25,0.5,0.25);break;
        case 38: glColor3f(0.25,0.5,0.5);break;
        case 39: glColor3f(0.25,0.5,0.75);break;
        case 40: glColor3f(0.25,0.5,1);break;
        case 41: glColor3f(0.25,0.75,0);break;
        case 42: glColor3f(0.25,0.75,0.25);break;
        case 43: glColor3f(0.25,0.75,0.5);break;
        case 44: glColor3f(0.25,0.75,0.75);break;
        case 45: glColor3f(0.25,0.75,1);break;
        case 46: glColor3f(0.25,1,0);break;
        case 47: glColor3f(0.25,1,0.25);break;
        case 48: glColor3f(0.25,1,0.5);break;
        case 49: glColor3f(0.25,1,0.75);break;
        case 50: glColor3f(0.25,1,1);break;
        case 51: glColor3f(0.5,0,0);break;
        case 52: glColor3f(0.5,0,0.25);break;
        case 53: glColor3f(0.5,0,0.5);break;
        case 54: glColor3f(0.5,0,0.75);break;
        case 55: glColor3f(0.5,0,1);break;
        case 56: glColor3f(0.5,0.25,0);break;
        case 57: glColor3f(0.5,0.25,0.25);break;
        case 58: glColor3f(0.5,0.25,0.5);break;
        case 59: glColor3f(0.5,0.25,0.75);break;
        case 60: glColor3f(0.5,0.25,1);break;
        case 61: glColor3f(0.5,0.5,0);break;
        case 62: glColor3f(0.5,0.5,0.25);break;
        case 63: glColor3f(0.5,0.5,0.5);break;
        case 64: glColor3f(0.5,0.5,0.75);break;
        case 65: glColor3f(0.5,0.5,1);break;
        case 66: glColor3f(0.5,0.75,0);break;
        case 67: glColor3f(0.5,0.75,0.25);break;
        case 68: glColor3f(0.5,0.75,0.5);break;
        case 69: glColor3f(0.5,0.75,0.75);break;
        case 70: glColor3f(0.5,0.75,1);break;
        case 71: glColor3f(0.5,1,0);break;
        case 72: glColor3f(0.5,1,0.25);break;
        case 73: glColor3f(0.5,1,0.5);break;
        case 74: glColor3f(0.5,1,0.75);break;
        case 75: glColor3f(0.5,1,1);break;
        case 76: glColor3f(0.75,0,0);break;
        case 77: glColor3f(0.75,0,0.25);break;
        case 78: glColor3f(0.75,0,0.5);break;
        case 79: glColor3f(0.75,0,0.75);break;
        case 80: glColor3f(0.75,0,1);break;
        case 81: glColor3f(0.75,0.25,0);break;
        case 82: glColor3f(0.75,0.25,0.25);break;
        case 83: glColor3f(0.75,0.25,0.5);break;
        case 84: glColor3f(0.75,0.25,0.75);break;
        case 85: glColor3f(0.75,0.25,1);break;
        case 86: glColor3f(0.75,0.5,0);break;
        case 87: glColor3f(0.75,0.5,0.25);break;
        case 88: glColor3f(0.75,0.5,0.5);break;
        case 89: glColor3f(0.75,0.5,0.75);break;
        case 90: glColor3f(0.75,0.5,1);break;
        case 91: glColor3f(0.75,0.75,0);break;
        case 92: glColor3f(0.75,0.75,0.25);break;
        case 93: glColor3f(0.75,0.75,0.5);break;
        case 94: glColor3f(0.75,0.75,0.75);break;
        case 95: glColor3f(0.75,0.75,1);break;
        case 96: glColor3f(0.75,1,0);break;
        case 97: glColor3f(0.75,1,0.25);break;
        case 98: glColor3f(0.75,1,0.5);break;
        case 99: glColor3f(0.75,1,0.75);break;
        case 100: glColor3f(0.75,1,1);break;
        case 101: glColor3f(1,0,0);break;
        case 102: glColor3f(1,0,0.25);break;
        case 103: glColor3f(1,0,0.5);break;
        case 104: glColor3f(1,0,0.75);break;
        case 105: glColor3f(1,0,1);break;
        case 106: glColor3f(1,0.25,0);break;
        case 107: glColor3f(1,0.25,0.25);break;
        case 108: glColor3f(1,0.25,0.5);break;
        case 109: glColor3f(1,0.25,0.75);break;
        case 110: glColor3f(1,0.25,1);break;
        case 111: glColor3f(1,0.5,0);break;
        case 112: glColor3f(1,0.5,0.25);break;
        case 113: glColor3f(1,0.5,0.5);break;
        case 114: glColor3f(1,0.5,0.75);break;
        case 115: glColor3f(1,0.5,1);break;
        case 116: glColor3f(1,0.75,0);break;
        case 117: glColor3f(1,0.75,0.25);break;
        case 118: glColor3f(1,0.75,0.5);break;
        case 119: glColor3f(1,0.75,0.75);break;
        case 120: glColor3f(1,0.75,1);break;
        case 121: glColor3f(1,1,0);break;
        case 122: glColor3f(1,1,0.25);break;
        case 123: glColor3f(1,1,0.5);break;
        case 124: glColor3f(1,1,0.75);break;
        default: glColor3f(1,1,1);
    }
}

void escreveTexto(int x, int y, char *texto, int cor){
    selecionaCor(cor);
    glRasterPos2i(x,y);
    int i;
    for (i=0; texto[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,texto[i]);
}

void desenhaPonto(int x, int y, int cor){
    selecionaCor(cor);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void desenhaArco(int x, int y, int raio_maior, int raio_menor, int ang_ini, int ang_fim, int cor, int espessura){
    selecionaCor(cor);
    selecionaEspessuraLinha(espessura);
    float x1,y1;
    int i, n;
    if (ang_fim > ang_ini)
        n = abs(ang_fim - ang_ini)/10;
    else
        n = abs(360 - ang_ini + ang_fim)/10.0;

    glBegin(GL_LINE_STRIP);
    for(i = 0; i <= n; i++){
        x1 = x + cos(ang_ini*PI/180)*raio_maior;
        y1 = y + sin(ang_ini*PI/180)*raio_menor;
        glVertex2f(x1,y1);
        ang_ini += 10.0;
    }
    glEnd();
}

void desenhaSetor(int x, int y, int raio_maior, int raio_menor, int ang_ini, int ang_fim, int cor){
    selecionaCor(cor);
    selecionaEspessuraLinha(1);
    float x1,y1;
    int i, n;
    if (ang_fim > ang_ini)
        n = abs(ang_fim - ang_ini)/10.0;
    else
        n = abs(360 - ang_ini + ang_fim)/10.0;

    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0; i <= n; i++){
        x1 = x + cos(ang_ini*PI/180)*raio_maior;
        y1 = y + sin(ang_ini*PI/180)*raio_menor;
        glVertex2f(x1,y1);
        ang_ini += 10.0;
    }

    glEnd();
}

void desenhaElipse(int x, int y, int raio_maior, int raio_menor, int cor){
    selecionaCor(cor);
    selecionaEspessuraLinha(1);
    glBegin(GL_POLYGON);
    float x1,y1,ang;
    for(ang = 0.0; ang < 360; ang+=10.0){
        x1 = x + cos(ang*PI/180)*raio_maior;
        y1 = y + sin(ang*PI/180)*raio_menor;
        glVertex2f(x1,y1);
    }
    glEnd();
}

void desenhaCircunferencia(int x, int y, int raio_maior, int raio_menor, int cor, int espessura){
    selecionaCor(cor);
    selecionaEspessuraLinha(espessura);
    glBegin(GL_LINE_LOOP);
    float x1,y1,ang;
    for(ang = 0.0; ang < 360; ang+=10.0){
        x1 = x + cos(ang*PI/180)*raio_maior;
        y1 = y + sin(ang*PI/180)*raio_menor;
        glVertex2f(x1,y1);
    }
    glEnd();
}

void desenhaTriangulo(int x1, int y1, int x2, int y2, int x3, int y3, int cor){
  selecionaCor(cor);
  selecionaEspessuraLinha(1);
  glBegin(GL_TRIANGLES);
  glVertex2i(x1,y1);
  glVertex2i(x2,y2);
  glVertex2i(x3,y3);
  glEnd();
}

void desenhaLinha(int x1, int y1, int x2, int y2, int cor, int espessura){
  selecionaCor(cor);
  selecionaEspessuraLinha(espessura);
  glBegin(GL_LINES);
  glVertex2i(x1,y1);
  glVertex2i(x2,y2);
  glEnd();
}

void desenhaRetangulo(int x1, int y1, int x2, int y2, int cor){
   selecionaCor(cor);
   selecionaEspessuraLinha(1);
   glBegin(GL_QUADS);
   glVertex2i(x1,y1);
   glVertex2i(x1,y2);
   glVertex2i(x2,y2);
   glVertex2i(x2,y1);
   glEnd();
}

void iniciaOpenGL(int largura, int altura, int corFundo, void (*funcaoDesenho)(void)){
  //glutInit(&argc, argv);                              // inicializa o glut
  int x = 1;
  char *aa = "program";
  char **argv1 = &aa;
  glutInit(&x, argv1);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_ALPHA);           // especifica o uso de cores e buffers
  glutInitWindowSize(largura, altura);                          // especifica as dimensoes da janela
  glutInitWindowPosition (100, 100);                      // especifica aonde a janela aparece na tela
  glutCreateWindow ("OpenGL");              // cria a janela
  //init();
  selecionaCorFundo(corFundo);
  glOrtho(0, largura, 0, altura, -1 ,1);     // modo de projecao ortogonal
  //ativa transparencia
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glShadeModel (GL_FLAT);

  glutDisplayFunc(funcaoDesenho);                               // funcao que sera redesenhada pelo GLUT
  //glutKeyboardFunc(keyboard);                             // funcoes de teclado
  glutMainLoop();                                         // mostra todas as janelas criadas
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}
