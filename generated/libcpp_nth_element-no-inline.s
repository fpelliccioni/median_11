	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4                               ## -- Begin function main
LCPI0_0:
	.quad	8                               ## 0x8
	.quad	16                              ## 0x10
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	8(%rsi), %rax
	movzbl	8(%rax), %ecx
	vpmovzxbq	9(%rax), %xmm0          ## xmm0 = mem[0],zero,zero,zero,zero,zero,zero,zero,mem[1],zero,zero,zero,zero,zero,zero,zero
	vpsllvq	LCPI0_0(%rip), %xmm0, %xmm0
	vmovd	%xmm0, %edx
	orl	%ecx, %edx
	vpextrd	$2, %xmm0, %esi
	orl	%edx, %esi
	movq	(%rax), %rdi
	callq	__Z9median_11IcET_NSt3__15arrayIS0_Lm11EEE
	movsbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z9median_11IcET_NSt3__15arrayIS0_Lm11EEE ## -- Begin function _Z9median_11IcET_NSt3__15arrayIS0_Lm11EEE
	.weak_def_can_be_hidden	__Z9median_11IcET_NSt3__15arrayIS0_Lm11EEE
	.p2align	4, 0x90
__Z9median_11IcET_NSt3__15arrayIS0_Lm11EEE: ## @_Z9median_11IcET_NSt3__15arrayIS0_Lm11EEE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	%rdi, -48(%rbp)
	movw	%si, -40(%rbp)
	shrl	$16, %esi
	movb	%sil, -38(%rbp)
	leaq	-48(%rbp), %r10
	leaq	-43(%rbp), %r8
	leaq	-37(%rbp), %r9
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_24 Depth 2
                                        ##     Child Loop BB1_39 Depth 2
                                        ##     Child Loop BB1_46 Depth 2
                                        ##       Child Loop BB1_47 Depth 3
                                        ##       Child Loop BB1_49 Depth 3
                                        ##     Child Loop BB1_17 Depth 2
                                        ##       Child Loop BB1_18 Depth 3
                                        ##       Child Loop BB1_20 Depth 3
                                        ##     Child Loop BB1_42 Depth 2
                                        ##     Child Loop BB1_35 Depth 2
	movq	%r9, %rcx
	subq	%r10, %rcx
	cmpq	$2, %rcx
	jb	LBB1_87
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	cmpq	$3, %rcx
	je	LBB1_54
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	cmpq	$2, %rcx
	je	LBB1_57
## %bb.4:                               ##   in Loop: Header=BB1_1 Depth=1
	cmpq	$7, %rcx
	jle	LBB1_59
## %bb.5:                               ##   in Loop: Header=BB1_1 Depth=1
	shrq	%rcx
	leaq	(%r10,%rcx), %r15
	leaq	-1(%r9), %rsi
	movb	(%r10,%rcx), %dl
	movb	(%r10), %cl
	movb	-1(%r9), %bl
	cmpb	%cl, %dl
	jge	LBB1_8
## %bb.6:                               ##   in Loop: Header=BB1_1 Depth=1
	cmpb	%dl, %bl
	jge	LBB1_11
## %bb.7:                               ##   in Loop: Header=BB1_1 Depth=1
	movb	%bl, (%r10)
	movb	%cl, (%rsi)
	movl	$1, %r14d
	jmp	LBB1_14
	.p2align	4, 0x90
LBB1_8:                                 ##   in Loop: Header=BB1_1 Depth=1
	xorl	%r14d, %r14d
	cmpb	%dl, %bl
	jge	LBB1_14
## %bb.9:                               ##   in Loop: Header=BB1_1 Depth=1
	movb	%bl, (%r15)
	movb	%dl, (%rsi)
	movb	(%r15), %al
	movb	(%r10), %cl
	movl	$1, %r14d
	cmpb	%cl, %al
	jge	LBB1_14
## %bb.10:                              ##   in Loop: Header=BB1_1 Depth=1
	movb	%al, (%r10)
	movb	%cl, (%r15)
	jmp	LBB1_13
	.p2align	4, 0x90
LBB1_11:                                ##   in Loop: Header=BB1_1 Depth=1
	movb	%dl, (%r10)
	movb	%cl, (%r15)
	movb	(%rsi), %al
	movl	$1, %r14d
	cmpb	%cl, %al
	jge	LBB1_14
