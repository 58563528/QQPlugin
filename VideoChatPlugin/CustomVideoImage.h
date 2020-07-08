#ifndef __CUSTOMVIDEOIMAGE__
#define __CUSTOMVIDEOIMAGE__

/// \brief �Զ�����ʾͼ��
class CustomVideoImage : public QLabel
{
public:
	/// \brief ���캯��
	/// \param[in] parent ������
	CustomVideoImage(QWidget* parent = 0);

	/// \brief ��������
	~CustomVideoImage();

	/// \brief ��ͼ��
	/// \param[in] TgtImage ͼ��
	void drawImage(const QImage& TgtImage);

	/// \brief ����ƶ��¼�
	/// \param[in] event ϵͳ����
	void mouseMoveEvent(QMouseEvent *event);

	/// \brief ������¼�
	/// \param[in] event ϵͳ����
	void mousePressEvent(QMouseEvent *event);

private:
	QPoint m_point;  ///< ��굱ǰλ��
	bool m_isPress;  ///< �����ʶ
};
#endif

