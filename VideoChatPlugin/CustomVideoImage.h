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
};

#endif

