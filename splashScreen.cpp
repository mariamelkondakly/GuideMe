#include "splashScreen.h"
#include "ui_splashScreen.h"
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoFrame>

SplashScreen::SplashScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    QString filename="C:/Users/MARIAM/qt projects/GuideMe/Assets/train.mp4";
    QMediaPlayer *player=new QMediaPlayer();
    QVideoWidget *video= new QVideoWidget();
    video->setStyleSheet("QVideoWidget {background-color: white;}");
    player->setVideoOutput(video);
    player->setSource(QUrl(filename));
    ui->gridLayout->addWidget(video);

    player->play();
    player->setLoops(QMediaPlayer::Infinite);


}

SplashScreen::~SplashScreen()
{
    delete ui;

}
