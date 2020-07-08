#ifndef VIDEOCHAT_H
#define VIDEOCHAT_H

#include "AbstractWidget.h"
#include "ui_VideoChat.h"
#include "opencv.hpp"
#include "CustomVideoImage.h"

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

	/// \brief �����û�����Ϣ��ʾ�ڽ�����
	/// ������ʾ
	/// \param[in] strNum �û��˺�
	void FintTgtNum(const QString& strNum);

	/// \brief ����Բ��ͼ��ͷ��
	/// \param[in] src ԭͼ��
	/// \param[in] radius Բ��
	/// \retval ���ػ��ƺõ�
	QPixmap PixmapToRound(const QPixmap &src, int radius);

	/// \brief �ر��¼�
	/// \param[in] event ϵͳ����
	void closeEvent(QCloseEvent *event);

	/// \brief ˢ�¶Է�ͼ��
	/// \param[in] image ֡
	void RefreshImage(const QImage& image);

public slots:
	/// \brief ����ͼ��
	void SlotUpdateImage();

	void SlotConsent();

	void SlotRejective();

private:
	Ui::VideoChat ui;
	Mat m_cvSrvImage;             ///< ֡
	VideoCapture m_cvVideo;       ///< ��Ƶ�ɼ�
	ProcessNetWork* m_pNetWork;   ///< ������������
	QTimer* m_pTimer;             ///< ��ʱ��ˢ��ͼ��
	QString m_strSelf;            ///< �����˺�
	QString m_strTgtNum;		  ///< �Է��˺�
	CustomVideoImage* m_CustomImage; ///< �Է�����Ƶ����
};

#endif // VIDEOCHAT_H
