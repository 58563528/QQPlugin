#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include "ui_ChatMessage.h"
#include "MacroDefine.h"
#include "ProcessChatMessage.h"
#include "sqlPlugin.h"
#include "AbstractWidget.h"
#include <QToolButton>


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
class ChatMessage : public AbstractWidget
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
	void InitChatMessage(const DataStructDefine& targetMessage);
	
	/// \brief ��ʼ�������¼UI
	/// \param[in] targetMessage Ŀ��������Ϣ�ṹ
	void InitMessageUI(const QMap<quint64, QList<Message_Content>>& targetContent);

	/// \brief ���������Ϣ
	/// \param[in] strMsg ��Ϣ����
	void SetAddMessage(QString strMsg);

	/// \brief ����������
	/// \param[in] pToolTgt �Է���Ϣ
	void SetAddChatTgt(QToolButton* pToolTgt);

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
    void SendTextContent(); 

	/// \brief �л���������
	/// \param[in] current ��ǰ��
	/// \param[in] previous ֮ǰ��
	void SwitchFriend(QListWidgetItem *current, QListWidgetItem *previous);

private:
	Ui::ChatMessage ui;		///< �������
	ProcessChatMessage* m_ProMsg;   ///< ������������ 
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
