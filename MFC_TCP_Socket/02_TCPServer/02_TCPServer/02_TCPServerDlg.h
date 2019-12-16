
// 02_TCPServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ServerSocket.h"

// CMy02_TCPServerDlg �Ի���
class CMy02_TCPServerDlg : public CDialogEx
{
// ����
public:
	CMy02_TCPServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY02_TCPSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	UINT m_port;
	CButton m_startBtn;
	CButton m_stopBtn;
	CButton m_clearBtn;
	CListCtrl m_listCtrl;
	CServerSocket m_serverSocket;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	// ����Ϣ�б������һ����Ϣ
	void AddMsg(CString msg);
	
};
