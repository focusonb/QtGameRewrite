#pragma once
#include <qthread.h>
#include <tuple>
#include <deque>

#include "../data_base/DataWuziqi.h"


using std::tuple;
using std::deque;



class RuleThread :
    public QThread
{
    Q_OBJECT;
public:
    using RuleDataElenment = tuple<QPointF, DataWuziqiSpecType>;

public:
    RuleThread(bool myTurn, qreal chess_width) :m_myTurn(myTurn), m_chess_width(chess_width) {}
    void run(void)override;
    void addNewChessPoint(const QPointF& point_chess, const DataWuziqiSpecType& chesses_data) {
        m_ruleData.push_back(std::make_tuple(point_chess, chesses_data));
    }
private:
    deque<RuleDataElenment> m_ruleData;
    bool m_myTurn;
    qreal m_chess_width;
};

