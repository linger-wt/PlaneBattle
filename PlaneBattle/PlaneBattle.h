#ifndef TANKBATTLE_H
#define TANKBATTLE_H

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include "ui_PlaneBattle.h"

class TankBattle : public QMainWindow
{
	Q_OBJECT

public:
	TankBattle(QWidget *parent = 0);
	~TankBattle();

	void initWidget();

	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);

private slots:
	void controlerTimer();// 控制者的定时器
	void refreshTimer();// 刷新定时器

private:
	Ui::PlaneBattleClass ui;

	QTimer m_controlerTimer;// 控制者的定时器
	QTimer m_refreshTimer;// 刷新定时器

	bool m_bLeftMove;// 左移标志位
	bool m_bRightMove;// 右移标志位
	bool m_bUpMove;// 上移标志位
	bool m_bDownMove;// 下移标志位
};

#endif // TANKBATTLE_H
