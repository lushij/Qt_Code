#include "thread.h"

child_thread::child_thread()
{
    //对于非基础类型需要注册
    qRegisterMetaType<Score>("Score");
}
void child_thread::run()
{
    while(1)
    {
//        static int idx = 0;
//        qDebug() << idx ++ ;
        Score sc;
        sc={"jack",1,10};
        emit sig_SendScore(sc);//发送
    }
}
