	.cpu cortex-a9
	.eabi_attribute 27, 3
	.fpu neon-fp16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"cft.c"
	.global	stackFrom
	.data
	.align	2
	.type	stackFrom, %object
	.size	stackFrom, 124
stackFrom:
	.word	20
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.word	9
	.word	10
	.word	11
	.word	12
	.word	13
	.word	14
	.word	15
	.word	16
	.word	17
	.word	18
	.word	19
	.word	20
	.word	21
	.word	22
	.word	23
	.word	24
	.word	25
	.word	26
	.word	27
	.word	28
	.word	29
	.word	30
	.global	stackTo
	.bss
	.align	2
	.type	stackTo, %object
	.size	stackTo, 124
stackTo:
	.space	124
	.global	stackAux
	.align	2
	.type	stackAux, %object
	.size	stackAux, 124
stackAux:
	.space	124
	.global	errorSignal
	.align	2
	.type	errorSignal, %object
	.size	errorSignal, 4
errorSignal:
	.space	4
	.section	.rodata
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	mov	r5, #2
	eor	r5, r5, #24
	eor	r5, r5, #14
	mov	r6, lr
	mov	r12, sp
	movw	r2, #:lower16:stackFrom
	movw	r10, #:lower16:stackFrom
	movt	r2, #:upper16:stackFrom
	movt	r10, #:upper16:stackFrom
	ldr	r0, [r2, #0]
	ldr	r8, [r10, #0]
	mov	r1, r0
	mov	r7, r8
	movw	r3, #:lower16:stackTo
	movw	r11, #:lower16:stackTo
	movt	r3, #:upper16:stackTo
	movt	r11, #:upper16:stackTo
	lsl	r1, r1, #2
	lsl	r7, r7, #2
	movw	r4, #:lower16:stackAux
	movw	r9, #:lower16:stackAux
	movt	r4, #:upper16:stackAux
	movt	r9, #:upper16:stackAux
	cmp	r1, r7
	bne	error
	str	r1, [r2, #0]
	cmp	r5, #20
	bne	error
	eor	r5, r5, #212
	bl	move
	and	r5, r5, #240
	mov	r6, lr
	ldr	r0, [r3, #0]
	ldr	r8, [r11, #0]
	ldr	r1, [r4, #0]
	ldr	r7, [r9, #0]
	lsr	r0, r0, #2
	lsr	r8, r8, #2
	lsr	r1, r1, #2
	lsr	r7, r7, #2
	cmp	r0, r8
	bne	error
	str	r0, [r3, #0]
	cmp	r1, r7
	bne	error
	str	r1,	[r4, #0]
	cmp	r5, #192
	bne	error
	eor	r5, r5, #224
end:
	ldmfd	sp!, {fp, pc}
	#mov	r12, sp
	.size	main, .-main
	.align	2
	.global	push
	.type	push, %function
push:
	eor	r5, r5, #11
	mov	r6, lr
	cmp	lr, r6
	bne	error
	stmfd	sp!, {lr}
	mov	r12, sp
	ldr	lr, [r1, #0]
	ldr	r6, [r7, #0]
	add	lr, lr, #4
	add	r6, r6, #4
	cmp	lr, r6
	bne	error
	str	lr, [r1, #0]
	cmp	r0, r8
	bne	error
	str	r0, [r1, lr]
	ldmfd	sp!, {lr}
	mov	r6, lr
	mov	r12, sp
	cmp	lr, r6
	bne	error
	cmp	r5, #118
	bne	error
	eor	r5, r5, #193
	bx	lr
	.size	push, .-push
	.align	2
	.global	pop
	.type	pop, %function
pop:
	eor	r5, r5, #7
	mov	r6, lr
	cmp	lr, r6
	bne	error
	stmfd	sp!, {lr}
	mov	r12, sp
	ldr	lr, [r1, #0]
	ldr	r6, [r7, #0]
	ldr	r0, [r1, lr]
	ldr	r8, [r7, r6]
	sub	lr, lr, #4
	sub	r6, r6, #4
	cmp	lr, r6
	bne	error
	str	lr, [r1, #0]
	ldmfd	sp!, {lr}
	mov	r6, lr
	mov	r12, sp
	cmp	lr, r6
	bne	error
	cmp	r5, #142
	bne	error
	eor	r5, r5, #243
	bx	lr
	.size	pop, .-pop
	.align	2
	.global	move
	.type	move, %function
move:
	mov	r6, lr
	cmp	r0, r8
	bne	error
	cmp	r0, #0
	ble	move_end
	and	r5, r5, #240
	cmp	lr, r6
	bne	error
	stmfd	sp!, {lr}
	mov	r12, sp
	sub	r0, r0, #1
	sub	r8, r8, #1
	cmp	r2, r10
	bne	error
	cmp	r3, r11
	bne	error
	cmp	r4, r9
	bne	error
	stmfd	sp!, {r2, r3, r4}
	mov	r12, sp
	mov	lr, r3
	mov	r6, r11
	mov	r3, r4
	mov	r11, r9
	mov	r4, lr
	mov	r9, r6
	cmp	r5, #192
	bne	error
	eor	r5, r5, #13
	bl	move
	and	r5, r5, #240
	mov	r6, lr
	ldmfd	sp!, {r2, r3, r4}
	mov	r10, r2
	mov	r11, r3
	mov	r9, r4
	mov	r12, sp
	cmp	r0, r8
	bne	error
	stmfd	sp!, {r0}
	mov	r12, sp
	mov	r1, r2
	mov	r7, r10
	cmp	r5, #192
	bne	error
	eor	r5, r5, #73
	bl	pop
	mov	r6, lr
	mov	r1, r3
	mov	r7, r11
	bl	push
	eor	r5, r5, #3
	mov	r6, lr
	ldmfd	sp!, {r0}
	mov	r8, r0
	mov	r12, sp
	cmp	r2, r10
	bne	error
	cmp	r3, r11
	bne	error
	cmp	r4, r9
	bne	error
	stmfd	sp!, {r2, r3, r4}
	mov	r12, sp
	mov	lr, r2
	mov	r6, r10
	mov	r2, r4
	mov	r10, r9
	mov	r4, lr
	mov	r9, r6
	cmp	r5, #180
	bne	error
	eor	r5, r5, #124
	bl	move
	and	r5, r5, #240
	mov	r6, lr
	ldmfd	sp!, {r2, r3, r4}
	mov	r10, r2
	mov	r11, r3
	mov	r9, r4
	mov	r12, sp
	ldmfd	sp!, {lr}
	mov	r6, lr
	mov	r12, sp
	add	r0, r0, #1
	add	r8, r8, #1
	cmp	r5, #192
	bne	error
	eor	r5, r5, #0
move_end:
	cmp	lr, r6
	bne	error
	bx	lr
	.size	move, .-move
	.align	2
	.global	error
	.type	error, %function
error:
	mov	r4, #1
	movw	r0, #:lower16:errorSignal
	movt	r0, #:upper16:errorSignal
	str	r4, [r0, #0]
	b	end
	.size	error, .-error
	.ident	"GCC: (Sourcery CodeBench Lite 2013.05-39) 4.7.3"
