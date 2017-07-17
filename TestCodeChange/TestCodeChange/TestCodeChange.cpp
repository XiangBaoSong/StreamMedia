// TestCodeChange.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <stdio.h>
#include <windows.h>
#include <locale.h>
#define BUFF_SIZE 1024

wchar_t * ANSIToUnicode( const char* str )
{
  int textlen ;
  wchar_t * result;
  textlen = MultiByteToWideChar( CP_ACP, 0, str,-1, NULL,0 );
  result = (wchar_t *)malloc((textlen+1)*sizeof(wchar_t));
  memset(result,0,(textlen+1)*sizeof(wchar_t));
  MultiByteToWideChar(CP_ACP, 0,str,-1,(LPWSTR)result,textlen );
  return result;
}

char * UnicodeToANSI( const wchar_t* str )
{
  char* result;
  int textlen;
  textlen = WideCharToMultiByte( CP_ACP, 0, str, -1, NULL, 0, NULL, NULL );
  result =(char *)malloc((textlen+1)*sizeof(char));
  memset( result, 0, sizeof(char) * ( textlen + 1 ) );
  WideCharToMultiByte( CP_ACP, 0, str, -1, result, textlen, NULL, NULL );
  return result;
}

wchar_t * UTF8ToUnicode( const char* str )
{
  int textlen ;
  wchar_t * result;
  textlen = MultiByteToWideChar( CP_UTF8, 0, str,-1, NULL,0 );
  result = (wchar_t *)malloc((textlen+1)*sizeof(wchar_t));
  memset(result,0,(textlen+1)*sizeof(wchar_t));
  MultiByteToWideChar(CP_UTF8, 0,str,-1,(LPWSTR)result,textlen );
  return result;
}

char * UnicodeToUTF8( const wchar_t* str )
{
  char* result;
  int textlen;
  textlen = WideCharToMultiByte( CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL );
  result =(char *)malloc((textlen+1)*sizeof(char));
  memset(result, 0, sizeof(char) * ( textlen + 1 ) );
  WideCharToMultiByte( CP_UTF8, 0, str, -1, result, textlen, NULL, NULL );
  return result;
}
/*���ַ�ת��Ϊ���ַ�Unicode - ANSI*/
char* w2m(const wchar_t* wcs)
{
  int len;
  char* buf;
  len =wcstombs(NULL,wcs,0);
  if (len == 0)
    return NULL;
  buf = (char *)malloc(sizeof(char)*(len+1));
  memset(buf, 0, sizeof(char) *(len+1));
  len =wcstombs(buf,wcs,len+1);
  return buf;
}
/*���ַ�ת��Ϊ���ַ�ANSI - Unicode*/
wchar_t* m2w(const char* mbs)
{
  int len;
  wchar_t* buf;
  len =mbstowcs(NULL,mbs,0);
  if (len == 0)
    return NULL;
  buf = (wchar_t *)malloc(sizeof(wchar_t)*(len+1));
  memset(buf, 0, sizeof(wchar_t) *(len+1));
  len =mbstowcs(buf,mbs,len+1);
  return buf;
}

char* ANSIToUTF8(const char* str)
{
  return UnicodeToUTF8(ANSIToUnicode(str));
}

char* UTF8ToANSI(const char* str)
{
  return UnicodeToANSI(UTF8ToUnicode(str));
}

int main()
{
  /*ʹ��wcstombs��mbstowcs֮ǰ�������setlocale���Ա��������*/
//   setlocale(LC_ALL,".936");
//   /*�ٶ���һ��Unicode(UTF-16LE)������ļ�������򿪣����±���ΪANSI
//   ��д��aa.txt�У��ټ��������Unicode��д��aw.txt��*/
//   /*���������a.txt�ļ�����������û����������*/
//   char* filename = "a.txt";
//   char* filenamea = "aa.txt";
//   char* filenamew = "aw.txt";
//   FILE*     input=fopen( filename, "rb+");
//   FILE*     inputa=fopen( filenamea, "wb");
//   FILE*     inputw=fopen( filenamew, "wb");
//   wchar_t * buf ;
//   /*BOE���ã�UTF-16LE��BOEΪFEFF��������Ƚ����ȡ������wcstombs�����ʧ��*/
//   fgetwc(input);
//   fputwc(0xFEFF,inputw);
//   /*��ʼ��ȡ�ļ�*/
//   while(!feof(input))
//   {
//     buf = (wchar_t *)malloc(sizeof(wchar_t)*BUFF_SIZE)         ;
//     memset(buf,    0, sizeof(wchar_t) * BUFF_SIZE );
//     fgetws(buf,    BUFF_SIZE,    input);
//     fputs(w2m(buf),    inputa);
//     fputws(m2w(w2m(buf)),    inputw);
//   }
//   /*��������*/
//   fclose(input);
//   fclose(inputa);
//   fclose(inputw);
//   free(buf);
	char* pRes = NULL;
	wchar_t* wcs = (wchar_t*)("\u6211\u7231\u7956\u56fd.mp3");
	pRes = UnicodeToANSI(wcs);
	pRes = UnicodeToUTF8(wcs);
	pRes = w2m(wcs);

	//pRes = 
  return 0;
}


