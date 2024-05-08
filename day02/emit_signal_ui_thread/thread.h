#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QDebug>
#include <string>
using namespace std;
struct Score
{
    string name;
    int id;
    int age;
};

class child_thread : public QThread
{
   Q_OBJECT

public:
    child_thread();
signals:
    void sig_SendScore(Score sc);

private:
    void run() override;
};

#endif // THREAD_H
