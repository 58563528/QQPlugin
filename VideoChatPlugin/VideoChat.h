#ifndef VIDEOCHAT_H
#define VIDEOCHAT_H

#include "AbstractWidget.h"
#include "ui_VideoChat.h"
#include "opencv.hpp"

using namespace cv;
class ProcessNetWork;

/// \brief ��Ƶͨ���࣬�̳п����
class VideoChat : public AbstractWidget
{
	Q_OBJECT

public:
	/// \brief ���캯��
	/// \param[in] parent ���캯��
	VideoChat(QWidget *parent = 0);

	/// \brief ��������
	~VideoChat();

	/// \brief ��ʾ�����ÿһ֡
	/// \param[in] event ϵͳ����
	void paintEvent(QPaintEvent *event);

	/// \brief ������Ƶ��
	/// \param[in] TgtImage ֡
	void ShowTgtImage(const QImage& TgtImage);

public slots:
	/// \brief ����ͼ��
	void UpdateImage();

private:
	Ui::VideoChat ui;
	Mat m_cvSrvImage;             ///< ֡
	VideoCapture m_cvVideo;       ///< ��Ƶ�ɼ�
	ProcessNetWork* m_pNetWork;
};

#endif // VIDEOCHAT_H
