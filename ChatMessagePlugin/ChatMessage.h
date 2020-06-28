#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include "ui_ChatMessage.h"
#include "MacroDefine.h"
#include "ProcessChatMessage.h"
#include "sqlPlugin.h"
#include "AbstractWidget.h"
#include "../FriendListPlugin/FriendList.h"
#include "ChatMessage_global.h"

/// \brief ��Ϣ���ݽṹ��
struct Message_Content {
	Message_Content():type(Content_Type::text),is_Self(true) {}
	QString strContent;  ///< ��Ϣ��
    /// \brief ��Ϣ���Ͷ���
	enum class Content_Type {
		file,  ///< �ļ�
		image, ///< ͼƬ
		text   ///< �ı�
	};
	Content_Type type; ///< ��Ϣ����
	bool is_Self;  ///< �Ƿ������Լ����͵���Ϣ
};

using namespace sqlPlugin;

/// \brief ������湦�ܶ���
class CHATMESSAGEPLUGIN_EXPORT ChatMessage : public AbstractWidget
{
	Q_OBJECT

public:
    /// \brief ���캯��
    /// \param[in] parent ������
	ChatMessage(QWidget *parent = 0);

	/// \brief ����
	~ChatMessage();
	
	/// \brief ��ʼ�������¼����
	/// \param[in] targetMessage Ŀ��������Ϣ�ṹ
	/// \param[in] tab ��ʾ�����¼�ı��
	void InitChatMessage(const DataStructDefine& targetMessage, QTableWidget* tab);
	
	/// \brief ��ʼ�������¼UI
	/// \param[in] targetMessage Ŀ��������Ϣ�ṹ
	/// \param[in] tab ��ʾ�����¼�ı��
	void InitMessageUI(const QMap<quint64, QList<Message_Content>>& targetContent, QTableWidget* tab);

	/// \brief ���������Ϣ
	/// \param[in] strTgtNum �Է��˺�
	/// \param[in] strMsg ��Ϣ����
	void SetAddMessage(const QString strTgtNum, const QString strMsg);

	/// \brief ����������
	/// \param[in] pToolTgt �Է���Ϣ
	/// \param[in] strTgtNum �Է��˺�
	/// \param[in] strSelfNum �����˺�
	void SetAddChatTgt(QToolButton* pToolTgt, const QString& strTgtNum, const QString& strSelfNum);

	/// \brief ������Ϣ
	void OnMessage();

	/// \brief ���������¼
	void SaveChatRecord();

	/// \brief ����Բ��ͼ��ͷ��
	/// \param[in] src ԭͼ��
	/// \param[in] radius Բ��
	/// \retval ���ػ��ƺõ�
	QPixmap PixmapToRound(const QPixmap &src, int radius);

private slots:
	
    /// \brief ����������Ϣ 
    void SlotSendTextContent(); 

	/// \brief �л���������
	/// \param[in] current ��ǰ��
	/// \param[in] previous ֮ǰ��
	void SlotSwitchFriend(QListWidgetItem *current, QListWidgetItem *previous);

	/// \brief ��Ƶͨ��
	void SlotBtnVedio();

	/// \brief ����ͨ��
	void SlotBtnVoiceChat();

	/// \brief �ʼ�
	void SlotBtnMail();

	/// \brief ����
	void SlotBtnFace();

	/// \brief ��ͼ
	void SlotBtnScreenshot();

	/// \brief ��
	void SlotBtnVibration();

	/// \brief ����
	void SlotBtnVoice();

	/// \brief ����󶨻س����˵�
	/// \param[in] point ���λ��
	void SlotCustomMenu(const QPoint& point);

	/// \brief ����󶨻س����ۺ���
	/// \param[in] isClicked �����ʶ
	void SlotBindEnter(bool isClicked);

	/// \brief ����󶨻س����ۺ���
	/// \param[in] isClicked �����ʶ
	void SlotRemoveBindEnter(bool isClicked);

private:
	Ui::ChatMessage ui;		///< �������
	struct NumInfo
	{
		NumInfo() : m_unknowMessage(0), m_Friend_Group(true), m_isCurrent(false) {}
		NumInfo(bool Friend_Group, bool isCurrent, QString& strNum, quint32 unknowMessage)
			: m_Friend_Group(Friend_Group), m_isCurrent(isCurrent), m_strNum(strNum), m_unknowMessage(unknowMessage) {}
		bool m_Friend_Group;
		bool m_isCurrent;
		QString m_strNum;
		quint32 m_unknowMessage;
	};
	QString m_strSelfNum;       ///< �����˺�
	ProcessChatMessage* m_ProMsg;   ///< ������������ 
	QMap<QString, QTableWidget *> m_mapFriend_GroupTgt; ///< �˺�ӳ�䵽���������
	QMap<CustomToolButton *, NumInfo> m_mapFriend_Group;  ///< �ǵ��Ļ��Ƕ�������
};

/// \brief ���ݽ��涨��
class CustomMessageWidget : public QWidget {
public:
    /// \brief ���캯��
    /// \param[in] parent ������
	CustomMessageWidget(QWidget* parent = 0);
	~CustomMessageWidget();
  
    /// \brief ������Ϣ�ı�����
    /// \param[in] strContent ��Ϣ
    /// \param[in] isSelf �Ƿ����Լ�����Ϣ
	void SetText(const QString& strContent, bool isSelf);
    
    /// \brief �������꣬������������
    /// \paran[in] event ϵͳ����
	void paintEvent(QPaintEvent* event);

	QString m_strContent;           ///< ��Ϣ��
	QTextEdit* m_pMessageContent;    ///< ����
    QTableWidget* m_pTargetTab;      ///< ���������ı��
};



#endif // CHATMESSAGE_H
