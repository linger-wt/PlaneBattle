#pragma once
#include "TEntity.h"
#include "TSceneItem.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QRectF>
#include <QTimer>

/* 场景类 */
class CTScene : public QGraphicsScene
{
	Q_OBJECT

public:
	CTScene(void);
	~CTScene(void);

	/* 设置场景边界 */
	void setSceneRange(QRectF rect);

	/* 实体坐标到场景坐标的转换 */
	QPointF coordinateEntityToScene(QPointF pos);

	/* 场景坐标到实体坐标的转换 */
	QPointF coordinateSceneToEntity(QPointF pos);

	/* 增加item，与现有实体绑定 */
	void addItemToScene(CTEntityPtr entity);

	/* 键盘敲击事件 */
	void keyPressEvent(QKeyEvent* event);
	
	/* 键盘释放事件 */
	void keyReleaseEvent(QKeyEvent* event);

	/* 获取控制者（红方实体，只有一个） */
	CTSceneItem* getControler();

private slots:
	/* 控制者定时器响应函数 */
	void onControlerTimer();

	/* 刷新定时器相应函数 */ 
	void onRefreshTimer();

private:
	QRectF m_rect; // 场景边界
	
	QTimer m_controlerTimer; // 控制者定时器
	QTimer m_refreshTimer; // 刷新定时器

	bool m_bLeftMove; // 左移标志位
	bool m_bRightMove; // 右移标志位
	bool m_bUpMove; // 上移标志位
	bool m_bDownMove; // 下移标志位

	CTEntityPtr m_pControlerEntity; // 控制者实体
};

typedef std::shared_ptr<CTScene> CTScenePtr;

