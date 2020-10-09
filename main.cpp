
#include <QApplication>
#include "opencvcap.h"
#include "widget.h"
//#include "opencvcap.h"


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
   Widget w;
    w.show();
    return a.exec();
}


