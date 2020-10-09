#include "opencvcap.h"

OpencvCap::OpencvCap(const char* url)
{
    m_cap.open(url);
}

OpencvCap::~OpencvCap()
{
    m_cap.release();
}

void OpencvCap::run()
{
    if(!m_cap.isOpened())
    {
	printf("cannot open the videocapture!\n");
        qDebug("cannot open the videocapture\n");
        return ;
    }
    Mat current_frame;
    while(true)
    {
        m_cap >> current_frame;
        if(current_frame.empty())
        {
            qDebug("frame empty\n");
            return ;
        }
        put_frame(current_frame);
        usleep(20);
	count++;
	//printf("thread is running!\n");
	if(count>50)
	{
		count = 0;
		printf("thread is running!\n");
	}

    }
}


void OpencvCap::put_frame(Mat frame)
{
    m_mutex.lock();
    // 这边采用的更简单粗暴的清理方式，可以根据实际情况自定义清理方式
    if(m_vec_frame.size() >5)
       m_vec_frame.clear();
    //存入容器
    m_vec_frame.push_back(frame);
    m_mutex.unlock();
    return;
}

bool OpencvCap::get_frame(Mat &frame)
{
    m_mutex.lock();
    if(m_vec_frame.size() < 1)
        return false;
    else
    {
   		 //从容器中取图像
        frame = m_vec_frame.back();
    }
    m_mutex.unlock();
    return true;
}


