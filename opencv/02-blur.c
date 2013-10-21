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
    out = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);

    // Aplica filtro
    // void cvSmooth(const CvArr* src, CvArr* dst, int smoothtype=CV_GAUSSIAN, int size1=3, int size2=0, double sigma1=0, double sigma2=0 )
    cvSmooth( img, out, CV_GAUSSIAN, 11, 11, 6.0, 6.0);

    // Muestra la imagen en la ventana
    cvShowImage("MyImage", out);

    do {
        // Espera
    } while (cvWaitKey(0) != 27);
    
    // Destruye la ventana "Original Image".
    cvDestroyWindow("MyImage");

    return 0;
}
