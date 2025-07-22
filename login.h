#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include "login_success.h"
#include "login_failed.h"
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/features2d.hpp>  // For ORB feature detection
#include<QFile>
QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow  // Keeping the name consistent with the UI
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
    login_success *loginsuccesswindow;
    QTimer *timer;
    cv::VideoCapture cap;
    cv::CascadeClassifier faceDetector;
    cv::Mat referenceFace;
    login_failed * loginfailedwindow;

    // ORB Feature Extractor and Matcher
    cv::Ptr<cv::ORB> orb;
    cv::BFMatcher matcher;

    std::vector<cv::Mat> refDescriptors;
    std::vector<std::vector<cv::KeyPoint>> refKeypoints;

    bool detectAndRecognizeFace(cv::Mat &frame);
    void extractORBFeatures(const cv::Mat &image, std::vector<cv::KeyPoint> &keypoints, cv::Mat &descriptors);
    bool compareFeatures(const cv::Mat &descriptors1, const cv::Mat &descriptors2);
    void openLoginSuccessWindow();
    void openLoginFailedWindow();
    void loadreferenceimages();
    bool recognizeFace(const cv::Mat &inputImage);
    bool validateCashier(const QString &username, const QString &password);
};

#endif // LOGIN_H
