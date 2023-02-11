#include "../socket/GameSocketManager.h"
#include "WuziqiGameWidget.h"
#include <QGraphicsEllipseItem>
#include <iostream>
#include <qmessagebox.h>
#include <thread>

#include "../../drawer/Drawer.h"
#include "../../myFunction.h"

void WuziqiGameWidget::show_window()
{
	m_gameWidgetBase.show_window();
}

void WuziqiGameWidget::drawOneChess(QPointF point_chess, bool BRequestConnection)
{
	m_gameWidgetBase.drawOneChess(point_chess, BRequestConnection);
}

void WuziqiGameWidget::matchplayer()
{
	m_gameWidgetBase.matchplayer();
}

