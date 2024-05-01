#include "splashScreen.h"
#include "ui_splashScreen.h"

SplashScreen::SplashScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
}

SplashScreen::~SplashScreen()
{
    delete ui;
}
