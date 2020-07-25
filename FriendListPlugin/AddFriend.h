#ifndef       __ADDFRIEND__
#define       __ADDFRIEND__


#include "AbstractWidget.h"
#include "ui_AddFriend.h"
#include "ApplyJoinFriend.h"

/// \brief �����ṩ����Ӻ��Ѻ����Ⱥ��Ĺ���
class AddFriend : public AbstractWidget
{
	Q_OBJECT

public:
	/// \brief ���캯��
	/// \param[in] isAddFriend �Ƿ�Ϊ��Ӻ��ѣ�����Ϊ���Ⱥ��
	/// \param[in] parent ������
	AddFriend(bool isAddFriend, AbstractWidget *parent = Q_NULLPTR);

	/// \brief ��������
	~AddFriend();

private slots:

	/// \brief ���Һ���
	void SlotFindFriend();

	/// \brief ����Ⱥ��
	void SlotFineGroup();

	/// \brief ��ʼ����
	void SlotStartFind();

	/// \brief ������ѿ�ʼ���
	/// \param[in] row ��
	/// \param[in] col ��
	void SlotClickFriend(int row,int col);

	/// \brief ����Ⱥ�������
	void SlotGroupType();

	/// \brief ����ѡ������
	/// \param[in] state ״̬
	void ChangedSelectCondition(int state);

private:
	Ui::AddFriend ui;
	bool m_isAddFriend;  ///< ��Ӻ��ѱ�ʶ
};

/// \brief �Զ��������Ϣ���棬�ڱ������ʾĿ�����Ϣ
class CustomAddInformationWidget : public AbstractWidget {
	Q_OBJECT
public:
	/// \brief ���캯��
	/// \param[in] strName �û�����
	/// \param[in] strAttr �û�����
	/// \param[in] arrayImage ͼ������
	/// \param[in] parent ������
	CustomAddInformationWidget(QString strName, QString strAttr, QByteArray& arrayImage, bool isFriend, AbstractWidget* parent = 0);

	/// \brief ���캯��
	/// \param[in] parent ������
	CustomAddInformationWidget(AbstractWidget* parent = 0);

	/// \brief ��������
	~CustomAddInformationWidget();

	/// \brief ��������
	/// \param[in] event ϵͳ����
	void paintEvent(QPaintEvent *event);

	/// \brief �����û�����
	/// \param[in] strName �û�����
	/// \param[in] strAttr �û�����
	/// \param[in] arrayImage ͼ������
	void SetAttribute(QString strName, QString strAttr, QByteArray& arrayImage);

private slots:

	/// \brief ��ʾĿ����Ϣ
	void TgtInfor();

	/// \brief ȷ�����
	void Add();
private:
	QPushButton* m_BtnAddButton;
	QToolButton* m_BtnTgtInfo;
	QString m_strUserName;
	QString m_ExtraParam;
	QPixmap m_Pixmap;
	ApplyJoinFriend* m_Apply;
	bool m_IsFriend;
	AbstractWidget* m_UserWidget;
};


#endif
