#ifndef TRANSPORTATIONDISPLAY_H
#define TRANSPORTATIONDISPLAY_H
#include <QWidget>
using namespace std;
namespace Ui {
class transportationDisplay;
}

class transportationDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit transportationDisplay(QWidget *parent = nullptr);
    ~transportationDisplay();


private:
    Ui::transportationDisplay *ui;
    vector<QWidget *> transportationCreate();
    void transportationshow();
};

#endif // TRANSPORTATIONDISPLAY_H
