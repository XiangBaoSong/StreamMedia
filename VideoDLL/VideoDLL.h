// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� VIDEODLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// VIDEODLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef VIDEODLL_EXPORTS
#define VIDEODLL_API __declspec(dllexport)
#else
#define VIDEODLL_API __declspec(dllimport)
#endif

// �����Ǵ� VideoDLL.dll ������
class VIDEODLL_API CVideoDLL {
public:
	CVideoDLL(void);
	// TODO: �ڴ�������ķ�����
};

extern VIDEODLL_API int nVideoDLL;

VIDEODLL_API int fnVideoDLL(void);
