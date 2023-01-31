#pragma once
#include<map>
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>

struct cmp
{
public:
	bool operator()(const QPointF& a, const QPointF& b)const
	{
		{
			if (a.y() < b.y())
			{
				return true;
			}
			else if (a.y() > b.y())
			{
				return false;
			}
			if (a.x() == b.x())
			{
				return false;
			}
			else if (a.x() < b.x())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};

using MapPoint = std::map<QPointF, int, cmp>;

class GameWidget;
class QMessageBox;

struct Threadarg_iswin
{
	QPointF* point_chess;
	MapPoint** ptrchesses;
	qreal* chess_width;
	bool* myturn;
	bool* gamegoingon;
	bool* mypart;
	QSemaphore* semaone;
	QSemaphore* sematwo;
	QSemaphore* semathree;
	GameWidget* ptrgamewidget;
	QMessageBox* messagebox;
	bool* is_matched;
	//QGraphicsScene** scene;
};

