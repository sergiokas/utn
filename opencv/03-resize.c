#include <highgui.h>
#include <cv.h>

int main(int argc, char** argv)
{
    // Puntero a la imagen cargada
    IplImage* img;
    IplImage* out;

    // Crea una ventana
    cvNamedWindow("MyImage", CV_WINDOW_AUTOSIZE);

    // Carga la imagen
    img = cvLoadImage("tucan.jpg",1);

    // Crea una imagen vacia del mismo tamanio que la entrada
    out = cvCreateImage(cvSize(img->width/2,img->height/2), img->depth, img->nChannels);

    // Hace la imagen mas pequena
    cvPyrDown(img, out, CV_GAUSSIAN_5x5);

    // Aplica filtro
    // void cvCanny(const CvArr* image, CvArr* edges, double threshold1, double threshold2, int aperture_size=3 )
    // cvCanny(out, out, 10.0, 100.0, 3);

    // Muestra la imagen en la ventana
    cvShowImage("MyImage", out);

    // Espera
    cvWaitKey(0);
    
    // Destruye la ventana "Original Image".
    cvDestroyWindow("MyImage");

    return 0;
}
