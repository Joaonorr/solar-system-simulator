#include <iostream>

using namespace std;

#include <gui.h>
#include "obj/Planet.h"
#include <vector>
#include "model3ds.h"

float px = 0.0;
float py = 0.0;
float raio = 0.5;
float theta = 0.0;

Model3DS* modelo = new Model3DS("../3ds/skeleton.3ds");

void light() {
    //definindo uma luz
    glEnable(GL_LIGHT0);

    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void skeleton() {
    //desenhando esqueleto em pe sobre o chao e com um tamanho adequado
    glPushMatrix();
        float s = 0.834;
        glScaled(s,s,s);
        glTranslated(0.0,0.768,0.0);
        s = 0.018;
        glScaled(s,s,s);
        modelo->draw();
    glPopMatrix();

}

void desenha() {
    GUI::displayInit();

        GUI::drawOrigin(0.4); // desenha a origem na referẽncia global
        GUI::drawFloor(); // desenha a malha de referência global

        light(); // define a iluminação do nosso sistema

        GUI::drawSphere(1.0, 0.0, 0.0, 0.1);

        /** Adicione aqui as transformações **/

        skeleton(); // desenha o modelo

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int mx, int my) {
    GUI::keyInit(tecla, mx, my);

    switch (tecla) {
        case 't': // habilita o movimento de translação com o mouse
            glutGUI::trans_obj = !glutGUI::trans_obj;
            break;

        case 'l': // habilita o movimento de translação da iluminação com o mouse
            glutGUI::trans_luz = !glutGUI::trans_luz;
            break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800, 600, desenha, teclado);
}

