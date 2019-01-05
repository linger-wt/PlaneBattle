#pragma once
#include "TEntity.h"
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

#define DATA_USERID	Qt::UserRole+1

/* 场景中的item
   每个item都有一个定时器，用来进行碰撞检测
*/
class CTSceneItem : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	CTSceneItem(CTEntityPtr pEntity); // 每个item和一个实体绑定
	~CTSceneItem();

private slots:
	/* 碰撞检测timer响应函数 */
	void onHitChectTimer();

private:
	QTimer m_hitCheckTimer; // 碰撞检测timer
};

typedef std::shared_ptr<CTSceneItem> CTSceneItemPtr;


