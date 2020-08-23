.data
	dqSendPacketFunction dq 0
	dqSendActionFunction dq 0	
.code

MoveSendPacketAddress PROC
	mov dqSendPacketFunction, rcx
	ret
MoveSendPacketAddress ENDP

SetSendActionAddress PROC
	mov dqSendActionFunction, rcx
	ret
SetSendActionAddress ENDP

SendPacket PROC
; RCX = SendClass //CHECK THIS, IT MAY SHUFFLE EVERY SO OFTEN
; RDX = Packet Buffer
; R8 = Length

    pushfq
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push rsp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    mov rax, rcx ;SendClass
    add rax, 1a8h
    mov [rax], rdx
    sub rax, 28h 
    mov [rax], r8 ;get packet buffer address
    sub rsp, 1000h ;need to add some space (atleast 0x500) as the func itself uses this and will overwrite stack
    call dqSendPacketFunction
    add rsp, 1000h

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rsp
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    popfq
    ret
SendPacket ENDP

SendAction PROC ; UINT64 ptrCharBase, SHORT SkillID, r8 optional_entity, r9 Ptr Vector2
;rcx = [charbase + 3A0]  for steam, charbase + 378 for S.A.
;rdx = skill id
;r8 = ptr to object entity?
;r9 = ptr to new Vector2

    pushfq
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push rsp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    ;
	sub rsp, 150h
	call dqSendActionFunction
	add rsp, 150h

   ;
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rsp
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    popfq
	ret
SendAction ENDP

END
