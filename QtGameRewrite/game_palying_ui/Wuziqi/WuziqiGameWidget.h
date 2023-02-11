#pragma once
#include "../../socket/GameSocketManager.h"
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
        QObject::connect(&m_gameWidgetBase, &GameWidgetBase::ruleStart, &m_controllerRuleWorker, &ControllerRuleWorker::emitOperate);
        QObject::connect(&m_gameWidgetBase, &GameWidgetBase::sendAChessData, gameSocketManager, &GameSocketManager::sendStrData);
    }
    
private:
    GameWidgetBase m_gameWidgetBase;
    ControllerRuleWorker m_controllerRuleWorker;


public slots:
    void show_window();
    void drawOneChess(QPointF point_chess, bool BRequestConnection);
    void matchplayer();

};

