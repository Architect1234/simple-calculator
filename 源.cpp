#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���������ڼ�����ѧ���ʽ�����ڱ��ʽ�Ľ�β��һ����=�������磺8/4+2-(5-1)=
//������֧���ҽ�֧��ʮλ���������㣬��Ȼ�ͼ�
//��������ʡ�Է���,�磺2(5+3);ҪдΪ��2*(5+3)
// 
// 
// 
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               ���汣��         ����BUG


struct Stack
{
    float n[40];
    char s[20];
    int top;
}sym, num;
Stack* pn = &num;
Stack* ps = &sym;


void chushihua(struct Stack* stack)  //��ʼ��ջ
{
    stack->top = -1;
}


int empty(struct Stack* stack)  //���ջ�Ƿ�Ϊ��
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}


void nruzhan(struct Stack* stack, float value)  //������ջ
{
    stack->n[++stack->top] = value;
}


void sruzhan(struct Stack* stack, char value)  //������ջ
{
    stack->s[++stack->top] = value;
}


float nchuzhan(struct Stack* stack)  //���ֳ�ջ
{
    return stack->n[stack->top--];
}


char schuzhan(struct Stack* stack)  //���ų�ջ
{
    if (empty(stack))
        printf("ջ��");
    return stack->s[stack->top--];
}

void compute(struct Stack* pn, struct Stack* ps) //��������
{
    float a, b;
    char s;
    b = nchuzhan(pn);
    a = nchuzhan(pn);
    s = schuzhan(ps);
    switch (s)
    {
    case '+':
        nruzhan(pn, a + b); break;
    case '-':
        nruzhan(pn, a - b); break;
    case '*':
        nruzhan(pn, a * b); break;
    case '/':
        nruzhan(pn, a * 1.0 / b); break;
    default:
        printf("error"); break;
    }

}


int cmpe(char a)//�Ƚ�a��ջ���������ȼ�
{
    int k=0, k2=0;
    char  b;
    if (empty(ps))
        return 1;
    b = schuzhan(ps);
    sruzhan(ps, b);
    if (a == '(')
        return 1;
    switch (a)
    {
    case '+': k = 1; break;
    case '-': k = 1; break;
    case '*': k = 2; break;
    case '/': k = 2; break;
    default:break;
    }
    switch (b)
    {
    case '+': k2 = 1; break;
    case '-': k2 = 1; break;
    case '*': k2 = 2; break;
    case '/': k2 = 2; break;
    default:break;
    }
    if (k > k2)
        return 1;
    else
        return 0;
}

void scan(struct Stack* pn, struct Stack* ps)//ɨ��ñ��ʽ��ֱ����=��
{
    char temp1=0;
    
    while (temp1 != '=')
    {
        scanf("%c", &temp1);
        if (temp1 >= '0' && temp1 <= '9')//�ж��ǲ�������

            nruzhan(pn, (float)temp1-48);  //����ֱ����ջ
        else
        {
            if (ps->top == -1)  //�жϷ���ջ�Ƿ�Ϊ��
            {
                if(temp1!='\n')
                sruzhan(ps, temp1);
                continue;
            }

            else if (temp1 != '=')
            {
                if (temp1 == ')')
                {
                    while (ps->s[ps->top] != '(') //���ϵ�������ֱ��������
                    {

                        compute(pn, ps);
                    }
                    ps->top--;
                }
                else
                {
                    if (cmpe(temp1))  //�ж��Ƿ�����ջ
                    {
                        if (temp1 != '\n')
                            sruzhan(ps, temp1);
                    }
                    else
                    {
                        while (!cmpe(temp1))//�޷���ջ����������
                        {
                            compute(pn, ps);
                        }
                        if (temp1 != '\n')
                            sruzhan(ps, temp1);
                    }
                }

            }

        }
    }

}


int main()
{
    printf("���������ڼ�����׺���ʽ\n");
    printf("���ڱ��ʽ�Ľ�β��һ����=�������磺8/4+2-(5-1)=\n");
    printf("������֧���ҽ�֧��ʮλ���������㣬��Ȼ�ͼ�\n");
    printf("��������ʡ�Է���,�磺2(5+3);ҪдΪ��2*(5+3)\n");
    system("pause");
    while (1)
    {

        chushihua(ps);
        chushihua(pn);
        system("cls");
        printf("��������ʽ��\n");
        scan(pn, ps);
        while (ps->top != -1)//����ջ�ڲ���
        {
            compute(pn, ps);
        }
        printf("%.6f\n", pn->n[0]);
        printf("\n");
        system("pause");
    }
    return 0;
}