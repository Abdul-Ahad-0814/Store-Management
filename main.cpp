#include"login.h"
#include"addproducts.h"
#include<opencv2/opencv.hpp>
#include"globals.h"
#include <QApplication>
#include<fstream>
#include<string>
#include"Login.h"

using namespace cv;

int main(int argc, char *argv[])
{
    // VideoCapture cap(0);
    // Mat frame;
    // while(true){
    //     cap>>frame;
    //     imshow("Webcam", frame);
    //     if(waitKey(1)=='q'){
    //         break;
    //     }
    // }
    // cap.release();
    // destroyAllWindows();
    QApplication a(argc, argv);

      // LoginWindow w;
      // w.show();
    globaladmin.loadCashiersFromFile();
    LoginWindow w;
     w.show();

    //  login1 loginwindow;
    // loginwindow.show();
    // login_failed failed;
    // failed.show();
    // rw r1;
    // r1.show();
    // Products p1;
    // p1.show();

     // rw r1;
     // r1.show();

    /*td::ofstream file("products.csv", std::ios::app);
    std::ofstream file1("cashier", std::ios::app);*/
    // Addproducts ap ;  // Pass it when creating Addproducts window
    // ap.show();




    return a.exec();
}
