#pragma once
#include "../game_palying_ui/Wuziqi/WuziqiGameWidget.h"
#include "../data_base/DataWuziqi.h"
class ChessBoard : public QObject
{
	Q_OBJECT
	DataWuziqiSpecType m_dataWuziqi;
	WuziqiGameWidget m_wuziqiGameWidget;
public slots:
	void handleMousePress(QMouseEvent* e);

};

