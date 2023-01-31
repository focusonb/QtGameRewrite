#include "DataWuziqi.h"

void DataWuziqiSpecType::insert(QPointF qPointF, chessState oneChessState)
{
	chessDataBase.insert(std::pair<QPointF, chessState>(qPointF, oneChessState));
}

DataWuziqiSpecType::chessesData* DataWuziqiSpecType::get()
{
	return &chessDataBase;
}
