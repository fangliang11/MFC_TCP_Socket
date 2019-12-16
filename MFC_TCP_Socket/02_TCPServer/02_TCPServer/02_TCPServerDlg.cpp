
// 02_TCPServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "02_TCPServer.h"
#include "02_TCPServerDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02_TCPServerDlg �Ի���



CMy02_TCPServerDlg::CMy02_TCPServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY02_TCPSERVER_DIALOG, pParent)
	, m_port(0), m_serverSocket(this)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy02_TCPServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_port);
	DDX_Control(pDX, IDC_BUTTON1, m_startBtn);
	DDX_Control(pDX, IDC_BUTTON2, m_stopBtn);
	DDX_Control(pDX, IDC_BUTTON3, m_clearBtn);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CMy02_TCPServerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CMy02_TCPServerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy02_TCPServerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy02_TCPServerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMy02_TCPServerDlg ��Ϣ�������

BOOL CMy02_TCPServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_port = 8888;// �������˿�
	m_stopBtn.EnableWindow(FALSE);
	UpdateData(FALSE);
	//m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy02_TCPServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy02_TCPServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// �����Ϣ�б�
void CMy02_TCPServerDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_listCtrl.DeleteAllItems();
	//m_serverSocket.SendMsg(_T("aaaa"));
}

// ����������
void CMy02_TCPServerDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	BOOL ret = m_serverSocket.Create(m_port, SOCK_STREAM);
	if (ret)
	{
		
		ret = m_serverSocket.Listen();
		if (ret)
		{
			//m_serverSocket.a
			m_startBtn.EnableWindow(FALSE);
			m_stopBtn.EnableWindow(TRUE);
			return;
		}
		else
		{
			MessageBox(_T("�����׽��ּ���ʧ��"));
		}
	}
	else 
	{
		MessageBox(_T("���������׽���ʧ��"));
	}
	m_startBtn.EnableWindow(TRUE);
	m_stopBtn.EnableWindow(FALSE);
}

// ֹͣ������
void CMy02_TCPServerDlg::OnBnClickedButton2()
{
	m_serverSocket.CloseAllConn();
	m_startBtn.EnableWindow(TRUE);
	m_stopBtn.EnableWindow(FALSE);
}

void CMy02_TCPServerDlg::AddMsg(CString msg)
{
	m_listCtrl.InsertItem(0, msg);
}
