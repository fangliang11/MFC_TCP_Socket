// ServerSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "02_TCPServer.h"
#include "ServerSocket.h"

#include "02_TCPServerDlg.h"

// CServerSocket

CServerSocket::CServerSocket(CMy02_TCPServerDlg* dlg)
{
	m_dlg = dlg;
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket ��Ա����

// �µ������������ˣ��ú��������ص�
void CServerSocket::OnAccept(int nErrorCode)
{
	// �ɿ�ܵ��ã�֪ͨ�����׽������ڿ��Ե���Accept��Ա�������������ҵģ�pending����������
	CConnSocket * client = new CConnSocket(m_dlg);
	SOCKADDR_IN addr;
	memset(&addr, 0, sizeof(addr));
	int addrLen = sizeof(addr);

	// ��ȡͨ���׽���
	Accept(*client,(SOCKADDR*)&addr,&addrLen);
	char* ip = inet_ntoa(addr.sin_addr);
	client->SetClientAddr(CString(ip), addr.sin_port);
	m_clientList.push_back(client);

	// �������������Ϣ
	CString msg;
	SYSTEMTIME t;
	GetLocalTime(&t);
	msg.Format(_T("[%d:%d:%d] %s:%d: connect success!"),t.wHour,t.wMinute,t.wSecond,CString(ip),addr.sin_port);
	m_dlg->AddMsg(msg);

	CSocket::OnAccept(nErrorCode);
}

void CServerSocket::CloseAllConn()
{
	// �رռ����׽��֣��ȹر� ���ӵ��׽���
	list<CConnSocket*>::iterator it = m_clientList.begin();
	for (; it != m_clientList.end(); )
	{
		(*it)->Close();
		delete (*it);
		it = m_clientList.erase(it);
	}
	this->Close();
}