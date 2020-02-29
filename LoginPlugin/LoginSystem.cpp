#include "stdafx1.h"
#include "LoginSystem.h"
#include "SqlDefine.h"
#include <QTypeInfo>

LoginSystem::LoginSystem(QWidget *parent) {
	ui.setupUi(this);
	connect(ui.BtnLogin, SIGNAL(clicked()), this, SLOT(SlotLogin()));
	connect(ui.BtnRegister, SIGNAL(clicked()), this, SLOT(SlotRegister()));
	connect(ui.BtnBackPassWD, SIGNAL(clicked()), this, SLOT(SlotBackPassWD()));
}

LoginSystem::~LoginSystem() {

}

void LoginSystem::SlotBackPassWD() {
	//hide();
	//�����һ��������
	
//	test();

}

void LoginSystem::SlotRegister() {
	hide();
	//����ע�����
	m_Register = new Register(this);
	SEND_SIGNAL(Signal_::RELOADUI, m_Register);
}

void LoginSystem::SlotLogin() {
	SEND_SIGNAL(Signal_::SWITCHPLUGIN, "FriendListPlugin");
	return;
	DataLib Data;
	if (Data.openDataLib()) {
		DataStructDefine UserData = DBSelect::GetDataLib(QString(SELECT_USER)
			.arg(ui.ComUserName->currentText()));
		if (UserData.m_lstAllData.isEmpty()) {
			QMessageBox::warning(this, QString::fromLocal8Bit("����"),
				QString::fromLocal8Bit("�˺��������"));
			return;
		} 
		if (UserData.m_lstAllData[0]["PASSWORD"].toString()
			!= ui.EditPassWd->text()) {
			QMessageBox::warning(this, QString::fromLocal8Bit("����"),
				QString::fromLocal8Bit("�����������"));
			return;
		}
		SEND_SIGNAL(Signal_::SWITCHPLUGIN, "FriendListPlugin");
	} 
	else
		QMessageBox::warning(this, QString::fromLocal8Bit("����"),
			QString::fromLocal8Bit("��������ʧ�ܣ�"));
}

