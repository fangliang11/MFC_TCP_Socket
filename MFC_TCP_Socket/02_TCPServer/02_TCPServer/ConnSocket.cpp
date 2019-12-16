// ConnSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "02_TCPServer.h"
#include "ConnSocket.h"

#include "02_TCPServerDlg.h"

// CConnSocket

CConnSocket::CConnSocket(CMy02_TCPServerDlg* dlg)
{
	m_dlg = dlg;
}

CConnSocket::~CConnSocket()
{
}


// CConnSocket ��Ա����

// ���������Ϳͻ��˳ɹ����������ӣ����������Զ����ô˺���
void CConnSocket::OnSend(int nErrorCode)
{
	// �������ɿ�ܵ��ã�֪ͨ�׽������ڿ��Ե���Send��Ա�������������ˡ�
	char buf[] = "your connect success";
	Send(buf, strlen(buf)); //���ͻ��˷�����Ϣ
	CSocket::OnSend(nErrorCode);
}

// ���Է�������Ϣ���Զ����ô˺���
// �����ں������������մ���
void CConnSocket::OnReceive(int nErrorCode)
{
	// �������ɿ�ܵ��ã�֪ͨ�׽��ֻ����������ݣ����Ե���Receive��Ա����ȡ��
	char recvBuf[512] = { 0 };
	int recvLen = this->Receive(recvBuf, sizeof(recvBuf));
	CString msg;
	SYSTEMTIME t;
	GetLocalTime(&t);
	msg.Format(_T("[%d:%d:%d] %s:%d: %s"),t.wHour,t.wMinute,t.wSecond, m_ip, m_port,CString(recvBuf));
	m_dlg->AddMsg(msg);
	// ������Ϣ
	CharUpperA(recvBuf);
	this->Send(recvBuf, strlen(recvBuf));
}

// �Է������Ͽ����ӣ��Զ����ô˺���
void CConnSocket::OnClose(int nErrorCode)
{
	CString msg;
	SYSTEMTIME t;
	GetLocalTime(&t);
	msg.Format(_T("[%d:%d:%d] %s:%d: already close!"), t.wHour,t.wMinute,t.wSecond,m_ip, m_port);
	m_dlg->AddMsg(msg);
	CSocket::OnClose(nErrorCode);
}

void CConnSocket::SetClientAddr(CString ip, USHORT port)
{
	m_ip = ip;
	m_port = port;
}
