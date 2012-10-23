#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
    // Crea una ventana llamada Original Image con un tamaño predeterminado.
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);

    // Crea la conexion con la Webcam.
    CvCapture* capture = cvCreateCameraCapture(0);

    // Variable donde se almazenara el frame sacado de la webcam.
    IplImage* originalImg;
    IplImage* outPut;

    // Hago que el ancho del capture sea de 320px
    if(cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH,320)) { 
        // Ojo! esta condicion puede ser problematica si tu webcam no soporta el ancho de 320 pixels

        while(1) {

            // Pongo el frame capturado dentro de la imagen originalImg.
            originalImg = cvQueryFrame(capture);

            if(!originalImg) break;

            outPut = cvCreateImage(cvGetSize(originalImg), IPL_DEPTH_8U, 3);
            
            // Hago que se vea el frame dentro de la ventana "Original Image".
            cvSmooth( originalImg, outPut, CV_BLUR, 7, 7, 0, 0);
            cvShowImage("Original Image", outPut);

            // Espero a que me pulsen el ESC para salir del bucle infinito.
            char c = cvWaitKey(10);
            if( c == 27 ) break;
        }

    }
    
    // Libera la memoria utilizada por la variable capture.
    cvReleaseCapture(&capture);

    // Destruye la ventana "Original Image".
    cvDestroyWindow("Original Image");

    return 0;
}
