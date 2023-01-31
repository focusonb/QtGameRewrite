

#include "rule.h"
#include "../myfunction.h"
#include <QMessageBox>
#include <stdlib.h>
//#include <QGraphicsScene>
//#include "GameWidget.h"
class GameWidget;


bool is_win(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, bool&myturn, const bool& gamegoingon)
{
	if (check_row(point_chess, ptrchesses, chess_width, myturn)||
		check_col(point_chess, ptrchesses, chess_width, myturn)||
		check_obl(point_chess, ptrchesses, chess_width, myturn)||
		check_obl_a(point_chess, ptrchesses, chess_width, myturn)
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}  
bool check_row(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, bool&myturn)
{
	if (myturn == true)
	{
		return Is_row_win(point_chess, ptrchesses, chess_width, 1);
	}

	return Is_row_win(point_chess, ptrchesses, chess_width, 2);

}
bool Is_row_win(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, int i)
{
	int count = -1;
	for (
		 qreal next_left_x = point_chess.rx();
		ptrchesses->at(QPointF(next_left_x, point_chess.ry())) == i;
		)
	{
		next_left_x -= chess_width;
		++count;
		if (is_outrange(QPointF(next_left_x, point_chess.ry()), chess_width))
		{
			break;
	    }  
	}
	for (
		qreal next_right_x = point_chess.rx();
		ptrchesses->at(QPointF(next_right_x, point_chess.ry())) == i;
		)
	{
		next_right_x += chess_width;
		++count;
		if (is_outrange(QPointF(next_right_x, point_chess.ry()), chess_width))
		{
			break;
		}
	}
	if (count >= 5)
	{
		return true;
	}
	else
		return false;
}
bool check_col(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, bool&myturn)
{
	if (myturn == true)
	{
		return Is_col_win(point_chess, ptrchesses, chess_width, 1);
	}

	return Is_col_win(point_chess, ptrchesses, chess_width, 2);

}
bool Is_col_win(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, int i)
{
	int count = -1;
	for (
		qreal next_down_y= point_chess.ry();
		ptrchesses->at(QPointF( point_chess.rx(), next_down_y)) == i;	
		)
	{
		next_down_y += chess_width;
		++count;
		if (is_outrange(QPointF(point_chess.rx(), next_down_y), chess_width))
		{
			break;
		}
	}
	for (
		qreal next_up_y = point_chess.ry();
		ptrchesses->at(QPointF(point_chess.rx(), next_up_y)) == i;
		)
	{
		next_up_y -= chess_width;
		++count;
		if (is_outrange(QPointF(point_chess.rx(), next_up_y), chess_width))
		{
			break;
		}
	}
	if (count >= 5)
	{
		return true;
	}
	else
		return false;
}

bool check_obl(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, bool&myturn)
{
	if (myturn == true)
	{
		return Is_obl_win(point_chess, ptrchesses, chess_width, 1);
	}

	return Is_obl_win(point_chess, ptrchesses, chess_width, 2);
}
bool Is_obl_win(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, int i)
{
	int count = -1;
	//QPointF temp = point_chess;
	for (
		auto p = std::make_pair(point_chess.rx(), point_chess.ry());
		ptrchesses->at(QPointF(p.first,p.second)) == i;
		)
	{
		p.first -= chess_width, p.second -= chess_width;
		++count;
		if (is_outrange(QPointF(p.first, p.second), chess_width))
		{
			break;
		}
			
	}
	for (
		auto p = std::make_pair(point_chess.rx(), point_chess.ry());
		ptrchesses->at(QPointF(p.first,p.second ) )== i;
		)
	{
		p.first += chess_width, p.second += chess_width;
		++count;
		if (is_outrange(QPointF(p.first, p.second), chess_width))
		{
			break;
		}
	}
	if (count >= 5)
	{
		return true;
	}
	else
		return false;
}
bool check_obl_a(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, bool&myturn)
{
	if (myturn == true)
	{
		return Is_obl_win_a(point_chess, ptrchesses, chess_width, 1);
	}
	return Is_obl_win_a(point_chess, ptrchesses, chess_width, 2);
}
bool Is_obl_win_a(QPointF& point_chess, map<QPointF, int, cmp>*&ptrchesses, qreal& chess_width, int i)
{
	int count = -1;
	//QPointF temp = point_chess;
	for (
		auto p = std::make_pair(point_chess.rx(), point_chess.ry());
		ptrchesses->at(QPointF(p.first,p.second)) == i;
		)
	{
		p.first += chess_width, p.second -= chess_width;
		++count;
		if (is_outrange(QPointF(p.first, p.second), chess_width))
		{
			break;
		}
	}
	for (
		auto p = std::make_pair(point_chess.rx(), point_chess.ry());
		ptrchesses->at(QPointF(p.first,p.second)) == i;
		)
	{
		p.first -= chess_width, p.second += chess_width;
		++count;
		if (is_outrange(QPointF(p.first, p.second), chess_width))
		{
			break;
		}
	}
	if (count >= 5)
	{
		return true;
	}
	else
		return false;
}
