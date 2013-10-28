#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
    int i = 0;

    const char * tpl = "frames/frame_%d.png";
    char filename[50];

    // Crea una ventana llamada Original Image con un tamaño predeterminado.
    cvNamedWindow("Camarita", CV_WINDOW_AUTOSIZE);

    // Crea la conexion con la Webcam.
    CvCapture* capture = cvCreateCameraCapture(0);

    // Variable donde se almazenara el frame sacado de la webcam.
    IplImage* original;
    IplImage* output;

    // Hago que el ancho del capture sea de 320px
    if(cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320)) { 
        // Ojo! esta condicion puede ser problematica si tu webcam no soporta el ancho de 320 pixels

        while(1) {

            // Pongo el frame capturado dentro de la imagen original.
            original = cvQueryFrame(capture);

            if(!original) break;

            output = cvCreateImage(cvGetSize(original), IPL_DEPTH_8U, 3);

			// Convert to gray
			IplImage* gray = cvCreateImage(cvGetSize(original), IPL_DEPTH_8U, 1); 
			cvCvtColor(original, gray, CV_BGR2GRAY);
			
            // Hago que se vea el frame dentro de la ventana "Original Image".
            // cvSmooth(original, output, CV_BLUR, 7, 7, 0, 0);
			// cvSmooth(original, output, CV_GAUSSIAN, 27, 27, 15, 15);
			cvCanny(gray, gray, 30, 80, 3);
			
			// Show the image
			cvShowImage("Camarita", gray);

            // if(!(i%60)) {
            //     sprintf(filename, tpl, i);                
            //     cvSaveImage(filename, gray, 0);
            // }

            // Espero a que me pulsen el ESC para salir del bucle infinito.
            char c = cvWaitKey(10);
            if( c == 27 ) break;

            i++;
        }

    }
    
    // Libera la memoria utilizada por la variable capture.
    cvReleaseCapture(&capture);

    // Destruye la ventana "Original Image".
    cvDestroyWindow("Camarita");

    return 0;
}
