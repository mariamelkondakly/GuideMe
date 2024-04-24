#ifndef GUI_MANAGEMENT_H
#define GUI_MANAGEMENT_H
#include <QApplication>
#include<QWidget>
#include<QString>
#include<QFile>
class GUI_management
{
public:
    GUI_management();
    static void applyStylesheet(QWidget *widget, const QString &filePath);
};

#endif // GUI_MANAGEMENT_H
