#include <cstdlib>
#include <iostream>

//#include <windows.h>
#include <stdio.h>

#include "CImg.h"
#include "resources/guicon.h"
#include "resources/imagehelper.h"

/// ---- include your own files here


/// ----

using namespace std;
using namespace cimg_library;
using namespace imaging;

unsigned char * rgb2gray(unsigned char *, int, int, int);

int main(int argc, char *argv[])
{
	// Open a console and bind I/O to it
	RedirectIOToConsole();

	cout << "Loading input image...\n";
    ImageHelper *helper = new ImageHelper();

    // input image
    unsigned char *image;
	int width;
	int height;
	int channel;

	helper->getImageInfo("assets/lena.bmp", width, height, channel);
	image = new unsigned char[width * height * channel];
	helper->loadImage("assets/lena.bmp", &image);

	helper->showImage(image, width, height, channel);
	cout << "Input image width:" << width << " height:" << height << endl;

    /// ---- Add your code here

    unsigned char* gray = rgb2gray(image, width, height, channel);

    helper->showImage(gray, width, height, 1);


    // set channel=1 or 3 to save image as grayscale or RGB, respectively
    // save your images as Bitmap
    //helper->saveImage("output1.bmp", ptr, width, height, channel);

    /// ----

    cout << "END\n";
    system("PAUSE");

    delete helper;
    delete[] image;

    return EXIT_SUCCESS;
}

//formula usada para conversao: ((0.3 * R) + (0.59 * G) + (0.11 * B)).
unsigned char * rgb2gray(unsigned char * img, int width, int height, int channel){
    //tamanhos e dimensoes
    int dim = width*height;
    int size = dim*channel;
    
    //variaveis auxiliares
    unsigned char r;
    unsigned char g;
    unsigned char b;

    //alocacao da matriz resultante
    unsigned char* gray = (unsigned char *) malloc(dim * sizeof(unsigned char));
    
    //calculos
    for (int row = 0; row < height; row++)
        for(int col = 0; col < height; row++){
            int parcela = row*height + col;
            r = (0*dim + parcela);
            g = (1*dim + parcela);
            b = (2*dim + parcela);

            gray[parcela] = (0.3*r) + (0.59*g) + (0.11*b);
        }
    
    return gray;
}