## %bb.12:                              ##   in Loop: Header=BB1_1 Depth=1
	movb	%al, (%r15)
	movb	%cl, (%rsi)
LBB1_13:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	$2, %r14d
LBB1_14:                                ##   in Loop: Header=BB1_1 Depth=1
	movb	(%r10), %r11b
	movb	(%r15), %cl
	cmpb	%cl, %r11b
	jge	LBB1_23
## %bb.15:                              ##   in Loop: Header=BB1_1 Depth=1
	movq	%rsi, %rdi
	leaq	1(%r10), %r11
	cmpq	%rdi, %r11
	jae	LBB1_27
LBB1_16:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	%r11, %rcx
	.p2align	4, 0x90
LBB1_17:                                ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB1_18 Depth 3
                                        ##       Child Loop BB1_20 Depth 3
	movb	(%r15), %dl
	.p2align	4, 0x90
LBB1_18:                                ##   Parent Loop BB1_1 Depth=1
                                        ##     Parent Loop BB1_17 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movzbl	(%rcx), %ebx
	incq	%rcx
	cmpb	%dl, %bl
	jl	LBB1_18
## %bb.19:                              ##   in Loop: Header=BB1_17 Depth=2
	leaq	-1(%rcx), %rsi
	.p2align	4, 0x90
LBB1_20:                                ##   Parent Loop BB1_1 Depth=1
                                        ##     Parent Loop BB1_17 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movzbl	-1(%rdi), %eax
	decq	%rdi
	cmpb	%dl, %al
	jge	LBB1_20
## %bb.21:                              ##   in Loop: Header=BB1_17 Depth=2
	cmpq	%rdi, %rsi
	jae	LBB1_28
## %bb.22:                              ##   in Loop: Header=BB1_17 Depth=2
	movb	%al, (%rsi)
	movb	%bl, (%rdi)
	incl	%r14d
	cmpq	%r15, %rsi
	cmoveq	%rdi, %r15
	jmp	LBB1_17
	.p2align	4, 0x90
LBB1_23:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	%rsi, %rdi
	.p2align	4, 0x90
LBB1_24:                                ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	decq	%rdi
	cmpq	%r10, %rdi
	je	LBB1_37
## %bb.25:                              ##   in Loop: Header=BB1_24 Depth=2
	movzbl	(%rdi), %eax
	cmpb	%cl, %al
	jge	LBB1_24
## %bb.26:                              ##   in Loop: Header=BB1_1 Depth=1
	movb	%al, (%r10)
	movb	%r11b, (%rdi)
	incl	%r14d
	leaq	1(%r10), %r11
	cmpq	%rdi, %r11
	jb	LBB1_16
LBB1_27:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	%r11, %rsi
LBB1_28:                                ##   in Loop: Header=BB1_1 Depth=1
	cmpq	%r15, %rsi
	je	LBB1_31
## %bb.29:                              ##   in Loop: Header=BB1_1 Depth=1
	movb	(%r15), %al
	movb	(%rsi), %cl
	cmpb	%cl, %al
	jge	LBB1_31
## %bb.30:                              ##   in Loop: Header=BB1_1 Depth=1
	movb	%al, (%rsi)
	movb	%cl, (%r15)
	incl	%r14d
LBB1_31:                                ##   in Loop: Header=BB1_1 Depth=1
	cmpq	%r8, %rsi
	je	LBB1_87
## %bb.32:                              ##   in Loop: Header=BB1_1 Depth=1
	testl	%r14d, %r14d
	je	LBB1_34
LBB1_33:                                ##   in Loop: Header=BB1_1 Depth=1
	leaq	1(%rsi), %rdi
	cmpq	%r8, %rsi
	cmovaq	%rsi, %r9
	cmovaq	%r10, %rdi
	jmp	LBB1_53
	.p2align	4, 0x90
LBB1_34:                                ##   in Loop: Header=BB1_1 Depth=1
	cmpq	%r8, %rsi
	jbe	LBB1_41
	.p2align	4, 0x90
LBB1_35:                                ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	%rsi, %r11
	je	LBB1_87
## %bb.36:                              ##   in Loop: Header=BB1_35 Depth=2
	movzbl	(%r11), %eax
	leaq	1(%r11), %rcx
	cmpb	-1(%r11), %al
	movq	%rcx, %r11
	jge	LBB1_35
	jmp	LBB1_33
	.p2align	4, 0x90
