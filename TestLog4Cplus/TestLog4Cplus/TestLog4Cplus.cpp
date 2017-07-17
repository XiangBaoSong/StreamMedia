// TestLog4Cplus.cpp : 定义控制台应用程序的入口点。
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
// 	// 定义一个文件Appender   
//         SharedAppenderPtr pFileAppender(new FileAppender(_T("d:\\testlog.log")));   
//   
//         // 定义Logger   
//         Logger pTestLogger = Logger::getInstance(_T("LoggerName"));      
//   
//         // 将需要关联Logger的Appender添加到Logger上   
//         pTestLogger.addAppender(pFileAppender);   
//   
//         // 输出日志信息   
//         LOG4CPLUS_WARN(pTestLogger, "This is a <Warn> log message..."); 

		// 定义1个控制台的Appender,3个文件Appender   
       SharedAppenderPtr pConsoleAppender(new ConsoleAppender());   
       SharedAppenderPtr pFileAppender1(new FileAppender(_T("d:\\testlog1.log")));   
       SharedAppenderPtr pFileAppender2(new FileAppender(_T("d:\\testlog2.log")));   
       SharedAppenderPtr pFileAppender3(new FileAppender(_T("d:\\testlog3.log")));   
 
       // 定义一个简单的Layout,并绑定到 pFileAppender1   
       auto_ptr<Layout> pSimpleLayout(new SimpleLayout());   
       pFileAppender1->setLayout(pSimpleLayout);   
 
       // 定义一个TTCLayout,并绑定到 pFileAppender2   
       auto_ptr<Layout> pTTCLayout(new TTCCLayout());   
       pFileAppender2->setLayout(pTTCLayout);   
 
       // 定义一个PatternLayout,并绑定到 pFileAppender3   
       auto_ptr<Layout> pPatternLayout(new PatternLayout(_T("%d{%m/%d/%y %H:%M:%S}    - %m [%l]%n")));   
       pFileAppender3->setLayout(pPatternLayout);   
 
       // 定义Logger   
       Logger pTestLogger = Logger::getInstance(_T("LoggerName"));      
 
       // 将需要关联Logger的Appender添加到Logger上   
       pTestLogger.addAppender(pConsoleAppender);   
       pTestLogger.addAppender(pFileAppender1);   
       pTestLogger.addAppender(pFileAppender2);   
       pTestLogger.addAppender(pFileAppender3);   
 
       // 输出日志信息   
       LOG4CPLUS_WARN(pTestLogger, "This is a <Warn> log message...");   


	return 0;
}

