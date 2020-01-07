.data
	dqWriteFileFunctionAddress dq 0
	dqWriteFileReturnAddress dq 0

	dqEntitySpawnReturnAddress dq 0
	dqEntityScanFunctionAddress dq 0

	dqSendBuffer dq 0
	dqPacketLength dq 0
	dqSendPacketReturnAddress dq 0
	dqSendPacketFunction dq 0
	dqSendClass dq 0
	dqCreatePacketFunc dq 0

	dqCurrentHP dq 0
	dqCurrentMP dq 0
	dqMaxHP dq 0
	dqMaxMP dq 0
	dqCurrentHPMPReturnAddress dq 0
	dqCurrentHPMPCallbackAddress dq 0
.code

MoveAutoPotReturnHookAddress PROC
	mov dqCurrentHPMPReturnAddress, rcx
	ret
MoveAutoPotReturnHookAddress ENDP

MoveAutoPotCallbackHookAddress PROC
	mov dqCurrentHPMPCallbackAddress, rcx
	ret
MoveAutoPotCallbackHookAddress ENDP


SetWriteFileHookReturnAddress PROC
	mov dqWriteFileReturnAddress, rcx
	ret
SetWriteFileHookReturnAddress ENDP

SetWriteFileHookCallbackAddress PROC
    mov dqWriteFileFunctionAddress, rcx
    ret
SetWriteFileHookCallbackAddress ENDP

WriteFileHook PROC
    
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

	;rax = buffer ptr
    sub rsp,28h
	push rax
	push rcx
	push rdx
	mov rcx, rax
	mov rdx, r8
	call dqWriteFileFunctionAddress
	pop rdx
	pop rcx
	pop rax
    add rsp,28h
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
	lea rdx, [rsp+040h]
    jmp dqWriteFileReturnAddress

WriteFileHook ENDP

SetEntitySpawnHookCallbackAddress PROC
	mov dqEntityScanFunctionAddress, rcx
	ret
SetEntitySpawnHookCallbackAddress ENDP

SetEntitySpawnHookReturnAddress PROC
	mov dqEntitySpawnReturnAddress, rcx
	ret
SetEntitySpawnHookReturnAddress ENDP

;RDX = Entity Ptr!
EntitySpawnHook PROC
    
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

    ; need some func to fill entity info here/scan
    sub rsp,280h
	push rcx
	push rdx
	mov rcx, rdx
	call dqEntityScanFunctionAddress
	pop rdx
	pop rcx
    add rsp,280h
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
	
	sub rsp, 0D0h
    jmp dqEntitySpawnReturnAddress
EntitySpawnHook ENDP

GetSendClass PROC
	mov rax, dqSendClass
	ret
GetSendClass ENDP

MoveSendPacketReturnAddress PROC
	mov dqSendPacketReturnAddress, rcx
	ret
MoveSendPacketReturnAddress ENDP

MoveCreatePacketAddress PROC
	mov dqCreatePacketFunc, rcx
	ret
MoveCreatePacketAddress ENDP

LogSendPacketHook PROC

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
    sub rsp,280h
    push rcx
    push rdx
    push rax
    mov rax, [rbx+180h]
    mov dqPacketLength, rax
    mov rax, [rbx+1a8h]
    mov dqSendBuffer, rax
    mov rcx, dqSendBuffer
    mov rdx, dqPacketLength
	mov dqSendClass, rbx
    call dqCreatePacketFunc
    pop rax
    pop rcx
    pop rdx
    add rsp,280h
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
    mov r8, [rcx+00000180h]
    mov rdx,[rcx+00000188h]
    jmp dqSendPacketReturnAddress

LogSendPacketHook ENDP

GetCurrentHPMPHook PROC
 
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
	push rax
	cmp r14, 0
	jne CurrentMP
	mov rax, rdx
	mov dqCurrentHP, rax
	mov rax, r9
	mov dqMaxHP, rax
	jmp Cleanup
	CurrentMP:
	mov rax, rdx 
	mov dqCurrentMP, rax
	mov rax, r9
	mov dqMaxMP, rax
	Cleanup:
	pop rax
    ;

	;
	sub rsp, 150h
	call dqCurrentHPMPCallbackAddress
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
	mov rsi, [rsp+0B8h]
	jmp dqCurrentHPMPReturnAddress
GetCurrentHPMPHook ENDP

END
