#include "PlaneBattle.h"
#include <QPoint>

TankBattle::TankBattle(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initWidget();

	connect(&m_controlerTimer,SIGNAL(timeout()), this, SLOT(controlerTimer()));
	m_controlerTimer.start(30);

	connect(&m_refreshTimer,SIGNAL(timeout()), this, SLOT(refreshTimer()));
	m_refreshTimer.start(17);// 刷新定时器按照1秒60帧的速率进行刷新
}

TankBattle::~TankBattle()
{

}

void TankBattle::initWidget()
{
	QPixmap pix = QPixmap("plane_icon.png");
	pix.scaled(ui.label_plane->size(), Qt::KeepAspectRatio);
	ui.label_plane->setScaledContents(true);
	ui.label_plane->setPixmap(pix);
	ui.label_plane->show();
}

void TankBattle::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Left)
	{
		m_bLeftMove = true;
		m_bRightMove = false;// 左右不能同移
	}
	else if (event->key() == Qt::Key_Right)
	{
		m_bLeftMove = false;// 左右不能同移
		m_bRightMove = true;
	}
	else if (event->key() == Qt::Key_Up)
	{
		m_bUpMove = true;
		m_bDownMove = false;// 上下不能同移
	}
	else if (event->key() == Qt::Key_Down)
	{
		m_bUpMove = false;// 上下不能同移
		m_bDownMove = true;
	}
}

void TankBattle::keyReleaseEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Left)
	{
		m_bLeftMove = false;
	}
	else if (event->key() == Qt::Key_Right)
	{
		m_bRightMove = false;
	}
	else if (event->key() == Qt::Key_Up)
	{
		m_bUpMove = false;
	}
	else if (event->key() == Qt::Key_Down)
	{
		m_bDownMove = false;
	}
}

void TankBattle::controlerTimer()
{
	// 获取当前位置
	QPoint pt = ui.label_plane->pos();
	// 位置变化量
	QPoint dpt;
	if (m_bLeftMove && pt.x()>0)
	{
		dpt.setX(-5);
	}
	if (m_bRightMove && pt.x()<size().width()-ui.label_plane->width())
	{
		dpt.setX(5);
	}
	if (m_bUpMove && pt.y()>0)
	{
		dpt.setY(-5);
	}
	if (m_bDownMove && pt.y()<size().height()-ui.label_plane->height())
	{
		dpt.setY(5);
	}
	pt = pt + dpt;
	ui.label_plane->move(pt);
}

void TankBattle::refreshTimer()
{

}
