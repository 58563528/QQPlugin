#include "stdafx.h"
#include "PluginControl.h"


std::vector<PluginInfo> PluginControl::m_VecPlugins;
PluginControl::PluginControl()
{
	SendPluginConfig();
}

PluginControl::~PluginControl() 
{

}

void PluginControl::SendPluginConfig()
{
	m_VecPlugins.emplace_back("ChatMessagePlugin", ".", QString::fromLocal8Bit("����"), false, QRect(100, 100, 800, 700));
	m_VecPlugins.emplace_back("FriendListPlugin", ".", "QQ", false, QRect(100, 100, 200, 800));
	m_VecPlugins.emplace_back("FtpSharesPlugin", ".", "ftp", false, QRect(100, 100, 500, 600));
	m_VecPlugins.emplace_back("LoginPlugin", ".", QString::fromLocal8Bit("��¼"), true, QRect(500, 300, 800, 700));
	m_VecPlugins.emplace_back("MailboxPlugin", ".", QString::fromLocal8Bit("�ʼ�"), false, QRect(500, 300, 700, 600));
	m_VecPlugins.emplace_back("QQSpacePlugin", ".", QString::fromLocal8Bit("QQ�ռ�"), false, QRect(200, 300, 300, 800));
	m_VecPlugins.emplace_back("VideoChatPlugin", ".", QString::fromLocal8Bit("��Ƶͨ��"), false, QRect(200, 300, 500, 800));
	
	SEND_SIGNAL(Signal_::MAKEPLUGINFILE, &m_VecPlugins);
}
