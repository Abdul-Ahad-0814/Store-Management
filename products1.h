#include <QDialog>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class products1; }
QT_END_NAMESPACE

class products1 : public QDialog
{
    Q_OBJECT

public:
    explicit products1(QWidget *parent = nullptr);
    ~products1();


    long long int getID();
    std::string getName();
    int getquantity();
    float getSalePrice();
    float getPrice();

private slots:
    void on_submitbutton_clicked();
    void on_capturebarcodebutton_clicked();

private:
    Ui::products1 *ui;
    cv::VideoCapture cap;
    QTimer *timer;
    QImage lastFrame;
};
