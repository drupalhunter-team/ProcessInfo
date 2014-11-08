
/*
 *�ο� http://zhangyafeikimi.iteye.com/blog/378658
 */

#ifndef INFO_H
#define INFO_H

#include <windows.h>  
#include <psapi.h>  
#include <assert.h> 
#include <tlhelp32.h>
#include <stdio.h>

typedef long long           int64_t;  
typedef unsigned long long  uint64_t; 

//cpu����  
static int processor_count_ = 0;

class ProcInfo
{
public:
	ProcInfo(wchar_t* name);
	~ProcInfo();


public:
	//��ȡ��ǰ���̵�cpuʹ���ʣ�����-1ʧ��  
	int get_cpu_usage();  

	//��ȡ��ǰ�����ڴ�������ڴ�ʹ����������-1ʧ�ܣ�0�ɹ�  
	int get_memory_usage(uint64_t* mem, uint64_t* vmem);  

	//��ȡ��ǰ�����ܹ�����д��IO�ֽ���������-1ʧ�ܣ�0�ɹ�  
	int get_io_bytes(uint64_t* read_bytes, uint64_t* write_bytes); 

	//ʱ��ת��  
	static uint64_t file_time_2_utc(const FILETIME* ftime);

	//���CPU�ĺ���  
	static int get_processor_number();

	HANDLE GetProcessHandle(int nID);

	HANDLE GetProcessHandleByName(wchar_t* pName);

	void SetEXEName(wchar_t* name) { m_wstrEXEName = name; }
	wchar_t* GetEXEName() { return m_wstrEXEName; }

	HANDLE GetHandle() { return m_Handle; }
	bool SetHandle();
	bool CheckHandle();

	void Clear();

private:
	wchar_t*	m_wstrEXEName;
	HANDLE		m_Handle;
};


#endif