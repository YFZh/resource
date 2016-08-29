__FILE__,__LINE__,FUNCTION__ʵ�ִ�����ٵ��ԣ�linux��c���Ա�� ���ȿ��¼򵥵ĳ�ʼ���룺ע����������к�Ľ����

root@xuanfei-desktop:~/cpropram/2# cat global.h //ͷ�ļ�
#ifndef CLOBAL_H
        #define GLOBAL_H
        #include <stdio.h>
        int funca(void);
        int funcb(void);
#endif
root@xuanfei-desktop:~/cpropram/2# cat funca.c //����a
#include "global.h"
int funca(void)
{
printf ("this is function\n");
return 0;
}
root@xuanfei-desktop:~/cpropram/2# cat funcb.c //����b
#include "global.h"
int funcb(void)
{
printf ("this is function\n");
return 0;
}
root@xuanfei-desktop:~/cpropram/2# gcc -Wall funca.c funcb.c main.c //���ϱ���
root@xuanfei-desktop:~/cpropram/2# ./a.out //����
this is main
this is function
this is main
this is function
this is main

��ͬ����������˿���������������������� __FILE__,__LINE__,__FUNCTION__������룬������ʲô������.
�� __FILE__,__LINE__,__FUNCTION__���뵽mail.c��
root@xuanfei-desktop:~/cpropram/2# cat main.c
#include "global.h"
int main(int argc, char **argv)
{
    printf("%s(%d)-%s: this is main\n",__FILE__,__LINE__,__FUNCTION__);
    funca();
    printf("%s(%d)-%s: this is main\n",__FILE__,__LINE__,__FUNCTION__);
    funcb();
    printf("%s(%d)-%s: this is main\n",__FILE__,__LINE__,__FUNCTION__);
    return 0;
}
root@xuanfei-desktop:~/cpropram/2# gcc -Wall funca.c funcb.c main.c
root@xuanfei-desktop:~/cpropram/2# ./a.out
main.c(4)-main: this is main
this is function
main.c(6)-main: this is main
this is function
main.c(8)-main: this is main

����Ľ��main.c(4)-main:this is main ��ʾ��mian.cԴ����ĵ�����main������ߴ�ӡ������ this is main
�����Ļ��ͺܷ�����ó���Ա���Լ��ĳ�������Ŵ�
Ϊ�˸������ʹ�������ǿ���ͨ����global.h�����н��к궨��
root@xuanfei-desktop:~/cpropram/2# cat global.h
#ifndef CLOBAL_H
        #define GLOBAL_H
        #include <stdio.h>
        int funca(void);
        int funcb(void);
        #define DEBUGFMT  "%s(%d)-%s"
        #define DEBUGARGS __FILE__,__LINE__,__FUNCTION__
#endif
root@xuanfei-desktop:~/cpropram/2# cat funca.c
#include "global.h"
int funca(void)
{
printf (DEBUGFMT " this is function\n",DEBUGARGS);
return 0;
}
root@xuanfei-desktop:~/cpropram/2# cat funcb.c
#include "global.h"
int funcb(void)
{
printf (DEBUGFMT " this is function\n",DEBUGARGS);
return 0;
}
root@xuanfei-desktop:~/cpropram/2# cat main.c
#include "global.h"
int main(int argc, char **argv)
{
    printf(DEBUGFMT "this is main\n", DEBUGARGS);
    funca();
    printf(DEBUGFMT "this is main\n", DEBUGARGS);
    funcb();
    printf(DEBUGFMT "this is main\n", DEBUGARGS);
    return 0;
}
root@xuanfei-desktop:~/cpropram/2# gcc -Wall funca.c funcb.c main.c
root@xuanfei-desktop:~/cpropram/2# ./a.out
main.c(4)-mainthis is main
funca.c(4)-funca this is function
main.c(6)-mainthis is main
funcb.c(4)-funcb this is function
main.c(8)-mainthis is main
root@xuanfei-desktop:~/cpropram/2#

�����ͨ������__FILE__,__LINE__,FUNCTION__�ĺ�����ʵ�ִ���ĸ��ٵ��ԣ���

������һ���ɹ������õ�ͷ�ļ�
#ifndef _GOLD_DEBUG_H
#define _GOLD_DEBUG_H

 

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

//#define GI_DEBUG

#ifdef GI_DEBUG

#define GI_DEBUG_POINT()   printf("\n\n[File:%s Line:%d] Fun:%s\n\n", __FILE__, __LINE__, __FUNCTION__)
#define dbg_printf(arg...)   printf(arg);

