// TestLog4Cplus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

   
#include <log4cplus/logger.h>   
#include <log4cplus/fileappender.h>   
#include <log4cplus/consoleappender.h> 

#include <log4cplus\loggingmacros.h> 

#include <log4cplus/layout.h>   
using namespace log4cplus;   
using namespace log4cplus::helpers;  


int _tmain(int argc, _TCHAR* argv[])
{
// 	// ����һ���ļ�Appender   
//         SharedAppenderPtr pFileAppender(new FileAppender(_T("d:\\testlog.log")));   
//   
//         // ����Logger   
//         Logger pTestLogger = Logger::getInstance(_T("LoggerName"));      
//   
//         // ����Ҫ����Logger��Appender��ӵ�Logger��   
//         pTestLogger.addAppender(pFileAppender);   
//   
//         // �����־��Ϣ   
//         LOG4CPLUS_WARN(pTestLogger, "This is a <Warn> log message..."); 

		// ����1������̨��Appender,3���ļ�Appender   
       SharedAppenderPtr pConsoleAppender(new ConsoleAppender());   
       SharedAppenderPtr pFileAppender1(new FileAppender(_T("d:\\testlog1.log")));   
       SharedAppenderPtr pFileAppender2(new FileAppender(_T("d:\\testlog2.log")));   
       SharedAppenderPtr pFileAppender3(new FileAppender(_T("d:\\testlog3.log")));   
 
       // ����һ���򵥵�Layout,���󶨵� pFileAppender1   
       auto_ptr<Layout> pSimpleLayout(new SimpleLayout());   
       pFileAppender1->setLayout(pSimpleLayout);   
 
       // ����һ��TTCLayout,���󶨵� pFileAppender2   
       auto_ptr<Layout> pTTCLayout(new TTCCLayout());   
       pFileAppender2->setLayout(pTTCLayout);   
 
       // ����һ��PatternLayout,���󶨵� pFileAppender3   
       auto_ptr<Layout> pPatternLayout(new PatternLayout(_T("%d{%m/%d/%y %H:%M:%S}    - %m [%l]%n")));   
       pFileAppender3->setLayout(pPatternLayout);   
 
       // ����Logger   
       Logger pTestLogger = Logger::getInstance(_T("LoggerName"));      
 
       // ����Ҫ����Logger��Appender��ӵ�Logger��   
       pTestLogger.addAppender(pConsoleAppender);   
       pTestLogger.addAppender(pFileAppender1);   
       pTestLogger.addAppender(pFileAppender2);   
       pTestLogger.addAppender(pFileAppender3);   
 
       // �����־��Ϣ   
       LOG4CPLUS_WARN(pTestLogger, "This is a <Warn> log message...");   


	return 0;
}

