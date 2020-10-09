#include "ui_widget.h"
#include "widget.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "opencvcap.h"



   
//创建对象，初始化
//OpencvCap *m_opencvcap;

static QTime timec;
static int framesc = 0;
static bool started = false;
static bool multi = false;

int imagesizes = 300;

QString m_current_fps;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

	 //cam = VideoCapture("rtsp://admin:a12345678@192.168.0.64/main/Channels/1");
	cam = VideoCapture("rtsp://admin:a12345678@192.168.0.64/h264/ch1/sub/av_stream");
	//开始线程
	  //m_opencvcap->start();
	



}

Widget::~Widget()
{
    delete ui;


}

void Widget::paintEvent(QPaintEvent *)
{
  

    	 Mat frame;

       if (cam.isOpened())
        {
            //capture >> frame;
	    bool result = cam.read(frame);

		//处理图像······
		//imshow("windows",frame);	
		    Mat images = frame;
     int new_width,new_height,width,height,channel;
        width=images.cols;
        height=images.rows;
        channel=images.channels();
        //调整图像大小
        new_width=imagesizes;

        new_height=int(new_width*1.0/width*height);
        cv::resize(images, images, cv::Size(new_width, new_height));


    QImage xii = cvMat_to_QImage(images);    

    ui->label->setPixmap(QPixmap::fromImage(xii));

	}




   





QPainter painter(this);

 if (!started || timec.elapsed() > 1000) {
            qreal fps = framesc * 1000. / timec.elapsed();
            if (fps == 0)
                m_current_fps = "counting fps...";
            else
                m_current_fps = QString::fromLatin1("%3 FPS").arg((int) qRound(fps));

            timec.start();
            started = true;
            framesc = 0;
	//printf("fps %f\n",fps);
        } else {
            ++framesc;
	    ui->fpslabel->setText(m_current_fps);

        }


}

QImage Widget::cvMat_to_QImage(const cv::Mat &mat ) {
 /* switch ( mat.type() )
  {
     // 8-bit, 4 channel
     case CV_8UC4:
     {
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32 );
        return image;
     }
 
     // 8-bit, 3 channel
     case CV_8UC3:
     {
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888 );
        return image.rgbSwapped();
     }
 
     // 8-bit, 1 channel
     case CV_8UC1:
     {
        static QVector<QRgb>  sColorTable;
        // only create our color table once
        if ( sColorTable.isEmpty() )
        {
           for ( int i = 0; i < 256; ++i )
              sColorTable.push_back( qRgb( i, i, i ) );
        }
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8 );
        image.setColorTable( sColorTable );
        return image;
     }
 
     default:
         printf("Image format is not supported: depth=%d and %d channels\n", mat.depth(), mat.channels());
        //qDebug("Image format is not supported: depth=%d and %d channels\n", mat.depth(), mat.channels());
        break;
  }
  return QImage();
*/

// 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        static QVector<QRgb>  sColorTable;
        // only create our color table once
        if ( sColorTable.isEmpty() )
        {
           for ( int i = 0; i < 256; ++i )
              sColorTable.push_back( qRgb( i, i, i ) );
        }
	image.setColorTable( sColorTable );
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }

}

