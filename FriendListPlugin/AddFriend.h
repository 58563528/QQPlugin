#ifndef       __ADDFRIEND__
#define       __ADDFRIEND__
#include "AbstractWidget.h"
#include "ui_AddFriend.h"
#include "ApplyJoinFriend.h"

/// \brief �û���Ϣ����
struct TargetInfor
{
	quint32 m_Age;				///< ����
	quint32 memberCount;        ///< Ⱥ��Ա����
	QString m_strGroupType;     ///< Ⱥ������
	QString m_Occupational;		///< ְҵ
	QString m_Address;			///< ��ַ
	QString m_strNumber;		///< �˺�
	QString m_strSchool;        ///< ��ҵԺУ
	QString m_strBirthPlace;	///< ����
	QString m_strName;          ///< �û�����
	QString m_Gender;           ///< �Ա�
	QPixmap pix;                ///< ͷ��
	bool m_IsFriend;            ///< �û�����Ⱥ

};

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
	/// \param[in] infor Ŀ����Ϣ
	/// \param[in] parent ������
	CustomAddInformationWidget(TargetInfor& infor, AbstractWidget* parent = 0);

	/// \brief ���캯��
	/// \param[in] parent ������
	CustomAddInformationWidget(AbstractWidget* parent = 0);

	/// \brief ��������
	~CustomAddInformationWidget();

	/// \brief ��������
	/// \param[in] event ϵͳ����
	void paintEvent(QPaintEvent *event);

private slots:

	/// \brief ��ʾĿ����Ϣ
	void TgtInfor();

	/// \brief ȷ�����
	void Add();
private:
	QPushButton* m_BtnAddButton;
	QToolButton* m_BtnTgtInfo;
	ApplyJoinFriend* m_Apply;
	TargetInfor m_Infor;
	AbstractWidget* m_UserWidget;
};
#endif
