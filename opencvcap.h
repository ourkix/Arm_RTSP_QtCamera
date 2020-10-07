#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <QThread>
#include <QMutex>


using namespace cv;
using namespace std;

class OpencvCap :public QThread
{
    Q_OBJECT

public:
    OpencvCap(const char* url);
    ~OpencvCap();

    void put_frame(Mat frame);
    bool get_frame(Mat &frame);

private:
    void run() override;
    //缓存容器
    vector<Mat> m_vec_frame;
    //互斥锁
    QMutex m_mutex;
    //videocapture
    VideoCapture m_cap;
};


