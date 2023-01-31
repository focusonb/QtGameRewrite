#pragma once
#include "GameWidget.h"
#include "../../comStruct.h"
#include "../../data_base/DataWuziqi.h"

class GameSocketManager;
class WuziqiGameWidget :
    public GameWidget
{
    Q_OBJECT
private:
    QPointF m_mousePoint;
    qreal m_width_chess;
    DataWuziqiSpecType *m_dataWuziqi;

    bool m_myturn = true;
    bool is_matched = false;
    QPointF achess;
    bool mypart = false;
    map<QPointF, int, cmp>* chesses;
    QSemaphore* sematwo;
    QSemaphore* semaone;
    bool gamegoingon = true;

    

signals:
    void getaplayer();
public slots:
    void show_window() override;
    void drawOneChess(QPointF point_chess, bool BRequestConnection);

protected:
    void mousePressEvent(QMouseEvent* e)override;
    void handleMousePress(QMouseEvent* e) override;
public:
    void matchplayer()override;
    WuziqiGameWidget(GameSocketManager* gameSocketManager, DataWuziqiSpecType* dataWuziqiSpecType) :GameWidget(gameSocketManager), m_dataWuziqi(dataWuziqiSpecType){}
    QPointF getLastMousePoint();
    qreal getWidthChess() const {
        return m_width_chess;
    }
    bool getMyTurn() const {
        return m_myturn;
    }
};

