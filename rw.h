#ifndef RW_H
#define RW_H

#include <QDialog>

#include "opencv2/core/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/opencv.hpp"
#include <direct.h>

#include <fstream>
#include <sstream>

using namespace std;
using namespace cv;
using namespace cv::face;

namespace Ui {
class rw;
}

class rw : public QDialog
{
    Q_OBJECT

public:
    explicit rw(QWidget *parent = nullptr);
    ~rw();


private slots:
    void on_pushButton_clicked();

private:
    void addFace();
    void trainEigenFace();
    void detectAndDisplay(Mat frame); // Declare inside class

    Ui::rw *ui;
    CascadeClassifier face_cascade;
    string name;
    int filenumber;  // Declare here
    static void dbread(vector<Mat>& images, vector<int>& labels);



};

#endif // RW_H
