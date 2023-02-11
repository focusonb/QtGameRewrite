#include "Drawer.h"

#include <QGraphicsView>
#include <map>

#include "../myfunction.h"



using std::pair;
void Drawer::drawChessBoard(QGraphicsView* graphicsView, QGraphicsScene* scene, qreal& witdth_chess, qreal& height_chess, DataWuziqi* ptrchesses)
{
	QBrush greenBrush(Qt::green);
	QPen  blackPen(Qt::black);

	qreal width_view = graphicsView->width();
	qreal height_view = graphicsView->height();
	witdth_chess = width_view / 15;
	height_chess = width_view / 15;

	//int i = 3;
	//int j = 10;
	//qreal x = i * witdth_chess - witdth_chess * 7;
	//qreal y = j * height_chess - height_chess * 7;
	//scene->addRect(
	//	x
	//	, y
	//	, witdth_chess
	//	, height_chess
	//	, blackPen
	//	, greenBrush);

	int i = 0;
	for (; i < 14; ++i)
	{
		int j = 0;
		for (; j < 14; ++j)
		{
			qreal x = i * witdth_chess - witdth_chess * 7;
			qreal y = j * height_chess - height_chess * 7;
			ptrchesses->insert(QPointF(x, y), 0);
			scene->addRect(
				x
				, y
				, witdth_chess
				, height_chess
				, blackPen
				, greenBrush);
		}
		qreal x = i * witdth_chess - witdth_chess * 7;
		qreal y = j * height_chess - height_chess * 7;
		ptrchesses->insert(QPointF(x, y), 0);
	}
	int j = 0;
	for (; j < 14; ++j)
	{
		qreal x = i * witdth_chess - witdth_chess * 7;
		qreal y = j * height_chess - height_chess * 7;
		ptrchesses->insert(QPointF(x, y), 0);
	}
	qreal x = i * witdth_chess - witdth_chess * 7;
	qreal y = j * height_chess - height_chess * 7;
	ptrchesses->insert(QPointF(x, y), 0);
}

void Drawer ::drawOneChess(bool& myturn, QPointF& point_chess, QGraphicsScene* scene, qreal& chess_width, map<QPointF, int,
	cmp>* ptrchesses, bool& gamegoingon)
{
	pointstd(point_chess, chess_width);

	if (is_outrange(point_chess, chess_width))
	{
		return;
	}
	if (is_chessmade(ptrchesses, point_chess))
	{
		return;
	}
	QRectF rect = qpointtoqrectf(point_chess, chess_width);
	if (myturn == true)
	{
		QPen pen(Qt::black);
		QBrush brush(Qt::black);
		//if (semaone->tryAcquire(1) == false)
		//{
		//	return;
		//}

		scene->addEllipse(rect, pen, brush);
		(*ptrchesses)[point_chess] = 1;
		//if (is_win(point_chess, ptrchesses, chess_width, myturn,gamegoingon))
		//{
		//	QMessageBox message(QMessageBox::Warning, "Information", "YOU WIN!", QMessageBox::Yes, NULL);
		//	message.exec();
		//}
		//QReleaseSemaphore(*sematwo, 1, NULL);
		//sematwo->release();
		//scene->addEllipse(QRectF(QPointF(-18.75, -18.75), QPointF(18.75, 18.75)), pen, brush);
		//scene->addEllipse(QRectF(QPointF(-chess_width /2, chess_width / 2), QPointF(chess_width / 2, -chess_width / 2)), pen, brush);
	}
	else
	{
		QPen pen(Qt::white);
		QBrush brush(Qt::white);
		//if (semaone->tryAcquire(1) == false)
		//{
		//	return;
		//}

		scene->addEllipse(rect, pen, brush);
		(*ptrchesses)[point_chess] = 2;
		//if (is_win(point_chess, ptrchesses, chess_width, myturn,gamegoingon))
		//{
		//	QMessageBox message(QMessageBox::Warning, "Information", "YOU WIN!", QMessageBox::Yes, NULL);
		//	message.exec();
		//}
		//sematwo->release();
		//yturn = true;

	}





}