#include "stdafx.h"
#include "PluginControl.h"

QVector<PluginInfo> PluginControl::m_VecPlugins;
PluginControl::PluginControl()
{
	SendPluginConfig();
}

PluginControl::~PluginControl() 
{

}

void PluginControl::SendPluginConfig()
{
	PluginInfo ChatMessagePlugin("ChatMessagePlugin", ".", QString::fromLocal8Bit("����"), false, QRect(100, 100, 800, 700));

	PluginInfo FriendListPlugin("FriendListPlugin", ".", "QQ", false, QRect(100, 100, 200, 800));

	PluginInfo FtpSharesPlugin("FtpSharesPlugin", ".", "ftp", false, QRect(100, 100, 500, 600));

	PluginInfo LoginPlugin("LoginPlugin", ".", QString::fromLocal8Bit("��¼"), true, QRect(500, 300, 800, 700));
	PluginInfo::ChildProject child1;
	child1.m_ChildName = QString::fromLocal8Bit("ע��");
	child1.m_rPosition = QRect(100, 100, 200, 800);
	child1.m_strTitle = QString::fromLocal8Bit("ע��");
	PluginInfo::ChildProject child2;
	child2.m_ChildName = QString::fromLocal8Bit("�һ�����");
	child2.m_rPosition = QRect(100, 100, 600, 700);
	child2.m_strTitle = QString::fromLocal8Bit("�һ�����");
	LoginPlugin.m_VecChild.append(child1);

	PluginInfo MailboxPlugin("MailboxPlugin", ".", QString::fromLocal8Bit("�ʼ�"), false, QRect(500, 300, 700, 600));

	PluginInfo QQSpacePlugin("QQSpacePlugin", ".", QString::fromLocal8Bit("QQ�ռ�"), false, QRect(200, 300, 300, 800));

	PluginInfo VideoChatPlugin("VideoChatPlugin", ".", QString::fromLocal8Bit("��Ƶͨ��"), false, QRect(200, 300, 500, 800));

	m_VecPlugins.append(ChatMessagePlugin);
	m_VecPlugins.append(FriendListPlugin);
	m_VecPlugins.append(FtpSharesPlugin);
	m_VecPlugins.append(LoginPlugin);
	m_VecPlugins.append(MailboxPlugin);
	m_VecPlugins.append(QQSpacePlugin);
	m_VecPlugins.append(VideoChatPlugin);
	SENDMESSAGE(Signal_::MAKEPLUGINFILE, &m_VecPlugins);
	//while (1);
}
