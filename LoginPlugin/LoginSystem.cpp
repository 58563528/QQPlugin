#include "stdafx1.h"
#include "LoginSystem.h"
#include "SqlDefine.h"

LoginSystem::LoginSystem(QWidget *parent)
	: QWidget(parent) {
	ui.setupUi(this);
	connect(ui.BtnLogin, SIGNAL(clicked()), this, SLOT(SlotLogin()));
	connect(ui.BtnRegister, SIGNAL(clicked()), this, SLOT(SlotRegister()));
	connect(ui.BtnBackPassWD, SIGNAL(clicked()), this, SLOT(SlotBackPassWD()));
}

LoginSystem::~LoginSystem() {

}

void LoginSystem::SlotBackPassWD() {
	hide();
	//�����һ��������


}

void LoginSystem::SlotRegister() {
	hide();
	//����ע�����
	m_Register = new Register(this);
	//m_Register->show();
}

void LoginSystem::SlotLogin() {
	
}

void LoginSystem::setSqlDataBase() {
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
		//����������
		SENDMESSAGE(Signal_::FREEPLUG, "LoginPlugin");
		SENDMESSAGE(Signal_::LOADPLUG, "FriendListPlugin");
	} 
	else
		QMessageBox::warning(this, QString::fromLocal8Bit("����"),
			QString::fromLocal8Bit("��������ʧ�ܣ�"));
}
