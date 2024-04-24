#include "gui_management.h"

GUI_management::GUI_management() {}

void GUI_management::applyStylesheet(QWidget *widget, const QString &filePath) {
    QFile styleFile(filePath);
    if (!styleFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Error: Cannot open stylesheet file";
        return;
    }

    QTextStream styleStream(&styleFile);
    QString styleSheet = styleStream.readAll();
    widget->setStyleSheet(styleSheet);
}

