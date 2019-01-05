#include "TScene.h"
#include "TGlobal.h"

Q_DECLARE_METATYPE(GUID)

CTScene::CTScene(void)
	: m_pControlerEntity(nullptr)
{
}

CTScene::~CTScene(void)
{
}

void CTScene::setSceneRange(QRectF rect)
{
	m_rect = rect;
}

QPointF CTScene::coordinateEntityToScene(QPointF pos)
{
	// 我们定义实体坐标系以场景区域的下边界中间位置为原点(0,0)，红方实体的初始位置
	// 实际上场景的坐标原点(0,0)在场景的左上角位置
	// 因此这两个坐标系同时描述一个物体时就需要进行坐标转换
	// 转换方式：entityPos+QPointF(rect.width/2.0, rect.height)
	return pos + QPointF(m_rect.width()/2.0 ,m_rect.height());
}

void CTScene::addItemToScene(CTEntityPtr entity)
{
	// 根据实体创建对应的item
	CTSceneItem* pItem = new CTSceneItem(entity);
	pItem->setPos(coordinateEntityToScene(entity->getPos())); // 将实体的位置进行坐标转换后设置为item的位置
	
	// 将item加入到场景中
	addItem(pItem);
}

void CTScene::keyPressEvent(QKeyEvent* event)
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

void CTScene::keyReleaseEvent(QKeyEvent* event)
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

CTSceneItem* CTScene::getControler()
{
	CTSceneItem* redEntity = nullptr;
	QList<QGraphicsItem *> itemList = items();
	for each(auto item in itemList)
	{
		GUID id = item->data(DATA_USERID).value<GUID>();
		CTEntityPtr pEntity = CTGlobal::instance()->getModelManager()->getEntityByID(id);
		if (pEntity)
		{
			CTEntity::Camp camp = pEntity->getCamp();
			if (camp == CTEntity::Red)
			{
				redEntity = (CTSceneItem*)item;
				break;
			}
		}
	}
	return redEntity;
}

void CTScene::onControlerTimer()
{
	// 控制者定时器中只根据用户操作修改实体数据
	if (m_pControlerEntity == nullptr)
	{
		CTEntityList entityList = CTGlobal::instance()->getModelManager()->getEntityList();
		auto res = std::find_if(entityList.begin(), entityList.end(), [](CTEntityPtr pEntity){return pEntity->getCamp() == CTEntity::Red;});
		if (res == entityList.end())
		{
			return;
		}
		m_pControlerEntity = *res;
	}
	// 获取实体当前位置
	QPointF pt = m_pControlerEntity->getPos();
	// 位置变化量
	QPoint dpt;
	if (m_bLeftMove && pt.x()>0)
	{
		dpt.setX(-5);
	}
	
	QSize itemSize= m_pControlerEntity->getSize();
	QRectF screenRect = sceneRect();
	if (m_bRightMove && pt.x()<screenRect.width()-itemSize.width())
	{
		dpt.setX(5);
	}
	if (m_bUpMove && pt.y()>0)
	{
		dpt.setY(-5);
	}
	if (m_bDownMove && pt.y()<screenRect.height()-itemSize.height())
	{
		dpt.setY(5);
	}
	pt = pt + dpt;
	m_pControlerEntity->setPos(pt);
}

void CTScene::onRefreshTimer()
{
	// 刷新定时器负责将所有实体数据刷新至所对应的item
}
