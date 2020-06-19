#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include "ui_FriendList.h"
#include "MacroDefine.h"
#include "friendlistplugin_global.h"
#include "AbstractNetWork.h"
#include "NetProtocConfig.pb.h"
#include "SqlStatementDefine.h"
#include "NetProtocConfig.pb.h"
#include "AbstractWidget.h"

class FRIENDLISTPLUGIN_EXPORT FriendList : public AbstractWidget
{
	Q_OBJECT

public:
	FriendList(QWidget *parent = 0);
	~FriendList();
	/// \brief ����¼��ʱ��ָ���������
	void RecoveryChatRecord();

	/// \brief ���ú����б����
	/// \param[in] strName ���ѵ��û�����
	/// \param[in] byteImage ���ѵ�ͷ��
	void SetMessage_ListUi(const QString& strName, const QByteArray& byteImage);

	/// \brief ��ͼ�¼�
	/// ����δ����Ϣ����������������Ϣ��Ϣ������
	/// \param[in] event ϵͳ����
	void paintEvent(QPaintEvent *event);

	/// \brief ��ʼ�������б�
	void InitFriendList();

	/// \brief ��ʼ��Ⱥ��
	void InitGroupList();

	/// \brief ��ʼ��QQ�ռ�
	void InitQQSpaceList();

	/// \brief ����Բ��ͼ��ͷ��
	/// \param[in] src ԭͼ��
	/// \param[in] radius Բ��
	/// \retval ���ػ��ƺõ�
	QPixmap PixmapToRound(const QPixmap &src, int radius);
private slots:
	/// \brief ��ʼ����
	void StartChat();

	/// \brief Ⱥ������
	void StartGroupChat();
private:
	Ui::FriendList ui;
	QString* m_pUserNumber;    ///< �����˺�
	QMap<QToolButton *, QString> m_mapGroup;    ///< Ⱥ��ӳ��
	QMap<QToolButton *, QString> m_mapFriend;   ///< ����ӳ��
};

#endif // FRIENDLIST_H