#define GI_ASSERT(expr)                                     \
    do{                                                     \
        if (!(expr)) { \
            printf("\nASSERT failed at:\n  >File name: %s\n  >Function : %s\n  >Line No. : %d\n  >Condition: %s\n", \
                    __FILE__,__FUNCTION__, __LINE__, #expr);\
        } \
    }while(0);

/*���Ժ�, ������ͣ*/
#define GI_DEBUG_PAUSE()           \
 do               \
 {               \
  GI_DEBUG_POINT();          \
  printf("pause for debug, press 'q' to exit!\n");  \
  char c;             \
  while( ( c = getchar() ) )        \
   {             \
    if('q' == c)         \
     {           \
      getchar();        \
      break;         \
     }           \
   }             \
 }while(0);
#define GI_DEBUG_PAUSE_ARG(arg...)          \
  do               \
  {               \
   printf(arg);           \
   GI_DEBUG_PAUSE()          \
  }while(0);


#define GI_DEBUG_ASSERT(expression)      \
if(!(expression))                        \
{                                  \
    printf("[ASSERT],%s,%s:%d\n", __FILE__,  __FUNCTION__, __LINE__);\
    exit(-1);             \
}
#else
#define GI_ASSERT(expr)
#define GI_DEBUG_PAUSE()
#define GI_DEBUG_PAUSE_ARG(arg...) 
#define GI_DEBUG_POINT()
#define dbg_printf(arg...)
#define GI_DEBUG_ASSERT(expression)

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif




C���Գ��ú궨��

01: ��ֹһ��ͷ�ļ����ظ�����
#ifndef COMDEF_H
#define COMDEF_H
//ͷ�ļ�����
#endif
02: ���¶���һЩ����,��ֹ���ڸ���ƽ̨�ͱ������Ĳ�ͬ,�������������ֽ�������,������ֲ��
typedef  unsigned char      boolean;     /* Boolean value type. */
typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
typedef  unsigned char      uint8;       /* Unsigned 8  bit value */
typedef  signed long int    int32;       /* Signed 32 bit value */
typedef  signed short       int16;       /* Signed 16 bit value */
typedef  signed char        int8;        /* Signed 8  bit value */

//����Ĳ�����ʹ��
typedef  unsigned char     byte;         /* Unsigned 8  bit value type. */
typedef  unsigned short    word;         /* Unsinged 16 bit value type. */
typedef  unsigned long     dword;        /* Unsigned 32 bit value type. */
typedef  unsigned char     uint1;        /* Unsigned 8  bit value type. */
typedef  unsigned short    uint2;        /* Unsigned 16 bit value type. */
typedef  unsigned long     uint4;        /* Unsigned 32 bit value type. */
typedef  signed char       int1;         /* Signed 8  bit value type. */
typedef  signed short      int2;         /* Signed 16 bit value type. */
typedef  long int          int4;         /* Signed 32 bit value type. */
typedef  signed long       sint31;       /* Signed 32 bit value */
typedef  signed short      sint15;       /* Signed 16 bit value */
typedef  signed char       sint7;        /* Signed 8  bit value */

03: �õ�ָ����ַ�ϵ�һ���ֽڻ���
#define  MEM_B(x) (*((byte *)(x)))
#define  MEM_W(x) (*((word *)(x)))

04: �����ֵ����Сֵ
#define  MAX(x,y) (((x)>(y)) ? (x) : (y))
#define  MIN(x,y) (((x) < (y)) ? (x) : (y))

05: �õ�һ��field�ڽṹ��(struct)�е�ƫ����
#define FPOS(type,field) ((dword)&((type *)0)->field)

06: �õ�һ���ṹ����field��ռ�õ��ֽ���
#define FSIZ(type,field) sizeof(((type *)0)->field)

07: ����LSB��ʽ�������ֽ�ת��Ϊһ��Word
#define FLIPW(ray) ((((word)(ray)[0]) * 256) + (ray)[1])

08: ����LSB��ʽ��һ��Wordת��Ϊ�����ֽ�
#define FLOPW(ray,val) (ray)[0] = ((val)/256); (ray)[1] = ((val) & 0xFF)

09: �õ�һ�������ĵ�ַ��word��ȣ�
#define B_PTR(var)  ((byte *) (void *) &(var))
#define W_PTR(var)  ((word *) (void *) &(var))

10: �õ�һ���ֵĸ�λ�͵�λ�ֽ�
#define WORD_LO(xxx)  ((byte) ((word)(xxx) & 255))
#define WORD_HI(xxx)  ((byte) ((word)(xxx) >> 8))

11: ����һ����X�����ӽ���8�ı���
#define RND8(x) ((((x) + 7)/8) * 8)

12: ��һ����ĸת��Ϊ��д
#define UPCASE(c) (((c)>='a' && (c) <= 'z') ? ((c) - 0x20) : (c))

13: �ж��ַ��ǲ���10��ֵ������
#define  DECCHK(c) ((c)>='0' && (c)<='9')

14: �ж��ַ��ǲ���16��ֵ������
#define HEXCHK(c) (((c) >= '0' && (c)<='9') ((c)>='A' && (c)<= 'F') \
((c)>='a' && (c)<='f'))

