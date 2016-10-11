#include "mainwindow.h"
#include <QApplication>

#include "ecosystemscene.h"
#include "statisticsscene.h"
#include "initialwater.h"
#include "initialplant.h"
#include "initialanimal.h"

#include "Ecosystem/MapItem.h"
#include "Ecosystem/Random.h"

void initialMap();

void sleep(unsigned int msec);
void initialMainWindow(MainWindow* pWindow);

const int mainwindowWidth = 1100;
const int mainwindowHeight = 670;
const int mainViewWidth = 1090;
const int mainViewHeight = 440;
const int dataViewWidth = 485;
const int dataViewHeigth = 95;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initialMap();

    EcosystemScene *pScene = new EcosystemScene(mainViewWidth-15,mainViewHeight-15);
    StatisticsScene *pStatisticsScene_Sheep = new StatisticsScene(dataViewWidth-5 , dataViewHeigth-5 , Parameters::paraSheep::speciesID);
    StatisticsScene *pStatisticsScene_Cow = new StatisticsScene(dataViewWidth-5 , dataViewHeigth-5 , Parameters::paraCow::speciesID);
    StatisticsScene *pStatisticsScene_Wolf = new StatisticsScene(dataViewWidth-5 , dataViewHeigth-5 , Parameters::paraWolf::speciesID);
    StatisticsScene *pStatisticsScene_Tiger = new StatisticsScene(dataViewWidth-5 , dataViewHeigth-5 , Parameters::paraTiger::speciesID);

    MainWindow *mainwindow = new MainWindow();
    initialMainWindow(mainwindow);

    mainwindow->graphicsView->setScene(pScene);
    mainwindow->statisticsView_Sheep->setScene(pStatisticsScene_Sheep);
    mainwindow->statisticsView_Cow->setScene(pStatisticsScene_Cow);
    mainwindow->statisticsView_Tiger->setScene(pStatisticsScene_Tiger);
    mainwindow->statisticsView_Wolf->setScene(pStatisticsScene_Wolf);

    mainwindow->show();

    while(1)
    {
        pScene->reDraw();
        mCreatureVector.Update();

        pStatisticsScene_Sheep->sceneUpdate();
        pStatisticsScene_Cow->sceneUpdate();
        pStatisticsScene_Tiger->sceneUpdate();
        pStatisticsScene_Wolf->sceneUpdate();

        sleep(100);
    }

    return a.exec();
}


void initialMainWindow(MainWindow* pWindow)
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint ;
    pWindow->setWindowFlags(flags); //设置禁止最大化
    pWindow->setFixedSize(mainwindowWidth,mainwindowHeight); //禁止改变窗口大小
}

void sleep(unsigned int msec)
{
    if(msec<=0) return;

    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void initialMap()
{
    MapParameters::InitialMap();

    initialWater::initial();
    initialPlant::initial();
    initialAnimal::initial();
}



