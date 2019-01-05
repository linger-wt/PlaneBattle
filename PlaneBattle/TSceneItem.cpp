
#include "TSceneItem.h"
Q_DECLARE_METATYPE(GUID)

CTSceneItem::CTSceneItem(CTEntityPtr pEntity)
{
	setData(DATA_USERID, QVariant::fromValue<GUID>(pEntity->getID())); // 将item的用户数据设置为实体ID
	
	// 设置item图标
	QPixmap pix = QPixmap("plane_icon.png");
	// 根据图标比例调整实体大小（宽度固定，只调整高度）
	int entityWidth = pEntity->getSize().width(); // 实体宽度
	QSize size;
	size.setWidth(entityWidth);
	size.setHeight(pix.height()/(float)pix.width()*entityWidth);
	pEntity->setSize(size);
	pix.scaled(pEntity->getSize(), Qt::KeepAspectRatio); // 图标根据实体大小进行缩放
	setPixmap(pix); // 设置图标

	connect(&m_hitCheckTimer, SIGNAL(timeout()), this, SLOT(onHitChectTimer()));
	m_hitCheckTimer.start(17); // 每一帧（17ms）都进行一次碰撞检测
}

CTSceneItem::~CTSceneItem()
{
	m_hitCheckTimer.stop();
}

void CTSceneItem::onHitChectTimer()
{
	QList<QGraphicsItem*> items = collidingItems(); // 获取和当前item碰撞的item列表
	if (items.size() <= 0)
	{
		return;
	}

	// 如果有和自己碰撞的item，则当前item改变状态
	// 当前item是武器：自爆（实体生命值置为0）
	// 当前item是飞机：如果碰撞者是武器，则根据武器伤害度减少实体生命值；如果碰撞者是飞机，则自爆（实体生命值置为0）
	
	// 修改实体属性的逻辑应该放到什么位置处理？？放到此处处理是否违背MVC设计原则，如果不在此处处理，那如何让控制器介入
}
