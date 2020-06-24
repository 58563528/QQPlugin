#ifndef  PROCESSMASSAGE_H__
#define  PROCESSMASSAGE_H__
#include "AbstractNetWork.h"
class ProsessMessage : public AbstractNetWork
{
public:
	ProsessMessage(AbstractNetWork::ProtoType Type, QHostAddress addr, int port, QObject* parent = 0);
	~ProsessMessage();

	int RecvMessage();
	
	/// \brief ����Э��
	/// \param[in] protocol ԭЭ������
	void AnalysisProtocol(QByteArray& protocol);

};

#endif
