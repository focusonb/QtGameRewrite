#pragma once
#include "../data_base/DataWuziqi.h"
#include "../comStruct.h"
#include<map>
#include <QtCore>


class QGraphicsView;
class QGraphicsScene;
class QGraphicsView;
class QPointF;


class Drawer
{
public:
	using chessesData = DataWuziqiSpecType::chessesData;
	using MapPoint = std::map<QPointF, int, cmp>;
public:
	//void drawChessBoard_(QGraphicsView* graphicsView, QGraphicsScene* scene, qreal& witdth_chess, qreal& height_chess, DataWuziqi* ptrchesses);
	void drawChessBoard(QGraphicsView* graphicsView, QGraphicsScene* scene, qreal& witdth_chess, qreal& height_chess, DataWuziqi* ptrchesses);
	void drawOneChess(bool& myturn, QPointF& point_chess, QGraphicsScene* scene, qreal& chess_width, std::map<QPointF, int,
		cmp>*& ptrchesses, bool& gamegoingon);
};

