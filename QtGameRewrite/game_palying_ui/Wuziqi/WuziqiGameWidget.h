#pragma once
#include <iostream>
#include <qmessagebox.h>

#include "GameWidgetBase.h"
#include "../../comStruct.h"
#include "../../data_base/DataWuziqi.h"
#include "../../rule/RuleWiorker.h"

class GameSocketManager;
class WuziqiGameWidget :
    public QMainWindow
{
    Q_OBJECT
public:
    WuziqiGameWidget(GameSocketManager* gameSocketManager, DataWuziqiSpecType* dataWuziqiSpecType):
        m_gameWidgetBase(gameSocketManager, dataWuziqiSpecType)
    {
        QObject::connect(&m_controllerRuleWorker, SIGNAL(workFinished()), m_gameWidgetBase.getMessageBox(), SLOT(exec()));
        QObject::connect(this, &WuziqiGameWidget::ruleStart, &m_controllerRuleWorker, &ControllerRuleWorker::emitOperate);
    }
    
private:
    GameWidgetBase m_gameWidgetBase;
    ControllerRuleWorker m_controllerRuleWorker;
    bool m_bRecieved = true;

signals:
    void drawOneChessNext();
    void sendAChessData(std::string s);
    void ruleStart(QPointF& point_chess, MapPoint*& ptrchesses, qreal& chess_width, bool& myturn);

public slots:
    void show_window();
    void drawOneChess(QPointF point_chess, bool BRequestConnection);
    void matchplayer();
    void setBRecieved();

};

