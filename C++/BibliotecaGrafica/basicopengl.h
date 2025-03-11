//#include <GL/gl.h>
//#include <GL/glut.h>
//#include <math.h>
//
//#define PI 3.1415926536

// prototipos das funcoes
void keyboard(unsigned char key, int x, int y);
void selecionaCorFundo(int cor);
void selecionaCor(int cor);
void escreveTexto(int x, int y, char *texto, int cor);
void desenhaPonto(int x, int y, int cor);
void desenhaArco(int x, int y, int raio_maior, int raio_menor, int ang_ini, int ang_fim, int cor, int espessura);
void desenhaSetor(int x, int y, int raio_maior, int raio_menor, int ang_ini, int ang_fim, int cor);
void desenhaElipse(int x, int y, int raio_maior, int raio_menor, int cor);
void desenhaCircunferencia(int x, int y, int raio_maior, int raio_menor, int cor, int espessura);
void desenhaTriangulo(int x1, int y1, int x2, int y2, int x3, int y3, int cor);
void desenhaLinha(int x1, int y1, int x2, int y2, int cor, int espessura);
void desenhaRetangulo(int x1, int y1, int x2, int y2, int cor);
void selecionaEspessuraLinha(int espessura);
void limpaJanela(void);
void renderizaOpenGL(void);
void iniciaOpenGL(int largura, int altura, int corFundo, void (*funcaoDesenho)(void));