LBB1_37:                                ##   in Loop: Header=BB1_1 Depth=1
	leaq	1(%r10), %rcx
	movb	(%rsi), %dl
	cmpb	%dl, %r11b
	jl	LBB1_45
	.p2align	4, 0x90
## %bb.38:                              ##   in Loop: Header=BB1_1 Depth=1
	cmpq	%rsi, %rcx
	je	LBB1_87
LBB1_39:                                ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movzbl	(%rcx), %eax
	cmpb	%al, %r11b
	jl	LBB1_44
## %bb.40:                              ##   in Loop: Header=BB1_39 Depth=2
	incq	%rcx
	cmpq	%rsi, %rcx
	jne	LBB1_39
	jmp	LBB1_87
LBB1_41:                                ##   in Loop: Header=BB1_1 Depth=1
	leaq	1(%rsi), %rcx
	.p2align	4, 0x90
LBB1_42:                                ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpq	%r9, %rcx
	je	LBB1_87
## %bb.43:                              ##   in Loop: Header=BB1_42 Depth=2
	movzbl	(%rcx), %eax
	leaq	1(%rcx), %rdx
	cmpb	-1(%rcx), %al
	movq	%rdx, %rcx
	jge	LBB1_42
	jmp	LBB1_33
LBB1_44:                                ##   in Loop: Header=BB1_1 Depth=1
	movb	%dl, (%rcx)
	movb	%al, (%rsi)
	incq	%rcx
LBB1_45:                                ##   in Loop: Header=BB1_1 Depth=1
	cmpq	%rsi, %rcx
	je	LBB1_87
	.p2align	4, 0x90
LBB1_46:                                ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB1_47 Depth 3
                                        ##       Child Loop BB1_49 Depth 3
	movb	(%r10), %bl
	.p2align	4, 0x90
LBB1_47:                                ##   Parent Loop BB1_1 Depth=1
                                        ##     Parent Loop BB1_46 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movzbl	(%rcx), %edx
	incq	%rcx
	cmpb	%dl, %bl
	jge	LBB1_47
## %bb.48:                              ##   in Loop: Header=BB1_46 Depth=2
	leaq	-1(%rcx), %rdi
	.p2align	4, 0x90
LBB1_49:                                ##   Parent Loop BB1_1 Depth=1
                                        ##     Parent Loop BB1_46 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movzbl	-1(%rsi), %eax
	decq	%rsi
	cmpb	%al, %bl
	jl	LBB1_49
## %bb.50:                              ##   in Loop: Header=BB1_46 Depth=2
	cmpq	%rsi, %rdi
	jae	LBB1_52
## %bb.51:                              ##   in Loop: Header=BB1_46 Depth=2
	movb	%al, (%rdi)
	movb	%dl, (%rsi)
	jmp	LBB1_46
LBB1_52:                                ##   in Loop: Header=BB1_1 Depth=1
	cmpq	%r8, %rdi
	ja	LBB1_87
LBB1_53:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	%rdi, %r10
	cmpq	%r8, %r9
	jne	LBB1_1
	jmp	LBB1_87
LBB1_54:
	movb	(%r10), %al
	movb	1(%r10), %cl
	movb	-1(%r9), %dl
	cmpb	%al, %cl
	jge	LBB1_81
## %bb.55:
	cmpb	%cl, %dl
	jge	LBB1_84
## %bb.56:
	movb	%dl, (%r10)
	jmp	LBB1_86
LBB1_57:
	movb	-1(%r9), %al
	movb	(%r10), %cl
	cmpb	%cl, %al
	jge	LBB1_87
## %bb.58:
	movb	%al, (%r10)
	movb	%cl, -1(%r9)
	jmp	LBB1_87
LBB1_59:
	leaq	-1(%r9), %r8
	cmpq	%r10, %r8
	je	LBB1_87
## %bb.60:
	movl	%r10d, %eax
	notl	%eax
	leal	(%r9,%rax), %ecx
	leaq	-2(%r9), %rax
	movq	%r10, %rdx
	testb	$1, %cl
	je	LBB1_67
## %bb.61:
	leaq	1(%r10), %rdx
	cmpq	%r9, %r10
	je	LBB1_67
## %bb.62:
	cmpq	%r9, %rdx
	je	LBB1_67
