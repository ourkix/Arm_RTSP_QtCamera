#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QPainter>
#include <QLineEdit>
#include <QVBoxLayout>

#include <string>
#include <exception>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//#include "opencvcap.h"


using namespace cv;





namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



private:
    Ui::Widget *ui;


    QVBoxLayout *mainLayout;

    VideoCapture cam;

    QImage *frame;
    QLabel *tp;
    QByteArray *aa;
    QPixmap *pix;
    int rs;
    unsigned int len;
    int convert_yuv_to_rgb_buffer();
    void print_quartet(unsigned int i);


    FILE * yuvfile;
    unsigned char rgb_buffer[640*480*3];
    unsigned char * yuv_buffer_pointer;

    char Y_frame[640*480*2+600];


    int writejpg();
    cv::Mat scancoder(cv::Mat &image);
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
    cv::Mat QImage_to_cvMat( const QImage &image, bool inCloneImageData = true );
    QImage cvMat_to_QImage(const cv::Mat &mat );







private slots:
    void paintEvent(QPaintEvent *);

    void on_changeex_clicked();
    void on_changesize_clicked();

};
#endif // WIDGET_H
