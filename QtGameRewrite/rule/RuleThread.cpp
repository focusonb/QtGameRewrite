#include "RuleThread.h"

#include "rule.h"

void RuleThread::run(void)
{
	while (m_ruleData.size()!= 0) {
		RuleDataElenment ruleDataElenment = m_ruleData.front();
		QPointF chessPoint = get<0>(ruleDataElenment);
		DataWuziqiSpecType chessData = get<1>(ruleDataElenment);
		MapPoint* ptrMapPoint = chessData.get();
		if (is_win(chessPoint, ptrMapPoint, m_chess_width, m_myTurn, true) == true) {
			//
		}

		m_ruleData.pop_front();
	}
}
