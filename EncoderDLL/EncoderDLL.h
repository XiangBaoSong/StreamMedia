// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ENCODERDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ENCODERDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef ENCODERDLL_EXPORTS
#define ENCODERDLL_API __declspec(dllexport)
#else
#define ENCODERDLL_API __declspec(dllimport)
#endif

// �����Ǵ� EncoderDLL.dll ������
class ENCODERDLL_API CEncoderDLL {
public:
	CEncoderDLL(void);
	// TODO: �ڴ�������ķ�����
};

extern ENCODERDLL_API int nEncoderDLL;

ENCODERDLL_API int fnEncoderDLL(void);
