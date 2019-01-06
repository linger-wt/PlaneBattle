#include "PlaneBattle.h"
#include "TGlobal.h"
#include "TScene.h"
#include <QPoint>

TankBattle::TankBattle(QWidget *parent)
	: QMainWindow(parent)
	, m_pView(nullptr)
{
	ui.setupUi(this);
}

TankBattle::~TankBattle()
{

}

void TankBattle::initWidget()
{
	CTScenePtr pScene = CTGlobal::instance()->getScene();
	if (pScene == nullptr)
	{
		return;
	}
	// 初始化界面
	m_pView = new QGraphicsView();
	m_pView->setScene(pScene.get()); // 将场景设置到QGraphicsView中
	m_pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 隐藏垂直滚动条
	m_pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 隐藏水平滚动条
	setCentralWidget(m_pView); // 设置QGraphicsView为中心窗体

	// 根据窗口大小设置场景边界
	QRect rt = rect(), sceneRange;
	sceneRange.setWidth(rt.width());
	sceneRange.setHeight(rt.height());
	pScene->setSceneRange(sceneRange);
	
	// 控制器初始化
	CTGlobal::instance()->getControler()->init();
}

void TankBattle::resizeEvent(QResizeEvent* event)
{
	CTScenePtr pScene = CTGlobal::instance()->getScene();
	if (pScene == nullptr)
	{
		return;
	}

	QSize rt = event->size();
	QRect sceneRange(0,0,0,0);
	sceneRange.setWidth(rt.width());
	sceneRange.setHeight(rt.height());
	pScene->setSceneRange(sceneRange);
}