## %bb.63:
	movb	(%r10), %r11b
	movl	%r11d, %ebx
	movq	%rdx, %rsi
	movq	%r10, %rdi
	.p2align	4, 0x90
LBB1_64:                                ## =>This Inner Loop Header: Depth=1
	movzbl	(%rsi), %ecx
	cmpb	%bl, %cl
	movzbl	%bl, %ebx
	cmovll	%ecx, %ebx
	cmovlq	%rsi, %rdi
	incq	%rsi
	cmpq	%r9, %rsi
	jne	LBB1_64
## %bb.65:
	cmpq	%r10, %rdi
	je	LBB1_67
## %bb.66:
	movb	(%rdi), %cl
	movb	%cl, (%r10)
	movb	%r11b, (%rdi)
LBB1_67:
	cmpq	%r10, %rax
	jne	LBB1_69
	jmp	LBB1_87
	.p2align	4, 0x90
LBB1_68:                                ##   in Loop: Header=BB1_69 Depth=1
	cmpq	%r8, %rdx
	je	LBB1_87
LBB1_69:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_72 Depth 2
                                        ##     Child Loop BB1_78 Depth 2
	leaq	1(%rdx), %rax
	cmpq	%r9, %rdx
	je	LBB1_75
## %bb.70:                              ##   in Loop: Header=BB1_69 Depth=1
	cmpq	%r9, %rax
	je	LBB1_75
## %bb.71:                              ##   in Loop: Header=BB1_69 Depth=1
	movb	(%rdx), %r10b
	movl	%r10d, %ebx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	.p2align	4, 0x90
LBB1_72:                                ##   Parent Loop BB1_69 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movzbl	(%rsi), %ecx
	cmpb	%bl, %cl
	movzbl	%bl, %ebx
	cmovll	%ecx, %ebx
	cmovlq	%rsi, %rdi
	incq	%rsi
	cmpq	%r9, %rsi
	jne	LBB1_72
## %bb.73:                              ##   in Loop: Header=BB1_69 Depth=1
	cmpq	%rdx, %rdi
	je	LBB1_75
## %bb.74:                              ##   in Loop: Header=BB1_69 Depth=1
	movb	(%rdi), %cl
	movb	%cl, (%rdx)
	movb	%r10b, (%rdi)
LBB1_75:                                ##   in Loop: Header=BB1_69 Depth=1
	addq	$2, %rdx
	cmpq	%r9, %rax
	je	LBB1_68
## %bb.76:                              ##   in Loop: Header=BB1_69 Depth=1
	cmpq	%r9, %rdx
	je	LBB1_68
## %bb.77:                              ##   in Loop: Header=BB1_69 Depth=1
	movb	(%rax), %r10b
	movl	%r10d, %ebx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	.p2align	4, 0x90
LBB1_78:                                ##   Parent Loop BB1_69 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movzbl	(%rsi), %ecx
	cmpb	%bl, %cl
	movzbl	%bl, %ebx
	cmovll	%ecx, %ebx
	cmovlq	%rsi, %rdi
	incq	%rsi
	cmpq	%r9, %rsi
	jne	LBB1_78
## %bb.79:                              ##   in Loop: Header=BB1_69 Depth=1
	cmpq	%rax, %rdi
	je	LBB1_68
## %bb.80:                              ##   in Loop: Header=BB1_69 Depth=1
	movb	(%rdi), %cl
	movb	%cl, (%rax)
	movb	%r10b, (%rdi)
	jmp	LBB1_68
LBB1_81:
	cmpb	%cl, %dl
	jge	LBB1_87
## %bb.82:
	movb	%dl, 1(%r10)
	movb	%cl, -1(%r9)
	movb	(%r10), %al
	movb	1(%r10), %cl
	cmpb	%al, %cl
	jge	LBB1_87
## %bb.83:
	movb	%cl, (%r10)
	movb	%al, 1(%r10)
	jmp	LBB1_87
LBB1_84:
	movb	%cl, (%r10)
	movb	%al, 1(%r10)
	movb	-1(%r9), %cl
	cmpb	%al, %cl
	jge	LBB1_87
## %bb.85:
	movb	%cl, 1(%r10)
LBB1_86:
	movb	%al, -1(%r9)
LBB1_87:
	movsbl	-43(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	cmpq	-32(%rbp), %rcx
	jne	LBB1_89
## %bb.88:
	addq	$24, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
LBB1_89:
	callq	___stack_chk_fail
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
