#pragma once
//#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include  "ConnSocket.h"

#include <list>
using namespace std;
// CServerSocket ����Ŀ��
class CMy02_TCPServerDlg;
class CServerSocket : public CSocket
{
public:
	CServerSocket(CMy02_TCPServerDlg* dlg = NULL);
	virtual ~CServerSocket();
	// ���ܵ��ͻ������ӵ� �ص�����
	virtual void OnAccept(int nErrorCode);
	// �ر����������׽���
	void CloseAllConn();
private:
	CMy02_TCPServerDlg* m_dlg;
	list<CConnSocket*> m_clientList;
public:
};


