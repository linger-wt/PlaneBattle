#pragma once
#include <objbase.h>
#include <QPointF>
#include <QGraphicsPixmapItem>

/* 实体类 */
class CTEntity
{
public:
	/* 阵营 */
	enum Camp
	{
		Red = 0, // 红方
		Blue = 1, // 蓝方
	};

	CTEntity(void);
	~CTEntity(void);

	/* 获取实体ID */
	GUID getID();

	/* 实体位置 */
	QPointF getPos();
	void setPos(QPointF point);

	/* 实体大小 */
	QSize getSize();
	void setSize(QSize size);

	/* 设置实体图标 */
	QString getIconPath();
	void setIconPath(QString iconPath);

	/* 实体阵营 */
	Camp getCamp();
	void setCamp(Camp camp);

private:
	GUID m_id; // 实体ID
	QPointF m_pos; // 实体位置
	QSize m_size; // 实体大小
	Camp m_camp; // 实体阵营
	QString m_iconPath; // 实体图标路径
};

typedef std::shared_ptr<CTEntity> CTEntityPtr;
typedef std::list<CTEntityPtr> CTEntityList;