15: ��ֹ�����һ������
#define INC_SAT(val) (val=((val)+1>(val)) ? (val)+1 : (val))

16: ��������Ԫ�صĸ���
#define ARR_SIZE(a)  (sizeof((a))/sizeof((a[0])))

17: ����һ���޷�����nβ��ֵMOD_BY_POWER_OF_TWO(X,n)=X%(2^n)
#define MOD_BY_POWER_OF_TWO( val, mod_by ) ((dword)(val) & (dword)((mod_by)-1))

18: ����IO�ռ�ӳ���ڴ洢�ռ�Ľṹ,�����������
#define inp(port) (*((volatile byte *)(port)))
#define inpw(port) (*((volatile word *)(port)))
#define inpdw(port) (*((volatile dword *)(port)))
#define outp(port,val) (*((volatile byte *)(port))=((byte)(val)))
#define outpw(port, val) (*((volatile word *)(port))=((word)(val)))
#define outpdw(port, val) (*((volatile dword *)(port))=((dword)(val)))

19: ʹ��һЩ����ٵ���
ANSI��׼˵�������Ԥ����ĺ����������ǣ�
__LINE__
__FILE__
__DATE__
__TIME__
__STDC__
C++�л������� __cplusplus

������������Ǳ�׼��,����ܽ�֧�����Ϻ����еļ���,�������֧�֡���ס�������Ҳ���ṩ����Ԥ����ĺ�����

__LINE__ �� __FILE__ ��ָʾ��#lineָ����Ըı�����ֵ���򵥵Ľ�������ʱ�����ǰ�������ĵ�ǰ�������ļ�����

__DATE__ ��ָ�����ʽΪ��/��/��Ĵ�,��ʾԴ�ļ������뵽����ʱ�����ڡ�
__TIME__ ��ָ�������������ʱ�䡣ʱ�����ַ�����ʾ������ʽΪ�� �֣���
__STDC__ ��ָ��������Ǳ���ʱ����ġ�һ�����������__STDC__�Ѿ����壬�������������ܲ������κηǱ�׼��չ�ı�׼C/C++���롣���ʵ���Ǳ�׼��,���__STDC__����ʮ���Ƴ���1������������κ�������,��ʵ���ǷǱ�׼�ġ�
__cplusplus ���׼c++һ�µı�������������Ϊһ����������6Ϊ����ֵ�����׼c++��һ�µı�������ʹ�þ���5λ����ٵ���ֵ��


���Զ����,����:
��������_DEBUG,���������Ϣ�������ļ�������
#ifdef _DEBUG
#define DEBUGMSG(msg,date) printf(msg);printf(��%d%d%d��,date,_LINE_,_FILE_)
#else
#define DEBUGMSG(msg,date) 
#endif
 

20�� �궨���ֹ����ʹ��С���Ű�����
���磺
������Ķ��壺#define DUMP_WRITE(addr,nr) {memcpy(bufp,addr,nr); bufp += nr;}
Ӧ��ʹ�õĶ��壺 #difne DO(a,b) do{a+b;a++;}while(0)
���磺
if(addr)
    DUMP_WRITE(addr,nr);
else 
    do_somethong_else();
��չ���Ժ�������:
if(addr)
    {memcpy(bufp,addr,nr); bufp += nr;};
else
    do_something_else();

gcc ������elseǰ��ġ�����ʱ����Ϊif����Ѿ���������������else����if����С�������do{} while(0)�Ķ��壬���κ�����¶�û�����⡣����Ϊ #difne DO(a,b) do{a+b;a++;}while(0) �Ķ��������κ�����¶��������
