#pragma once
#include <iostream>
#include <qmessagebox.h>

#include "GameWidget.h"
#include "../../comStruct.h"
#include "../../data_base/DataWuziqi.h"
//#include "../../rule/RuleWiorker.h"

class GameSocketManager;
class GameWidgetBase :
    public GameWidget
{
    Q_OBJECT
private:
    //ControllerRuleWorker m_controllerRuleWorker;
    QMessageBox message_game_end;
    QPointF m_mousePoint;
    qreal m_width_chess;
    DataWuziqiSpecType* m_dataWuziqi;

    bool m_myCharacter = true;
    //bool is_matched = false;
    QPointF achess;
    //bool mypart = false;
    //map<QPointF, int, cmp>* chesses;
    bool gamegoingon = true;
    //bool m_bRecieved = true;



signals:
    void drawOneChessNext();
    //void getaplayer();
    //void sendAChessData(std::string s);
    //void ruleStart(QPointF& point_chess, MapPoint*& ptrchesses, qreal& chess_width, bool& myturn);
public slots:
    void show_window() override;
    void drawOneChess(QPointF point_chess, bool BRequestConnection);
    void matchplayer()override;
    //void setBRecieved() {
    //    m_bRecieved = true;
    //}

protected:
    void mousePressEvent(QMouseEvent* e)override;
    void handleMousePress(QMouseEvent* e) override;
public:
    GameWidgetBase(GameSocketManager* gameSocketManager, DataWuziqiSpecType* dataWuziqiSpecType);

    QPointF getLastMousePoint();
    qreal getWidthChess() const {
        return m_width_chess;
    }
    bool getMyTurn() const {
        return m_myCharacter;
    }
    QMessageBox* getMessageBox() {
        return &message_game_end;
    }
};

