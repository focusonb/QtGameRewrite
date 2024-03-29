

#include "myfunction.h"
#include <QMessageBox>
#include <stdlib.h>
//#include <QGraphicsScene>
//#include "GameWidget.h"
class GameWidget;
void makeBoard(QGraphicsView* graphicsView, QGraphicsScene*scene, qreal& witdth_chess, qreal& height_chess ,map<QPointF, int, cmp>*&ptrchesses)
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
		for (; j <14; ++j)
		{
			qreal x = i * witdth_chess - witdth_chess * 7;
			qreal y = j * height_chess - height_chess * 7;
			ptrchesses->insert(pair<QPointF, int>(QPointF(x, y), 0));
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
		ptrchesses->insert(pair<QPointF, int>(QPointF(x, y), 0));
	}
	int j = 0;
	for (; j < 14; ++j)
	{
		qreal x = i * witdth_chess - witdth_chess * 7;
		qreal y = j * height_chess - height_chess * 7;
		ptrchesses->insert(pair<QPointF, int>(QPointF(x, y), 0));
	}
	qreal x = i * witdth_chess - witdth_chess * 7;
	qreal y = j * height_chess - height_chess * 7;
	ptrchesses->insert(pair<QPointF, int>(QPointF(x, y), 0));
}

QRectF  qpointtoqrectf(QPointF& point_chess,qreal& chess_width)
{
	QPointF topLeft(point_chess.rx() - chess_width * 0.4, point_chess.ry() -chess_width * 0.4);
	QPointF bottomRight(point_chess.rx() +chess_width * 0.4, point_chess.ry() +chess_width * 0.4);
	return QRectF(topLeft, bottomRight);
}
void drawachess(bool&myturn,QPointF& point_chess, QGraphicsScene*scene, qreal& chess_width,map<QPointF, int,
	cmp>*&ptrchesses, bool& gamegoingon, QSemaphore* sematwo, QSemaphore* semaone)
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
	if(myturn==true)
	{
		QPen pen(Qt::black);
		QBrush brush(Qt::black);
		if (semaone->tryAcquire(1) == false)
		{
			return;
		}

		scene->addEllipse(rect, pen, brush);
		ptrchesses->at(point_chess) = 1;
		//if (is_win(point_chess, ptrchesses, chess_width, myturn,gamegoingon))
		//{
		//	QMessageBox message(QMessageBox::Warning, "Information", "YOU WIN!", QMessageBox::Yes, NULL);
		//	message.exec();
		//}
		//QReleaseSemaphore(*sematwo, 1, NULL);
		sematwo->release();
		//scene->addEllipse(QRectF(QPointF(-18.75, -18.75), QPointF(18.75, 18.75)), pen, brush);
		//scene->addEllipse(QRectF(QPointF(-chess_width /2, chess_width / 2), QPointF(chess_width / 2, -chess_width / 2)), pen, brush);
	}
	else
	{
		QPen pen(Qt::white);
		QBrush brush(Qt::white);
		if (semaone->tryAcquire(1) == false)
		{
			return;
		}

		scene->addEllipse(rect, pen, brush);
		ptrchesses->at(point_chess) = 2;
		//if (is_win(point_chess, ptrchesses, chess_width, myturn,gamegoingon))
		//{
		//	QMessageBox message(QMessageBox::Warning, "Information", "YOU WIN!", QMessageBox::Yes, NULL);
		//	message.exec();
		//}
		sematwo->release();
		//yturn = true;

	}

	
	
	

}
void pointstd(QPointF& point_chess, qreal& chess_width)
{
	qreal extra_x = point_chess.x()/chess_width;
	qreal extra_y= point_chess.y()/chess_width;
	int x;
	int y;
	if(extra_x<=0)
	 x=extra_x-0.5;
	else
		x = extra_x + 0.5;
	if (extra_y <= 0)
		y = extra_y - 0.5;
	else
		y = extra_y +0.5;

	point_chess.rx() = x* chess_width;
	point_chess.ry() = y* chess_width;
}


bool is_outrange(QPointF point_chess, qreal chess_width)
{
	if (
		((point_chess.rx() <= chess_width * 7) &&
		(point_chess.rx() >= chess_width * (-7)))
		&&
		((point_chess.ry() <= chess_width * 7) &&
		(point_chess.ry() >= chess_width * (-7)))
		)
	{
		return false;
	}
	else
		return true;
}
bool is_chessmade(map<QPointF, int, cmp>*&ptrchesses, QPointF& point_chess)
{
	//if (ptrchesses->at(point_chess) != 0)
	if (ptrchesses->find(point_chess) != ptrchesses->end() &&
		ptrchesses->at(point_chess) != 0)
	{
		return true;
	}
	return false;
}
void split_a(string&s, QPointF&chesspoint)
{
	size_t pos = s.find('a');
    
	string xstr(s, 0, pos);
	string ystr(s, pos + 1);
	qreal xq = atof(xstr.c_str());
	qreal yq = atof(ystr.c_str());
	chesspoint.setX(xq);
	chesspoint.setY(yq);
}
