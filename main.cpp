#include <iostream>

using namespace std;

#include <gui.h>
#include "obj/Planet.h"
#include <vector>

float px = 0.0;
float py = 0.0;
float raio = 0.5;
float theta = 0.0;

/**float gauss(Planet planet) {
    float numerador = pow((x - px), 2);
    float denominador = 2*pow(2, 2);

    float numerador2 = pow((z - pz), 2);
    float denominador2 = 2*pow(2, 2);

    float numerador3 = pow((x - px2), 2);
    float denominador3 = 2*pow(2, 2);

    float numerador4 = pow((z - pz2), 2);
    float denominador4 = 2*pow(2, 2);


    return constante * pow(M_E, -((numerador/denominador) + (numerador2/denominador2)) * ((numerador3/denominador3) + (numerador4/denominador4)));
}*/

/*void drawMalha(std::vector<Planet> planets, float width, float height, float discrWidth, float discrHeight, float texWidth, float texHeight, bool inverted)
{
    int nWidth = width/discrWidth;
    int nHeight = height/discrHeight;
    discrWidth = width/nWidth; //correcao necessaria, pois, caso width/discrWidth nao seja inteiro, nWidth*discrWidth (feito pelo for) nao completara exatamente a width
    discrHeight = height/nHeight; //correcao necessaria, pois, caso height/discrHeight nao seja inteiro, nHeight*discrHeight (feito pelo for) nao completara exatamente a height
    float discrTexWidth = texWidth*(discrWidth/width);
    float discrTexHeight = texHeight*(discrHeight/height);
    for(float i=-0.5*(width/discrWidth);i<0.5*(width/discrWidth);i++) {
        for(float j=-0.5*(height/discrHeight);j<0.5*(height/discrHeight);j++) {
            glPushMatrix();
                if (inverted) glRotatef(180,1,0,0);
                glTranslatef(i*discrWidth,0.0,j*discrHeight);
                glBegin( GL_LINE_LOOP );
                    glNormal3f(0.,1.,0.);
                        glTexCoord2f(     i*discrTexWidth, (j+1)*discrTexHeight); glVertex3f(        0.0, gauss(-3, i*discrWidth, j*discrHeight+discrHeight),+discrHeight);
                        glTexCoord2f( (i+1)*discrTexWidth, (j+1)*discrTexHeight); glVertex3f(+discrWidth, gauss(-3, i*discrWidth+discrWidth , j*discrHeight+discrHeight ),+discrHeight);
                        glTexCoord2f( (i+1)*discrTexWidth,     j*discrTexHeight); glVertex3f(+discrWidth, gauss(-3, i*discrWidth+discrWidth , j*discrHeight), 0.0);
                        glTexCoord2f(     i*discrTexWidth,     j*discrTexHeight); glVertex3f(        0.0, gauss(-3, i*discrWidth, j*discrHeight),         0.0);
                glEnd();
            glPopMatrix();
        }
    }
}*/

void desenha() {

    Planet earth(70, 0, 70, 1, 1);

    Planet jupty(180, 0, 180, 20, 1);

    Planet moon(earth.initx - 1, earth.inity, earth.initz, 1);

    GUI::displayInit();

        // sol -> modificação no método setLight para definir o tamanho da iluminação
        GUI::setLight(1, 0, 0, 0, true, false, 40.0);

        // terra
        glPushMatrix();
            glRotated(px,0,1, 0);
            earth.draw();

            // lua
            glPushMatrix();
                glRotatef(px, 0, 1, 0); // rotação em torno do eixo y (eixo vertical)
                glTranslatef(3.0f, 0.0f, 0.0f); // translação para a posição da lua em relação à Terra
                moon.draw();
            glPopMatrix(); // fim lua

            glPopMatrix(); // fim terra


        // lua
        glPushMatrix();

        glPopMatrix();

        px += 1;

        // outro qualquer
        glPushMatrix();
            glRotated(py,0,1, 0);
            jupty.draw();
        glPopMatrix();
        py -= 0.7;


        glPushMatrix();
            glTranslatef(0, -20, 0);
            //GUI::drawFloor(100, 100, 1, 1);
        glPopMatrix();

    // posição inicial do sol






//    // desenhando a terra
//    Planet earth(2, 2, 0, 1, 1);
//    earth.draw();

//    std::vector<Planet> planets;

//    planets.push_back(sun);
//    planets.push_back(earth);

//    for (Planet planet : planets) {
//        planet.draw();
//    }

    //glTranslated(1, 1, 1); // translada o objeto atráves de um vetor

    // desenhando malha distorcida
    //drawMalha(5, 5, 0.2, 0.2, 1, 1, false);

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

