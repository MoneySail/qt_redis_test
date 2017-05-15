#include "widget.h"
#include <QApplication>
#include "redis.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Redis *r = new Redis();

    if(!r->connect("127.0.0.1", 6379))
        {
            printf("connect error!\n");
            return 0;
        }
        r->set("name", "Andy");
        printf("Get the name is %s\n", r->get("name").c_str());
        delete r;
    w.show();

    return a.exec();
}
