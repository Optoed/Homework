.model small                 ;������ ������ SMALL ���������� �������� 
                             ;�������� �� ����� 64��
.stack 100h                  ;������� ����� �������� 100h (256 ����)
.data                        ;������ �������� ������
Hello db 'Steklyannikov Petr 251$'
.code                        ;������ �������� ����
start:                       ;����� ����� � ��������� start 
                             ;���������������� ����� @data ����������
                             ;����� �������� ������ � ������ ������� ���������,
mov AX, @data                ;������� ������� �������� � AX,
mov DS,AX                    ;� ����� ��������� �� AX � DS
mov AH,09h
mov DX,offset Hello
int 21h
mov AX,4C00h
int 21h
end start