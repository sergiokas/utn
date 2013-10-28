#include <highgui.h>
#include <cv.h>

int main(int argc, char** argv)
{
    // Puntero a la imagen cargada
    IplImage* img;
    IplImage* out;

    // Point
    CvPoint pt1 = cvPoint(10,30);

    // Color
    CvScalar blue = CV_RGB(0xFF,0xFF,0);

    // Text variables
    const char* text = "El Tucan";
    double hscale = 1.0;
    double vscale = 0.8;
    double shear = 0.2;
    int thickness = 1;
    int linetype = CV_AA;

    CvFont font1;
    // cvInitFont (&dfont, CV_FONT_HERSHEY_SIMPLEX , hscale, vscale, italicscale, thickness, CV_AA);
    cvInitFont(&font1,CV_FONT_HERSHEY_DUPLEX,hscale,vscale,shear,thickness,linetype);

    // Carga la imagen
    img = cvLoadImage("tucan.jpg",1);

    cvPutText(img,text,pt1,&font1,blue);

    // Crea una ventana
    cvNamedWindow("MyImage", CV_WINDOW_AUTOSIZE);

    // Muestra la imagen en la ventana
    cvShowImage("MyImage", img);

    // Espera
    cvWaitKey(0);
    
    // Destruye la ventana "Original Image".
    cvDestroyWindow("MyImage");

    return 0;
}
