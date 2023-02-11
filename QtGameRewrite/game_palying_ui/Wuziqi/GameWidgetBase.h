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
    QMessageBox message_game_end;
    QPointF m_mousePoint;
    qreal m_width_chess;
    DataWuziqiSpecType* m_dataWuziqi;

    bool m_myCharacter = true;
    QPointF achess;

    bool gamegoingon = true;
    bool m_bRecieved = true;



signals:
    void sendAChessData(std::string message_toopponent);
    void ruleStart(QPointF& point_chess, MapPoint*& ptrchesses, qreal& chess_width, bool& myturn);
public slots:
    void show_window() override;
    void drawOneChess(QPointF point_chess, bool BRequestConnection);
    void matchplayer()override;
    void setBRecieved() {
        m_bRecieved = true;
    }

protected:
    void mousePressEvent(QMouseEvent* e)override;
    void handleMousePress(QMouseEvent* e) override;
public:
    GameWidgetBase(GameSocketManager* gameSocketManager, DataWuziqiSpecType* dataWuziqiSpecType);
    void drawOneChessUi(bool& myturn, QPointF& point_chess, QGraphicsScene* scene, qreal& chess_width, std::map<QPointF, int,
        cmp>* ptrchesses, bool& gamegoingon);

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

